# JvC-Programming-Language
Compiler design repository. My high-level programming language, which is similar to C (provides very basic functionalities) and displays error message similar to Java.

## Languages and Tools
1. Win flex-bison
2. C
3. Sublime text editor

---

### 1. Calculator
This folder contains grammar for basic mathematical operations. [myCalc.l](https://github.com/vavadiyasanket/JvC-Programming-Language/blob/master/1.%20Calculator/myCalc.l) file generates tokens and [myCalc.y](https://github.com/vavadiyasanket/JvC-Programming-Language/blob/master/1.%20Calculator/myCalc.y) checks language grammar. Batch contains commands to execute language.

### 2. Syntax Analyser
This folder has functionality simmilar to high level programming languages like if...else, switch-case, for and while loop. Also it contains grammar for declaration and assignment statement. I only checks grammar of the given program.

### 3. Symbol Table
Adding symbols in symbol table. Symbols used/declared in programs are added to the SymbolTable

### 4. Abstract Syntax Tree
ASTBasic generates abstract syntax tree only for assignment and declaration statement. 
#### main
This folder has functionality simmilar to high level programming languages like if...else, switch-case, for and while loop. It generates AST of the program as well as also executes program line by line.

---

Contributions are welcome!
### Built with
[Babel AST Explorer](http://lihautan.com/babel-ast-explorer) <br/>
[Darshan Maradiya](https://github.com/DarshanMaradiya) (Guide) <br/>
lots of :heart: and passion
