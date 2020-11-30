// CONSTANTS FOR DATATYPE
#define INTEGER 1
#define FLOAT 2
#define DOUBLE 3
#define CHARACTER 4
#define BOOLEAN 5
#define STRING 6

int line = 0;

typedef char* string;
typedef char boolean;

typedef union Value{
    int i_val;
    float f_val;
    double d_val;
    char c_val;
    boolean b_val;
    string str_val;
};

struct DatatypeAndValue{
    int datatype;
    union Value *value;
};

struct SymbolTable{
    char *var_name;
    struct DatatypeAndValue *datatype_and_value;
    struct SymbolTable *next;
}*origin_of_symbols;

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

char* toString(struct DatatypeAndValue *datatype_and_value){
    char *str_val;
    int size;
    switch(datatype_and_value->datatype){
        case INTEGER:
            size = snprintf(NULL, 0, "%d", datatype_and_value->value->i_val);
            str_val = malloc(size + 1);
            snprintf(str_val, size+1, "%d", datatype_and_value->value->i_val);
            break;
        case FLOAT:
            size = snprintf(NULL, 0, "%f", datatype_and_value->value->f_val);
            str_val = malloc(size + 1);
            snprintf(str_val, size+1, "%f", datatype_and_value->value->f_val);
            break;
        case DOUBLE:
            size = snprintf(NULL, 0, "%d", datatype_and_value->value->d_val);
            str_val = malloc(size + 1);
            snprintf(str_val, size+1, "%d", datatype_and_value->value->d_val);
            break;
        case CHARACTER:
            size = snprintf(NULL, 0, "%c", datatype_and_value->value->c_val);
            str_val = malloc(size + 1);
            snprintf(str_val, size+1, "%c", datatype_and_value->value->c_val);
            break;
        case BOOLEAN:
            size = snprintf(NULL, 0, "%c", datatype_and_value->value->c_val);
            str_val = malloc(size + 1);
            snprintf(str_val, size+1, "%c", datatype_and_value->value->c_val);
            break;
    }
    return str_val;
}

void changeUnionValue(struct DatatypeAndValue *new_node, struct DatatypeAndValue *new_symbol){
    int to_datatype = new_node->datatype;
    int from_datatype = new_symbol->datatype;
    if(to_datatype == INTEGER){
        if(from_datatype == INTEGER) new_node->value->i_val = new_symbol->value->i_val;
        else if(from_datatype == FLOAT) new_node->value->i_val = (int)new_symbol->value->f_val;
        else if(from_datatype == DOUBLE) new_node->value->i_val = (int)new_symbol->value->i_val;
        else if(from_datatype == CHARACTER) new_node->value->i_val = new_symbol->value->c_val;
        else if(from_datatype == BOOLEAN) {
            if(new_symbol->value->b_val=='1')
                new_node->value->i_val = 1;
            else
                new_node->value->i_val = 0;
        }
        else if(from_datatype == STRING) printf("[error: %d] fail type conversion string to int\n", line+1);
    }

    else if(to_datatype == FLOAT){
        if(from_datatype == INTEGER) new_node->value->f_val = new_symbol->value->i_val;
        else if(from_datatype == FLOAT) new_node->value->f_val = new_symbol->value->f_val;
        else if(from_datatype == DOUBLE) new_node->value->f_val = (float)new_symbol->value->d_val;
        else if(from_datatype == CHARACTER) new_node->value->f_val = (float)new_symbol->value->c_val;
        else if(from_datatype == BOOLEAN) new_node->value->f_val = (float)new_symbol->value->b_val;
        else if(from_datatype == STRING) printf("[error: %d] fail type conversion string to float\n", line+1);
    }

    else if(to_datatype == DOUBLE){
        if(from_datatype == INTEGER) new_node->value->d_val = new_symbol->value->i_val;
        else if(from_datatype == FLOAT) new_node->value->d_val = new_symbol->value->f_val;
        else if(from_datatype == DOUBLE) new_node->value->d_val = new_symbol->value->d_val;
        else if(from_datatype == CHARACTER) new_node->value->d_val = (double)new_symbol->value->c_val;
        else if(from_datatype == BOOLEAN) new_node->value->d_val = (double)new_symbol->value->b_val;
        else if(from_datatype == STRING) printf("[error: %d] fail type conversion string to double\n", line+1);
    }

    else if(to_datatype == CHARACTER){
        if(from_datatype == INTEGER)new_node->value->c_val = new_symbol->value->i_val;
        else if(from_datatype == FLOAT) printf("[error: %d] fail type conversion float to char\n", line+1);
        else if(from_datatype == DOUBLE) printf("[error: %d] fail type conversion double to char\n", line+1);
        else if(from_datatype == CHARACTER) new_node->value->c_val = new_symbol->value->c_val;
        else if(from_datatype == BOOLEAN) new_node->value->c_val = new_symbol->value->c_val;
        else if(from_datatype == STRING) printf("[error: %d] fail type conversion string to char\n", line+1);
    }

    else if(to_datatype == BOOLEAN){
        if(from_datatype == INTEGER) printf("[error: %d] fail type conversion int to boolean\n", line+1);
        else if(from_datatype == FLOAT) printf("[error: %d] fail type conversion float to boolean\n", line+1);
        else if(from_datatype == DOUBLE) printf("[error: %d] fail type conversion double to boolean\n", line+1);
        else if(from_datatype == CHARACTER) printf("[error: %d] fail type conversion char to boolean\n", line+1);
        else if(from_datatype == BOOLEAN) new_node->value->b_val = new_symbol->value->b_val;
        else if(from_datatype == STRING) printf("[error: %d] fail type conversion string to boolean\n", line+1);
    }
    
    else if(to_datatype == STRING){
        if(from_datatype == INTEGER) new_node->value->str_val = toString(new_symbol);
        else if(from_datatype == FLOAT) new_node->value->str_val = toString(new_symbol);
        else if(from_datatype == DOUBLE) new_node->value->str_val = toString(new_symbol);
        else if(from_datatype == CHARACTER) new_node->value->str_val = toString(new_symbol);
        else if(from_datatype == BOOLEAN) new_node->value->str_val = toString(new_symbol);
        else if(from_datatype == STRING) new_node->value->str_val = strdup(new_symbol->value->str_val);
    }
}

