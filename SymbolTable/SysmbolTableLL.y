%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define SIZE 5
    void insertInt(char *symname, int val);
    void insertFloat(char *symname, float val);
    void insertDouble(char *symname, double val);
    void insertChar(char *symname, char val);
    void insertString(char *symname, char val[]);
    void insertBoolean(char *symname, char *val);
    void printAll();
    void printId(char *symname);
    void getValue(char *symname);
    union AllDt{
        int ival;
        float fval;
        double dval;
        char cval;
        char sval[20];
        int bval;
    };
    struct Table{
        char *var_name;
        char *type;
        union AllDt val;
        struct Table *next;
    }*start;
%}
%token intdt floatdt doubledt chardt stringdt booleandt
%token intval floatval doubleval charval stringval true false
%token plus minus multiplication division percentage exclamation pow modulo
%token increment decrement logicalor logicaland
%token equal openbracket closebracket
%token gteq gt lt lteq eqeq noteq
%token questionmark colon leftshift rightshift and or xor
%token id newline print comma
%%
SS : SS S | S;

S : E newline ;

E : DECLARATION 
  | print       {printAll();}
  | print id  {printId($2);}
  ;

DECLARATION : intdt INT_DECLARATION
            | floatdt FLOAT_DECLARATION 
            | doubledt DOUBLE_DECLARATION
            | chardt CHAR_DECLARATION
            | stringdt STRING_DECLARATION
            | booleandt BOOLEAN_DECLARATION
            ;

INT_DECLARATION : id                                     {insertInt($1, 0);}
                | id equal TERNARY                       {insertInt($1, $3);}
                | id comma INT_DECLARATION               {insertInt($1, 0);}
                | id equal TERNARY comma INT_DECLARATION {insertInt($1, $3);}
                ;

FLOAT_DECLARATION : id                                       {insertFloat($1, 0);}
                  | id equal TERNARY                         {insertFloat($1, $3);}
                  | id comma FLOAT_DECLARATION               {insertFloat($1, 0);}
                  | id equal TERNARY comma FLOAT_DECLARATION {insertFloat($1, $3);}
                  ;

DOUBLE_DECLARATION : id                                 {insertDouble($1, 0);}
                   | id equal TERNARY                   {insertDouble($1, $3);}
                   | id comma DOUBLE_DECLARATION        {insertDouble($1, 0);}
                   | id equal TERNARY comma DOUBLE_DECLARATION {insertDouble($1,    $3);}
                   ;

CHAR_DECLARATION : id                        {insertChar($1, '0');}
                 | id equal charval          {char *c = $3; insertChar($1, c[1]);}
                 | id comma CHAR_DECLARATION {insertChar($1, '0');}
                 | id equal charval comma CHAR_DECLARATION {char *c = $3;       insertChar($1, c[1]);}
                 ;  

STRING_DECLARATION : id                                 {insertString($1, "");}
                   | id equal stringval                 {insertString($1, $3);}
                   | id comma STRING_DECLARATION        {insertString($1, "");}
                   | id equal stringval comma STRING_DECLARATION {insertString($1,  $3);}
                   ;

BOOLEAN_DECLARATION : id                            {insertBoolean($1, "false");}
                    | id equal VALUE                {insertBoolean($1, $3);}
                    | id comma BOOLEAN_DECLARATION  {insertBoolean($1, "false");}
                    | id equal VALUE comma BOOLEAN_DECLARATION {insertBoolean($1, $3);}
                    ;

TERNARY : LOGICAL questionmark LOGICAL colon LOGICAL {$$ = $1 ? $3 : $5;}
        | LOGICAL                                     {$$ = $1;}
        ;

LOGICAL : LOGICAL logicalor BITWISE_OPERATIONS                {$$ = $1 || $3;}
        | LOGICAL logicaland BITWISE_OPERATIONS               {$$ = $1 && $3;}
        | BITWISE_OPERATIONS                                  {$$ = $1;}
        ;        

BITWISE_OPERATIONS : BITWISE_OPERATIONS or RELATIONAL_EXP_1     {$$ = $1 | $3;}
                   | BITWISE_OPERATIONS xor RELATIONAL_EXP_1    {$$ = $1 ^ $3;}
                   | BITWISE_OPERATIONS and RELATIONAL_EXP_1    {$$ = $1 & $3;}
                   | RELATIONAL_EXP_1                           {$$ = $1;}
                   ;

RELATIONAL_EXP_1 : RELATIONAL_EXP_1 gteq RELATIONAL_EXP_2   {$$ = $1 >= $3;}
                 | RELATIONAL_EXP_1 gt RELATIONAL_EXP_2     {$$ = $1 > $3;}
                 | RELATIONAL_EXP_1 lteq RELATIONAL_EXP_2   {$$ = $1 <= $3;}
                 | RELATIONAL_EXP_1 lt RELATIONAL_EXP_2     {$$ = $1 < $3;}
                 | RELATIONAL_EXP_2                         {$$ = $1;}
                 ;

