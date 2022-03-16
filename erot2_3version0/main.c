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
    printf("0:square 1:rhombus 2:orthogonal triangle 3: isosceles triangle 4: exit\n");
    scanf("%i",&userchoice);
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
}
char getinputchar(void)
{
    printf("getinputchar\n");
}
void drawsquare(void)
{
    getsize();
    getinputchar();
    printf("drawsquare\n");
}
void drawrhombus(void)
{
    getsize();
    getinputchar();
    printf("drawrhombus\n");
}
void draworthtrig(void)
{
    getsize();
    getinputchar();
    printf("drawotrhtrig\n");
}
void drawisotrig(void)
{
    getsize();
    getinputchar();
    printf("draisotrig\n");
}
