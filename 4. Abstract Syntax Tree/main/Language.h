#include "constants.h"
#include "union_and_structures.h"

ValueNode* executeExpressionStatementNode(ExpressionStatement *expression_statement, int this_line);

int line = 1;
int scope = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                             //
// --------------------------------------------- Node generation Functions --------------------------------------------- //   //
//                                                                                                                           //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    res->scope = scope;
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

ForStatement* makeForStatementNode(Statement *init, Statement *test, Statement *update, StatementSet *body){
    ForStatement *res = (ForStatement*) malloc(sizeof(ForStatement));
    res->init = init;
    res->test = test;
    res->update = update;
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                      //
// --------------------------------------------- AST print Functions --------------------------------------------- //   //
//                                                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
                case FORSTATEMENT:
                    printForStatementNode(this_statement->statement_set_type->for_statement, indent);
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

void printForStatementNode(ForStatement *for_statement, int indent){
    printIndent(indent);
    printf("ForStatement\n");
    if(for_statement->init!=NULL){
        printIndent(indent+1);
        printf("init: \n");
        printStatementNode(for_statement->init, indent+2);
    }
    if(for_statement->test!=NULL){
        printIndent(indent+1);
        printf("test: \n");
        printStatementNode(for_statement->test, indent+2);
    }
    if(for_statement->update!=NULL){
        printIndent(indent+1);
        printf("update: \n");
        printStatementNode(for_statement->update, indent+2);
    }
    printIndent(indent+1);
    printf("body: \n");
    printStatementSetNode(for_statement->body, indent+2);
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                       //
// --------------------------------------------- Util Functions --------------------------------------------- //        //
//                                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string toString(ValueNode *value_node){
    char *str_val;
    int size;
    switch(value_node->datatype){
        case INTEGER:
            size = snprintf(NULL, 0, "%d", value_node->value->i_val);
            str_val = malloc(size + 1);
            snprintf(str_val, size+1, "%d", value_node->value->i_val);
            break;
        case FLOAT:
            size = snprintf(NULL, 0, "%f", value_node->value->f_val);
            str_val = malloc(size + 1);
            snprintf(str_val, size+1, "%f", value_node->value->f_val);
            break;
        case DOUBLE:
            size = snprintf(NULL, 0, "%d", value_node->value->d_val);
            str_val = malloc(size + 1);
            snprintf(str_val, size+1, "%d", value_node->value->d_val);
            break;
        case CHARACTER:
            size = snprintf(NULL, 0, "%c", value_node->value->c_val);
            str_val = malloc(size + 1);
            snprintf(str_val, size+1, "%c", value_node->value->c_val);
            break;
        case BOOLEAN:
            size = snprintf(NULL, 0, "%c", value_node->value->c_val);
            str_val = malloc(size + 1);
            snprintf(str_val, size+1, "%c", value_node->value->c_val);
            break;
    }
    return str_val;
}

ValueNode* changeValueNode(ValueNode *value_node, int to_datatype){
    int from_datatype = value_node->datatype;
    ValueNode *res = (ValueNode*) malloc(sizeof(ValueNode));
    res->datatype = to_datatype;
    res->scope = scope;
    res->value = (Value*) malloc(sizeof(Value));

    if(to_datatype == INTEGER){
        if(from_datatype == INTEGER) res->value->i_val = value_node->value->i_val;
        else if(from_datatype == FLOAT) res->value->i_val = (int)value_node->value->f_val;
        else if(from_datatype == DOUBLE) res->value->i_val = (int)value_node->value->i_val;
        else if(from_datatype == CHARACTER) res->value->i_val = value_node->value->c_val;
        else if(from_datatype == BOOLEAN) {
            if(value_node->value->b_val=='1')
                res->value->i_val = 1;
            else
                res->value->i_val = 0;
        }
        else if(from_datatype == STRING) {
            printf("JvC: [error: %d] fail type conversion string to int\n", line);
            exit(0);
        }
    }

    else if(to_datatype == FLOAT){
        if(from_datatype == INTEGER) res->value->f_val = value_node->value->i_val;
        else if(from_datatype == FLOAT) res->value->f_val = value_node->value->f_val;
        else if(from_datatype == DOUBLE) res->value->f_val = (float)value_node->value->d_val;
        else if(from_datatype == CHARACTER) res->value->f_val = (float)value_node->value->c_val;
        else if(from_datatype == BOOLEAN) res->value->f_val = (float)value_node->value->b_val;
        else if(from_datatype == STRING) {
            printf("JvC: [error: %d] fail type conversion string to float\n", line);
            exit(0);
        }
    }

    else if(to_datatype == DOUBLE){
        if(from_datatype == INTEGER) res->value->d_val = value_node->value->i_val;
        else if(from_datatype == FLOAT) res->value->d_val = value_node->value->f_val;
        else if(from_datatype == DOUBLE) res->value->d_val = value_node->value->d_val;
        else if(from_datatype == CHARACTER) res->value->d_val = (double)value_node->value->c_val;
        else if(from_datatype == BOOLEAN) res->value->d_val = (double)value_node->value->b_val;
        else if(from_datatype == STRING) {
            printf("JvC: [error: %d] fail type conversion string to double\n", line);
            exit(0);
        }
    }

    else if(to_datatype == CHARACTER){
        if(from_datatype == INTEGER)res->value->c_val = value_node->value->i_val;
        else if(from_datatype == FLOAT) {
            printf("JvC: [error: %d] fail type conversion float to char\n", line);
            exit(0);
        }
        else if(from_datatype == DOUBLE) {
            printf("JvC: [error: %d] fail type conversion double to char\n", line);
            exit(0);
        }
        else if(from_datatype == CHARACTER) res->value->c_val = value_node->value->c_val;
        else if(from_datatype == BOOLEAN) res->value->c_val = value_node->value->c_val;
        else if(from_datatype == STRING) {
            printf("JvC: [error: %d] fail type conversion string to char\n", line);
            exit(0);
        }
    }

    else if(to_datatype == BOOLEAN){
        if(from_datatype == INTEGER) {
            printf("JvC: [error: %d] fail type conversion int to boolean\n", line);
            exit(0);
        }
        else if(from_datatype == FLOAT) {
            printf("JvC: [error: %d] fail type conversion float to boolean\n", line);
            exit(0);
        }
        else if(from_datatype == DOUBLE) {
            printf("JvC: [error: %d] fail type conversion double to boolean\n", line);
            exit(0);
        }
        else if(from_datatype == CHARACTER) {
            printf("JvC: [error: %d] fail type conversion char to boolean\n", line);
            exit(0);
        }
        else if(from_datatype == BOOLEAN) res->value->b_val = value_node->value->b_val;
        else if(from_datatype == STRING) {
            printf("JvC: [error: %d] fail type conversion string to boolean\n", line);
            exit(0);
        }
    }
    
    else if(to_datatype == STRING){
        if(from_datatype == INTEGER) res->value->str_val = toString(value_node);
        else if(from_datatype == FLOAT) res->value->str_val = toString(value_node);
        else if(from_datatype == DOUBLE) res->value->str_val = toString(value_node);
        else if(from_datatype == CHARACTER) res->value->str_val = toString(value_node);
        else if(from_datatype == BOOLEAN) res->value->str_val = toString(value_node);
        else if(from_datatype == STRING) res->value->str_val = strdup(value_node->value->str_val);
    }
    res->location = value_node->location;
    return res;
}

ValueNode* findSymbol(char *identifier, int this_line){
    SymbolTable *ptr = first_symbol;
    while(ptr!=NULL){
        if(strcmp(ptr->identifier, identifier) == 0){
            if(ptr->value_node->scope != scope){
                printf("JvC: [error: %d] symbol '%s' is out of scope\n", ptr->value_node->location->line, ptr->identifier);
                exit(0);
            }
            return ptr->value_node;
        }
        ptr = ptr->next;
    }
    printf("JvC: [error: %d] cannot find symbol %s\n", this_line, identifier);
    exit(0);
    return NULL;
}

ValueNode* cloneSymbol(ValueNode *value_node, int this_line){
    ValueNode *res = (ValueNode*) malloc(sizeof(ValueNode));
    res->datatype = value_node->datatype;
    res->scope = scope;
    res->value = (Value*) malloc(sizeof(Value));

    switch(value_node->datatype){
        case INTEGER:
            res->value->i_val = value_node->value->i_val;
            break;
        case FLOAT:
            res->value->f_val = value_node->value->f_val;
            break;
        case DOUBLE:
            res->value->d_val = value_node->value->d_val;
            break;
        case CHARACTER:
            res->value->c_val = value_node->value->c_val;
            break;
        case BOOLEAN:
            res->value->b_val = value_node->value->b_val;
            break;
        case STRING:
            res->value->str_val = strdup(value_node->value->str_val);
            break;
    }
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = this_line;
    return res;
}

string getDatatype(int datatype_of){
    switch(datatype_of){
        case INTEGER:
            return "int";
            break;
        case FLOAT:
            return "float";
            break;
        case DOUBLE:
            return "double";
            break;
        case CHARACTER:
            return "char";
            break;
        case BOOLEAN:
            return "boolean";
            break;
        default:
            return "string";
            break;
    }
}

void showVariables(){
    int i=0;
    for(;i<55;i++)
        printf("-");
    printf("\n%35s\n", "Variable summary");
    for(i=0;i<55;i++)
        printf("-");
    printf("\n %-10s %-10s %-15s %-10s %-10s\n", "Name", "Datatype", "Value", "line", "scope");
    SymbolTable *ptr = first_symbol;
    while(ptr!=NULL){
        printf(" %-10s %-10s", ptr->identifier, getDatatype(ptr->value_node->datatype));
        switch(ptr->value_node->datatype){
            case INTEGER:
                printf(" %-15d", ptr->value_node->value->i_val);
                break;
            case FLOAT:
                printf(" %-15f", ptr->value_node->value->f_val);
                break;
            case DOUBLE:
                printf(" %-15lf", ptr->value_node->value->d_val);
                break;
            case CHARACTER:
                printf(" %-15c", ptr->value_node->value->c_val);
                break;
            case BOOLEAN:
                printf(" %-15s", ptr->value_node->value->b_val=='0' ? "false" : "true");
                break;
            case STRING:
                printf(" %-15s", ptr->value_node->value->str_val);
                break;
        }
        printf(" %-10d %-10d\n", ptr->value_node->location->line, ptr->value_node->scope);
        ptr = ptr->next;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                       //
// --------------------------------------------- Execution Functions --------------------------------------------- //   //
//                                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void executeProgram(StatementSet *first_statement){
    StatementSet *ptr = first_statement;
    while(ptr!=NULL){
        int this_line = ptr->location->line;
        switch(ptr->type){
            case STATEMENT:
                executeStatementNode(ptr->statement_set_type->statement, this_line);
                break;
            case IFSTATEMENT:
                // executeIfStatementNode(ptr->statement_set_type->if_statement);
                break;
            case WHILESTATEMENT:
                // executeWhileStatementNode(ptr->statement_set_type->while_statement);
                break;
            case FORSTATEMENT:
                // executeForStatementNode(ptr->statement_set_type->for_statement);
                break;
        }
        ptr = ptr->next;
    }
}

void executeStatementNode(Statement *statement, int this_line){
    ValueNode *value_node;
    switch(statement->type){
        case EXPRESSION:
            value_node = executeExpressionStatementNode(statement->statement_type->expression_statement, this_line);
            break;
        case DECLARATION:
            executeDeclarationStatementNode(statement->statement_type->declaration_statement, this_line);
            break;
        case ASSIGNMENT:
            executeAssignmentStatementNode(statement->statement_type->assignment_statement, this_line);
            break;
    }
}

void executeDeclarationStatementNode(DeclarationStatement *declaration_statement, int this_line){
    executeDeclarationListNode(declaration_statement->declaration_list, declaration_statement->datatype, declaration_statement->location->line);
}

void executeAssignmentStatementNode(AssignmentStatement *assignment_statement, int this_line){
    ValueNode *left = findSymbol(assignment_statement->left, this_line);
    ValueNode *right = executeExpressionStatementNode(assignment_statement->right, this_line);

    ValueNode *res = cloneSymbol(left, this_line);
    res = changeValueNode(right, res->datatype);

    if(strcmp(assignment_statement->operator, "=")==0){
        left->value = res->value;
    }
    else if(strcmp(assignment_statement->operator, "+=")==0){
        if(res->datatype==BOOLEAN){
            printf("JvC: [error: %d] bad operand types for binary operator '%s'\n", this_line, assignment_statement->operator);
            exit(0);
        }
        switch(res->datatype){
            case INTEGER:
                left->value->i_val += res->value->i_val;
                break;
            case FLOAT:
                left->value->f_val += res->value->f_val;
                break;
            case DOUBLE:
                left->value->d_val += res->value->d_val;
                break;
            case CHARACTER:
                left->value->c_val += res->value->c_val;
                break;
            case STRING:
                left->value->str_val = strcat(left->value->str_val, res->value->str_val);
                break;
        }
    }
    else if(strcmp(assignment_statement->operator, "-=")==0){
        if(res->datatype==BOOLEAN || res->datatype==STRING){
            printf("JvC: [error: %d] bad operand types for binary operator '%s'\n", this_line, assignment_statement->operator);
            exit(0);
        }
        switch(res->datatype){
            case INTEGER:
                left->value->i_val -= res->value->i_val;
                break;
            case FLOAT:
                left->value->f_val -= res->value->f_val;
                break;
            case DOUBLE:
                left->value->d_val -= res->value->d_val;
                break;
            case CHARACTER:
                left->value->c_val -= res->value->c_val;
                break;
        }
    }
    else if(strcmp(assignment_statement->operator, "*=")==0){
        if(res->datatype==BOOLEAN || res->datatype==STRING){
            printf("JvC: [error: %d] bad operand types for binary operator '%s'\n", this_line, assignment_statement->operator);
            exit(0);
        }
        switch(res->datatype){
            case INTEGER:
                left->value->i_val *= res->value->i_val;
                break;
            case FLOAT:
                left->value->f_val *= res->value->f_val;
                break;
            case DOUBLE:
                left->value->d_val *= res->value->d_val;
                break;
            case CHARACTER:
                left->value->c_val *= res->value->c_val;
                break;
        }
    }
    else if(strcmp(assignment_statement->operator, "/=")==0){
        if(res->datatype==BOOLEAN || res->datatype==STRING){
            printf("JvC: [error: %d] bad operand types for binary operator '%s'\n", this_line, assignment_statement->operator);
            exit(0);
        }
        switch(res->datatype){
            case INTEGER:
                left->value->i_val -= res->value->i_val;
                break;
            case FLOAT:
                left->value->f_val -= res->value->f_val;
                break;
            case DOUBLE:
                left->value->d_val -= res->value->d_val;
                break;
            case CHARACTER:
                left->value->c_val -= res->value->c_val;
                break;
        }
    }
    else if(strcmp(assignment_statement->operator, "%=")==0){
        if(res->datatype==BOOLEAN || res->datatype==STRING){
            printf("JvC: [error: %d] bad operand types for binary operator '%s'\n", this_line, assignment_statement->operator);
            exit(0);
        }
        switch(res->datatype){
            case INTEGER:
                left->value->i_val -= res->value->i_val;
                break;
            case FLOAT:
                left->value->f_val -= res->value->f_val;
                break;
            case DOUBLE:
                left->value->d_val -= res->value->d_val;
                break;
            case CHARACTER:
                left->value->c_val -= res->value->c_val;
                break;
        }
    }
}

void executeDeclarationListNode(DeclarationList *declaration_list, int datatype, int this_line){
    DeclarationList *ptr = declaration_list;
    while(ptr!=NULL){
        insertInSymbolTable(ptr->identifier, ptr->init, datatype, this_line);
        ptr = ptr->next;
    }
}

ValueNode* executeValueNode(ValueNode *value_node){
    return value_node;
}

ValueNode* executeBinaryExpressionNode(BinaryExpression *binary_expression, int this_line){
    ValueNode *left = executeExpressionStatementNode(binary_expression->left, this_line);
    ValueNode *right = executeExpressionStatementNode(binary_expression->right, this_line);

    ValueNode *res = (ValueNode*) malloc(sizeof(ValueNode));
    res->value = (Value*) malloc(sizeof(Value));

    if(strcmp(binary_expression->operator, "||")==0){
        if(left->datatype==BOOLEAN && right->datatype){
            res->datatype = BOOLEAN;
            res->value->b_val = (left->value->b_val-'0') || (right->value->b_val-'0') ? '1' : '0';
        }
        else{
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
    }
    else if(strcmp(binary_expression->operator, "&&")==0){
        if(left->datatype==BOOLEAN && right->datatype){
            res->datatype = BOOLEAN;
            res->value->b_val = (left->value->b_val-'0') && (right->value->b_val-'0') ? '1' : '0';
        }
        else{
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
    }
    else if(strcmp(binary_expression->operator, "|")==0){
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val | right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val | right->value->c_val;
            }
            else{
                printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
                printf("first type: %s\n", getDatatype(left->datatype));
                printf("second type: %s\n", getDatatype(right->datatype));
                exit(0);
            }
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val | right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val | right->value->c_val;
            }
            else{
                printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
                printf("first type: %s\n", getDatatype(left->datatype));
                printf("second type: %s\n", getDatatype(right->datatype));
                exit(0);
            }
        }
        else{
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
    }
    else if(strcmp(binary_expression->operator, "^")==0){
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val ^ right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val ^ right->value->c_val;
            }
            else{
                printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
                printf("first type: %s\n", getDatatype(left->datatype));
                printf("second type: %s\n", getDatatype(right->datatype));
                exit(0);
            }
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val ^ right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val ^ right->value->c_val;
            }
            else{
                printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
                printf("first type: %s\n", getDatatype(left->datatype));
                printf("second type: %s\n", getDatatype(right->datatype));
                exit(0);
            }
        }
        else{
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
    }
    else if(strcmp(binary_expression->operator, "&")==0){
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val & right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val & right->value->c_val;
            }
            else{
                printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
                printf("first type: %s\n", getDatatype(left->datatype));
                printf("second type: %s\n", getDatatype(right->datatype));
                exit(0);
            }
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val & right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val & right->value->c_val;
            }
            else{
                printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
                printf("first type: %s\n", getDatatype(left->datatype));
                printf("second type: %s\n", getDatatype(right->datatype));
                exit(0);
            }
        }
        else{
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
    }
    else if(strcmp(binary_expression->operator, ">=")==0){
        res->datatype = BOOLEAN;
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==STRING || right->datatype==STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->i_val >= right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->i_val >= right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->i_val >= right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->i_val >= right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==FLOAT){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->f_val >= right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->f_val >= right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->f_val >= right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->f_val >= right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==DOUBLE){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->d_val >= right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->d_val >= right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->d_val >= right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->d_val >= right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->c_val >= right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->c_val >= right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->c_val >= right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->c_val >= right->value->c_val ? '1' : '0';
        }
    }
    else if(strcmp(binary_expression->operator, ">")==0){
        res->datatype = BOOLEAN;
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==STRING || right->datatype==STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->i_val > right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->i_val > right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->i_val > right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->i_val > right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==FLOAT){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->f_val > right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->f_val > right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->f_val > right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->f_val > right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==DOUBLE){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->d_val > right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->d_val > right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->d_val > right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->d_val > right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->c_val > right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->c_val > right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->c_val > right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->c_val > right->value->c_val ? '1' : '0';
        }
    }
    else if(strcmp(binary_expression->operator, "<=")==0){

        res->datatype = BOOLEAN;
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==STRING || right->datatype==STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->i_val <= right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->i_val <= right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->i_val <= right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->i_val <= right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==FLOAT){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->f_val <= right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->f_val <= right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->f_val <= right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->f_val <= right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==DOUBLE){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->d_val <= right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->d_val <= right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->d_val <= right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->d_val <= right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->c_val <= right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->c_val <= right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->c_val <= right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->c_val <= right->value->c_val ? '1' : '0';
        }
    }
    else if(strcmp(binary_expression->operator, "<")==0){
        res->datatype = BOOLEAN;
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==STRING || right->datatype==STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->i_val < right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->i_val < right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->i_val < right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->i_val < right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==FLOAT){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->f_val < right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->f_val < right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->f_val < right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->f_val < right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==DOUBLE){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->d_val < right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->d_val < right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->d_val < right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->d_val < right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->c_val < right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->c_val < right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->c_val < right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->c_val < right->value->c_val ? '1' : '0';
        }
    }
    else if(strcmp(binary_expression->operator, "==")==0){
        res->datatype = BOOLEAN;
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            if(left->datatype==BOOLEAN && right->datatype==BOOLEAN)
                res->value->b_val = left->value->b_val == right->value->b_val ? '1' : '0';
            else{
                printf("JvC: [error: %d]  incomparable types: %s and %s\n", this_line, getDatatype(left->datatype), getDatatype(right->datatype));
                exit(0);
            }
        }
        if(left->datatype==STRING || right->datatype==STRING){
            if(left->datatype==STRING && right->datatype==STRING)
                res->value->b_val = strcmp(left->value->str_val, right->value->str_val) ? '0' : '1';
            else{
                printf("JvC: [error: %d]  incomparable types: %s and %s\n", this_line, getDatatype(left->datatype), getDatatype(right->datatype));
                exit(0);
            }
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->i_val == right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->i_val == right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->i_val == right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->i_val == right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==FLOAT){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->f_val == right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->f_val == right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->f_val == right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->f_val == right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==DOUBLE){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->d_val == right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->d_val == right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->d_val == right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->d_val == right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->c_val == right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->c_val == right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->c_val == right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->c_val == right->value->c_val ? '1' : '0';
        }
    }
    else if(strcmp(binary_expression->operator, "!=")==0){
        res->datatype = BOOLEAN;
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            if(left->datatype==BOOLEAN && right->datatype==BOOLEAN)
                res->value->b_val = left->value->b_val == right->value->b_val ? '1' : '0';
            else{
                printf("JvC: [error: %d]  incomparable types: %s and %s\n", this_line, getDatatype(left->datatype), getDatatype(right->datatype));
                exit(0);
            }
        }
        if(left->datatype==STRING || right->datatype==STRING){
            if(left->datatype==STRING && right->datatype==STRING)
                res->value->b_val = strcmp(left->value->str_val, right->value->str_val) ? '1' : '0';
            else{
                printf("JvC: [error: %d]  incomparable types: %s and %s\n", this_line, getDatatype(left->datatype), getDatatype(right->datatype));
                exit(0);
            }
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->i_val != right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->i_val != right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->i_val != right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->i_val != right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==FLOAT){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->f_val != right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->f_val != right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->f_val != right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->f_val != right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==DOUBLE){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->d_val != right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->d_val != right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->d_val != right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->d_val != right->value->c_val ? '1' : '0';
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER)
                res->value->b_val = left->value->c_val != right->value->i_val ? '1' : '0';
            else if(right->datatype==FLOAT)
                res->value->b_val = left->value->c_val != right->value->f_val ? '1' : '0';
            else if(right->datatype==DOUBLE)
                res->value->b_val = left->value->c_val != right->value->d_val ? '1' : '0';
            else if(right->datatype==CHARACTER)
                res->value->b_val = left->value->c_val != right->value->c_val ? '1' : '0';
        }
    }
    else if(strcmp(binary_expression->operator, ">>")==0){
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val >> right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val >> right->value->c_val;
            }
            else{
                printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
                printf("first type: %s\n", getDatatype(left->datatype));
                printf("second type: %s\n", getDatatype(right->datatype));
                exit(0);
            }
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val >> right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val >> right->value->c_val;
            }
            else{
                printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
                printf("first type: %s\n", getDatatype(left->datatype));
                printf("second type: %s\n", getDatatype(right->datatype));
                exit(0);
            }
        }
        else{
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
    }
    else if(strcmp(binary_expression->operator, "<<")==0){
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val << right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val << right->value->c_val;
            }
            else{
                printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
                printf("first type: %s\n", getDatatype(left->datatype));
                printf("second type: %s\n", getDatatype(right->datatype));
                exit(0);
            }
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val << right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val << right->value->c_val;
            }
            else{
                printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
                printf("first type: %s\n", getDatatype(left->datatype));
                printf("second type: %s\n", getDatatype(right->datatype));
                exit(0);
            }
        }
        else{
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
    }
    else if(strcmp(binary_expression->operator, "-")==0){
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==STRING || right->datatype==STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val - right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->i_val - right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->i_val - right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val - right->value->c_val;
            }
        }
        else if(left->datatype==FLOAT){
            if(right->datatype==INTEGER){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val - right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val - right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->f_val - right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val - right->value->c_val;
            }
        }
        else if(left->datatype==DOUBLE){
            if(right->datatype==INTEGER){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val - right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->d_val = left->value->d_val - right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val - right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val - right->value->c_val;
            }
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val - right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->c_val - right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->c_val - right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = CHARACTER;
                res->value->i_val = left->value->c_val - right->value->c_val;
            }
        }
    }
    else if(strcmp(binary_expression->operator, "+")==0){
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val + right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->i_val + right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->i_val + right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val + right->value->c_val;
            }
            else if(right->datatype==STRING){
                res->datatype = STRING;
                res->value->str_val = strcat(toString(left), right->value->str_val);
            }
        }
        else if(left->datatype==FLOAT){
            if(right->datatype==INTEGER){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val + right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val + right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->f_val + right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val + right->value->c_val;
            }
            else if(right->datatype==STRING){
                res->datatype = STRING;
                res->value->str_val = strcat(toString(left), right->value->str_val);
            }
        }
        else if(left->datatype==DOUBLE){
            if(right->datatype==INTEGER){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val + right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->d_val = left->value->d_val + right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val + right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val + right->value->c_val;
            }
            else if(right->datatype==STRING){
                res->datatype = STRING;
                res->value->str_val = strcat(toString(left), right->value->str_val);
            }
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val + right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->c_val + right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->c_val + right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = CHARACTER;
                res->value->i_val = left->value->c_val + right->value->c_val;
            }
            else if(right->datatype==STRING){
                res->datatype = STRING;
                res->value->str_val = strcat(toString(left), right->value->str_val);
            }
        }
        else if(left->datatype==STRING){
            res->datatype = STRING;
            if(right->datatype==INTEGER)
                res->value->str_val = strcat(left->value->str_val, toString(right));
            if(right->datatype==FLOAT)
                res->value->str_val = strcat(left->value->str_val, toString(right));
            else if(right->datatype==DOUBLE)
                res->value->str_val = strcat(left->value->str_val, toString(right));
            else if(right->datatype==CHARACTER)
                res->value->str_val = strcat(left->value->str_val, toString(right));
            else if(right->datatype==STRING)
                res->value->str_val = strcat(left->value->str_val, right->value->str_val);
        }
    }
    else if(strcmp(binary_expression->operator, "*")==0){
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==STRING || right->datatype==STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val * right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->i_val * right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->i_val * right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val * right->value->c_val;
            }
        }
        else if(left->datatype==FLOAT){
            if(right->datatype==INTEGER){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val * right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val * right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->f_val * right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val * right->value->c_val;
            }
        }
        else if(left->datatype==DOUBLE){
            if(right->datatype==INTEGER){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val * right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->d_val = left->value->d_val * right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val * right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val * right->value->c_val;
            }
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val * right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->c_val * right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->c_val * right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = CHARACTER;
                res->value->i_val = left->value->c_val * right->value->c_val;
            }
        }
    }
    else if(strcmp(binary_expression->operator, "/")==0){
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==STRING || right->datatype==STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val / right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->i_val / right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->i_val / right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val / right->value->c_val;
            }
        }
        else if(left->datatype==FLOAT){
            if(right->datatype==INTEGER){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val / right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val / right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->f_val / right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = FLOAT;
                res->value->f_val = left->value->f_val / right->value->c_val;
            }
        }
        else if(left->datatype==DOUBLE){
            if(right->datatype==INTEGER){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val / right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->d_val = left->value->d_val / right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val / right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->d_val / right->value->c_val;
            }
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val / right->value->i_val;
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = left->value->c_val / right->value->f_val;
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = left->value->c_val / right->value->d_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = CHARACTER;
                res->value->i_val = left->value->c_val / right->value->c_val;
            }
        }
    }
    else if(strcmp(binary_expression->operator, "%")==0){
        if(left->datatype==FLOAT || right->datatype==FLOAT){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==DOUBLE || right->datatype==DOUBLE){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==STRING || right->datatype==STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val % right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->i_val % right->value->c_val;
            }
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = left->value->c_val % right->value->i_val;
            }
            else if(right->datatype==CHARACTER){
                res->datatype = CHARACTER;
                res->value->i_val = left->value->c_val % right->value->c_val;
            }
        }
    }
    else if(strcmp(binary_expression->operator, "**")==0){
        if(left->datatype==BOOLEAN || right->datatype==BOOLEAN){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==STRING || right->datatype==STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, binary_expression->operator);
            printf("first type: %s\n", getDatatype(left->datatype));
            printf("second type: %s\n", getDatatype(right->datatype));
            exit(0);
        }
        if(left->datatype==INTEGER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = pow(left->value->i_val, right->value->i_val);
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = pow(left->value->i_val, right->value->f_val);
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = pow(left->value->i_val, right->value->d_val);
            }
            else if(right->datatype==CHARACTER){
                res->datatype = INTEGER;
                res->value->i_val = pow(left->value->i_val, right->value->c_val);
            }
        }
        else if(left->datatype==FLOAT){
            if(right->datatype==INTEGER){
                res->datatype = FLOAT;
                res->value->f_val = pow(left->value->f_val, right->value->i_val);
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = pow(left->value->f_val, right->value->f_val);
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = pow(left->value->f_val, right->value->d_val);
            }
            else if(right->datatype==CHARACTER){
                res->datatype = FLOAT;
                res->value->f_val = pow(left->value->f_val, right->value->c_val);
            }
        }
        else if(left->datatype==DOUBLE){
            if(right->datatype==INTEGER){
                res->datatype = DOUBLE;
                res->value->d_val = pow(left->value->d_val, right->value->i_val);
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->d_val = pow(left->value->d_val, right->value->f_val);
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = pow(left->value->d_val, right->value->d_val);
            }
            else if(right->datatype==CHARACTER){
                res->datatype = DOUBLE;
                res->value->d_val = pow(left->value->d_val, right->value->c_val);
            }
        }
        else if(left->datatype==CHARACTER){
            if(right->datatype==INTEGER){
                res->datatype = INTEGER;
                res->value->i_val = pow(left->value->c_val, right->value->i_val);
            }
            else if(right->datatype==FLOAT){
                res->datatype = FLOAT;
                res->value->f_val = pow(left->value->c_val, right->value->f_val);
            }
            else if(right->datatype==DOUBLE){
                res->datatype = DOUBLE;
                res->value->d_val = pow(left->value->c_val, right->value->d_val);
            }
            else if(right->datatype==CHARACTER){
                res->datatype = CHARACTER;
                res->value->i_val = pow(left->value->c_val, right->value->c_val);
            }
        }
    }
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = this_line;
    return res;
}

