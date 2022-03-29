#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

void welcomePage();
int TypingPage();
int resultPage();
void getNutral();


/////////////////////////
int UP=72,DOWN=80,LEFT=75,RIGHT=77,ENTER=13; BACKSPACE=8;// key handling
int blue=1,green=10,red=12,yellow=14,black=0,white=15,sky=3;

void setColor(int latter , int backgroud)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    if(backgroud==0|| backgroud>15)    SetConsoleTextAttribute(hcon,latter);
    else    SetConsoleTextAttribute(hcon,(backgroud*16 + latter));
}

int getKey()
{
    char x;
    int k;
    while(!kbhit()){x=getch();}
    x=getch();
    k=x;
    return k;
}

void setconsole(int x,int y)
{
    COORD coord;
    coord.X=x; coord.Y=y;
    HANDLE hhh=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hhh,coord);
}

void rect(int x,int y,int col,int len,int wid)
{
    setconsole(x,y);
    setColor(0,col);
    for(int i=0; i<len; i++) printf(" ");
    for(int j=0; j<wid-2; j++)
    {
        setconsole(x,++y);
        printf("  ");
        setColor(0,col);
        for(int k=0; k<len-4; k++) printf(" ");
        setColor(15,col);
        printf("  ");
    }
    setconsole(x,++y);
    for(int i=0; i<len; i++) printf(" ");
    setColor(7,0);
}




///////////////////////////////////////////////////////////////////

void welcomePage()
{
    getNutral();
    char input;
    int onButton=0;
    rect(20,5,yellow,150,40);
    setColor(0,10);


    //show welcome page
    setconsole(80,10);
    setColor(blue,white);
    printf("                                ");setconsole(80,11);
    printf("    Welcome to Typing master    ");setconsole(80,12);
    printf("                                ");

    setColor(7,0);
    setconsole(150,40);


    //taking input
    do{

        //display button
        //first button
        setconsole(60,23);
        if(onButton==0) setColor(blue,green);
        else setColor(blue,white);
        printf("           ");setconsole(60,24);
        printf("   START   ");setconsole(60,25);
        printf("           ");
        setColor(7,0);
        ///second button
        setconsole(120,23);
        if(onButton==1) setColor(blue,green);
        else setColor(blue,white);
        printf("          ");setconsole(120,24);
        printf("   STOP   ");setconsole(120,25);
        printf("          ");
        setColor(7,0);

        if(onButton==0) setconsole(65,25);
        else setconsole(124,25);


        input=getch();
        if(input==RIGHT){
            onButton++;
            if(onButton>1) onButton=0;
        }
        if(input==LEFT){
            onButton--;
            if(onButton<0) onButton=1;
        }

    }while(input!=ENTER);
    if(onButton==0){
        onButton=TypingPage();
        if(onButton==0) welcomePage();
    }
    else return ;


}


