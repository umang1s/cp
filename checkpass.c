#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    printf("     #        #    # #     # # #    # # #     #         #     # # #  # # # # #\n  ");
    printf("   #   ##   #  #     #   #    #   #     #   #         #   #            #\n    ");
    printf(" #  #  #  #  #     #   # # #    #     #   #         #     # #        #\n");
    printf("     # #    # #  #     #   #    #   #     #   #         #         #      #\n   ");
    printf("  ##      ##    # #     #     #  # # #     # # # #   #   # # #        #\n\n\n");

    long int scanned,maxPassLength=100000,toalPassword,k,passLength[10000],j;
    char password[maxPassLength][20],newPasswd[20];
    int i=5,totalPassword,m=7,newLength,l,sum=0,done;

    ///////////////////////////scanning from file//////////////////////


    printf("scanning...\n");
    FILE *read,*write;
    read=fopen("pass.txt","r");
    for(totalPassword=0; i!=0; totalPassword++)
    {
       fscanf(read,"%s",password[totalPassword]);
       if(password[totalPassword][0]=='\0')
            i=0;
    }
   // fclose(read);
    printf("scannning completed\n");
    printf("(%d)   password found !\n",--totalPassword);

    ///////////////////////////////password checking and seving/////////////////////


    for(k=0; k<totalPassword; k++)
    {
        printf("%s\n",password[k]);
        passLength[k]=strlen(password[k]);
    }
    printf("###################################################\n");
    while(m !=0)
    {
        printf("Enter wordlist for check : ");
        scanf("%s",newPasswd);
        newLength=strlen(newPasswd);
        printf("searching...\n");
        done=0;
        for(k=0; k<totalPassword && done!=9; k++)
        {
            sum=0;
            for(l=0; l<newLength; l++)
            {
                if(newPasswd[l]==password[k][l]) sum++;
            }
            if(sum==newLength)
            {
                if(newLength==passLength[k])
                {
                    printf("matched\n");
                    done=9;
                }
                else printf("similer wordlist %s:::\n",password[k]);
            }
        }

        /////////////////////////////       saving in file ////////////////////
        if(done!=9)
        {
            write=("pass.txt","w");
            printf("not matched\nsaving password...\n");
            strcpy(password[totalPassword],newPasswd);
            totalPassword++;
            for(j=0; j<totalPassword; j++) fprintf(write,"%s\n",password[j]);
            printf("saved password\n");
            fclose(write);
        }
    }
}
