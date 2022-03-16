#include <stdio.h>
#include <stdlib.h>
void drawsquare(void);
void drawrhombus(void);
void draworthtrig(void);
void drawisotrig(void);
int getchoice(void);
int getsize(void);
char getinputchar(void);
void drawchooser(void);

int main()
{
    drawchooser();
    return 0;
}
int getchoice(void)
{
    int userchoice;
    printf("Please input number to print corresponding shape \n");
    printf("0:square 1:rhombus 2:orthogonal triangle 3: isosceles triangle 4: exit 5: clear the console\n");
    scanf("%d",&userchoice);
    return userchoice;
}
void drawchooser(void)
{
    int exitvar =0;
    int choicevar;
    while (exitvar == 0)
    {

        choicevar = getchoice();
        switch(choicevar)
        {
        case 0:
            drawsquare();
            break;
        case 1:
            drawrhombus();
            break;
        case 2 :
            draworthtrig();
            break;
        case 3 :
            drawisotrig();
            break;
        case 4:
            exitvar++;
            break;
        case 5:
            system("cls");

            break;
        default:

            printf("invalid input\n");

            choicevar = 5;
            break;


        }
    }
}
int getsize(void)
{
    int intreturn;
    printf("Please input an integer");
    scanf("%d",&intreturn);
    return intreturn;

}
char getinputchar(void)
{

    char charreturn;
    printf("Please input a character");
    scanf("\n%c",&charreturn);

    return charreturn;
}
void drawsquare(void)
{
    int x;
    int y;
    int shapesize;
    char charofshape;
    shapesize = getsize();
    charofshape =getinputchar();
    for(y=0;y<shapesize;y++)
    {
        for(x=0;x<shapesize;x++)
        {
            if (x ==0 || x == shapesize-1||y==0||y==shapesize-1)
            {
                printf("%c",charofshape);
            }
            else{printf("-");}
        }
        printf("\n");
    }

}
void drawrhombus(void)
{
    int y;
    int x;
    int shapesize;
    int truesize;
    char charofshape;
    shapesize = getsize();
    truesize = (shapesize*2-1);
    charofshape =getinputchar();
    for(y=0;y<shapesize/2;y++)
    {
        for(x=0;x<truesize;x++){
            if (x==shapesize-1+y||x==shapesize-1-y){
                printf("%c",charofshape);
            }
            else{
                if(x>shapesize-1-y&&x<shapesize-1+y){
                        printf("-");}
                else{
                    if(x <shapesize/2-y)
                    {printf(" ");}
                }

            }

        }

        printf("\n");
    }
    for(y=shapesize/2;y>=0;y--){
        for(x=0;x<truesize;x++){
            if (x==shapesize-1+y||x==shapesize-1-y){
                printf("%c",charofshape);
            }
            else{
                if(x>shapesize-1-y&&x<shapesize-1+y){
                        printf("-");}
                else{
                    if(x <shapesize/2-y)
                    {printf(" ");}
                }
            }

        }
        printf("\n");
    }

}
void draworthtrig(void)
{
    int y;
    int x;
    int shapesize;
    char charofshape;
    shapesize = getsize();
    charofshape =getinputchar();
    for(y=0;y<shapesize;y++)
    {
        for(x=0;x<shapesize;x++)
        {
            if(x == 0 || y==shapesize-1||x==y)
            {
              printf("%c",charofshape);
            }
            else{
                if(x<y){
                    printf("-");
                }
            }



        }
        printf("\n");
    }

}
void drawisotrig(void)
{
    int y;
    int x;
    int shapesize;
    int truesize;
    char charofshape;
    shapesize = getsize();
    truesize = shapesize*2 -1;
    charofshape =getinputchar();
    for(y=0;y<shapesize;y++)
    {
        for(x=0;x<truesize;x++){
            if (y == shapesize-1|| x ==shapesize-1-y||x == shapesize-1+y)
            {
                printf("%c",charofshape);
            }
            else{
                if(x>shapesize-1-y && x<shapesize-1+y){
                    printf("-");

                }
                else{printf(" ");}
            }
        }
        printf("\n");
    }

}
