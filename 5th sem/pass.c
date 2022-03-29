#include<stdio.h>
int main()
{
    int x=0;
    FILE *write;
    write=fopen("mobile.txt","w");
    printf("started\n");
    for(int i=6; i<10; i++){
        for(int j=0; j<10; j++)
            for(int k=0; k<10; k++)
                for(int l=0; l<10; l++)
                    for(int m=0; m<10; m++)
                        for(int n=0; n<10; n++)
                            for(int o=0; o<10; o++)
                                for(int p=0; p<10; p++)
                                    printf("+91%d%d%d%d%d%d%d%d10   %d\n",i,j,l,m,n,o,p,x++);
                                    //x+=15;
                                    //fprintf(write,"+91%i%j%k%l%m%n%o%p10\n");
        printf("%d\n",(i-5)*25);
    }
    fclose(write);
    printf("completed %d MB ",x/1024);
}
