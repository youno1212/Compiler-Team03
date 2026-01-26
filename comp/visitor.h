
#ifndef _VISITOR_H_
#define _VISITOR_H_

#include "csua.h"

//typedef void (*visit_expr)(Expression* expr);
//typedef void (*visit_stmt)(Statement*  stmt);

typedef void (*visit_expr)(Expression* expr, Visitor* visitor);
typedef void (*visit_stmt)(Statement*  stmt, Visitor* visitor);




typedef struct MeanCheckLog_tag {
    char                    *log_str;
    struct MeanCheckLog_tag *next;
} MeanCheckLogger;

struct Visitor_tag {
    visit_expr* enter_expr_list;
    visit_expr* leave_expr_list;
    
    visit_expr* notify_expr_list;
    
    visit_stmt* enter_stmt_list;
    visit_stmt* leave_stmt_list;
    
    /* if文やwhile文のバイトコード生成用
     * 条件式評価後にジャンプ命令を生成するためのコールバック */
    visit_stmt* notify_stmt_list;
    
    /* if文のelse節用: then節終了後にJUMP命令を生成するためのコールバック
     * else節がある場合のみ呼ばれる */
    visit_stmt* notify2_stmt_list;
};

struct MeanVisitor_tag {
    Visitor visitor;
    CS_Compiler *compiler;
    int i;
    int j;
    MeanCheckLogger *check_log;
    int loop_nest_level;
};

typedef enum {
    VISIT_NORMAL,
    VISIT_NOMAL_ASSIGN,
} VisitState;

/* ============================================================
 * if文のバックパッチ情報を保存するスタック
 * ============================================================
 * ネストしたif文に対応するため、スタック構造を使用
 * 各if文のJUMP_IF_FALSEとJUMPの位置を保存
 * ============================================================ */
#define MAX_IF_NEST_DEPTH 64  /* if文の最大ネスト深度 */

typedef struct {
    uint32_t jump_if_false_pos;  /* JUMP_IF_FALSEのオペランド位置 */
    uint32_t jump_pos;           /* JUMPのオペランド位置（else節がある場合） */
    int has_else;                /* else節があるかどうか */
} IfBackpatchInfo;

/* ============================================================
 * while文のバックパッチ情報を保存するスタック
 * ============================================================ */
#define MAX_WHILE_NEST_DEPTH 64 /* while文の最大ネスト深度 */

typedef struct {
    uint32_t loop_start_pos;      /* ループ開始位置 */
    uint32_t jump_if_false_pos;   /* JUMP_IF_FALSEのオペランド位置 */
    uint32_t break_jumps[MAX_WHILE_NEST_DEPTH];
    int      break_jumps_count;
    uint32_t continue_jumps[MAX_WHILE_NEST_DEPTH];
    int      continue_jumps_count;
} WhileBackpatchInfo;


struct CodegenVisitor_tag {
    Visitor        visitor;
    CS_Compiler   *compiler;
    CS_Executable *exec;
    
    VisitState     v_state;
    uint16_t       assign_depth;
    
    uint32_t       CODE_ALLOC_SIZE;
    uint32_t       current_code_size;
    uint32_t       pos;
    uint8_t        *code;
    
    /* if文バックパッチ用スタック */
    IfBackpatchInfo if_stack[MAX_IF_NEST_DEPTH];
    int             if_stack_top;  /* スタックのトップインデックス */

    /* while文バックパッチ用スタック */
    WhileBackpatchInfo while_stack[MAX_WHILE_NEST_DEPTH];
    int                while_stack_top; /* スタックのトップインデックス */
};

/* visitor.c */
void print_depth();
Visitor* create_treeview_visitor();
void delete_visitor(Visitor* visitor);
void traverse_expr(Expression* expr, Visitor* visitor);
void traverse_stmt(Statement*  stmt, Visitor* visitor);

/* mean_visitor */
MeanVisitor* create_mean_visitor();
void show_mean_error(MeanVisitor* visitor);
char* get_type_name(CS_BasicType type);

/* codegen_visitor */
CodegenVisitor* create_codegen_visitor(CS_Compiler* compiler, CS_Executable *exec);

#endif