#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "csua.h"
#include "visitor.h"
#include "../svm/svm.h"


static size_t get_opsize(OpcodeInfo *op) {
    size_t size = strlen(op->parameter);
    size *= 2;    
    return size;
}


static void gen_byte_code(CodegenVisitor* visitor, SVM_Opcode op, ...) {
    va_list ap;
    va_start(ap, op);
    
    OpcodeInfo oInfo = svm_opcode_info[op];
    // printf("-->%s\n", oInfo.opname);
    // printf("-->%s\n", oInfo.parameter);
    
    // pos + 1byte + operator (1byte) + operand_size
    if ((visitor->pos + 1 + 1 + (get_opsize(&oInfo))) > visitor->current_code_size) {
        visitor->code = MEM_realloc(visitor->code,
                visitor->current_code_size += visitor->CODE_ALLOC_SIZE);        
    }
    
    visitor->code[visitor->pos++] = op & 0xff;
    
    for (int i = 0; i < strlen(oInfo.parameter); ++i) {
        switch(oInfo.parameter[i]) {
            case 'i': { // 2byte index
                int operand = va_arg(ap, int);
                visitor->code[visitor->pos++] = (operand >> 8) & 0xff;
                visitor->code[visitor->pos++] = operand        & 0xff;                
                break;
            }
            default: {
                fprintf(stderr, "undefined parameter\n");
                exit(1);
                break;
            }
        }
    }
    /*
    for (int i = 0; i < visitor->pos; ++i) {
        printf("%02x ", visitor->code[i]);
    }
    printf("\n");
    */
    va_end(ap);
    
    
    
    
    
    
    
    
    
    
    
}

static int add_constant(CS_Executable* exec, CS_ConstantPool* cpp) {
    exec->constant_pool = MEM_realloc(exec->constant_pool, 
            sizeof(CS_ConstantPool) * (exec->constant_pool_count+1));
    exec->constant_pool[exec->constant_pool_count] = *cpp;
    return exec->constant_pool_count++;
}


static void enter_castexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter castexpr : %d\n", expr->u.cast_expression.ctype);
}
static void leave_castexpr(Expression* expr, Visitor* visitor) { 
//    fprintf(stderr, "leave castexpr\n");
}

static void enter_boolexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter boolexpr : %d\n", expr->u.boolean_value);
}
static void leave_boolexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave boolexpr\n");
    CS_Executable* exec = ((CodegenVisitor*)visitor)->exec;
    CS_ConstantPool cp;
    cp.type = CS_CONSTANT_INT;
    cp.u.c_int = expr->u.boolean_value;
    int idx = add_constant(exec, &cp);
    gen_byte_code((CodegenVisitor*)visitor, SVM_PUSH_INT, idx);
}


static void enter_intexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter intexpr : %d\n", expr->u.int_value);

}
static void leave_intexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave intexpr\n");
    CS_Executable* exec = ((CodegenVisitor*)visitor)->exec;
    CS_ConstantPool cp;
    cp.type = CS_CONSTANT_INT;
    cp.u.c_int = expr->u.int_value;
    int idx = add_constant(exec, &cp);
    gen_byte_code((CodegenVisitor*)visitor, SVM_PUSH_INT, idx);    
}

static void enter_doubleexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter doubleexpr : %f\n", expr->u.double_value);
}
static void leave_doubleexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave doubleexpr\n");            
}

