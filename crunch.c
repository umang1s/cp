#include<stdio.h>
#include<math.h>
//////////////////////// gloable declaretion ////////////
char words[],para[];
int size=0,mins,maxs;





////////////////////////////////////////    operation_H  ///////////////////////////////////////////////////////
operation_H()
{
    printf("HELP--\n\t[option] [min] [max] [string] [parameter]\n");
    printf("[option]\n  X--  write with parameter\n  W--  write only\n  S--  display size\nD W--  write with display\nD X--  write & display parameter\nD O--  dispaly only\n");
}






///////////////////////////////////////     operation_W ///////////////////////////////////////////////////////
operation_W()
{
    printf("this is now empty       W\n");
}





////////////////////////////////////////    operation_D_W   ////////////////////////////////////////////////////
operation_D_W()
{
    printf("this is now empty       D W\n");
}







///////////////////////////////////     operation_S //////////////////////////////////////////////////////////
operation_S()
{
    int i;
    for(i=mins; i<=maxs; i++)  size+=pow(strlen(words),i);
    printf("size : %d",size);
}





////////////////////////////////////        operation_D_O   ///////////////////////////////////////////////////
operation_D_O()
{
    printf("this is now empty       D O\n");
}






////////////////////////////////////        operation_X     /////////////////////////////////////////////////////////
operation_X()
{
    printf("this is now empty       X\n");
}






///////////////////////////////////// operation_D_X     ///////////////////////////////////////////////////////////
operation_D_X()
{
    printf("this is now empty       D X\n");

}







//////////////////////////////////////// main function///////////////////////////////////////////////////////////
int main()
{
    char a; char b;
    printf("enter the operation  : ");
    scanf("%c",&a);
    if(a=='W' || a=='w')        { scanf("%d %d %[^\n]",&mins,&maxs,words);   operation_W(); }
    else if (a=='X' || a=='x')  { scanf("%d %d %[^\n]",&mins,&maxs,words); operation_X();   }
    else if (a=='S' || a=='s')  { scanf("%d %d %[^\n]",&mins,&maxs,words);  operation_S();  }
    else if (a=='D' || a=='d')  {
                                    fflush(stdin);
                                    scanf("%c %d %d %[^\n]",&b,&mins,&maxs,words);
                                    if(b=='W' || b=='w' ) operation_D_W();
                                    else if (b=='X' || b=='x') operation_D_X();
                                    else if (b=='o' || b=='O') operation_D_O();
                                    else operation_H();
                                }
    else operation_H();
}