struct SymbolTable* insertInSymbolTable(int datatype, struct SymbolTable *new_symbol){
    struct SymbolTable *new_node = (struct SymbolTable*) malloc(sizeof(struct SymbolTable));
    new_node->var_name = new_symbol->var_name;

    new_node->datatype_and_value = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue)); 
    new_node->datatype_and_value->datatype = datatype;

    new_node->datatype_and_value->value = (union Value*) malloc(sizeof(union Value));
    
    if(new_symbol->datatype_and_value==NULL){
        switch(new_node->datatype_and_value->datatype){
            case INTEGER:
                new_node->datatype_and_value->value->i_val = 0;
                break;
            case FLOAT:
                new_node->datatype_and_value->value->f_val = 0;
                break;
            case DOUBLE:
                new_node->datatype_and_value->value->d_val = 0;
                break;
            case CHARACTER:
                new_node->datatype_and_value->value->c_val = 0;
                break;
            case BOOLEAN:
                new_node->datatype_and_value->value->b_val = '0';
                break;
            case STRING:
                new_node->datatype_and_value->value->str_val = NULL;
                break;
        }
    }
    else
        changeUnionValue(new_node->datatype_and_value, new_symbol->datatype_and_value);

    if(origin_of_symbols==NULL){
        origin_of_symbols = new_node;
        origin_of_symbols->next = NULL;
    }
    else{
        struct SymbolTable *ptr = origin_of_symbols;
        while(ptr->next!=NULL) {
          if(strcmp(ptr->var_name, new_symbol->var_name) == 0) {
            // printf("Re-Declaration of variable : %s\n", new_symbol->var_name);
            return NULL;
          }
          ptr = ptr->next;
        }
        
        if(strcmp(ptr->var_name, new_symbol->var_name) == 0){
          // printf("Re-Declaration of variable : %s\n", new_symbol->var_name);
          return NULL;
        }

        ptr->next = new_node;
        new_node->next = NULL;
    }
    return new_node;    
}

struct SymbolTable* insertAll(int datatype, struct SymbolTable *new_symbols){
    struct SymbolTable *res = NULL;
    while(new_symbols!=NULL){
        res = insertInSymbolTable(datatype, new_symbols);
        new_symbols = new_symbols->next;
    }
    return res;
}

struct SymbolTable* makeSymbolNodeWithoutDatatype(char *var_name, struct DatatypeAndValue *datatype_and_value){
    struct SymbolTable *new_node = (struct SymbolTable*) malloc(sizeof(struct SymbolTable));
    new_node->var_name = strdup(var_name);
    new_node->datatype_and_value = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    new_node->datatype_and_value = datatype_and_value;
    new_node->next = NULL;
    return new_node;
}