static void enter_identexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter identifierexpr : %s\n", expr->u.identifier.name);
}
static void leave_identexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave identifierexpr\n");            
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (c_visitor->v_state) {
        case VISIT_NORMAL: {
//            fprintf(stderr, "push value to stack\n");
            if (expr->u.identifier.is_function) {
//                printf("name=%s, index=%d\n", 
//                        expr->u.identifier.u.function->name,
//                        expr->u.identifier.u.function->index);
                gen_byte_code(c_visitor, SVM_PUSH_FUNCTION,
                        expr->u.identifier.u.function->index);
            } else {
                switch(expr->type->basic_type) {
                    case CS_BOOLEAN_TYPE:
                    case CS_INT_TYPE: {
                        gen_byte_code(c_visitor, SVM_PUSH_STATIC_INT,
                                expr->u.identifier.u.declaration->index);
                        break;
                    }
                    case CS_DOUBLE_TYPE: {
                        fprintf(stderr, "double not implementerd visit_nomal in leave_identexpr codegenvisitor\n");
                        exit(1);
                                                
                    }
                    default: {
                        fprintf(stderr, "%d: unknown type in visit_normal in leave_identexpr codegenvisitor\n", expr->line_number); 
                        exit(1);
                    }
                }
            }
            break;
        }
        case VISIT_NOMAL_ASSIGN: {
//            fprintf(stderr, "store value to index\n");
            
            if (!expr->u.identifier.is_function) {
//                fprintf(stderr, "index = %d\n", expr->u.identifier.u.declaration->index);
//                fprintf(stderr, "type = %s\n", get_type_name(expr->type->basic_type));
                switch (expr->type->basic_type) {
                    case CS_BOOLEAN_TYPE:
                    case CS_INT_TYPE:    {
                        gen_byte_code(c_visitor, SVM_POP_STATIC_INT, 
                                expr->u.identifier.u.declaration->index);
                        break;
                    }
                    case CS_DOUBLE_TYPE: {
                        fprintf(stderr, "double not implementerd in leave_identexpr codegenvisitor\n");
                        exit(1);
                    }
                    default: {
                        fprintf(stderr, "unknown type in leave_identexpr codegenvisitor\n");
                        exit(1);
                    }
                }
            } else {
                fprintf(stderr, "%d: cannot assign value to function\n", expr->line_number);
                exit(1);
            }
            
            if (c_visitor->assign_depth > 1) { // nested assign
                switch(expr->type->basic_type) {
                    case CS_BOOLEAN_TYPE:
                    case CS_INT_TYPE: {
                        gen_byte_code(c_visitor, SVM_PUSH_STATIC_INT,
                                expr->u.identifier.u.declaration->index);
                        break;
                    }
                    case CS_DOUBLE_TYPE: {
                        fprintf(stderr, "double not implementerd assign_depth in leave_identexpr codegenvisitor\n");
                        exit(1);
                                                
                    }
                    default: {
                        fprintf(stderr, "%d: unknown type in leave_identexpr codegenvisitor\n", expr->line_number); 
                        exit(1);
                    }
                }
            }                                                            
            
            break;
        }
        default: {
            fprintf(stderr, "no such v_state error\n");
            exit(1);
        }
    }
}


static void enter_addexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter addexpr : +\n");
}
static void leave_addexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave addexpr\n");
    switch(expr->type->basic_type) {
        case CS_INT_TYPE: {
            gen_byte_code((CodegenVisitor*)visitor, SVM_ADD_INT);
            break;
        }
        case CS_DOUBLE_TYPE: {
            gen_byte_code((CodegenVisitor*)visitor, SVM_ADD_DOUBLE);
            break;
        }
        default: {
            fprintf(stderr, "%d: unknown type in leave_addexpr codegenvisitor\n", expr->line_number); 
            exit(1);
        }
        
    }
}

static void enter_subexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter subexpr : -\n");
}
static void leave_subexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave subexpr\n");
    /* 減算: スタックの上2つの値を引く（下 - 上） */
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (expr->type->basic_type) {
        case CS_INT_TYPE: {
            gen_byte_code(c_visitor, SVM_SUB_INT);
            break;
        }
        case CS_DOUBLE_TYPE: {
            gen_byte_code(c_visitor, SVM_SUB_DOUBLE);
            break;
        }
        default: {
            fprintf(stderr, "%d: unknown type in leave_subexpr codegenvisitor\n", expr->line_number);
            exit(1);
        }
    }
}

static void enter_mulexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter mulexpr : *\n");
}
static void leave_mulexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave mulexpr\n");
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (expr->u.binary_expression.left->type->basic_type) {
        case CS_INT_TYPE:
            gen_byte_code(c_visitor, SVM_MUL_INT);
            break;
        case CS_DOUBLE_TYPE:
            gen_byte_code(c_visitor, SVM_MUL_DOUBLE);
            break;
        default:
            fprintf(stderr, "unsupported type for * operator\n");
            exit(1);
    }
}

static void enter_divexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter divexpr : /\n");
}
static void leave_divexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave divexpr\n");
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (expr->u.binary_expression.left->type->basic_type) {
        case CS_INT_TYPE:
            gen_byte_code(c_visitor, SVM_DIV_INT);
            break;
        case CS_DOUBLE_TYPE:
            gen_byte_code(c_visitor, SVM_DIV_DOUBLE);
            break;
        default:
            fprintf(stderr, "unsupported type for / operator\n");
            exit(1);
    }
}

static void enter_modexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter modexpr : mod \n");
}
static void leave_modexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave modexpr\n");
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (expr->u.binary_expression.left->type->basic_type) {
        case CS_INT_TYPE:
            gen_byte_code(c_visitor, SVM_MOD_INT);
            break;
        case CS_DOUBLE_TYPE:
            gen_byte_code(c_visitor, SVM_MOD_DOUBLE);
            break;
        default:
            fprintf(stderr, "unsupported type for %% operator\n");
            exit(1);
    }
}


static void enter_gtexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter gtexpr : > \n");
}
static void leave_gtexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave gtexpr\n");
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (expr->u.binary_expression.left->type->basic_type) {
        case CS_BOOLEAN_TYPE:
        case CS_INT_TYPE:
            gen_byte_code(c_visitor, SVM_GT_INT);
            break;
        case CS_DOUBLE_TYPE:
            gen_byte_code(c_visitor, SVM_GT_DOUBLE);
            break;
        default:
            fprintf(stderr, "unsupported type for > operator\n");
            exit(1);
    }
}

