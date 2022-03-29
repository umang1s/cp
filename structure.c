#include<stdio.h>
#include<stdlib.h>
typedef struct dist{int km,meter;}distance;
distance d1,d2,d3,d4;
add_distance()
{
    printf("enter the first distance in km and in meter\n");
    scanf("%d%d",&d1.km,&d1.meter);
    printf("enter the second distance in km and in meter\n");
    scanf("%d%d",&d2.km,&d2.meter);
    d3.km=d1.km+d2.km;
    d3.meter=d1.meter+d2.meter;
    display_sum();
}
sub_distance()
{
    printf("enter the first distance in km and in meter\n");
    scanf("%d%d",&d1.km,&d1.meter);
    printf("enter the second distance in km and in meter\n");
    scanf("%d%d",&d2.km,&d2.meter);
    d4.km=d1.km-d2.km;
    d4.meter=d1.meter-d2.meter;
    display_sub();
}
display_sum()
{
    printf("the sum of distance in km is%d\tin meter is %d\n",d3.km,d3.meter);
}
display_sub()
{
    printf("the sub of%d km\n %d meter\n",d4.km,d4.meter);
}
int main()
{
    int i;
    distance num1,num2;
    printf("please choose the option\n 1.for addition\t 2.for substraction\t0.for exit\n");
    scanf("%d",&i);
    while(i !=0)
    {
        if(i==1) add_distance();
        else if(i==2) sub_distance();
        else printf("wrong selection please choose (0,1,2)\n");
        printf("please choose the option\n 1.for addition\t 2.for substraction\t0.for exit\n");

        scanf("%d",&i);
    }
}
