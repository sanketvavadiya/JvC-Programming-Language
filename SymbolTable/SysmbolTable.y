%{
    #include <stdio.h>
    #include <stdlib.h>
    #define SIZE 5
    void insertInt(char *symname, int val);
    void insertFloat(char *symname, float val);
    void insertDouble(char *symname, double val);
    void insertChar(char *symname, char val);
    void insertString(char *symname, char *val);
    void insertBoolean(char *symname, char *val);
    void getValue(char *symname);
    union AllDt{
        int ival;
        float fval;
        double dval;
        char cval;
        char *sval;
        int bval;
    };
    struct Table{
        char *var_name;
        char *type;
        union AllDt val;
    };
    struct Table symbolTable[SIZE];
%}
%token intdt floatdt doubledt chardt stringdt booleandt
%token intval floatval doubleval charval stringval true false
%token id new_line equal print
%%
SS : SS S | S;

S : E new_line ;

E : DECLARATION 
  | print id        {/*getValue($2);*/}
  ;

DECLARATION : intdt id equal intval     {insertInt($2, $4);}
            | intdt id                  {insertInt($2, 0);}
            | floatdt id equal floatval {insertFloat($2, $4);}
            | floatdt id                {insertFloat($2, 0);}
            | doubledt id equal doubleval {insertDouble($2, $4);}
            | doubledt id                  {insertDouble($2,0);}
            | chardt id equal charval      {char *c = $4; insertChar($2, c[1]);}
            | chardt id                    {insertChar($2, '0');}
            | stringdt id equal stringval {insertString($2, $4);}
            | stringdt id                   {insertString($2, "");}
            | booleandt id equal booleanval {insertBoolean($2, $4);}
            | booleandt id                  {insertBoolean($2, "false");}
            ;

booleanval : true | false;

%%
void insertInt(char *symname, int val){
    printf("var_name: %s value: %d\n", symname, val);
    int index = computeIndex();
    if(index!=-1){
        symbolTable[index].var_name = symname;
        symbolTable[index].type = "int";
        symbolTable[index].val.ival = val;
        printf("%s of type %s inserted at %d with value = %d\n", symbolTable[index].var_name, symbolTable[index].type, index, symbolTable[index].val.ival);
    }
    else
        printf("Out of memory\n");
}
void insertFloat(char *symname, float val){
    printf("var_name: %s value: %f\n", symname, val);
    int index = computeIndex();
    if(index!=-1){
        symbolTable[index].var_name = symname;
        symbolTable[index].type = "float";
        symbolTable[index].val.fval = val;
        printf("%s of type %s inserted at %d with value = %f\n", symbolTable[index].var_name, symbolTable[index].type, index, symbolTable[index].val.fval);
    }
    else
        printf("Out of memory\n");
}
void insertDouble(char *symname, double val){
    printf("var_name: %s value: %lf\n", symname, val);
    int index = computeIndex();
    if(index!=-1){
        symbolTable[index].var_name = symname;
        symbolTable[index].type = "double";
        symbolTable[index].val.dval = val;
        printf("%s of type %s inserted at %d with value = %lf\n", symbolTable[index].var_name, symbolTable[index].type, index, symbolTable[index].val.dval);
    }
    else
        printf("Out of memory\n");
}
void insertChar(char *symname, char val){
    printf("var_name: %s value: %c\n", symname, val);
    int index = computeIndex();
    if(index!=-1){
        symbolTable[index].var_name = symname;
        symbolTable[index].type = "char";
        symbolTable[index].val.cval = val;
        printf("%s of type %s inserted at %d with value = %c\n", symbolTable[index].var_name, symbolTable[index].type, index, symbolTable[index].val.cval);
    }
    else
        printf("Out of memory\n");
}
void insertString(char *symname, char *val){
    // removing double " " qoates from string val
    int i=0;
    for(;val[i]!='\0';i++);
    int length = i-2;
    char val1[length];
    for(i=0;i<length;i++)
        val1[i] = val[i+1];
    printf("var_name: %s value: %s\n", symname, val1);
    int index = computeIndex();
    if(index!=-1){
        symbolTable[index].var_name = symname;
        symbolTable[index].type = "string";
        symbolTable[index].val.sval = val1;
        printf("%s of type %s inserted at %d with value = %s\n", symbolTable[index].var_name, symbolTable[index].type, index, symbolTable[index].val.sval);
    }
    else
        printf("Out of memory\n");
}
void insertBoolean(char *symname, char *val){
    printf("var_name: %s value: %c\n", symname, val);
    int index = computeIndex();
    if(index!=-1){
        symbolTable[index].var_name = symname;
        symbolTable[index].type = "boolean";
        symbolTable[index].val.bval = val[0]=='t' || val[0]=='T' ? 1 : 0;
        printf("%s of type %s inserted at %d with value = %d\n", symbolTable[index].var_name, symbolTable[index].type, index, symbolTable[index].val.bval);
    }
    else
        printf("Out of memory\n");
}
int computeIndex(){
    int i;
    for(i=0;i<SIZE;i++)
        if(symbolTable[i].var_name == NULL)
            return i;
    return -1;
}
void getValue(char *symname){
    int i;
    for(i=0;i<SIZE;i++){
        if(strcmp(symbolTable[i].var_name, symname)==0)
            printf("%s = %d\n", symname, symbolTable[i].val.ival);
    }
    printf("symbol not found\n");
}
int main (void) {
    yyparse();
    return 0;
}