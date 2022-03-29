#include<stdio.h>
#include<stdlib.h>
char position[9],cpu[9],ply1[20],ply2[20];
int player1=0,player2=0,tie=0,match=0,move=0,cp=0,ps=0;
void display();         char check_game();          void player_cpu();          void game_progress(int k);
int main()
{
    int i=5,j; char check, machin[20]="CPU";
    for(j=0; j<9; j++) position[j]=j+49;
    printf("enter name of player\n"); scanf("%s",ply1);
    printf("play with cpu enter .....3\t play with human enter .....5\t exit enter ......0\n");
    scanf("%d",&i);
    while(i !=0)
    {
        check=check_game(); if(i==3) {cp=5; strcpy(ply2,machin);} else { if(ps==0){printf("enter name of second player\n"); scanf("%s",ply2); ps++;} }
        if(match%2==0)  while(check == 'C' )
        {
            display();
            if(check !='D' && check !='X'   && check !='#' ) {if(i==3)player_cpu(); else game_progress(1);}
            check=check_game();
            if(check !='D' && check !='X'   && check !='#' ) game_progress(2);
            check=check_game();
        }
        else    while(check == 'C' )
        {
            display();
            if(check !='D' && check !='X'   && check !='#' ) game_progress(2);
            check=check_game();
            if(check !='D' && check !='X'   && check !='#' )    {if(i==3)player_cpu(); else game_progress(1);}
            check=check_game();
        }
        if(check=='X') {printf("****************************%s won the match******************************\n",ply1);  player1++;  }
        else if(check=='#')  {   printf("****************************%s won the match******************************\n",ply2); player2++;   }
        else { printf("************************match draw***********************\n"); tie++;    }
        printf("play with cpu enter .....3\t play with human enter .....5\t exit enter ......0\n");
        scanf("%d",&i);
        if(i !=0) { for(j=0; j<9; j++) position[j]=j+49;  match++; move=0; cp=0;}
    }
}
void display()
{
    system("cls");
    printf("%s:X: %d\t\t%s :O: %d\t\tdraw match : %d\t\tmove : %d\n",ply1,player1,ply2,player2,tie,move);
    printf("\n\t\t\t\t      |       |\n\t\t\t\t  %c   |   %c   |   %c\n\t\t\t\t      |       |\n",position[0],position[1],position[2]);
    printf("\t\t\t\t---------------------\n");
    printf("\t\t\t\t      |       |\n\t\t\t\t  %c   |   %c   |   %c\n\t\t\t\t      |       |\n",position[3],position[4],position[5]);
    printf("\t\t\t\t---------------------\n");
    printf("\t\t\t\t      |       |\n\t\t\t\t  %c   |   %c   |   %c\n\t\t\t\t      |       |\n\n",position[6],position[7],position[8]);
}
void game_progress(int k)
{
    int i=1,j,d=0;
    if(k==1)printf("%s\t",ply1);
    else printf("%s\t",ply2);
    scanf("%d",&j);     if(j>10 || j<0 ){printf("you entered wrong position\n"); game_progress(k);}
    if(position[j-1] == 'X' || position[j-1]=='#') d++;
    if(d==0)
    {
        if(k==1)  position[j-1]='X';
        else  position[j-1]='#';
        move++;
    }
    else {printf("this position is already filled\n");  game_progress(k);}
    display();
}
char check_game()
{
   char k;
   if(position[0]==position[1] && position[1]==position[2]) k=position[0];
   else if(position[0]==position[3] && position[3]==position[6]) k=position[0];
   else if(position[0]==position[4] && position[4]==position[8]) k=position[0];
   else if(position[2]==position[5] && position[5]==position[8]) k=position[2];
   else if(position[6]==position[7] && position[7]==position[8]) k=position[6];
   else if(position[2]==position[4] && position[4]==position[6]) k=position[6];
   else if(position[1]==position[4] && position[4]==position[7]) k=position[1];
   else if(position[4]==position[3] && position[4]==position[5]) k=position[5];
   else if (move==9) k='D';
   else k='C';
   return k;
}
void player_cpu()
{
    printf("cpu is thinking   "); logo();
    int i,j,k,l,n=0;
    for(i=0; i<9; i++)  cpu[i]=position[i];
    cpu[3]=cpu[1];  cpu[2]=cpu[6]; cpu[5]=cpu[7]; cpu[1]=position[3]; cpu[6]=position[2]; cpu[7]=position[5];
    for(i=0; i<9; i++)
    {
        j=i+3;  k=i+6;  if(j>8) j-=9;    if(k>8) k-=9;
        if(position[i]==position[j])  {  if(position[k] !='X' && position[k] != '#' ) { position[0]='X'; move++;} else n++; }
        if(cpu[i]==cpu[j]) { if(position[k] !='X' && position[k] != '#' ) { position[0]='X'; move++; for(l=0; l<9; l++) position[l]=cpu[l];} else n++;}
    }
    if(position[4] == position[8])       {if(position[0] !='X' && position[0] != '#' ) {position[0]='X';    move++;} else n++; }
    else if(position[0] == position[8])  {if(position[4] !='X' && position[4] != '#' ) {position[4]='X';    move++;} else n++; }
    else if(position[4] == position[0])  {if(position[8] !='X' && position[8] != '#' ) {position[8]='X';    move++;} else n++; }
    else if(position[4] == position[6])  {if(position[2] !='X' && position[2] != '#' ) {position[2]='X';    move++;} else n++; }
    else if(position[4] == position[2])  {if(position[6] !='X' && position[6] != '#' ) {position[6]='X';    move++;} else n++; }
    else if(position[2] == position[6])  {if(position[4] !='X' && position[4] != '#' ) {position[4]='X';    move++;} else n++; }
    else
    {
        printf("now not avaible\n");
    }
    if(n !=0) {
        printf("now not avaible\n");
    }
    if(match%2==0)
    {
        if(move==0)
        {
            printf("898");
        }
    }
}
/*void players_cpu()
{
    printf("please wait cpu is thinking  n");
    int i,j,k,l,m,o;
    if(move==0)
    {
        i=corner_rand();
        position[i-1]='X';
        return 0;
    }
    else if(move==1)
    {
        if(position[0]=='#' || position[2]=='#' || position[6]=='#' || position[8]=='#') { position[4]='X' return 0;}
        else if(position[4]=='#') ;
        else ;
    }
    else if(move==2)
    {

    }
    else if(move==3)
    {

    }
    else
    {

    }
} */
void logo()
{
    int i;
    for(i=0; i<100; i++) {printf("%d",i+1);  if(i<10) printf("\b"); else printf("\b\b"); }
}