static void enter_geexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter geexpr : >= \n");
}
static void leave_geexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave geexpr\n");
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (expr->u.binary_expression.left->type->basic_type) {
        case CS_BOOLEAN_TYPE:
        case CS_INT_TYPE:
            gen_byte_code(c_visitor, SVM_GE_INT);
            break;
        case CS_DOUBLE_TYPE:
            gen_byte_code(c_visitor, SVM_GE_DOUBLE);
            break;
        default:
            fprintf(stderr, "unsupported type for >= operator\n");
            exit(1);
    }
}

static void enter_ltexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter ltexpr : < \n");
}
static void leave_ltexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave ltexpr\n");
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (expr->u.binary_expression.left->type->basic_type) {
        case CS_BOOLEAN_TYPE:
        case CS_INT_TYPE:
            gen_byte_code(c_visitor, SVM_LT_INT);
            break;
        case CS_DOUBLE_TYPE:
            gen_byte_code(c_visitor, SVM_LT_DOUBLE);
            break;
        default:
            fprintf(stderr, "unsupported type for < operator\n");
            exit(1);
    }
}

static void enter_leexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter leexpr : <= \n");
}
static void leave_leexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave leexpr\n");
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (expr->u.binary_expression.left->type->basic_type) {
        case CS_BOOLEAN_TYPE:
        case CS_INT_TYPE:
            gen_byte_code(c_visitor, SVM_LE_INT);
            break;
        case CS_DOUBLE_TYPE:
            gen_byte_code(c_visitor, SVM_LE_DOUBLE);
            break;
        default:
            fprintf(stderr, "unsupported type for <= operator\n");
            exit(1);
    }
}

static void enter_eqexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter eqexpr : == \n");
}
static void leave_eqexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave eqexpr\n");
    /* == 演算子: スタックトップの2つの値を比較し、等しければ1（真）、そうでなければ0（偽）をプッシュ */
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (expr->u.binary_expression.left->type->basic_type) {
        case CS_BOOLEAN_TYPE:
        case CS_INT_TYPE:
            gen_byte_code(c_visitor, SVM_EQ_INT);
            break;
        case CS_DOUBLE_TYPE:
            gen_byte_code(c_visitor, SVM_EQ_DOUBLE);
            break;
        default:
            fprintf(stderr, "unsupported type for == operator\n");
            exit(1);
    }
}

static void enter_neexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter neexpr : != \n");
}
static void leave_neexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave neexpr\n");
    /* != 演算子: スタックトップの2つの値を比較し、等しくなければ1（真）、等しければ0（偽）をプッシュ */
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (expr->u.binary_expression.left->type->basic_type) {
        case CS_BOOLEAN_TYPE:
        case CS_INT_TYPE:
            gen_byte_code(c_visitor, SVM_NE_INT);
            break;
        case CS_DOUBLE_TYPE:
            gen_byte_code(c_visitor, SVM_NE_DOUBLE);
            break;
        default:
            fprintf(stderr, "unsupported type for != operator\n");
            exit(1);
    }
}

static void enter_landexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter landexpr : && \n");
}
static void leave_landexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave landexpr\n");
    gen_byte_code((CodegenVisitor*)visitor, SVM_LOGICAL_AND);
}

static void enter_lorexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter lorexpr : || \n");
}
static void leave_lorexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave lorexpr\n");
    gen_byte_code((CodegenVisitor*)visitor, SVM_LOGICAL_OR);
}

static void enter_incexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter incexpr : ++ \n");
}
static void leave_incexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave incexpr\n");
}

static void enter_decexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter decexpr : -- \n");
}
static void leave_decexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave decexpr\n");
}

static void enter_minusexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter minusexpr : - \n");
}
static void leave_minusexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave minusexpr\n");
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (expr->type->basic_type) {
        case CS_INT_TYPE:
            gen_byte_code(c_visitor, SVM_MINUS_INT);
            break;
        case CS_DOUBLE_TYPE:
            gen_byte_code(c_visitor, SVM_MINUS_DOUBLE);
            break;
        default:
            fprintf(stderr, "unsupported type for unary - operator\n");
            exit(1);
    }
}

static void enter_lognotexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter lognotexpr : ! \n");
}
static void leave_lognotexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave lognotexpr\n");
    gen_byte_code((CodegenVisitor*)visitor, SVM_LOGICAL_NOT);
}

static void enter_assignexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter assignexpr : %d \n", expr->u.assignment_expression.aope);
    ((CodegenVisitor*)visitor)->assign_depth++;
}
static void leave_assignexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave assignexpr\n");
    --((CodegenVisitor*)visitor)->assign_depth;
