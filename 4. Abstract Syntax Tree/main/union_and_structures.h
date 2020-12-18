typedef char* string;
typedef char boolean;

typedef union Value{
    int i_val;
    float f_val;
    double d_val;
    char c_val;
    boolean b_val;
    string str_val;
}Value;

typedef struct Location{
    int line;
    // column
    // start, end
}Location;

typedef struct ValueNode{
    int datatype;
    int scope;
    Location *location;
    Value *value;
}ValueNode;

typedef struct UnaryExpression{
    char prefix;
    char *operator;
    struct ExpressionStatement *expression_statement;
    Location *location;
}UnaryExpression;

typedef struct BinaryExpression{
    char *operator;
    Location *location;
    struct ExpressionStatement *left, *right;  
}BinaryExpression;

typedef struct TernaryExpression{
    Location *location;
    struct ExpressionStatement *test, *consequent, *alternate;
}TernaryExpression;

typedef union ExpressionType{
    char *identifier;
    ValueNode *value_node;
    UnaryExpression *unary_expression;
    BinaryExpression *binary_expression;
    TernaryExpression *ternary_expression;
}ExpressionType;

typedef struct ExpressionStatement{
    int type;
    Location *location;
    ExpressionType *expression_type;   
}ExpressionStatement;

typedef struct DeclarationList{
    char *identifier;
    ExpressionStatement *init;
    struct DeclarationList *next;
}DeclarationList;

typedef struct DeclarationStatement{
    int datatype;
    Location *location;
    struct DeclarationList *declaration_list;
}DeclarationStatement;

typedef struct AssignmentStatement{
    char *operator;
    char *left;
    Location *location;
    ExpressionStatement *right;
}AssignmentStatement;

typedef union StatementType{
    ExpressionStatement *expression_statement;
    DeclarationStatement *declaration_statement;
    AssignmentStatement *assignment_statement;
}StatementType;

typedef struct Statement{
    int type;
    StatementType *statement_type;
}Statement;

typedef struct IfStatement{
    ExpressionStatement *test;
    Location *location;
    struct StatementSet *consequent;
    struct StatementSet *alternate;
}IfStatement;

typedef struct WhileStatement{
    ExpressionStatement *test;
    Location *location;
    struct StatementSet *body;
}WhileStatement;

typedef struct ForStatement{
    Location *location;
    ExpressionStatement *init;
    ExpressionStatement *test;
    ExpressionStatement *update;
    struct StatementSet *body;
}ForStatement;

typedef union StatementSetType{
    Statement *statement; 
    IfStatement *if_statement;
    WhileStatement *while_statement;
    ForStatement *for_statement;
}StatementSetType;

typedef struct StatementSet{
    int type;
    Location *location;
    StatementSetType *statement_set_type;
    struct StatementSet *next;
}StatementSet;