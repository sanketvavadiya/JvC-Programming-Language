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
    Location *location;
    Value *value;
}ValueNode;

typedef union ExpressionType{
    char *identifier;
    ValueNode *value_node;
    struct UnaryExpression *unary_expression;
    struct BinaryExpression *binary_expression;
    struct TernaryExpression *ternary_expression;
}ExpressionType;

typedef struct Expression{
    int type;
    Location *location;
    ExpressionType *expression_type;   
}Expression;

typedef struct AssignmentExpression{
    char *operator;
    char *left;
    Location *location;
    Expression *right;
}AssignmentExpression;

typedef struct DeclarationExpression{
    int datatype;
    Location *location;
    struct DeclarationList *declaration_list;
}DeclarationExpression;

typedef struct UnaryExpression{
    char prefix;
    char *operator;
    Expression *expression;
    Location *location;
}UnaryExpression;

typedef struct BinaryExpression{
    char *operator;
    Location *location;
    Expression *left, *right;  
}BinaryExpression;

typedef struct TernaryExpression{
    Location *location;
    Expression *test, *consequent, *alternate;
}TernaryExpression;

typedef struct DeclarationList{
    char *identifier;
    Expression *init;
    struct DeclarationList *next;
}DeclarationList;

typedef union ExpressionStatementType{
    AssignmentExpression *assignment_expression;
    DeclarationExpression *declaration_expression;
}ExpressionStatementType;

typedef struct ExpressionStatement{
    int type;
    Location *location;
    ExpressionStatementType *expression_statement_type;
}ExpressionStatement;

typedef union StatementType{
    ExpressionStatement *expression_statement;
    // print
    // if..else
    // for, while
}StatementType;

typedef struct Statement{
    int type;
    Location *location;
    StatementType *statement_type;
    struct Statement *next;
}Statement;

Statement *first_statement, *last_statement;