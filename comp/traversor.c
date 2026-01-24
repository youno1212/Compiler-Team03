#include <stdio.h>
#include <stdlib.h>

#include "visitor.h"

static void traverse_expr_children(Expression* expr, Visitor* visitor);
static void traverse_stmt_children(Statement*  stmt, Visitor* visitor);


void traverse_expr(Expression* expr, Visitor* visitor) {
    if (expr) {
        if (visitor->enter_expr_list[expr->kind] == NULL) {
            fprintf(stderr, "enter->type(%d) is null\n", expr->kind);
            exit(1);
        }

        visitor->enter_expr_list[expr->kind](expr, visitor);
        traverse_expr_children(expr, visitor);
        visitor->leave_expr_list[expr->kind](expr, visitor);

    }    
}

void traverse_stmt(Statement* stmt, Visitor* visitor) {
    if (stmt) {
        if (visitor->enter_stmt_list[stmt->type] == NULL) {
            fprintf(stderr, "enter->type(%d) is null\n", stmt->type);
            exit(1);
        }
        visitor->enter_stmt_list[stmt->type](stmt, visitor);
        traverse_stmt_children(stmt, visitor);
        visitor->leave_stmt_list[stmt->type](stmt, visitor);
    }
}

static void traverse_stmt_children(Statement* stmt, Visitor* visitor) {
    switch(stmt->type) {
        case EXPRESSION_STATEMENT: {
            traverse_expr(stmt->u.expression_s, visitor);
          break;  
        }
        case DECLARATION_STATEMENT: {
            traverse_expr(stmt->u.declaration_s->initializer, visitor);
            break;
        }
        case BLOCK_STATEMENT: {
            StatementList* list = stmt->u.block_s->statement_list;
            while (list != NULL) {
                traverse_stmt(list->stmt, visitor);
                list = list->next;
            }
            break;
        }
        /* ============================================================
         * IF_STATEMENT の走査処理
         * ============================================================
         * if文のバイトコード生成は以下の順序で行う:
         * 
         *   1. 条件式を評価 (traverse_expr)
         *   2. notify_stmt_list[IF_STATEMENT] を呼び出し
         *      -> JUMP_IF_FALSE命令を生成し、バックパッチ位置を保存
         *   3. then節を処理 (traverse_stmt)
         *   4. else節があれば:
         *      a. notify2_stmt_list[IF_STATEMENT] を呼び出し
         *         -> JUMP命令を生成（if文の終わりへ）
         *         -> JUMP_IF_FALSEのジャンプ先をバックパッチ（else節の開始）
         *      b. else節を処理 (traverse_stmt)
         *   5. leave_stmt_list[IF_STATEMENT] でJUMPをバックパッチ
         * ============================================================ */
        case IF_STATEMENT: {
            /* 1. 条件式を評価 -> 結果がスタックにプッシュされる */
            traverse_expr(stmt->u.if_s->condition, visitor);
            
            /* 2. notifyを呼び出してJUMP_IF_FALSE命令を生成 */
            if (visitor->notify_stmt_list && visitor->notify_stmt_list[IF_STATEMENT]) {
                visitor->notify_stmt_list[IF_STATEMENT](stmt, visitor);
            }
            
            /* 3. then節を走査 */
            traverse_stmt(stmt->u.if_s->then_block, visitor);
            
            /* 4. else節があれば走査 */
            if (stmt->u.if_s->else_block != NULL) {
                /* 4a. notify2を呼び出してJUMP命令を生成し、JUMP_IF_FALSEをバックパッチ */
                if (visitor->notify2_stmt_list && visitor->notify2_stmt_list[IF_STATEMENT]) {
                    visitor->notify2_stmt_list[IF_STATEMENT](stmt, visitor);
                }
                /* 4b. else節を走査 */
                traverse_stmt(stmt->u.if_s->else_block, visitor);
            }
            break;
        }
        case WHILE_STATEMENT: {
            /* 1. 条件式を評価 */
            traverse_expr(stmt->u.while_s->condition, visitor);

            /* 2. notify（ループ開始用） */
            if (visitor->notify_stmt_list && visitor->notify_stmt_list[WHILE_STATEMENT]) {
                visitor->notify_stmt_list[WHILE_STATEMENT](stmt, visitor);
            }

            /* 3. 本体 */
            traverse_stmt(stmt->u.while_s->body, visitor);

            /* 4. leaveでループ末尾処理 */
            break;
}

        default: {
            fprintf(stderr, "No such stmt->type %d in traverse_stmt_children\n", stmt->type);
        }
    }
}

static void traverse_expr_children(Expression* expr, Visitor *visitor) {
    switch(expr->kind) {
        case BOOLEAN_EXPRESSION:
        case IDENTIFIER_EXPRESSION:
        case DOUBLE_EXPRESSION:
        case INT_EXPRESSION: {
            break;
        }

        case INCREMENT_EXPRESSION:
        case DECREMENT_EXPRESSION: {
            traverse_expr(expr->u.inc_dec, visitor);
            break;
        }
        case MINUS_EXPRESSION: {
            traverse_expr(expr->u.minus_expression, visitor);
            break;
        }
        case LOGICAL_NOT_EXPRESSION: {
            traverse_expr(expr->u.logical_not_expression, visitor);
            break;
        }
        case ASSIGN_EXPRESSION: {
            traverse_expr(expr->u.assignment_expression.right, visitor);
            if (visitor->notify_expr_list) {
                if (visitor->notify_expr_list[ASSIGN_EXPRESSION]) {
                    visitor->notify_expr_list[ASSIGN_EXPRESSION](expr, visitor);
                }
            }
            
            
            traverse_expr(expr->u.assignment_expression.left, visitor);
            break;
        }
        case CAST_EXPRESSION: {
            traverse_expr(expr->u.cast_expression.expr, visitor);
            break;
        }
        case FUNCTION_CALL_EXPRESSION: {
            traverse_expr(expr->u.function_call_expression.function, visitor);
            break;
        }
        case LOGICAL_AND_EXPRESSION:
        case LOGICAL_OR_EXPRESSION:            
        case LT_EXPRESSION:
        case LE_EXPRESSION:
        case GT_EXPRESSION:
        case GE_EXPRESSION:
        case EQ_EXPRESSION:
        case NE_EXPRESSION:            
        case MOD_EXPRESSION:
        case DIV_EXPRESSION:
        case MUL_EXPRESSION:
        case SUB_EXPRESSION:
        case ADD_EXPRESSION: {
            if (expr->u.binary_expression.left) {
                traverse_expr(expr->u.binary_expression.left, visitor);
            }
            if (expr->u.binary_expression.right) {
                traverse_expr(expr->u.binary_expression.right, visitor);
            }
            break;
        }
        default:
            fprintf(stderr, "No such expr->kind %d in traverse_expr_children\n", expr->kind);
    }
}
