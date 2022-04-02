#include <stdio.h>
#include <stdlib.h>
int rhombusprep(int);
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
    printf("0:square 1:rhombus 2:orthogonal triangle 3: isosceles triangle 4: exit(your next inputs wont be used) 5: clear console\n");
    scanf("%d",&userchoice);
    return userchoice;
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
        shapesize = getsize();
        charofshape = getinputchar();
        switch(choicevar)
        {
        case 0:
            drawsquare(charofshape,shapesize);
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
int rhombusprep(int num){

    num = num/2+1;

    return num;
}
void drawsquare(char charofshape,int shapesize)
{
    int x;
    int y;

    for(y=1;y<=shapesize;y++)
    {
        for(x=1;x<=shapesize;x++)
        {
            if (x ==1 || x == shapesize||y==1||y==shapesize)
            {
                printf("%c",charofshape);
            }
            else{printf("-");}
        }
        printf("\n");
    }

}

void drawrhombus(char charofshape,int shapesize)
{
    int y;
    int x1,x2;

    shapesize = rhombusprep(shapesize);
    /* με αυτη την μετατροπή θα επιτύχω τον σχεδιασμο ρόμβου ανεξαρτητα με το αν είναι μονό ή ζυγο το input
    που θα έχει διαμετρο getsize αν το getsize είναι περριτο και getsize+1 αρτίο*/
    for(y = 0;y<=shapesize;y++){
        for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }
        for(x2 = 0;x2<(y*2)-1;x2++){
            if (x2 ==0 || x2 ==(y*2)-2||y==0)
            {
                printf("%c",charofshape);
            }
            else{printf("-");}
        }
        printf("\n");
   }
    for(y = shapesize-1;y>0;y--){
        for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }
        for(x2 = 0;x2<(y*2)-1;x2++){
            if (x2 ==0 || x2 ==(y*2)-2||y==0)
            {
                printf("%c",charofshape);
            }
            else{printf("-");}
        }
        printf("\n");
   }
   return;

}

void draworthtrig(char charofshape,int shapesize)
{
    int y;
    int x2;

    for(y = 0;y<=shapesize;y++){
       /* for(x1=y;x1<shapesize;x1++){
            printf(" ");
        } δεν χρησημοποιηται απλα για να θυμαμαι οτι είναι ιδιο με το ισοσκελες εκτος απο αυτο το βημα*/
        for(x2 = 0;x2<y;x2++){
            if (x2 ==0 || x2 ==y-1||y==0||y==shapesize)
            {
                printf("%c",charofshape);
            }
            else{printf("-");}
        }
        printf("\n");
   }
}
void drawisotrig(char charofshape,int shapesize)
{
    int y;
    int x1,x2;

    for(y = 0;y<=shapesize;y++){
        for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }
        for(x2 = 0;x2<(y*2)-1;x2++){
            if (x2 ==0 || x2 ==(y*2)-2||y==0||y==shapesize)
            {
                printf("%c",charofshape);
            }
            else{printf("-");}
        }
        printf("\n");
   }


}
