#include<stdio.h>
#include<stdlib.h>
#line 100
//  #   define,elif,else,endif,error,if,ifdef,ifndef,include,line,pragma,undef
// ******************** #define
#define pi 3.14
#define xyz "hi i am umang"
#define abc(d) (d)<0?-(d) :(d)  //using fuction for macros
//#error  error-message;    // use of #error
//use of #if else elif and endif
int main()
{
    printf("#define used value of pi %f and xyz %s\n",pi,xyz);
    printf("abc value  for -1 and 1 : %d %d\n",abc(-1),abc(1));
     printf("\n\n Using line \n");
    printf("%d   %s\n ",__LINE__,__FILE__);
//    printf(error);
    printf("\n\nuse of # and ##\n");
    #define mans(b) # b
    printf(mans(I love umang));
    #define concat(a,b) a##b
    int xy=10;
    printf("\n%d\n",concat(x,y));
    printf("\n\n predefined macros name");
    printf("line %d\nfile %s\ndate %s\ntime %s\nstdc %s\ncplusplus %d\n",__LINE__,__FILE__,__DATE__,__TIME__,__STDC__,90);    //90->__cplusplus
    printf("\n\n using #if #else #elif #endif\n");
    #if 3<4
    printf("4 is greater than 3\n");

    #endif
    return 0 ;// pi
    printf("use of #if and #else\n\n");
    // it is use like elseif statment
    printf("using #ifdef and #ifndef\n");
    //  #ifdef macro-name
    //statement sequence
    //#endif
}
