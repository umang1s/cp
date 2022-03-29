#include<iostream> 
using namespace std;
class Lexical{
    char lanuage[10000];
    char declaredVariable[400][30];
    int declaredVariableType[32];
    int token=0;
    

    public:
    Lexical(char filename[]){
        FILE *file;
        file=fopen(filename,"r");
        ///read all file and store in lanuage
    }
    void start(){
        char temp[20];
        int x=0;
        int tempN;

        for(int i=0; i<strlen(language); i++){
            switch(lanuage[i]){
                case (47 && 58): 
                    if(x=0) break;
                    temp[x++];
                case (64 && i<91):
                case (i>96 && i<123):
                case ';':    ///line break than process last
                case '"':    ///string found
                case '*':
                case '/':
                case '=':
                case '&':
                case '+':
                case '-':
                case '%':
                case ')':
                case '[':
                case ']':
                case '{':
                case '}':
                case ')': 
                case '\n':
                case '#':
                    if()
                case '>':
                case '<':
                case ',':
                case '.':

            }
        }
    }


}
int main(int a,char filename[]){
    Lexical lexical=Lexical(filename);
    lexical.start();
}

///features
///#include