//    ((CodegenVisitor*)visitor)->v_state = VISIT_NORMAL;
}

static void notify_assignexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "NOTIFY assignexpr : %d \n", expr->u.assignment_expression.aope);
    ((CodegenVisitor*)visitor)->v_state = VISIT_NOMAL_ASSIGN;    
}

static void enter_funccallexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "enter function call :\n");
}
static void leave_funccallexpr(Expression* expr, Visitor* visitor) {
//    fprintf(stderr, "leave function call\n");
    gen_byte_code((CodegenVisitor*)visitor, SVM_INVOKE);
}

/* For statement */
static void enter_exprstmt(Statement* stmt, Visitor* visitor) {
//    fprintf(stderr, "enter exprstmt :\n");

}
static void leave_exprstmt(Statement* stmt, Visitor* visitor) {
//    fprintf(stderr, "leave exprstmt\n");
    
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    switch (c_visitor->v_state) {
        case VISIT_NORMAL: {
            gen_byte_code(c_visitor, SVM_POP);
            break;
        }
        case VISIT_NOMAL_ASSIGN: {            
            c_visitor->v_state = VISIT_NORMAL;
            c_visitor->assign_depth = 0;
            break;
        }
        default: {
            fprintf(stderr, "no such visit state in leave_exprstmt\n");
            break;
        }
    }
    
//    ((CodegenVisitor*)visitor)->v_state = VISIT_NORMAL;
    
    
}

static void enter_declstmt(Statement* stmt, Visitor* visitor) {
//    fprintf(stderr, "enter declstmt name=%s, type=%s:\n", 
//            stmt->u.declaration_s->name,
//            get_type_name(stmt->u.declaration_s->type->basic_type));
            
}

static void leave_declstmt(Statement* stmt, Visitor* visitor) {
//    fprintf(stderr, "leave declstmt\n");
    /* 宣言文: 初期化式の値をスタックからポップして変数に格納 */
    CodegenVisitor* c_visitor = (CodegenVisitor*)visitor;
    if (stmt->u.declaration_s->initializer != NULL) {
        /* 初期化式がある場合、値を変数に格納 */
        switch (stmt->u.declaration_s->type->basic_type) {
            case CS_BOOLEAN_TYPE:
            case CS_INT_TYPE:
                gen_byte_code(c_visitor, SVM_POP_STATIC_INT,
                        stmt->u.declaration_s->index);
                break;
            case CS_DOUBLE_TYPE:
                gen_byte_code(c_visitor, SVM_POP_STATIC_DOUBLE,
                        stmt->u.declaration_s->index);
                break;
            default:
                fprintf(stderr, "unsupported type in leave_declstmt\n");
                exit(1);
        }
    }
}

/* Block statement */
static void enter_blockstmt(Statement* stmt, Visitor* visitor) {
//    fprintf(stderr, "enter blockstmt\n");
}

static void leave_blockstmt(Statement* stmt, Visitor* visitor) {
//    fprintf(stderr, "leave blockstmt\n");
}

/* ============================================================
 * If statement のバイトコード生成
 * ============================================================
 * 
 * if文のバイトコード構造:
 * 
 *   [条件式のバイトコード]      <- 条件式を評価し、結果をスタックにプッシュ
 *   JUMP_IF_FALSE else_label   <- 条件が偽ならelse部分へジャンプ
 *   [then節のバイトコード]      <- 条件が真の場合に実行
 *   JUMP end_label             <- then節実行後、if文の終わりへジャンプ
 * else_label:
 *   [else節のバイトコード]      <- 条件が偽の場合に実行（省略可能）
 * end_label:
 *   [if文の次の処理]
 * 
 * バックパッチ:
 *   ジャンプ命令を生成する時点では、ジャンプ先のアドレスが未確定。
 *   そのため、仮のアドレス(0)を設定しておき、後でジャンプ先が確定したら
 *   正しいアドレスに書き換える（バックパッチ）。
 * ============================================================ */

/* 
 * バックパッチ用ヘルパー関数
 * 指定した位置のジャンプ先アドレスを更新する
 * 
 * @param visitor: CodegenVisitor
 * @param patch_pos: パッチする位置（ジャンプ命令のオペランド位置）
 * @param target_addr: 新しいジャンプ先アドレス
 */
static void backpatch(CodegenVisitor* visitor, uint32_t patch_pos, uint32_t target_addr) {
    /* 2バイトのアドレスを書き込む（上位バイト、下位バイトの順） */
    visitor->code[patch_pos]     = (target_addr >> 8) & 0xff;  /* 上位8ビット */
    visitor->code[patch_pos + 1] = target_addr & 0xff;          /* 下位8ビット */
}

/*
 * 現在のコード位置を取得
 * ジャンプ先のラベル位置として使用
 */
