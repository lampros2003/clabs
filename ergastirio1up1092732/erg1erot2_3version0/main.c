#include <stdio.h>
#include <stdlib.h>
void drawsquare(int sizeofshape,char charofshape);
void drawrhombus(int sizeofshape,char charofshape);
void draworthtrig(int sizeofshape,char charofshape);
void drawisotrig(int sizeofshape,char charofshape);
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
void drawchooser(void)
{
    int exitvar =0;
    int choicevar;
    int sizeofshape;
    char charofshape;

    while (exitvar == 0)
    {
        choicevar = getchoice();
        sizeofshape =getsize();
        charofshape= getinputchar();
        switch(choicevar)
        {
        case 0:
            drawsquare( sizeofshape ,charofshape);
            break;
        case 1:
            drawrhombus(sizeofshape ,charofshape);
            break;
        case 2 :
            draworthtrig(sizeofshape ,charofshape);
            break;
        case 3 :
            drawisotrig(sizeofshape ,charofshape);
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
int getsize(void)
{
    printf("getsize\n");
    return 0 ;
}
char getinputchar(void)
{
    printf("getinputchar\n");
    return '0';
}
void drawsquare(int sizeofshape,char charofshape)
{

    printf("drawsquare\n");
}
void drawrhombus(int sizeofshape,char charofshape)
{

    printf("drawrhombus\n");
}
void draworthtrig(int sizeofshape,char charofshape)
{

    printf("drawotrhtrig\n");
}
void drawisotrig(int sizeofshape,char charofshape)
{

    printf("draisotrig\n");
}
