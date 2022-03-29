#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define seed 12345
void play(void);
int throw(void);
main()
{
    char answer = 'Y';
    printf("welcome to the fame of craps\n\n");
    printf("to throw dice , press enter\n\n");
    srand(seed);
    while(toupper(answer) != 'N')
    {
        play();
        printf("\n Do you want to play again\n if yes enter 'y' \t if no enter'n' \n");
        scanf("%c",&answer);
        printf("\n");
    }
    printf("bye have a nice day");
}
void play(void)
{
    int score1,score2;
    char dummy;
    printf("\n please throw the dice . . . \n");
    scanf("%c",&dummy);
    printf("\n");
    score1 = throw();
    printf("\n%2d",score1);
    switch(score1)
    {
        case 7:
        case 11: printf("\n congratulations ! win the first throw \n"); break;
        case 2:
        case 3:
        case 12 : printf("sorry you loose on first throw \n"); break;
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:do {
            printf("\nthrow the dice again . . .");
    scanf("%c",&dummy);
    score2 = throw();
    printf("\n%2d ",score2);
    }
    while(score2 !=score1 && score2 !=7) ;
    if(score2==score1) printf("\n you win by the first score");
    else printf(" \n you lose by failing to match");
    break ;
}
return;
}
int throw(void)
{
    float x1,x2;
    int n1,n2;
    x1 = rand()/32768.0 ;
    x2 = rand()/32768.0 ;
    n1= 1 + (int) (6*x1) ;
    n2 = 1+ (int) (6*x2);
    return(n1+n2);
}