static uint32_t get_current_pos(CodegenVisitor* visitor) {
    return visitor->pos;
}

/*
 * ジャンプ命令を生成し、後でバックパッチするための位置を返す
 * 
 * @param visitor: CodegenVisitor
 * @param op: ジャンプオペコード（SVM_JUMP または SVM_JUMP_IF_FALSE）
 * @return: オペランド（アドレス）の位置（バックパッチ用）
 */
static uint32_t gen_jump_code(CodegenVisitor* visitor, SVM_Opcode op) {
    /* ジャンプ命令を生成（アドレスは仮に0を設定） */
    gen_byte_code(visitor, op, 0);
    /* オペランドの開始位置を返す（オペコード1バイトの直後） */
    /* pos は gen_byte_code 後に進んでいるので、-2 で2バイトのオペランド位置を指す */
    return visitor->pos - 2;
}

static void enter_ifstmt(Statement* stmt, Visitor* visitor) {
//    fprintf(stderr, "enter ifstmt\n");
    /* 
     * enter時: バックパッチスタックに新しいエントリを準備
     * else節があるかどうかを事前に確認して保存
     */
    CodegenVisitor* cv = (CodegenVisitor*)visitor;
    cv->if_stack_top++;
    
    if (cv->if_stack_top >= MAX_IF_NEST_DEPTH) {
        fprintf(stderr, "Error: if statement nesting too deep\n");
        exit(1);
    }
    
    /* else節の有無を保存 */
    cv->if_stack[cv->if_stack_top].has_else = (stmt->u.if_s->else_block != NULL);
    cv->if_stack[cv->if_stack_top].jump_if_false_pos = 0;
    cv->if_stack[cv->if_stack_top].jump_pos = 0;
}

/*
 * notify_ifstmt: 条件式評価後に呼ばれる
 * 
 * このタイミングで:
 *   1. JUMP_IF_FALSE命令を生成（条件が偽ならelse/endif へジャンプ）
 *   2. バックパッチ位置を保存
 */
static void notify_ifstmt(Statement* stmt, Visitor* visitor) {
//    fprintf(stderr, "notify ifstmt: generating JUMP_IF_FALSE\n");
    CodegenVisitor* cv = (CodegenVisitor*)visitor;
    
    /* JUMP_IF_FALSE命令を生成し、オペランド位置を保存 */
    /* 条件が偽の場合、else節またはif文の終わりにジャンプ */
    cv->if_stack[cv->if_stack_top].jump_if_false_pos = gen_jump_code(cv, SVM_JUMP_IF_FALSE);
}

/*
 * notify2_ifstmt: then節終了後、else節開始前に呼ばれる
 * 
 * else節がある場合のみ呼ばれる
 * このタイミングで:
 *   1. JUMP命令を生成（then節からif文の終わりへジャンプ）
 *   2. JUMP_IF_FALSEのジャンプ先をバックパッチ（else節の開始位置）
 */
static void notify2_ifstmt(Statement* stmt, Visitor* visitor) {
//    fprintf(stderr, "notify2 ifstmt: generating JUMP and backpatching JUMP_IF_FALSE\n");
    CodegenVisitor* cv = (CodegenVisitor*)visitor;
    
    /* 1. JUMP命令を生成（then節実行後、if文の終わりへスキップ） */
    cv->if_stack[cv->if_stack_top].jump_pos = gen_jump_code(cv, SVM_JUMP);
    
    /* 2. JUMP_IF_FALSEのジャンプ先を現在位置（else節の開始）にバックパッチ */
    uint32_t else_start_pos = get_current_pos(cv);
    backpatch(cv, cv->if_stack[cv->if_stack_top].jump_if_false_pos, else_start_pos);
}

static void leave_ifstmt(Statement* stmt, Visitor* visitor) {
//    fprintf(stderr, "leave ifstmt: backpatching\n");
    CodegenVisitor* cv = (CodegenVisitor*)visitor;
    
    uint32_t current_pos = get_current_pos(cv);
    
    /* 
     * leave時: 最終的なバックパッチを実行
     * 
     * else節がない場合:
     *   JUMP_IF_FALSE -> 現在位置（if文の終わり）
     * 
     * else節がある場合:
     *   JUMP_IF_FALSE は notify2 で既にバックパッチ済み
     *   JUMP -> 現在位置（if文の終わり）
     */
    
    if (cv->if_stack[cv->if_stack_top].has_else) {
        /* else節がある場合: JUMPのジャンプ先を現在位置にバックパッチ */
        backpatch(cv, cv->if_stack[cv->if_stack_top].jump_pos, current_pos);
    } else {
        /* else節がない場合: JUMP_IF_FALSEのジャンプ先を現在位置にバックパッチ */
        backpatch(cv, cv->if_stack[cv->if_stack_top].jump_if_false_pos, current_pos);
    }
    
    /* スタックをポップ */
    cv->if_stack_top--;
}