ValueNode* executeUnaryExpressionNode(UnaryExpression *unary_expression, int this_line){
    ValueNode *value_node = executeExpressionStatementNode(unary_expression->expression_statement, this_line);

    ValueNode *res = (ValueNode*) malloc(sizeof(ValueNode));
    res->value = (Value*) malloc(sizeof(Value));
    if(strcmp(unary_expression->operator, "+")==0){
        if(value_node->datatype == BOOLEAN || value_node->datatype == STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, unary_expression->operator);
            printf("first type: %s\n", getDatatype(value_node->datatype));
            printf("second type: %s\n", getDatatype(value_node->datatype));
            exit(0);
        }
        else
            res = cloneSymbol(value_node, this_line);
    }
    else if(strcmp(unary_expression->operator, "-")==0){
        if(value_node->datatype == BOOLEAN || value_node->datatype == STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, unary_expression->operator);
            printf("first type: %s\n", getDatatype(value_node->datatype));
            printf("second type: %s\n", getDatatype(value_node->datatype));
            exit(0);
        }
        else{
            res = cloneSymbol(value_node, this_line);
            switch(res->datatype){
                case INTEGER:
                    res->value->i_val = -1*res->value->i_val;
                    break;
                case FLOAT:
                    res->value->f_val = -1*res->value->f_val;
                    break;
                case DOUBLE:
                    res->value->d_val = -1*res->value->d_val;
                    break;
                case CHARACTER:
                    res->value->c_val = -1*res->value->c_val;
                    break;
            }
        }
    }
    else if(strcmp(unary_expression->operator, "++")==0){
        if(value_node->datatype == BOOLEAN || value_node->datatype == STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, unary_expression->operator);
            printf("first type: %s\n", getDatatype(value_node->datatype));
            printf("second type: %s\n", getDatatype(value_node->datatype));
            exit(0);
        }
        else{
            res = cloneSymbol(value_node, this_line);
            switch(res->datatype){
                case INTEGER:
                    res->value->i_val = res->value->i_val++;
                    break;
                case FLOAT:
                    res->value->f_val = res->value->f_val++;
                    break;
                case DOUBLE:
                    res->value->d_val = res->value->d_val++;
                    break;
                case CHARACTER:
                    res->value->c_val = res->value->c_val++;
                    break;
            }
        }
    }
    else if(strcmp(unary_expression->operator, "--")==0){
        if(value_node->datatype == BOOLEAN || value_node->datatype == STRING){
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, unary_expression->operator);
            printf("first type: %s\n", getDatatype(value_node->datatype));
            printf("second type: %s\n", getDatatype(value_node->datatype));
            exit(0);
        }
        else{
            res = cloneSymbol(value_node, this_line);
            switch(res->datatype){
                case INTEGER:
                    res->value->i_val = res->value->i_val--;
                    break;
                case FLOAT:
                    res->value->f_val = res->value->f_val--;
                    break;
                case DOUBLE:
                    res->value->d_val = res->value->d_val--;
                    break;
                case CHARACTER:
                    res->value->c_val = res->value->c_val--;
                    break;
            }
        }
    }
    else if(strcmp(unary_expression->operator, "!")==0){
        if(value_node->datatype==INTEGER || value_node->datatype==CHARACTER){
            res = cloneSymbol(value_node, this_line);
            int i = 1;
            switch(res->datatype){
                case INTEGER:
                    while(res->value->i_val)
                        i *= res->value->i_val--;
                    res->value->i_val = i;
                    break;
                case CHARACTER:
                    while(res->value->c_val)
                         i *= res->value->c_val--;
                    res->value->c_val = i;
                    break;
            }
        }
        else{
            printf("JvC: [error: %d]  bad operand types for binary operator %s\n", this_line, unary_expression->operator);
            printf("first type: %s\n", getDatatype(value_node->datatype));
            printf("second type: %s\n", getDatatype(value_node->datatype));
            exit(0);
        }
    }
    res->location = (Location*) malloc(sizeof(Location));
    res->location->line = this_line;
    return res;
}