struct DatatypeAndValue* makeDatatypeAndValue(int datatype, union Value *input_val){
    struct DatatypeAndValue *value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    value_node->value = (union Value*) malloc(sizeof(union Value)); 
    value_node->datatype = datatype;
    switch(datatype){
        case INTEGER:
            value_node->value->i_val = input_val->i_val;
            break;
        case FLOAT:
            value_node->value->f_val = input_val->f_val;
            break;
        case DOUBLE:
            value_node->value->d_val = input_val->d_val;
            break;
        case CHARACTER:
            value_node->value->c_val = input_val->c_val;
            break;
        case BOOLEAN:
            value_node->value->b_val = input_val->b_val;
            break;
        case STRING:
            value_node->value->str_val = strdup(input_val->str_val);
            break;
    }
    return value_node;
}

struct DatatypeAndValue* ternary(struct DatatypeAndValue *condition, struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(condition->value->b_val == '1')  {
        datatype_and_value_node->datatype = first_operand;
        switch(first_operand){
            case INTEGER:
                datatype_and_value_node->value->i_val = input_val1->value->i_val;
                break;
            case FLOAT:
                datatype_and_value_node->value->f_val = input_val1->value->f_val;
                break;
            case DOUBLE:
                datatype_and_value_node->value->d_val = input_val1->value->d_val;
                break;
            case CHARACTER:
                datatype_and_value_node->value->c_val = input_val1->value->c_val;
                break;
            case BOOLEAN:
                datatype_and_value_node->value->b_val = input_val1->value->b_val;
                break;
            case STRING:
                datatype_and_value_node->value->str_val = input_val1->value->str_val;
                break;
        }
    }
    else{
        datatype_and_value_node->datatype = second_operand;
        switch(first_operand){
            case INTEGER:
                datatype_and_value_node->value->i_val = input_val2->value->i_val;
                break;
            case FLOAT:
                datatype_and_value_node->value->f_val = input_val2->value->f_val;
                break;
            case DOUBLE:
                datatype_and_value_node->value->d_val = input_val2->value->d_val;
                break;
            case CHARACTER:
                datatype_and_value_node->value->c_val = input_val2->value->c_val;
                break;
            case BOOLEAN:
                datatype_and_value_node->value->b_val = input_val2->value->b_val;
                break;
            case STRING:
                datatype_and_value_node->value->str_val = input_val2->value->str_val;
                break;
        }
    }

    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryAddition(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==BOOLEAN || second_operand==BOOLEAN){
        printf("[error: %d]  bad operand types for binary operator '+'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }
    
    else if(first_operand==INTEGER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->i_val + input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->i_val+input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->i_val+input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->i_val+input_val2->value->c_val;
        }
        else if(second_operand==STRING){
            datatype_and_value_node->datatype = STRING;
            input_val1->value->str_val = toString(input_val1);
            datatype_and_value_node->value->str_val = strcat(input_val1->value->str_val, input_val2->value->i_val);
        }
    }

    else if(first_operand==FLOAT){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val + input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val+input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->f_val+input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val+input_val2->value->c_val;
        }
        else if(second_operand==STRING){
            datatype_and_value_node->datatype = STRING;
            input_val1->value->str_val = toString(input_val1);
            datatype_and_value_node->value->str_val = strcat(input_val1->value->str_val, input_val2->value->str_val);
        }
    }

    else if(first_operand==DOUBLE){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val + input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->d_val = input_val1->value->d_val+input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val+input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val+input_val2->value->c_val;
        }
        else if(second_operand==STRING){
            datatype_and_value_node->datatype = STRING;
            input_val1->value->str_val = toString(input_val1);
            datatype_and_value_node->value->str_val = strcat(input_val1->value->str_val, input_val2->value->str_val);
        }
    }

    else if(first_operand==CHARACTER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->c_val + input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->c_val+input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->c_val+input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->c_val+input_val2->value->c_val;
        }
        else if(second_operand==STRING){
            datatype_and_value_node->datatype = STRING;
            input_val1->value->str_val = toString(input_val1);
            datatype_and_value_node->value->str_val = strcat(input_val1->value->str_val, input_val2->value->str_val);
        }
    }


    else if(first_operand==STRING){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = STRING;
            input_val1->value->str_val = toString(input_val2);
            datatype_and_value_node->value->str_val = strcat(input_val1->value->str_val, input_val2->value->str_val);
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = STRING;
            input_val1->value->str_val = toString(input_val2);
            datatype_and_value_node->value->str_val = strcat(input_val1->value->str_val, input_val2->value->str_val);
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = STRING;
            input_val1->value->str_val = toString(input_val2);
            datatype_and_value_node->value->str_val = strcat(input_val1->value->str_val, input_val2->value->str_val);
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = STRING;
            input_val1->value->str_val = toString(input_val2);
            datatype_and_value_node->value->str_val = strcat(input_val1->value->str_val, input_val2->value->str_val);
        }
        else if(second_operand==STRING){
            datatype_and_value_node->datatype = STRING;
            datatype_and_value_node->value->str_val = strcat(input_val1->value->str_val, input_val2->value->str_val);
        }
    }        

    return datatype_and_value_node;
}