RELATIONAL_EXP_2 : RELATIONAL_EXP_2 eqeq SHIFTS     {$$ = $1==$3;}
                 | RELATIONAL_EXP_2 noteq SHIFTS    {$$ = $1!=$3;}
                 | SHIFTS                           {$$ = $1;}

SHIFTS : SHIFTS rightshift ARITHMETIC_EX       {$$ = $1 >> $3;}
       | SHIFTS leftshift ARITHMETIC_EX        {$$ = $1 << $3;}
       | ARITHMETIC_EX                          {$$ = $1;}
       ;

ARITHMETIC_EX : ARITHMETIC_EX minus ARITHMETIC_1        {$$ = $1 - $3;}
              | ARITHMETIC_EX plus ARITHMETIC_1         {$$ = $1 + $3;}
              | ARITHMETIC_1                            {$$ = $1;}
           ;

ARITHMETIC_1 : ARITHMETIC_1 multiplication ARITHMETIC_2     {$$ = $1*$3;}
             | ARITHMETIC_1 division ARITHMETIC_2           {$$ = $1/$3;}
             | ARITHMETIC_1 modulo ARITHMETIC_2             {$$ = $1%$3;}
             | ARITHMETIC_1 percentage ARITHMETIC_2         {$$ = $1*$3/100;}
             | plus VALUE                                   {$$ = $2;}
             | minus VALUE                                  {$$ = -$2;}
             | increment VALUE                              {$$ = $2+1;}
             | decrement VALUE                              {$$ = $2-1;}
             | ARITHMETIC_2                                 {$$ = $1;}
             ;

ARITHMETIC_2 : ARITHMETIC_2 exclamation     {$$ = $1; while($1-- > 1) $$ *= $1;}
             | BRACKETS pow ARITHMETIC_2    {$$ = $1; while($3-- > 1) {$$ *= $1;}}
             | VALUE increment              {$$ = $1+1;}
             | VALUE decrement              {$$ = $1-1;}
             | BRACKETS                     {$$ = $1;}
             ;

BRACKETS : openbracket TERNARY closebracket         {$$ = $2;}
         | VALUE                                {$$ = $1;}
         ;

/*SWAPPING : VALUE SWAP VALUE ;*/

VALUE : intval
      | floatval
      | doubleval
      | BOOLEAN_VAL
      | id
      ;

BOOLEAN_VAL : true | false;