ValueNode* executeTernaryExpressionNode(TernaryExpression *ternary_expression, int this_line){
    ValueNode *test = executeExpressionStatementNode(ternary_expression->test, this_line);
    ValueNode *consequent = executeExpressionStatementNode(ternary_expression->consequent, this_line);
    ValueNode *alternate = executeExpressionStatementNode(ternary_expression->alternate, this_line);

    ValueNode *res = (ValueNode*) malloc(sizeof(ValueNode));
    res->value = (Value*) malloc(sizeof(Value));
    if(test->datatype==BOOLEAN){
        if(test->value->b_val!='0')
            res = cloneSymbol(consequent, this_line);
        else
            res = cloneSymbol(alternate, this_line);
    }
    else{
        printf("JvC: [error: %d] incompatible types: %s cannot be converted to %s\n", getDatatype(test->datatype), "boolean");
        exit(0);
    }
    return res;
}

ValueNode* executeExpressionStatementNode(ExpressionStatement *expression_statement, int this_line){
    ValueNode *res = (ValueNode*) malloc(sizeof(ValueNode));
    switch(expression_statement->type){
        case IDENTIFIER:
            res = findSymbol(expression_statement->expression_type->identifier, this_line);
            if(res==NULL){
                printf("JvC: [error: %d] cannot find symbol %s\n", this_line, expression_statement->expression_type->identifier);
                exit(0);
            }
            res = cloneSymbol(res, this_line);
            break;
        case NUMERIC:
            res = executeValueNode(expression_statement->expression_type->value_node);
            break;
        case BINARYEXP:
            res = executeBinaryExpressionNode(expression_statement->expression_type->binary_expression, this_line);
            break;
        case UNARYEXP:
            res = executeUnaryExpressionNode(expression_statement->expression_type->unary_expression, this_line);
            break;
        case TERNARYEXP:
            res = executeTernaryExpressionNode(expression_statement->expression_type->ternary_expression, this_line);
            break;
    }
    return res;
}

