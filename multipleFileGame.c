#include<stdio.h>
char Board[25][25];
int Score;
int takeInput()
{
    FILE *read;
    int i;
    read = fopen("bixer.txt","r");
    fscanf(read,"%d",&i);
    fclose(read);
    return i;
}
void display()
{
    system("cls");
    for(int i=0; i<51; i++) printf("%%");    printf("\tSCORE   : %d\n",Score); //first line
    for(int i=0; i<25; i++)                                      // second to last line
    {
        printf("%%");
        for(int j=0; j<25; j++)
        {
            printf("%c",Board[i][j]);
            if(j!=24) printf(" ");
        }
        printf("%\n");
    }
    for(int i=0; i<51; i++) printf("%%"); printf("\n");     //last line
}
void BoardIni()
{
    for(int i=0; i<25; i++) for(int j=0; j<25; j++) Board[i][j]=' ';
    Score=0;
    Board[12][12]='*';
}
int main()
{
    int Move;
    int i=12,j=12;
    int ii,jj;
    BoardIni();
    while(1)
    {
        display();
        Move=takeInput();
        if(Move==8)
        {
            Board[i][j]=' ';    //deleting last position
            Board[--i][j] ='*';
        }
        else if(Move==6)
        {
            Board[i][j]=' ';    //deleting last position
            Board[i][++j] ='*';
        }
        else if(Move==4)
        {
            Board[i][j]=' ';    //deleting last position
            Board[i][--j] ='*';
        }
        else if(Move==2)
        {
            Board[i][j]=' ';    //deleting last position
            Board[++i][j] ='*';
        }
        else if(Move==0) return 0;
        else ;
        if(i<25 && i>-1 && j<25 && j>-1) ;
        else
        {
            printf("Game over \n\n");
        }

    }
    system("cls");
    printf("Match drawn\n\n");
}