%%
void insertInt(char *symname, int val){
    if(start==NULL){
        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "int";
        new_node->val.ival = val;

        start = new_node;
        start->next = NULL;
    }
    else{
        struct Table *ptr = start;
        while(ptr->next!=NULL) {
          if(strcmp(ptr->var_name, symname) == 0) {
            printf("Re-Declaration of variable : %s\n", symname);
            return;
          }
          ptr = ptr->next;
        }
        
        if(strcmp(ptr->var_name, symname) == 0){
          printf("Re-Declaration of variable : %s\n", symname);
          return;
        }
        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "int";
        new_node->val.ival = val;

        ptr->next = new_node;
        new_node->next = NULL;
    }
    printf("%s of type %s inserted with value = %d\n", symname, strdup("int"), val);
}
void insertFloat(char *symname, float val){
    if(start==NULL){
        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "float";
        new_node->val.fval = val;

        start = new_node;
        start->next = NULL;
    }
    else{
        struct Table *ptr = start;
        while(ptr->next!=NULL) {
          if(strcmp(ptr->var_name, symname) == 0) {
            printf("Re-Declaration of variable : %s\n", symname);
            return;
          }
          ptr = ptr->next;
        }
        
        if(strcmp(ptr->var_name, symname) == 0){
          printf("Re-Declaration of variable : %s\n", symname);
          return;
        }
        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "float";
        new_node->val.fval = val;

        ptr->next = new_node;
        new_node->next = NULL;
    }
    printf("%s of type %s inserted with value = %f\n", symname, strdup("float"), val);
}
void insertDouble(char *symname, double val){
    if(start==NULL){
        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "double";
        new_node->val.dval = val;

        start = new_node;
        start->next = NULL;
    }
    else{
        struct Table *ptr = start;
        while(ptr->next!=NULL) {
          if(strcmp(ptr->var_name, symname) == 0) {
            printf("Re-Declaration of variable : %s\n", symname);
            return;
          }
          ptr = ptr->next;
        }
        
        if(strcmp(ptr->var_name, symname) == 0){
          printf("Re-Declaration of variable : %s\n", symname);
          return;
        }
        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "double";
        new_node->val.dval = val;

        ptr->next = new_node;
        new_node->next = NULL;
    }
    printf("%s of type %s inserted with value = %lf\n", symname, strdup("double"), val);
}
void insertChar(char *symname, char val){
    if(start==NULL){
        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "char";
        new_node->val.cval = val;

        start = new_node;
        start->next = NULL;
    }
    else{
        struct Table *ptr = start;
        while(ptr->next!=NULL) {
          if(strcmp(ptr->var_name, symname) == 0) {
            printf("Re-Declaration of variable : %s\n", symname);
            return;
          }
          ptr = ptr->next;
        }
        
        if(strcmp(ptr->var_name, symname) == 0){
          printf("Re-Declaration of variable : %s\n", symname);
          return;
        }
        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "char";
        new_node->val.cval = val;

        ptr->next = new_node;
        new_node->next = NULL;
    }
    printf("%s of type %s inserted with value = %c\n", symname, strdup("char"), val);
}
void insertString(char *symname, char val[]){
    // removing double " " qoates from string val
    int i=0;
    for(;val[i]!='\0';i++);
    int length = i-2;
    char val1[length];
    for(i=0;i<length;i++)
        val1[i] = val[i+1];

    if(start==NULL){
        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "string";
        for(i=0;i<length;i++)
            new_node->val.sval[i] = val1[i];
        new_node->val.sval[length] = '\0';
        start = new_node;
        start->next = NULL;
    }
    else{
        struct Table *ptr = start;
        while(ptr->next!=NULL) {
          if(strcmp(ptr->var_name, symname) == 0) {
            printf("Re-Declaration of variable : %s\n", symname);
            return;
          }
          ptr = ptr->next;
        }
        
        if(strcmp(ptr->var_name, symname) == 0){
          printf("Re-Declaration of variable : %s\n", symname);
          return;
        }

        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "string";
        for(i=0;i<length;i++)
            new_node->val.sval[i] = val1[i];
        new_node->val.sval[length] = '\0';
        ptr->next = new_node;
        new_node->next = NULL;
    }
    printf("%s of type %s inserted with value = %s\n", symname, strdup("string"), val);
}
void insertBoolean(char *symname, char *val){
    if(start==NULL){
        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "boolean";
        new_node->val.bval = val[0]=='t' || val[0]=='T' ? 1 : 0;

        start = new_node;
        start->next = NULL;
    }
    else{
        struct Table *ptr = start;
        while(ptr->next!=NULL) {
          if(strcmp(ptr->var_name, symname) == 0) {
            printf("Re-Declaration of variable : %s\n", symname);
            return;
          }
          ptr = ptr->next;
        }
        
        if(strcmp(ptr->var_name, symname) == 0){
          printf("Re-Declaration of variable : %s\n", symname);
          return;
        }
        struct Table *new_node;
        new_node = (struct Table*) malloc(sizeof(struct Table));
        new_node->var_name = symname;
        new_node->type = "boolean";
        new_node->val.bval = val[0]=='t' || val[0]=='T' ? 1 : 0;

        ptr->next = new_node;
        new_node->next = NULL;
    }
    printf("%s of type %s inserted with value = %s\n", symname, strdup("boolean"), val);
}
void printAll(){
    struct Table *ptr;
    ptr = (struct Table*) malloc(sizeof(struct Table));
    ptr = start;
    while(ptr!=NULL){
        printf("%s %s ", ptr->var_name, ptr->type);
        if(ptr->type=="int")
            printf("%d\n", ptr->val.ival);
        else if(ptr->type=="float")
            printf("%f\n", ptr->val.fval);
        else if(ptr->type=="double")
            printf("%lf\n", ptr->val.dval);
        else if(ptr->type=="char")
            printf("%c\n", ptr->val.cval);
        else if(ptr->type=="string")
            printf("%s\n", ptr->val.sval);
        else if(ptr->type=="boolean"){
            if(ptr->val.bval == 0)
                printf("false\n");
            else
                printf("true\n");
        }
        ptr = ptr->next;
    }
}
void printId(char *symname){
    struct Table *ptr;
    ptr = (struct Table*) malloc(sizeof(struct Table));
    ptr = start;
    while(ptr!=NULL){
        if(strcmp(ptr->var_name, symname) == 0) {
          printf("%s %s ", ptr->var_name, ptr->type);
          if(ptr->type=="int")
            printf("%d\n", ptr->val.ival);
          else if(ptr->type=="float")
              printf("%f\n", ptr->val.fval);
          else if(ptr->type=="double")
              printf("%lf\n", ptr->val.dval);
          else if(ptr->type=="char")
              printf("%c\n", ptr->val.cval);
          else if(ptr->type=="string")
              printf("%s\n", ptr->val.sval);
          else if(ptr->type=="boolean"){
              if(ptr->val.bval == 0)
                  printf("false\n");
              else
                  printf("true\n");
          }
          break;
        }
        ptr = ptr->next;
    }
    if(ptr==NULL)
      printf("Symbol not found\n");
}
int main (void) {
    yyparse();
    return 0;
}