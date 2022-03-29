#include<stdio.h>
int xe(char x){return x==62 ? 1:0;}
int main(){
    for(int i=0; i<256; i++)
    printf("%d  %c\t",i,i);
    printf("--------------------%d-----------------",' ');

}