/* ============================================================
 * While statement のバイトコード生成
 * ============================================================
 *
 * while文のバイトコード構造:
 *
 * loop_start:
 *   [条件式のバイトコード]
 *   JUMP_IF_FALSE loop_end
 *   [ループ本体のバイトコード]
 *   JUMP loop_start
 * loop_end:
 *   [ループの次の処理]
 * ============================================================ */

static void enter_whilestmt(Statement* stmt, Visitor* visitor) {
    CodegenVisitor* cv = (CodegenVisitor*)visitor;
    cv->while_stack_top++;

    if (cv->while_stack_top >= MAX_WHILE_NEST_DEPTH) {
        fprintf(stderr, "Error: while statement nesting too deep\n");
        exit(1);
    }

    /* ループ開始位置をスタックに保存 */
    cv->while_stack[cv->while_stack_top].loop_start_pos = get_current_pos(cv);
    cv->while_stack[cv->while_stack_top].break_jumps_count = 0;
    cv->while_stack[cv->while_stack_top].continue_jumps_count = 0;
}

static void notify_whilestmt(Statement* stmt, Visitor* visitor) {
    CodegenVisitor* cv = (CodegenVisitor*)visitor;

    /* JUMP_IF_FALSE命令を生成し、オペランド位置を保存 */
    cv->while_stack[cv->while_stack_top].jump_if_false_pos = gen_jump_code(cv, SVM_JUMP_IF_FALSE);
}

static void leave_whilestmt(Statement* stmt, Visitor* visitor) {
    CodegenVisitor* cv = (CodegenVisitor*)visitor;

    /* ループの開始地点へ戻るJUMP命令を生成 */
    uint32_t loop_start = cv->while_stack[cv->while_stack_top].loop_start_pos;
    gen_byte_code(cv, SVM_JUMP, loop_start);

    /* JUMP_IF_FALSEのジャンプ先を現在位置（ループの終わり）にバックパッチ */
    uint32_t loop_end = get_current_pos(cv);
    backpatch(cv, cv->while_stack[cv->while_stack_top].jump_if_false_pos, loop_end);

    // break文のバックパッチ
    for (int i = 0; i < cv->while_stack[cv->while_stack_top].break_jumps_count; i++) {
        backpatch(cv, cv->while_stack[cv->while_stack_top].break_jumps[i], loop_end);
    }

    // continue文のバックパッチ
    for (int i = 0; i < cv->while_stack[cv->while_stack_top].continue_jumps_count; i++) {
        backpatch(cv, cv->while_stack[cv->while_stack_top].continue_jumps[i], loop_start);
    }

    /* スタックをポップ */
    cv->while_stack_top--;
}

static void enter_breakstmt(Statement* stmt, Visitor* visitor) {
    CodegenVisitor* cv = (CodegenVisitor*)visitor;
    if (cv->while_stack_top == -1) {
        return;
    }
    WhileBackpatchInfo* current_loop = &cv->while_stack[cv->while_stack_top];
    if (current_loop->break_jumps_count >= MAX_WHILE_NEST_DEPTH) {
        fprintf(stderr, "Error: Too many break statements in a loop\n");
        exit(1);
    }
    current_loop->break_jumps[current_loop->break_jumps_count++] = gen_jump_code(cv, SVM_JUMP);
}

static void leave_breakstmt(Statement* stmt, Visitor* visitor) {
    // leave処理は不要
}

static void enter_continuestmt(Statement* stmt, Visitor* visitor) {
    CodegenVisitor* cv = (CodegenVisitor*)visitor;
    if (cv->while_stack_top == -1) {
        return;
    }
    WhileBackpatchInfo* current_loop = &cv->while_stack[cv->while_stack_top];
    if (current_loop->continue_jumps_count >= MAX_WHILE_NEST_DEPTH) {
        fprintf(stderr, "Error: Too many continue statements in a loop\n");
        exit(1);
    }
    current_loop->continue_jumps[current_loop->continue_jumps_count++] = gen_jump_code(cv, SVM_JUMP);
}

static void leave_continuestmt(Statement* stmt, Visitor* visitor) {
    // leave処理は不要
}