int TypingPage(){
    getNutral();
    int wordTyped=0;
    FILE *txt;
    txt=fopen("sentence.txt","r");
    int totalWord=0;
    int time=60;
    int inaccurate=0;
    int completed=0;
    char textData[500]="Hi I am umang. I'm from kanpur. We are making a typing master game using c++ computer language.This game is easy and easy to play. You just have to do only type the characters from keyboard on screen.";
    totalWord=strlen(textData);
    ///display text and design


    getNutral();
    char input;
    int onButton=0;
    rect(20,5,yellow,150,40);
    setColor(0,10);

    int wpm=0;//char_typed/5;
    int accur=100;//=(accuracy*100)/char_typed;
    //accur-=100;


    //
    setconsole(37,8);
    setColor(blue,white);
    printf("             ");setconsole(37,10);
    printf("             ");setconsole(80,8);
    printf("                   ");setconsole(80,10);
    printf("                   ");setconsole(120,8);
    printf("                    ");setconsole(120,10);
    printf("                    ");

    int tempPrinted=0;
    int templine=20;
    setconsole(37,templine);
    while(tempPrinted!=totalWord){
        printf("%c",textData[tempPrinted]);
        tempPrinted++;
        if(tempPrinted%120==0) setconsole(37,++templine);
    }



    int cursorPositionX=37; int cursorPositionY=20;

    //taking input
    do{

        //display button
        setColor(blue,white);
        setconsole(37,9); printf("  WPM :  %2d  ",wpm);
        setconsole(80,9); printf("  Accuracy : %2d   ",accur);
        setconsole(120,9); printf("  Characters : %3d  ",wordTyped);
        setconsole(cursorPositionX,cursorPositionY);


        input=getch();



        //check correctness
        if(input==BACKSPACE){
            wordTyped--;
            cursorPositionX--;
            if(cursorPositionX<37){
                cursorPositionX=37;
                cursorPositionY--;
                if(cursorPositionY<20) cursorPositionY=20;
            }
            setconsole(cursorPositionX,cursorPositionY);
            setColor(blue,white);
            printf("%c",textData[wordTyped]);
            setColor(7,0);
        }else{

            wordTyped++;
            cursorPositionX++;

            if(cursorPositionX>157){
                cursorPositionX=37;
                cursorPositionY++;
                if(cursorPositionY>23) cursorPositionY=23;
            }
            setconsole(cursorPositionX,cursorPositionY);

            if(textData[wordTyped]==input) setColor(green,white);
            else setColor(red,white);
            printf("%c",textData[wordTyped]);
            setColor(7,0);

        }

    }while(!completed);
    int ret = resultPage(wordTyped,inaccurate);
    return ret;
}

int resultPage(int char_typed,int accuracy,int timepassed){

    getNutral();
    char input;
    int onButton=0;
    rect(20,5,yellow,150,40);
    setColor(0,10);

    int wpm=char_typed/5;
    int accur=(accuracy*100)/char_typed;
    accur-=100;


    //show welcome page
    setconsole(80,10);
    setColor(blue,white);
    printf("                                ");setconsole(80,11);
    printf("           YOUR-RESULT          ");setconsole(80,12);
    printf("                                ");setconsole(37,19);


    printf("             ");setconsole(37,20);
    printf("  WPM :  %2d  ",wpm);setconsole(37,21);
    printf("             ");setconsole(80,19);

    printf("                   ");setconsole(80,20);
    printf("  Accuracy : %2d   ",accur);setconsole(80,21);
    printf("                   ");setconsole(120,19);

    printf("                    ");setconsole(120,20);
    printf("  Characters : %3d  ",char_typed);setconsole(120,21);
    printf("                    ");


    setColor(7,0);
    setconsole(150,40);


    //taking input
    do{

        //display button
        //first button
        setconsole(60,31);
        if(onButton==0) setColor(blue,green);
        else setColor(blue,white);
        printf("             ");setconsole(60,32);
        printf("   RE-PLAY   ");setconsole(60,33);
        printf("             ");
        setColor(7,0);
        ///second button
        setconsole(120,31);
        if(onButton==1) setColor(blue,green);
        else setColor(blue,white);
        printf("            ");setconsole(120,32);
        printf("    STOP    ");setconsole(120,33);
        printf("            ");
        setColor(7,0);

        if(onButton==0) setconsole(65,33);
        else setconsole(125,33);


        input=getch();
        if(input==RIGHT){
            onButton++;
            if(onButton>1) onButton=0;
        }
        if(input==LEFT){
            onButton--;
            if(onButton<0) onButton=1;
        }

    }while(input!=ENTER);
    if(onButton==0) return 0;
    else return 1;
}

void getNutral(){
    setColor(7,0);
    system("cls");

}

int main(){
    printf("Please make full screen  and press enter\n");
    getch();
    //TypingPage();
    welcomePage();
    getNutral();
    exit(0);
}
