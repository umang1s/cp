int errorno=0;
int warningno=0;
int isInvertedCommas(char x){return x==34 ? 1:0;}
int isLessThanSymbol(char x){return x==60 ? 1:0;}
int isGreaterThanSymbol(char x){ return x==62 ? 1:0;}
int isArithmeticOperator(char x){
    if(x=='*') return 1;
    if(x=='-') return 1;
    if(x=='*') return 1;
    if(x=='%') return 1;
    if(x=='/') return 1;
    else return 0;
}
int isSpace(char x){return x==32 ? 1:0;}
int isNextLine(char x){return x==10 ? 1:0;}
void Print(char *value){ printf("%s\n",value);}
void ShowError(char *what,int line){printf("Error %d : [%s] found in line %d\n",errorno++,what,line);}
void ShowWarning(char *what , int line){printf("Warning %d : [%s] found in line %d\n",warningno++,what,line);}