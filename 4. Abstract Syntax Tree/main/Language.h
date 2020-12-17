#include "constants.h"
#include "union_and_structures.h"

int line = 1;
int scope = 0;

ValueNode* makeValueNode(int datatype, Value* value){
    ValueNode *value_node = (ValueNode*) malloc(sizeof(ValueNode));
    value_node->datatype = datatype;
    value_node->scope = scope;

    value_node->value = (Value*) malloc(sizeof(Value));
    value_node->value = value;
    value_node->location = (Location*) malloc(sizeof(Location));
    value_node->location->line = line;
    return value_node;
}

Expression* makeExpressionNode(char *identifier, ValueNode *value_node){
    Expression *res = (Expression*) malloc(sizeof(Expression));
    res->expression_type = (ExpressionType*) malloc(sizeof(ExpressionType));
    if(identifier!=NULL){
        res->type = IDENTIFIER;
        res->expression_type->identifier = identifier;
    }
    else{
        res->type = NUMERIC;
        res->expression_type->value_node = value_node;
    }
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

AssignmentExpression* makeAssignmentNode(char *identifier, char *operator, Expression *input){
    AssignmentExpression *res = (AssignmentExpression*) malloc(sizeof(AssignmentExpression));
    res->operator = strdup(operator);
    res->left = strdup(identifier);
    res->right = input;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

DeclarationExpression* makeDeclarationNode(int datatype, DeclarationList *declaration_list){
    DeclarationExpression *res = (DeclarationExpression*) malloc(sizeof(DeclarationExpression));
    res->datatype = datatype;
    res->declaration_list = declaration_list;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

void* makeIfStatementNode(void *input1, void *input2, int input){
        // only if statement
        if(input==1){
            IfStatement *res = (IfStatement*) malloc(sizeof(IfStatement));
            res->test = (Expression*)input1;
            res->consequent = (Statement*)input2;
            res->alternate = NULL;
            res->location = (Location*) malloc(sizeof(Location));
            res->location->line = line;
            return res;
        }
        // if with else
        if(input==2){
            IfStatement *res = (IfStatement*)input1;
            res->alternate = (Statement*)input2;
            res->location = (Location*) malloc(sizeof(Location));
            res->location->line = line;
            return res;
        }
        // else if with else
        if(input==3){
            Statement *res = (Statement*) malloc(sizeof(Statement));
            res->type = IFSTATEMENT;
            res->next = NULL;            
            if(input1!=NULL){
                Statement *dummy = (Statement*) malloc(sizeof(StatementType));
                IfStatement *ptr = (IfStatement*)input1;
                while(ptr->alternate!=NULL)
                    ptr = ptr->alternate->statement_type->if_statement;
                ptr->alternate = (Statement*)input2;
                dummy->statement_type = (StatementType*) malloc(sizeof(StatementType));
                dummy->statement_type->if_statement = ptr;
                dummy->location = (Location*) malloc(sizeof(Location));
                dummy->location->line = line;

                // dummy is pointing to last else if statement res will point to first else if
                res->statement_type = (StatementType*) malloc(sizeof(StatementType));
                res->statement_type->if_statement = (IfStatement*) input1;
                res->location = (Location*) malloc(sizeof(Location));
                res->location->line = line;
            }
            else
                res = (Statement*)input2;
            return res;
        }
}

IfStatement* makeElseifStatementNode(IfStatement *prev, Expression *test, Statement *consequent){
    IfStatement *res = (IfStatement*) malloc(sizeof(IfStatement));
    res->test = test;
    res->consequent = consequent;
    res->alternate = NULL;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;

    // if else if statement is followed by another else if then new else if statement is in alternate part of prev else if statement
    if(prev!=NULL){
        IfStatement *ptr = prev;
        while(ptr->alternate!=NULL)
            ptr = ptr->alternate->statement_type->if_statement;
        ptr->alternate = (Statement*) malloc(sizeof(Statement));
        ptr->alternate->type = IFSTATEMENT;
        ptr->alternate->statement_type = (StatementType*) malloc(sizeof(StatementType));
        ptr->alternate->statement_type->if_statement = res;
        ptr->alternate->next = NULL;

        // always returns first else if statement of/among all the else if statement
        return prev;
    }
    return res;
}

WhileStatement* makeWhileStatementNode(Expression *test, Statement *body){
    WhileStatement *res = (WhileStatement*) malloc(sizeof(WhileStatement));
    res->test = test;
    res->body = body;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

Expression* makeBinaryExpressionNode(Expression *left, char *operator, Expression *right){
    BinaryExpression *binary_expression = (BinaryExpression*) malloc(sizeof(BinaryExpression));
    binary_expression->left = left;
    binary_expression->operator =strdup(operator);
    binary_expression->right = right;
    binary_expression->location = (Location*) malloc(sizeof(Location));
    binary_expression->location->line = line;
    
    Expression *res = (Expression*) malloc(sizeof(Expression));
    res->type = BINARYEXP;
    res->expression_type = (ExpressionType*) malloc(sizeof(ExpressionType));
    res->expression_type->binary_expression = binary_expression;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

Expression* makeUnaryExpressionNode(char *operator, char prefix, Expression *expression){
    UnaryExpression *unary_expression = (UnaryExpression*) malloc(sizeof(UnaryExpression));
    unary_expression->prefix = prefix;
    unary_expression->operator = strdup(operator);
    unary_expression->expression = expression;
    unary_expression->location = (Location*) malloc(sizeof(Location));
    unary_expression->location->line = line;

    Expression *res = (Expression*) malloc(sizeof(Expression));
    res->type = UNARYEXP;
    res->expression_type = (ExpressionType*) malloc(sizeof(ExpressionType));
    res->expression_type->unary_expression = unary_expression;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

Expression* makeTernaryExpressionNode(Expression *test, Expression *consequent, Expression *alternate){
    TernaryExpression *ternary_expression = (TernaryExpression*) malloc(sizeof(TernaryExpression));
    ternary_expression->test = test;
    ternary_expression->consequent = consequent;
    ternary_expression->alternate = alternate;
    ternary_expression->location = (Location*) malloc(sizeof(Location));
    ternary_expression->location->line = line;

    Expression *res = (Expression*) malloc(sizeof(Expression));
    res->type = TERNARYEXP;
    res->expression_type = (ExpressionType*) malloc(sizeof(ExpressionType));
    res->expression_type->ternary_expression = ternary_expression;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

DeclarationList* makeDeclarationListNode(char *identifier, Expression *init){
    DeclarationList *res = (DeclarationList*) malloc(sizeof(DeclarationList));
    res->identifier = strdup(identifier);
    res->init = init;
    res->next = NULL;
    return res;
}

ExpressionStatement* makeExpressionStatementNode(int type, void *expression_statement_type){
    ExpressionStatement *res = (ExpressionStatement*) malloc(sizeof(ExpressionStatement));
    res->type = type;
    res->expression_statement_type = (ExpressionStatementType*) malloc(sizeof(ExpressionStatementType));
    switch(res->type){
        case ASSIGNMENT:
            res->expression_statement_type->assignment_expression = (AssignmentExpression*)expression_statement_type;
            break;
        case DECLARATION:
            res->expression_statement_type->declaration_expression = (DeclarationExpression*)expression_statement_type;
            break;
    }
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

Statement* makeStatementNode(int type, void *statement_type, Statement *next){
    Statement *res = (Statement*) malloc(sizeof(Statement));
    res->type = type;
    res->statement_type = (StatementType*) malloc(sizeof(StatementType));
    switch(res->type){
        case EXPRESSION:
            res->statement_type->expression_statement = (ExpressionStatement*)statement_type;
            break;
        case IFSTATEMENT:
            res->statement_type->if_statement = (IfStatement*)statement_type;
            break;
        case WHILESTATEMENT:
            res->statement_type->while_statement = (WhileStatement*)statement_type;
            break;
    }
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    
    // we are inserting every node in the front, so in the last we need to reverse the entire linked list
    res->next = next;    
    return res;
}

Statement* reverseStatements(Statement *curr){
    Statement *prev = NULL;
    while(curr!=NULL){
        Statement *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printStatementNode(Statement *statement, int indent){
    if(statement==NULL){
        printIndent(indent);
        printf("Block does not contain any statement\n");
    }
    else{
        Statement *this_statement = statement;
        while(this_statement!=NULL){
            switch(this_statement->type){
                case EXPRESSION:
                    printExpressionNode(this_statement->statement_type->expression_statement, indent);
                    break;
                case IFSTATEMENT:
                    printIfStatementNode(this_statement->statement_type->if_statement, indent);
                    break;
                case WHILESTATEMENT:
                    printWhileStatementNode(this_statement->statement_type->while_statement, indent);
            }
            this_statement = this_statement->next;
        }
    }
}

void printExpressionNode(ExpressionStatement *expression_statement, int indent){
    printIndent(indent);
    printf("ExpressionStatement\n");
    switch(expression_statement->type){
        case ASSIGNMENT:
            printAssignmentNode(expression_statement->expression_statement_type->assignment_expression, indent+1);
            break;
        case DECLARATION:
            printDeclarationNode(expression_statement->expression_statement_type->declaration_expression, indent+1);
            break;
    }
}

void printIfStatementNode(IfStatement *if_statement, int indent){
    printIndent(indent);
    printf("IfStatement\n");
    printIndent(indent+1);
    printf("test: \n");
    printExpression(if_statement->test, indent+2);
    printIndent(indent+1);
    printf("consequent: \n");
    printStatementNode(if_statement->consequent, indent+2);
    printIndent(indent+1);
    printf("alternate: \n");
    printStatementNode(if_statement->alternate, indent+2);
}

void printWhileStatementNode(WhileStatement *while_statement, int indent){
    printIndent(indent);
    printf("WhileStatement\n");
    printIndent(indent+1);
    printf("test: \n");
    printExpression(while_statement->test, indent+2);
    printIndent(indent+1);
    printf("body: \n");
    printStatementNode(while_statement->body, indent+2);
}

void printAssignmentNode(AssignmentExpression *assignment_expression, int indent){
    printIndent(indent);
    printf("AssignmentExpression\n");
    printIndent(indent+1);
    printf("Left:\n");
    printIndent(indent+2);
    printf("identifier: %s\n", assignment_expression->left);
    printIndent(indent+1);
    printf("Operator: %s\n", assignment_expression->operator);
    printIndent(indent+1);
    printf("Right:\n");
    printExpression(assignment_expression->right, indent+2);
}

void printDeclarationNode(DeclarationExpression *declaration_expression, int indent){
    printIndent(indent);
    printf("DeclarationExpression\n");
    printIndent(indent+1);
    printf("datatype:\n");
    printIndent(indent+2);
    switch(declaration_expression->datatype){
        case INTEGER:
            printf("int\n");
            break;
        case FLOAT:
            printf("float\n");
            break;
        case DOUBLE:
            printf("double\n");
            break;
        case CHARACTER:
            printf("char\n");
            break;
        case BOOLEAN:
            printf("boolean");
            break;
        case STRING:
            printf("string\n");
            break;
    }
    printDeclarationListNode(declaration_expression->declaration_list, indent+1);
}

void printExpression(Expression *expression, int indent){
    switch(expression->type){
        case IDENTIFIER:
            printIndent(indent);
            printf("identifier: %s\n", expression->expression_type->identifier);
            break;
        case NUMERIC:
            printValueNode(expression->expression_type->value_node, indent);
            break;
        case BINARYEXP:
            printBinaryExpressionNode(expression->expression_type->binary_expression, indent+1);
            break;
        case UNARYEXP:
            printUnaryExpressionNode(expression->expression_type->unary_expression, indent+1);
            break;
        case TERNARYEXP:
            printTernaryExpressionNode(expression->expression_type->ternary_expression, indent+1);
            break;
    }
}

void printValueNode(ValueNode *value_node, int indent){
    printIndent(indent);
    printf("Value\n");
    printIndent(indent+1);
    switch(value_node->datatype){
        case INTEGER:
            printf("int: %d\n", value_node->value->i_val);
            break;
        case FLOAT:
            printf("float: %f\n", value_node->value->f_val);
            break;
        case DOUBLE:
            printf("double: %lf\n", value_node->value->d_val);
            break;
        case CHARACTER:
            printf("char: %c\n", value_node->value->c_val);
            break;
        case BOOLEAN:
            printf("boolean: ");
            if(value_node->value->b_val == '0')
                printf("false\n");
            else
                printf("true\n");
            break;
        case STRING:
            printf("string: %s\n", value_node->value->str_val);
            break;
    }
}

void printBinaryExpressionNode(BinaryExpression *binary_expression, int indent){
    printIndent(indent-1);
    printf("BinaryExpression\n");
    printIndent(indent);
    printf("Left:\n");
    switch(binary_expression->left->type){
        case IDENTIFIER:
            printIndent(indent+1);
            printf("identifier: %s\n", binary_expression->left->expression_type->identifier);
            break;
        case NUMERIC:
            printValueNode(binary_expression->left->expression_type->value_node, indent+1);
            break;
        case BINARYEXP:
            printBinaryExpressionNode(binary_expression->left->expression_type->binary_expression, indent+1);
            break;
        case UNARYEXP:
            printUnaryExpressionNode(binary_expression->left->expression_type->unary_expression, indent+1);
            break;
        case TERNARYEXP:
            printTernaryExpressionNode(binary_expression->left->expression_type->ternary_expression, indent+1);
            break;
    }
    printIndent(indent);
    printf("operator: %s\n", binary_expression->operator);
    printIndent(indent);
    printf("Right:\n");
    switch(binary_expression->right->type){
        case IDENTIFIER:
            printIndent(indent+1);
            printf("identifier: %s\n", binary_expression->right->expression_type->identifier);
            break;
        case NUMERIC:
            printValueNode(binary_expression->right->expression_type->value_node, indent+1);
            break;
        case BINARYEXP:
            printBinaryExpressionNode(binary_expression->right->expression_type->binary_expression, indent+1);
            break;
        case UNARYEXP:
            printUnaryExpressionNode(binary_expression->right->expression_type->unary_expression, indent+1);
            break;
        case TERNARYEXP:
            printTernaryExpressionNode(binary_expression->right->expression_type->ternary_expression, indent+1);
            break;
    }
}

void printUnaryExpressionNode(UnaryExpression *unary_expression, int indent){
    printIndent(indent-1);
    printf("UnaryExpression\n");
    printIndent(indent);
    printf("Operator: %s\n", unary_expression->operator);
    printIndent(indent);
    printf("prefix: ");
    if(unary_expression->prefix=='1')
        printf("true\n");
    else if(unary_expression->prefix=='0')
        printf("false\n");
    switch(unary_expression->expression->type){
        case IDENTIFIER:
            printIndent(indent+1);
            printf("identifier: %s\n", unary_expression->expression->expression_type->identifier);
            break;
        case NUMERIC:
            printValueNode(unary_expression->expression->expression_type->value_node, indent+1);
            break;
        case BINARYEXP:
            printBinaryExpressionNode(unary_expression->expression->expression_type->binary_expression, indent+1);
            break;
        case UNARYEXP:
            printUnaryExpressionNode(unary_expression->expression->expression_type->unary_expression, indent+1);
            break;
        case TERNARYEXP:
            printTernaryExpressionNode(unary_expression->expression->expression_type->ternary_expression, indent+1);
            break;
    }
}

void printTernaryExpressionNode(TernaryExpression *ternary_expression, int indent){
    printIndent(indent-1);
    printf("TernaryExpression\n");
    printIndent(indent);
    printf("test:\n");
    switch(ternary_expression->test->type){
        case IDENTIFIER:
            printIndent(indent+1);
            printf("identifier: %s\n", ternary_expression->test->expression_type->identifier);
            break;
        case NUMERIC:
            printValueNode(ternary_expression->test->expression_type->value_node, indent+1);
            break;
        case BINARYEXP:
            printBinaryExpressionNode(ternary_expression->test->expression_type->binary_expression, indent+1);
            break;
        case UNARYEXP:
            printUnaryExpressionNode(ternary_expression->test->expression_type->unary_expression, indent+1);
            break;
        case TERNARYEXP:
            printTernaryExpressionNode(ternary_expression->test->expression_type->ternary_expression, indent+1);
            break;
    }
    printIndent(indent);
    printf("consequent:\n");
    switch(ternary_expression->consequent->type){
        case IDENTIFIER:
            printIndent(indent+1);
            printf("identifier: %s\n", ternary_expression->consequent->expression_type->identifier);
            break;
        case NUMERIC:
            printValueNode(ternary_expression->consequent->expression_type->value_node, indent+1);
            break;
        case BINARYEXP:
            printBinaryExpressionNode(ternary_expression->consequent->expression_type->binary_expression, indent+1);
            break;
        case UNARYEXP:
            printUnaryExpressionNode(ternary_expression->consequent->expression_type->unary_expression, indent+1);
            break;
        case TERNARYEXP:
            printTernaryExpressionNode(ternary_expression->consequent->expression_type->ternary_expression, indent+1);
            break;
    }
    printIndent(indent);
    printf("alternate:\n");
    switch(ternary_expression->alternate->type){
        case IDENTIFIER:
            printIndent(indent+1);
            printf("identifier: %s\n", ternary_expression->alternate->expression_type->identifier);
            break;
        case NUMERIC:
            printValueNode(ternary_expression->alternate->expression_type->value_node, indent+1);
            break;
        case BINARYEXP:
            printBinaryExpressionNode(ternary_expression->alternate->expression_type->binary_expression, indent+1);
            break;
        case UNARYEXP:
            printUnaryExpressionNode(ternary_expression->alternate->expression_type->unary_expression, indent+1);
            break;
        case TERNARYEXP:
            printTernaryExpressionNode(ternary_expression->alternate->expression_type->ternary_expression, indent+1);
            break;
    }
}

void printDeclarationListNode(DeclarationList *declaration_list, int indent){
    DeclarationList *ptr = declaration_list;
    while(ptr!=NULL){
        printIndent(indent);
        printf("identifier:\n");
        printIndent(indent+1);
        printf("%s\n", ptr->identifier);
        printIndent(indent);
        printf("init:\n");
        if(ptr->init==NULL){
            printIndent(indent+1);
            printf("default initialization\n");
        }
        else
            printExpression(ptr->init, indent+1);
        ptr = ptr->next;
    }
}

void printIndent(int indent){
    while(indent-- > 0)
        printf("    |");
}