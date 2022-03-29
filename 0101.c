// this is first of star
#include<stdio.h>
//  @@
int main()
{
    signed name=5;      // if we do not specifies data type than it will be default int
    printf("using signed without type define %d\n",name);
    //  Identifiers -> user defined object is called identifiers
    int ram =78;    //here ram is identifiers
    //  Qualifiers are two types 1.Const 2.Volatile
    const int lesss=78;
    printf("this is use of const int lesss = %d",lesss);
    printf("\n we can't be change const once it initialized lesss++ it showing error\n");
    const volatile int den=78;
    printf("value of den when volatile is used : %d",den);//we can use const and volatile together
    //storage class using
    printf("\n\nusing storage class variable\n");
   // extern int ext=10;
    printf("ext is 10 ");
    //using size spacifier
    printf("\n this is size specifier\n");
    int m=34; float n=432.23;
    printf("m=34 and n=432.23\n");
    printf("m->05--%05d,5--%5d,5.3--%5.3d\n",m,m,m);
    printf("n->04--%04f,4--%4f,4.3--%4.3f,4.02--%4.02f\n",n,n,n,n);
    //  formate modifiers * and #
    printf("\n formate modifiers is two * and #\n");
    printf("%x is normal    %#x is #used\n",10,10);
    printf("%*.*f  is *.* used and 10,4,124.34\n",10,4,1234.34);
    // using a scanset
    printf("\n using a scanset for a string\n");
    char user[40];
    printf("enter the user name &it start with only abcd later only\n");
    scanf("%[abcd]",user);
    printf("you enterd  %s\n",user); fflush(stdin);
    printf("formate modifiers enter name more than 5 charecter it can only 5char");
    scanf("%5s",user);
    printf("%s",user);

}
