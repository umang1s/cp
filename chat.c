#include<stdio.h>
typedef struct LoginData
{
    int loginId;
    int pin;
} Login;
typedef struct message
{
    char message[200];
    int chat[300];
} Message;

int login(){
    Login all[1000];
    int x=0,newUser=0,founded=0,foundedAt=0,matched=0,pin1,pin2;
    FILE *fil;
    fil=fopen("database.txt","r");
    fscanf(fil,"%d",&founded);
    for(int i=0 ; i<founded; i++) fscanf(fil,"%d %d",&all[i].loginId,&all[i].pin);
    fclose(fil);
    while(1){
        printf("9 for exit\nenter login id : ");
        scanf("%d",&x);
        if(x==9) return -1;
        else{
            matched=0;
            for(int j=0; j<founded; j++){ if(all[j].loginId==x){matched=1; foundedAt=j; j=founded;}}
            if(matched==1){
                printf("enter otp : ");
                scanf("%d",&pin1);
                if(pin1==all[foundedAt].pin) return x;
                else printf("wrong password\n");
            } else{
                printf("create 4 digit otp : ");
                scanf("%d",&pin1);
                printf("enter otp again : ");
                scanf("%d",&pin2);
                if(pin1==pin2){
                        printf("creating account \n");
                        if(founded==0) pin2=10000;
                        else pin2=all[founded-1].loginId+1;
                        all[founded].loginId=pin2; all[founded].pin=pin1;
                        founded++;
                        fil=fopen("database.txt","w");
                        fprintf(fil,"%d\n",founded);
                        for(int i=0; i<founded; i++) fprintf(fil,"%d %d\n",all[i].loginId,all[i].pin);
                        fclose(fil);
                        printf("your id is  %d",pin2);
                        return pin2;
                }
                else printf("otp not matched\n");
            }
        }

    }
}

void sendMessage(int id,char *message,int current){
    printf("%s",message);
    int total=0;
    char fileName[10];
    FILE *fil;
    for(int i=3; i>-1; i--) { fileName[i]=(id%10)+48; i/=10;}
    fileName[4]='.';  fileName[5]=fileName[7]='t'; fileName[6]='x';
    fil=fopen(fileName,"r");
    fscanf(file,"%d",&total);
    // print this

}

void receivedMessage(int id){
    int total=0;
    char fileName[10];
    FILE *fil;
    for(int i=3; i>-1; i--) { fileName[i]=(id%10)+48; i/=10;}
    fileName[4]='.';  fileName[5]=fileName[7]='t'; fileName[6]='x';
    fil=fopen(fileName,"r");
    fscanf(file,"%d",&total);
    if(total!=0){
        //take all message
        fclose(fil);
    }
    if(total>received){
        //print all message
    }
}

void deleteMessage(int id,part){
    int total=0;
    char fileName[10];
    FILE *fil;
    for(int i=3; i>-1; i--) { fileName[i]=(id%10)+48; i/=10;}
    fileName[4]='.';  fileName[5]=fileName[7]='t'; fileName[6]='x';
    fil=fopen(fileName,"r");
    fscanf(file,"%d",&total);
    //delete this
}
int received=0;
void main()
{
    int id=0;
    if(id!=-1){
        printf("********welcome to chats******press 9 for refress\n\n");
        receivedMessage()
    }
    int j=9;
    sendMessage(2,"umnag",4);
}
