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

ExpressionStatement* makeBinaryExpressionNode(ExpressionStatement *left, char *operator, ExpressionStatement *right){
    BinaryExpression *binary_expression = (BinaryExpression*) malloc(sizeof(BinaryExpression));
    binary_expression->left = left;
    binary_expression->operator =strdup(operator);
    binary_expression->right = right;
    binary_expression->location = (Location*) malloc(sizeof(Location));
    binary_expression->location->line = line;
    
    ExpressionStatement *res = (ExpressionStatement*) malloc(sizeof(ExpressionStatement));
    res->type = BINARYEXP;
    res->expression_type = (ExpressionType*) malloc(sizeof(ExpressionType));
    res->expression_type->binary_expression = binary_expression;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

ExpressionStatement* makeUnaryExpressionNode(char *operator, char prefix, ExpressionStatement *expression_statement){
    UnaryExpression *unary_expression = (UnaryExpression*) malloc(sizeof(UnaryExpression));
    unary_expression->prefix = prefix;
    unary_expression->operator = strdup(operator);
    unary_expression->expression_statement = expression_statement;
    unary_expression->location = (Location*) malloc(sizeof(Location));
    unary_expression->location->line = line;

    ExpressionStatement *res = (ExpressionStatement*) malloc(sizeof(ExpressionStatement));
    res->type = UNARYEXP;
    res->expression_type = (ExpressionType*) malloc(sizeof(ExpressionType));
    res->expression_type->unary_expression = unary_expression;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

ExpressionStatement* makeTernaryExpressionNode(ExpressionStatement *test, ExpressionStatement *consequent, ExpressionStatement *alternate){
    TernaryExpression *ternary_expression = (TernaryExpression*) malloc(sizeof(TernaryExpression));
    ternary_expression->test = test;
    ternary_expression->consequent = consequent;
    ternary_expression->alternate = alternate;
    ternary_expression->location = (Location*) malloc(sizeof(Location));
    ternary_expression->location->line = line;

    ExpressionStatement *res = (ExpressionStatement*) malloc(sizeof(ExpressionStatement));
    res->type = TERNARYEXP;
    res->expression_type = (ExpressionType*) malloc(sizeof(ExpressionType));
    res->expression_type->ternary_expression = ternary_expression;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

ExpressionStatement* makeExpressionStatementNode(char *identifier, ValueNode *value_node){
    ExpressionStatement *res = (ExpressionStatement*) malloc(sizeof(ExpressionStatement));
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

AssignmentStatement* makeAssignmentStatementNode(char *identifier, char *operator, ExpressionStatement *input){
    AssignmentStatement *res = (AssignmentStatement*) malloc(sizeof(AssignmentStatement));
    res->operator = strdup(operator);
    res->left = strdup(identifier);
    res->right = input;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

DeclarationStatement* makeDeclarationStatementNode(int datatype, DeclarationList *declaration_list){
    DeclarationStatement *res = (DeclarationStatement*) malloc(sizeof(DeclarationStatement));
    res->datatype = datatype;
    res->declaration_list = declaration_list;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

DeclarationList* makeDeclarationListNode(char *identifier, ExpressionStatement *init){
    DeclarationList *res = (DeclarationList*) malloc(sizeof(DeclarationList));
    res->identifier = strdup(identifier);
    res->init = init;
    res->next = NULL;
    return res;
}

Statement* makeStatementNode(void *statement_type, int type){
    Statement *res = (Statement*) malloc(sizeof(Statement));
    res->type = type;
    res->statement_type = (StatementType*) malloc(sizeof(StatementType));
    switch(res->type){
        case EXPRESSION:            
            res->statement_type->expression_statement = (ExpressionStatement*)statement_type;
            break;
        case DECLARATION:
            res->statement_type->declaration_statement = (DeclarationStatement*)statement_type;
            break;
        case ASSIGNMENT:
            res->statement_type->assignment_statement = (AssignmentStatement*)statement_type;
            break;
    }
    return res;
}

void* makeIfStatementNode(void *input1, void *input2, int input){
        // only if statement
        if(input==1){
            IfStatement *res = (IfStatement*) malloc(sizeof(IfStatement));
            res->test = (ExpressionStatement*)input1;
            res->consequent = (StatementSet*)input2;
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
            StatementSet *res = (StatementSet*) malloc(sizeof(StatementSet));
            res->type = IFSTATEMENT;
            res->next = NULL;            
            if(input1!=NULL){
                StatementSet *dummy = (StatementSet*) malloc(sizeof(StatementSetType));
                IfStatement *ptr = (IfStatement*)input1;
                while(ptr->alternate!=NULL)
                    ptr = ptr->alternate->statement_set_type->if_statement;
                ptr->alternate = (StatementSet*)input2;
                dummy->statement_set_type = (StatementSetType*) malloc(sizeof(StatementSetType));
                dummy->statement_set_type->if_statement = ptr;
                dummy->location = (Location*) malloc(sizeof(Location));
                dummy->location->line = line;

                // dummy is pointing to last else if statement res will point to first else if
                res->statement_set_type = (StatementSetType*) malloc(sizeof(StatementSetType));
                res->statement_set_type->if_statement = (IfStatement*) input1;
                res->location = (Location*) malloc(sizeof(Location));
                res->location->line = line;
            }
            else
                res = (StatementSet*)input2;
            return res;
        }
}

IfStatement* makeElseifStatementNode(IfStatement *prev, ExpressionStatement *test, StatementSet *consequent){
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
            ptr = ptr->alternate->statement_set_type->if_statement;
        ptr->alternate = (StatementSet*) malloc(sizeof(StatementSet));
        ptr->alternate->type = IFSTATEMENT;
        ptr->alternate->statement_set_type = (StatementSetType*) malloc(sizeof(StatementSetType));
        ptr->alternate->statement_set_type->if_statement = res;
        ptr->alternate->next = NULL;

        // always returns first else if statement of/among all the else if statement
        return prev;
    }
    return res;
}

WhileStatement* makeWhileStatementNode(ExpressionStatement *test, Statement *body){
    WhileStatement *res = (WhileStatement*) malloc(sizeof(WhileStatement));
    res->test = test;
    res->body = body;
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    return res;
}

StatementSet* makeStatementSetNode(int type, void *statement_set_type, StatementSet *next){
    StatementSet *res = (StatementSet*) malloc(sizeof(StatementSet));
    res->type = type;
    res->statement_set_type = (StatementSetType*) malloc(sizeof(StatementSetType));
    switch(res->type){
        case STATEMENT:
            res->statement_set_type->statement = (Statement*)statement_set_type;
            break;
        case IFSTATEMENT:
            res->statement_set_type->if_statement = (IfStatement*)statement_set_type;
            break;
        case WHILESTATEMENT:
            res->statement_set_type->while_statement = (WhileStatement*)statement_set_type;
            break;
        case FORSTATEMENT:
            res->statement_set_type->for_statement = (ForStatement*)statement_set_type;
            break;
    }
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = line;
    
    // we are inserting every node in the front, so in the last we need to reverse the entire linked list
    res->next = next;    
    return res;
}

StatementSet* reverseStatements(StatementSet *curr){
    StatementSet *prev = NULL;
    while(curr!=NULL){
        StatementSet *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printStatementSetNode(StatementSet *statement_set, int indent){
    if(statement_set==NULL){
        printIndent(indent);
        printf("Block does not contain any statement\n");
    }
    else{
        StatementSet *this_statement = statement_set;
        while(this_statement!=NULL){
            switch(this_statement->type){
                case STATEMENT:
                    printStatementNode(this_statement->statement_set_type->statement, indent);
                    break;
                case IFSTATEMENT:
                    printIfStatementNode(this_statement->statement_set_type->if_statement, indent);
                    break;
                case WHILESTATEMENT:
                    printWhileStatementNode(this_statement->statement_set_type->while_statement, indent);
                    break;
            }
            this_statement = this_statement->next;
        }
    }
}

void printStatementNode(Statement *statement, int indent){
    printIndent(indent);
    printf("Statement\n");
    switch(statement->type){
        case EXPRESSION:
            printExpressionStatementNode(statement->statement_type->expression_statement, indent+1);
            break;
        case DECLARATION:
            printDeclarationStatementNode(statement->statement_type->declaration_statement, indent+1);
            break;
        case ASSIGNMENT:
            printAssignmentStatementNode(statement->statement_type->assignment_statement, indent+1);
            break;
    }
}

void printIfStatementNode(IfStatement *if_statement, int indent){
    printIndent(indent);
    printf("IfStatement\n");
    printIndent(indent+1);
    printf("test: \n");
    printExpressionStatementNode(if_statement->test, indent+2);
    printIndent(indent+1);
    printf("consequent: \n");
    printStatementSetNode(if_statement->consequent, indent+2);
    printIndent(indent+1);
    printf("alternate: \n");
    printStatementSetNode(if_statement->alternate, indent+2);
}

void printWhileStatementNode(WhileStatement *while_statement, int indent){
    printIndent(indent);
    printf("WhileStatement\n");
    printIndent(indent+1);
    printf("test: \n");
    printExpressionStatementNode(while_statement->test, indent+2);
    printIndent(indent+1);
    printf("body: \n");
    printStatementSetNode(while_statement->body, indent+2);
}

void printAssignmentStatementNode(AssignmentStatement *assignment_statement, int indent){
    printIndent(indent);
    printf("AssignmentStatement\n");
    printIndent(indent+1);
    printf("Left:\n");
    printIndent(indent+2);
    printf("identifier: %s\n", assignment_statement->left);
    printIndent(indent+1);
    printf("Operator: %s\n", assignment_statement->operator);
    printIndent(indent+1);
    printf("Right:\n");
    printExpressionStatementNode(assignment_statement->right, indent+2);
}

void printDeclarationStatementNode(DeclarationStatement *declaration_statement, int indent){
    printIndent(indent);
    printf("DeclarationStatement\n");
    printIndent(indent+1);
    printf("datatype:\n");
    printIndent(indent+2);
    switch(declaration_statement->datatype){
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
    printDeclarationListNode(declaration_statement->declaration_list, indent+1);
}

void printExpressionStatementNode(ExpressionStatement *expression_statement, int indent){
    switch(expression_statement->type){
        case IDENTIFIER:
            printIndent(indent);
            printf("identifier: %s\n", expression_statement->expression_type->identifier);
            break;
        case NUMERIC:
            printValueNode(expression_statement->expression_type->value_node, indent);
            break;
        case BINARYEXP:
            printBinaryExpressionNode(expression_statement->expression_type->binary_expression, indent+1);
            break;
        case UNARYEXP:
            printUnaryExpressionNode(expression_statement->expression_type->unary_expression, indent+1);
            break;
        case TERNARYEXP:
            printTernaryExpressionNode(expression_statement->expression_type->ternary_expression, indent+1);
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
    switch(unary_expression->expression_statement->type){
        case IDENTIFIER:
            printIndent(indent+1);
            printf("identifier: %s\n", unary_expression->expression_statement->expression_type->identifier);
            break;
        case NUMERIC:
            printValueNode(unary_expression->expression_statement->expression_type->value_node, indent+1);
            break;
        case BINARYEXP:
            printBinaryExpressionNode(unary_expression->expression_statement->expression_type->binary_expression, indent+1);
            break;
        case UNARYEXP:
            printUnaryExpressionNode(unary_expression->expression_statement->expression_type->unary_expression, indent+1);
            break;
        case TERNARYEXP:
            printTernaryExpressionNode(unary_expression->expression_statement->expression_type->ternary_expression, indent+1);
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
            printExpressionStatementNode(ptr->init, indent+1);
        ptr = ptr->next;
    }
}

void printIndent(int indent){
    while(indent-- > 0)
        printf("    |");
}