#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int length=26,width=70,x,y,fruitx,fruity,key,score=0,gameover;
void foodreplace()
{
    if(x==fruitx && y==fruity)
    {
        score++;
        elements();
    }
}

void button()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'w':
              key=1;
              break;
            case 'a':
              key=2;
              break;
             case 's':
              key=3;
              break;
              case 'd':
              key=4;
              break;
        }
    }
}
void logic()
{
    switch(key)
    {
    case 1:
        x--;
        break;
      case 2:
        y--;
        break;
      case 3:
        x++;
        break;
      case 4:
        y++;
        break;

    }

}
void elements()
{
    if(key!=1 && key!=2 && key!=3 && key!=4)
    {

    x=length/2;
    y=width/2;
    }

    label1:
    fruitx=rand()%20;
    if(fruitx==0)
        goto label1;

    label2:
    fruity=rand()%20;
    if(fruity==0)
        goto label2;
}
void structure()
{
    system("cls");
    int i,j;
    for(i=0;i<=length;i++)
    {
        for(j=0;j<=width;j++)
        {
            if(i==0 || i==length || j==0 || j==width)
                printf("*");
            else if(i==x && j==y)
            {

                if(key==1)
                    printf("^");
                else if(key==2)
                    printf("<");
                else if(key==3)
                    printf("#");
                else
                    printf(">");
            }
            else if(i==fruitx && j==fruity)
            {
                printf("0");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    gameover=0;
     if(x==0 || x==length ||y==0 || y==width)
       {
        printf("Game  over\n");
        gameover=1;
        printf("Score is=%d\n",score);
       }
}
int main()
{
   elements();

   while(gameover!=1)
   {

   button();
   structure();
   logic();
   foodreplace();

   }

   getch();
}