struct DatatypeAndValue* binarySubtraction(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==BOOLEAN || second_operand==BOOLEAN || first_operand==STRING || second_operand==STRING){
        printf("[error: %d]  bad operand types for binary operator '-'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }

    else if(first_operand==INTEGER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->i_val - input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->i_val - input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->i_val - input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->i_val - input_val2->value->c_val;
        }
    }

    else if(first_operand==FLOAT){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val - input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val - input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->f_val - input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val - input_val2->value->c_val;
        }
    }

    else if(first_operand==DOUBLE){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val - input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->d_val = input_val1->value->d_val - input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val - input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val - input_val2->value->c_val;
        }
    }

    else if(first_operand==CHARACTER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->c_val - input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->c_val - input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->c_val - input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->c_val - input_val2->value->c_val;
        }
    }
    
    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryMultiplication(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==BOOLEAN || second_operand==BOOLEAN || first_operand==STRING || second_operand==STRING){
        printf("[error: %d]  bad operand types for binary operator '*'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }

    else if(first_operand==INTEGER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->i_val * input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->i_val * input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->i_val * input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->i_val * input_val2->value->c_val;
        }
    }

    else if(first_operand==FLOAT){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val * input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val * input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->f_val * input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val * input_val2->value->c_val;
        }
    }

    else if(first_operand==DOUBLE){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val * input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->d_val = input_val1->value->d_val * input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val * input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val * input_val2->value->c_val;
        }
    }

    else if(first_operand==CHARACTER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->c_val * input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->c_val * input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->c_val * input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->c_val * input_val2->value->c_val;
        }
    }
    
    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryDivision(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==BOOLEAN || second_operand==BOOLEAN || first_operand==STRING || second_operand==STRING){
        printf("[error: %d]  bad operand types for binary operator '*'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }

    else if(first_operand==INTEGER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->i_val / input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->i_val / input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->i_val / input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->i_val / input_val2->value->c_val;
        }
    }

    else if(first_operand==FLOAT){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val / input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val / input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->f_val / input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->f_val / input_val2->value->c_val;
        }
    }

    else if(first_operand==DOUBLE){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val / input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->d_val = input_val1->value->d_val / input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val / input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->d_val / input_val2->value->c_val;
        }
    }

    else if(first_operand==CHARACTER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->c_val / input_val2->value->i_val;
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = input_val1->value->c_val / input_val2->value->f_val;
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = input_val1->value->c_val / input_val2->value->d_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->c_val / input_val2->value->c_val;
        }
    }
    
    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryModulo(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==INTEGER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->i_val % input_val2->value->i_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->i_val % input_val2->value->c_val;
        }
    }

    else if(first_operand==CHARACTER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->c_val % input_val2->value->i_val;
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = input_val1->value->c_val % input_val2->value->c_val;
        }
    }

    else{
        printf("[error: %d]  bad operand types for binary operator '%'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }

    
    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryPower(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==BOOLEAN || second_operand==BOOLEAN || first_operand==STRING || second_operand==STRING){
        printf("[error: %d]  bad operand types for binary operator '*'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }

    else if(first_operand==INTEGER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = pow(input_val1->value->i_val, input_val2->value->i_val);
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = pow(input_val1->value->i_val, input_val2->value->f_val);
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = pow(input_val1->value->i_val, input_val2->value->d_val);
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = (int)pow(input_val1->value->i_val, input_val2->value->c_val);
        }
    }

    else if(first_operand==FLOAT){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = pow(input_val1->value->f_val, input_val2->value->i_val);
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = pow(input_val1->value->f_val, input_val2->value->f_val);
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = pow(input_val1->value->f_val, input_val2->value->d_val);
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = pow(input_val1->value->f_val, input_val2->value->c_val);
        }
    }

    else if(first_operand==DOUBLE){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = pow(input_val1->value->d_val, input_val2->value->i_val);
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->d_val = pow(input_val1->value->d_val, input_val2->value->f_val);
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = pow(input_val1->value->d_val, input_val2->value->d_val);
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = pow(input_val1->value->d_val, input_val2->value->c_val);
        }
    }

    else if(first_operand==CHARACTER){
        if(second_operand==INTEGER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = (int)pow(input_val1->value->c_val, input_val2->value->i_val);
        }
        else if(second_operand==FLOAT){
            datatype_and_value_node->datatype = FLOAT;
            datatype_and_value_node->value->f_val = pow(input_val1->value->c_val, input_val2->value->f_val);
        }
        else if(second_operand==DOUBLE){
            datatype_and_value_node->datatype = DOUBLE;
            datatype_and_value_node->value->d_val = pow(input_val1->value->c_val, input_val2->value->d_val);
        }
        else if(second_operand==CHARACTER){
            datatype_and_value_node->datatype = INTEGER;
            datatype_and_value_node->value->i_val = (int)pow(input_val1->value->c_val, input_val2->value->c_val);
        }
    }
    
    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryRightShift(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==INTEGER && second_operand==INTEGER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->i_val >> input_val2->value->i_val;
        return datatype_and_value_node;
    }
    else{
        printf("[error: %d]  bad operand types for binary operator '>>'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }
    return input_val1;
}

struct DatatypeAndValue* binaryLeftShift(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==INTEGER && second_operand==INTEGER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->i_val << input_val2->value->i_val;
        return datatype_and_value_node;
    }
    else{
        printf("[error: %d]  bad operand types for binary operator '<<'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }
    return input_val1;
}

struct DatatypeAndValue* binaryEquals(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;
    datatype_and_value_node->datatype = BOOLEAN;

    if(first_operand == second_operand){
        switch(first_operand){
            case INTEGER:
                if(input_val1->value->i_val == input_val2->value->i_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case FLOAT:
                if(input_val1->value->f_val == input_val2->value->f_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case DOUBLE:
                if(input_val1->value->d_val == input_val2->value->d_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case CHARACTER:
                if(input_val1->value->c_val == input_val2->value->c_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case BOOLEAN:
                if(input_val1->value->b_val == input_val2->value->b_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case STRING:
                // compares pointer not  value
                if(input_val1->value->str_val == input_val2->value->str_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
        }
    }
    else
        printf("[error: %d] datatypes of binary operator '==' mismatch\n", line);
    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryNotEquals(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;
    datatype_and_value_node->datatype = BOOLEAN;

    if(first_operand == second_operand){
        switch(first_operand){
            case INTEGER:
                if(input_val1->value->i_val != input_val2->value->i_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case FLOAT:
                if(input_val1->value->f_val != input_val2->value->f_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case DOUBLE:
                if(input_val1->value->d_val != input_val2->value->d_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case CHARACTER:
                if(input_val1->value->c_val != input_val2->value->c_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case BOOLEAN:
                if(input_val1->value->b_val != input_val2->value->b_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case STRING:
                if(input_val1->value->str_val != input_val2->value->str_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
        }
    }
    else
        printf("[error: %d] datatypes of binary operator '!=' mismatch\n", line);
    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryLessThan(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;
    datatype_and_value_node->datatype = BOOLEAN;

    if(first_operand == second_operand){
        switch(first_operand){
            case INTEGER:
                if(input_val1->value->i_val < input_val2->value->i_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case FLOAT:
                if(input_val1->value->f_val < input_val2->value->f_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case DOUBLE:
                if(input_val1->value->d_val < input_val2->value->d_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case CHARACTER:
                if(input_val1->value->c_val < input_val2->value->c_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case BOOLEAN:
                if(input_val1->value->b_val < input_val2->value->b_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case STRING:
                printf("[error: %d]  bad operand types for binary operator '%'\n", line);
                printf("first type: %s\n", getDatatype(first_operand));
                printf("second type: %s\n", getDatatype(second_operand));
                break;
        }
    }
    else
        printf("[error: %d] datatypes of binary operator '<' mismatch\n", line);
    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryLessEqual(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;
    datatype_and_value_node->datatype = BOOLEAN;

    if(first_operand == second_operand){
        switch(first_operand){
            case INTEGER:
                if(input_val1->value->i_val <= input_val2->value->i_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case FLOAT:
                if(input_val1->value->f_val <= input_val2->value->f_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case DOUBLE:
                if(input_val1->value->d_val <= input_val2->value->d_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case CHARACTER:
                if(input_val1->value->c_val <= input_val2->value->c_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case BOOLEAN:
                if(input_val1->value->b_val <= input_val2->value->b_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case STRING:
                printf("[error: %d]  bad operand types for binary operator '%'\n", line);
                printf("first type: %s\n", getDatatype(first_operand));
                printf("second type: %s\n", getDatatype(second_operand));
                break;
        }
    }
    else
        printf("[error: %d] datatypes of binary operator '<=' mismatch\n", line);
    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryGreaterThan(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;
    datatype_and_value_node->datatype = BOOLEAN;

    if(first_operand == second_operand){
        switch(first_operand){
            case INTEGER:
                if(input_val1->value->i_val > input_val2->value->i_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case FLOAT:
                if(input_val1->value->f_val > input_val2->value->f_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case DOUBLE:
                if(input_val1->value->d_val > input_val2->value->d_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case CHARACTER:
                if(input_val1->value->c_val > input_val2->value->c_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case BOOLEAN:
                if(input_val1->value->b_val > input_val2->value->b_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case STRING:
                printf("[error: %d]  bad operand types for binary operator '%'\n", line);
                printf("first type: %s\n", getDatatype(first_operand));
                printf("second type: %s\n", getDatatype(second_operand));
                break;
        }
    }
    else
        printf("[error: %d] datatypes of binary operator '>' mismatch\n", line);
    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryGreaterEqual(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;
    datatype_and_value_node->datatype = BOOLEAN;

    if(first_operand == second_operand){
        switch(first_operand){
            case INTEGER:
                if(input_val1->value->i_val >= input_val2->value->i_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case FLOAT:
                if(input_val1->value->f_val >= input_val2->value->f_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case DOUBLE:
                if(input_val1->value->d_val >= input_val2->value->d_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case CHARACTER:
                if(input_val1->value->c_val >= input_val2->value->c_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case BOOLEAN:
                if(input_val1->value->b_val >= input_val2->value->b_val)
                    datatype_and_value_node->value->b_val = '1';
                else
                    datatype_and_value_node->value->b_val = '0';
                break;
            case STRING:
                printf("[error: %d]  bad operand types for binary operator '%'\n", line);
                printf("first type: %s\n", getDatatype(first_operand));
                printf("second type: %s\n", getDatatype(second_operand));
                break;
        }
    }
    else
        printf("[error: %d] datatypes of binary operator '>=' mismatch\n", line);
    return datatype_and_value_node;
}

struct DatatypeAndValue* binaryOR(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==INTEGER && second_operand==INTEGER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->i_val | input_val2->value->i_val;
        return datatype_and_value_node;
    }
    else if(first_operand==INTEGER && second_operand==CHARACTER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->i_val | input_val2->value->c_val;
        return datatype_and_value_node;
    }
    else if(first_operand==CHARACTER && second_operand==INTEGER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->c_val | input_val2->value->i_val;
        return datatype_and_value_node;
    }
    else if(first_operand==CHARACTER && second_operand==CHARACTER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->c_val | input_val2->value->i_val;
        return datatype_and_value_node;
    }
    else{
        printf("[error: %d]  bad operand types for binary operator '|'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }
    return input_val1;
}

struct DatatypeAndValue* binaryXOR(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==INTEGER && second_operand==INTEGER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->i_val ^ input_val2->value->i_val;
        return datatype_and_value_node;
    }
    else if(first_operand==INTEGER && second_operand==CHARACTER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->i_val ^ input_val2->value->c_val;
        return datatype_and_value_node;
    }
    else if(first_operand==CHARACTER && second_operand==INTEGER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->c_val ^ input_val2->value->i_val;
        return datatype_and_value_node;
    }
    else if(first_operand==CHARACTER && second_operand==CHARACTER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->c_val ^ input_val2->value->i_val;
        return datatype_and_value_node;
    }
    else{
        printf("[error: %d]  bad operand types for binary operator '^'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }
    return input_val1;
}

struct DatatypeAndValue* binaryAND(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==INTEGER && second_operand==INTEGER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->i_val & input_val2->value->i_val;
        return datatype_and_value_node;
    }
    else if(first_operand==INTEGER && second_operand==CHARACTER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->i_val & input_val2->value->c_val;
        return datatype_and_value_node;
    }
    else if(first_operand==CHARACTER && second_operand==INTEGER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->c_val & input_val2->value->i_val;
        return datatype_and_value_node;
    }
    else if(first_operand==CHARACTER && second_operand==CHARACTER){
        datatype_and_value_node->datatype = INTEGER;
        datatype_and_value_node->value->i_val = input_val1->value->c_val & input_val2->value->i_val;
        return datatype_and_value_node;
    }
    else{
        printf("[error: %d]  bad operand types for binary operator '&'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }
    return input_val1;
}

struct DatatypeAndValue* logicalOR(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==BOOLEAN && second_operand==BOOLEAN){
        datatype_and_value_node->datatype = BOOLEAN;
        char first_value = input_val1->value->b_val, second_value = input_val2->value->b_val;
        if(first_value=='1' || second_value=='1')
            datatype_and_value_node->value->b_val = '1';
        else
            datatype_and_value_node->value->b_val = '0';
        return datatype_and_value_node;
    }
    else{
        printf("[error: %d]  bad operand types for binary operator '||'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }
    return input_val1;
}

struct DatatypeAndValue* logicalAND(struct DatatypeAndValue *input_val1, struct DatatypeAndValue *input_val2){
    struct DatatypeAndValue *datatype_and_value_node = (struct DatatypeAndValue*) malloc(sizeof(struct DatatypeAndValue));
    datatype_and_value_node->value = (union Value*) malloc(sizeof(union Value)); 
    int first_operand = input_val1->datatype, second_operand = input_val2->datatype;

    if(first_operand==BOOLEAN && second_operand==BOOLEAN){
        datatype_and_value_node->datatype = BOOLEAN;
        char first_value = input_val1->value->b_val, second_value = input_val2->value->b_val;
        if(first_value=='0' || second_value=='0')
            datatype_and_value_node->value->b_val = '0';
        else
            datatype_and_value_node->value->b_val = '1';
        return datatype_and_value_node;
    }
    else{
        printf("[error: %d]  bad operand types for binary operator '&&'\n", line);
        printf("first type: %s\n", getDatatype(first_operand));
        printf("second type: %s\n", getDatatype(second_operand));
    }
    return input_val1;
}

struct DatatypeAndValue* unaryIncrement(struct DatatypeAndValue *input_val){
    switch(input_val->datatype){
        case INTEGER:
            input_val->value->i_val++;
            break;
        case FLOAT:
            input_val->value->f_val++;
            break;
        case DOUBLE:
            input_val->value->d_val++;
            break;
        case CHARACTER:
            input_val->value->i_val = input_val->value->c_val+1;
            break;
        default:
            printf("[error: %d] bad operand type %s for unary operator '++'\n", line, getDatatype(input_val->datatype));
    }
    return input_val; 
}

struct DatatypeAndValue* unaryDecrement(struct DatatypeAndValue *input_val){
    switch(input_val->datatype){
        case INTEGER:
            input_val->value->i_val--;
            break;
        case FLOAT:
            input_val->value->f_val--;
            break;
        case DOUBLE:
            input_val->value->d_val--;
            break;
        case CHARACTER:
            input_val->value->i_val = input_val->value->c_val-1;
            break;
        default:
            printf("[error: %d] bad operand type %s for unary operator '--'\n", line, getDatatype(input_val->datatype));
    }
    return input_val; 
}

struct DatatypeAndValue* unaryNegation(struct DatatypeAndValue *input_val){
    switch(input_val->datatype){
        case INTEGER:
            input_val->value->i_val = -input_val->value->i_val;
            break;
        case FLOAT:
            input_val->value->f_val = -input_val->value->f_val;
            break;
        case DOUBLE:
            input_val->value->d_val = -input_val->value->d_val;
            break;
        case CHARACTER:
            input_val->value->i_val = -input_val->value->c_val;
            break;
        default:
            printf("[error: %d] bad operand type %s for unary operator '-'\n", line, getDatatype(input_val->datatype));
    }
    return input_val; 
}

struct DatatypeAndValue* unaryFactorial(struct DatatypeAndValue *input_val){
    if(input_val->datatype == INTEGER){
        int n = input_val->value->i_val;
        while(n-- > 1)
            input_val->value->i_val *= n;
    }
    else 
        printf("[error: %d] bad operand type %s for unary operator '**'\n", line, getDatatype(input_val->datatype));
    return input_val; 
}

struct SymbolTable* getSymbol(char *var_name){
    struct SymbolTable *ptr = (struct SymbolTable*) malloc(sizeof(struct SymbolTable));
    ptr = origin_of_symbols;
    while(ptr!=NULL){
        if(strcmp(ptr->var_name, var_name) == 0) 
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void unaryIncrementOfID(char *var_name){
    struct SymbolTable *required_symbol_node = getSymbol(var_name);
    if(required_symbol_node==NULL)
        printf("[error: %d] '%s' not found\n", line, var_name);
    else
        unaryIncrement(required_symbol_node->datatype_and_value);
}

void unaryDecrementOfID(char *var_name){
    struct SymbolTable *required_symbol_node = getSymbol(var_name);
    if(required_symbol_node==NULL)
        printf("[error: %d] '%s' not found\n", line, var_name);
    else
        unaryDecrement(required_symbol_node->datatype_and_value);
}

void assignNewValue(char *var_name, struct DatatypeAndValue *new_datatype_and_value_node){
    struct SymbolTable *required_symbol_node = getSymbol(var_name);

    if(required_symbol_node==NULL)
        printf("[error: %d] '%s' not found\n", line, var_name);
    else
        changeUnionValue(required_symbol_node->datatype_and_value, new_datatype_and_value_node);
}

void assignPlusEqual(char *var_name, struct DatatypeAndValue *new_datatype_and_value_node){
    struct SymbolTable *required_symbol_node = getSymbol(var_name);

    if(required_symbol_node==NULL)
        printf("[error: %d] '%s' not found\n", line, var_name);
    else
        required_symbol_node->datatype_and_value = binaryAddition(required_symbol_node->datatype_and_value, new_datatype_and_value_node);
}

void assignMinusEqual(char *var_name, struct DatatypeAndValue *new_datatype_and_value_node){
    struct SymbolTable *required_symbol_node = getSymbol(var_name);

    if(required_symbol_node==NULL)
        printf("[error: %d] '%s' not found\n", line, var_name);
    else
        required_symbol_node->datatype_and_value = binarySubtraction(required_symbol_node->datatype_and_value, new_datatype_and_value_node);
}

void assignMultiplicationEqual(char *var_name, struct DatatypeAndValue *new_datatype_and_value_node){
    struct SymbolTable *required_symbol_node = getSymbol(var_name);

    if(required_symbol_node==NULL)
        printf("[error: %d] '%s' not found\n", line, var_name);
    else
        required_symbol_node->datatype_and_value = binaryMultiplication(required_symbol_node->datatype_and_value, new_datatype_and_value_node);
}

void assignDivisionEqual(char *var_name, struct DatatypeAndValue *new_datatype_and_value_node){
    struct SymbolTable *required_symbol_node = getSymbol(var_name);

    if(required_symbol_node==NULL)
        printf("[error: %d] '%s' not found\n", line, var_name);
    else
        required_symbol_node->datatype_and_value = binaryDivision(required_symbol_node->datatype_and_value, new_datatype_and_value_node);
}

void assignModuloEqual(char *var_name, struct DatatypeAndValue *new_datatype_and_value_node){
    struct SymbolTable *required_symbol_node = getSymbol(var_name);

    if(required_symbol_node==NULL)
        printf("[error: %d] '%s' not found\n", line, var_name);
    else
        required_symbol_node->datatype_and_value = binaryModulo(required_symbol_node->datatype_and_value, new_datatype_and_value_node);
}

struct DatatypeAndValue* fetchId(char *var_name){
    struct SymbolTable *required_symbol_node = getSymbol(var_name);

    if(required_symbol_node==NULL){
        printf("[error: %d] '%s' not found\n", line, var_name);
        return NULL;
    }
    else
        return required_symbol_node->datatype_and_value;
}

void printAll(){
    struct SymbolTable *ptr;
    ptr = origin_of_symbols;
    while(ptr!=NULL){
        printf("%s %s ", ptr->var_name, getDatatype(ptr->datatype_and_value->datatype));
        switch(ptr->datatype_and_value->datatype){
            case INTEGER:
                printf("%d\n", ptr->datatype_and_value->value->i_val);
                break;
            case FLOAT:
                printf("%f\n", ptr->datatype_and_value->value->f_val);
                break;
            case DOUBLE:
                printf("%lf\n", ptr->datatype_and_value->value->d_val);
                break;
            case CHARACTER:
                printf("%c\n", ptr->datatype_and_value->value->c_val);
                break;
            case BOOLEAN:
                if(ptr->datatype_and_value->value->b_val == '0')
                    printf("false\n");
                else
                    printf("true\n");
                break;
            case STRING:
                printf("%s\n", ptr->datatype_and_value->value->str_val);
                break;
        }
        ptr = ptr->next;
    }
}

void printId(char *symname){
    struct SymbolTable *ptr = getSymbol(symname);
    if(ptr!=NULL){
        printf("%s %s ", ptr->var_name, getDatatype(ptr->datatype_and_value->datatype));
        switch(ptr->datatype_and_value->datatype){
            case INTEGER:
                printf("%d\n", ptr->datatype_and_value->value->i_val);
                break;
            case FLOAT:
                printf("%f\n", ptr->datatype_and_value->value->f_val);
                break;
            case DOUBLE:
                printf("%lf\n", ptr->datatype_and_value->value->d_val);
                break;
            case CHARACTER:
                printf("%c\n", ptr->datatype_and_value->value->c_val);
                break;
            case BOOLEAN:
                if(ptr->datatype_and_value->value->b_val == '0')
                    printf("false\n");
                else
                    printf("true\n");
                break;
            case STRING:
                printf("%s\n", ptr->datatype_and_value->value->str_val);
                break;
        }
    }
    else
      printf("Symbol not found\n");
}