void insertInSymbolTable(char *identifier, ExpressionStatement *init, int datatype, int this_line){
    SymbolTable *new_node = (SymbolTable*) malloc(sizeof(SymbolTable));
    new_node->identifier = identifier;

    if(init==NULL){
        ValueNode *default_init = (ValueNode*) malloc(sizeof(ValueNode));
        default_init->datatype = datatype;
        default_init->scope = scope;

        default_init->location = (Location*) malloc(sizeof(Location));
        default_init->location->line = this_line;

        default_init->value = (Value*) malloc(sizeof(Value));
        switch(datatype){
            case INTEGER:
                default_init->value->i_val = 0;
                break;
            case FLOAT:
                default_init->value->f_val = 0;
                break;
            case DOUBLE:
                default_init->value->d_val = 0;
                break;
            case CHARACTER:
                default_init->value->c_val = 0;
                break;
            case BOOLEAN:
                default_init->value->b_val = '0';
                break;
            case STRING:
                default_init->value->i_val = NULL;
                break;
        }
        new_node->value_node = default_init;
    }
    else{
        ValueNode *value_node = executeExpressionStatementNode(init, this_line);
        new_node->value_node = changeValueNode(value_node, datatype);
    }
    new_node->value_node->scope = scope;
    if(first_symbol==NULL){
        first_symbol = new_node;
        first_symbol->next = NULL;
    }
    else{
        SymbolTable *ptr = first_symbol;
        while(ptr->next!=NULL) {
          if(strcmp(ptr->identifier, new_node->identifier) == 0) {
            printf("JvC: [error: %d] variable %s is already defined\n", line, new_node->identifier);
            exit(0);
            return;
          }
          ptr = ptr->next;
        }
        
        if(strcmp(ptr->identifier, new_node->identifier) == 0){
          printf("JvC: [error: %d] variable %s is already defined\n", line, new_node->identifier);
          exit(0);
          return NULL;
        }

        ptr->next = new_node;
        new_node->next = NULL;
    }
}