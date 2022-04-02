#include <stdio.h>
#include <stdlib.h>
void drawsquare(char charofshape,int shapesize);
void drawrhombus(char charofshape,int shapesize);
void draworthtrig(char charofshape,int shapesize);
void drawisotrig(char charofshape,int shapesize);
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
    printf("0:square 1:rhombus 2:orthogonal triangle 3: isosceles triangle 4: exit(your next inputs wont be used)\n");
    scanf("%i",&userchoice);
    return userchoice;
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

void drawchooser(void)
{
    int exitvar =0;
    int choicevar;

    char charofshape;
    int shapesize;

    while (exitvar == 0)
    {
        choicevar = getchoice();
        shapesize =getsize();
        charofshape= getinputchar();
        switch(choicevar)
        {
        case 0:
            drawsquare( charofshape,shapesize);
            break;
        case 1:
            drawrhombus(charofshape,shapesize);
            break;
        case 2 :
            draworthtrig(charofshape,shapesize);
            break;
        case 3 :
            drawisotrig(charofshape,shapesize);
            break;
        case 4:
            exitvar++;
            break;
        default:
            system("cls");
            printf("invalid input\n");
            break;

        }
    }
}

void drawsquare(char charofshape,int shapesize)
{
    int i ;
    for(i=0;i<shapesize;i++){
            printf("%c",charofshape);}

    printf("drawsquare\n");
}
void drawrhombus(char charofshape,int shapesize)
{
    int i ;
    for(i=0;i<shapesize;i++){
            printf("%c",charofshape);}

    printf("drawrhombus\n");
}
void draworthtrig(char charofshape,int shapesize)
{
    int i ;
    for(i=0;i<shapesize;i++){
            printf("%c",charofshape);}

    printf("drawotrhtrig\n");
}
void drawisotrig(char charofshape,int shapesize)
{
    int i ;
    for(i=0;i<shapesize;i++){
            printf("%c",charofshape);}

    printf("drawisotrig\n");
}