CodegenVisitor* create_codegen_visitor(CS_Compiler* compiler, CS_Executable *exec) {
    visit_expr* enter_expr_list;
    visit_expr* leave_expr_list;
    visit_stmt* enter_stmt_list;
    visit_stmt* leave_stmt_list;
    
    visit_expr* notify_expr_list;
    visit_stmt* notify_stmt_list;   /* if文などの制御文用: 条件式評価後 */
    visit_stmt* notify2_stmt_list;  /* if文のelse節用: then節終了後 */
    
    if (compiler == NULL || exec == NULL) {
        fprintf(stderr, "Compiler or Executable is NULL\n");
        exit(1);
    }
    
    CodegenVisitor* visitor = (CodegenVisitor*)MEM_malloc(sizeof(CodegenVisitor));
    visitor->compiler = compiler;
    visitor->exec = exec;
    visitor->CODE_ALLOC_SIZE = 10; // temporary
    visitor->current_code_size = 0;
    visitor->pos = 0;
    visitor->code = NULL;
    visitor->v_state = VISIT_NORMAL;
    visitor->assign_depth = 0;
    
    /* if文バックパッチ用スタックの初期化 */
    visitor->if_stack_top = -1;  /* スタックは空の状態 */

    /* while文バックパッチ用スタックの初期化 */
    visitor->while_stack_top = -1; /* スタックは空の状態 */

    enter_expr_list = (visit_expr*)MEM_malloc(sizeof(visit_expr) * EXPRESSION_KIND_PLUS_ONE);
    leave_expr_list = (visit_expr*)MEM_malloc(sizeof(visit_expr) * EXPRESSION_KIND_PLUS_ONE);
    notify_expr_list = (visit_expr*)MEM_malloc(sizeof(visit_expr) * EXPRESSION_KIND_PLUS_ONE);
    
    enter_stmt_list = (visit_stmt*)MEM_malloc(sizeof(visit_stmt) * STATEMENT_TYPE_COUNT_PLUS_ONE);
    leave_stmt_list = (visit_stmt*)MEM_malloc(sizeof(visit_stmt) * STATEMENT_TYPE_COUNT_PLUS_ONE);
    notify_stmt_list = (visit_stmt*)MEM_malloc(sizeof(visit_stmt) * STATEMENT_TYPE_COUNT_PLUS_ONE);   /* if文用 */
    notify2_stmt_list = (visit_stmt*)MEM_malloc(sizeof(visit_stmt) * STATEMENT_TYPE_COUNT_PLUS_ONE);  /* else節用 */
    
    memset(enter_expr_list, 0, sizeof(visit_expr) * EXPRESSION_KIND_PLUS_ONE);
    memset(leave_expr_list, 0, sizeof(visit_expr) * EXPRESSION_KIND_PLUS_ONE);
    memset(notify_expr_list, 0, sizeof(visit_expr) * EXPRESSION_KIND_PLUS_ONE);    
    memset(enter_stmt_list, 0, sizeof(visit_stmt) * STATEMENT_TYPE_COUNT_PLUS_ONE);
    memset(leave_stmt_list, 0, sizeof(visit_stmt) * STATEMENT_TYPE_COUNT_PLUS_ONE);
    memset(notify_stmt_list, 0, sizeof(visit_stmt) * STATEMENT_TYPE_COUNT_PLUS_ONE);   /* if文用 */
    memset(notify2_stmt_list, 0, sizeof(visit_stmt) * STATEMENT_TYPE_COUNT_PLUS_ONE);  /* else節用 */

    
    enter_expr_list[BOOLEAN_EXPRESSION]       = enter_boolexpr;
    enter_expr_list[INT_EXPRESSION]           = enter_intexpr;
    enter_expr_list[DOUBLE_EXPRESSION]        = enter_doubleexpr;
    enter_expr_list[IDENTIFIER_EXPRESSION]    = enter_identexpr;    
    enter_expr_list[ADD_EXPRESSION]           = enter_addexpr;
    enter_expr_list[SUB_EXPRESSION]           = enter_subexpr;
    enter_expr_list[MUL_EXPRESSION]           = enter_mulexpr;
    enter_expr_list[DIV_EXPRESSION]           = enter_divexpr;
    enter_expr_list[MOD_EXPRESSION]           = enter_modexpr;    
    enter_expr_list[GT_EXPRESSION]            = enter_gtexpr;
    enter_expr_list[GE_EXPRESSION]            = enter_geexpr;
    enter_expr_list[LT_EXPRESSION]            = enter_ltexpr;
    enter_expr_list[LE_EXPRESSION]            = enter_leexpr;
    enter_expr_list[EQ_EXPRESSION]            = enter_eqexpr;
    enter_expr_list[NE_EXPRESSION]            = enter_neexpr;
    enter_expr_list[LOGICAL_AND_EXPRESSION]   = enter_landexpr;
    enter_expr_list[LOGICAL_OR_EXPRESSION]    = enter_lorexpr;
    enter_expr_list[INCREMENT_EXPRESSION]     = enter_incexpr;
    enter_expr_list[DECREMENT_EXPRESSION]     = enter_decexpr;
    enter_expr_list[MINUS_EXPRESSION]         = enter_minusexpr;
    enter_expr_list[LOGICAL_NOT_EXPRESSION]   = enter_lognotexpr;
    enter_expr_list[ASSIGN_EXPRESSION]        = enter_assignexpr;
    enter_expr_list[FUNCTION_CALL_EXPRESSION] = enter_funccallexpr;
    enter_expr_list[CAST_EXPRESSION]          = enter_castexpr;
    
    enter_stmt_list[EXPRESSION_STATEMENT]     = enter_exprstmt;
        enter_stmt_list[DECLARATION_STATEMENT]    = enter_declstmt;
        enter_stmt_list[BLOCK_STATEMENT]          = enter_blockstmt;
        enter_stmt_list[IF_STATEMENT]             = enter_ifstmt;  /* if文のenter関数を登録 */
        enter_stmt_list[WHILE_STATEMENT]          = enter_whilestmt;
        enter_stmt_list[BREAK_STATEMENT]          = enter_breakstmt;
        enter_stmt_list[CONTINUE_STATEMENT]       = enter_continuestmt;
        
        notify_expr_list[ASSIGN_EXPRESSION]       = notify_assignexpr;
        
        /* if文: 条件式評価後にJUMP_IF_FALSE命令を生成するためのnotify関数 */
        notify_stmt_list[IF_STATEMENT]            = notify_ifstmt;
        notify_stmt_list[WHILE_STATEMENT]         = notify_whilestmt;
        
        /* if文: then節終了後にJUMP命令を生成し、JUMP_IF_FALSEをバックパッチするnotify2関数 */
        notify2_stmt_list[IF_STATEMENT]           = notify2_ifstmt;
        
        
        
        leave_expr_list[BOOLEAN_EXPRESSION]       = leave_boolexpr;
        leave_expr_list[INT_EXPRESSION]           = leave_intexpr;
        leave_expr_list[DOUBLE_EXPRESSION]        = leave_doubleexpr;
        leave_expr_list[IDENTIFIER_EXPRESSION]    = leave_identexpr;    
        leave_expr_list[ADD_EXPRESSION]           = leave_addexpr;
        leave_expr_list[SUB_EXPRESSION]           = leave_subexpr;
        leave_expr_list[MUL_EXPRESSION]           = leave_mulexpr;
        leave_expr_list[DIV_EXPRESSION]           = leave_divexpr;
        leave_expr_list[MOD_EXPRESSION]           = leave_modexpr;    
        leave_expr_list[GT_EXPRESSION]            = leave_gtexpr;
        leave_expr_list[GE_EXPRESSION]            = leave_geexpr;
        leave_expr_list[LT_EXPRESSION]            = leave_ltexpr;
        leave_expr_list[LE_EXPRESSION]            = leave_leexpr;
        leave_expr_list[EQ_EXPRESSION]            = leave_eqexpr;
        leave_expr_list[NE_EXPRESSION]            = leave_neexpr;
        leave_expr_list[LOGICAL_AND_EXPRESSION]   = enter_landexpr;
        leave_expr_list[LOGICAL_OR_EXPRESSION]    = enter_lorexpr;
        leave_expr_list[INCREMENT_EXPRESSION]     = leave_incexpr;
        leave_expr_list[DECREMENT_EXPRESSION]     = leave_decexpr;
        leave_expr_list[MINUS_EXPRESSION]         = leave_minusexpr;
        leave_expr_list[LOGICAL_NOT_EXPRESSION]   = leave_lognotexpr;
        leave_expr_list[ASSIGN_EXPRESSION]        = leave_assignexpr;
        leave_expr_list[FUNCTION_CALL_EXPRESSION] = leave_funccallexpr;
        leave_expr_list[CAST_EXPRESSION]          = leave_castexpr;
        
        leave_stmt_list[EXPRESSION_STATEMENT]     = leave_exprstmt;
        leave_stmt_list[DECLARATION_STATEMENT]    = leave_declstmt;
        leave_stmt_list[BLOCK_STATEMENT]          = leave_blockstmt;
        leave_stmt_list[IF_STATEMENT]             = leave_ifstmt;  /* if文のleave関数を登録 */
        leave_stmt_list[WHILE_STATEMENT]          = leave_whilestmt;
        leave_stmt_list[BREAK_STATEMENT]          = leave_breakstmt;
        leave_stmt_list[CONTINUE_STATEMENT]       = leave_continuestmt;
        
        ((Visitor*)visitor)->enter_expr_list = enter_expr_list;
        ((Visitor*)visitor)->leave_expr_list = leave_expr_list;
        ((Visitor*)visitor)->enter_stmt_list = enter_stmt_list;
        ((Visitor*)visitor)->leave_stmt_list = leave_stmt_list;

    ((Visitor*)visitor)->notify_expr_list = notify_expr_list;
    ((Visitor*)visitor)->notify_stmt_list = notify_stmt_list;    /* if文用: 条件式評価後 */
    ((Visitor*)visitor)->notify2_stmt_list = notify2_stmt_list;  /* if文用: then節終了後 */
    
    
    
    
    return visitor;
}
