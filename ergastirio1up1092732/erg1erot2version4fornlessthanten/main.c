#include <stdio.h>
#include <stdlib.h>

int rhombusprep(int);/*μετατρέπει κατάλληλα το όρισμα ω΄στε να μπορεί να εκτυπώνει ρόμβο*/
char inttochar(int);/*με αυτή την συνάρτηση μπορώ να χρησημοποίσω τις ίδιες συναρτήσεις με τα άλλα ερωτήματα κάνοντας τον αριθμό της γραμμής χαρακτήρα */
void drawsquare(char charofshape,int shapesize);
void drawrhombus(char charofshape,int shapesize);
void draworthtrig(char charofshape,int shapesize);
void drawisotrig(char charofshape,int shapesize,int isrhombus);
int getchoice(void);
int getsize(void);
char getinputchar(void);
void drawchooser(void);
void printempty(int start,int stop,char charofshape);/*το printempτy και printfull ειναι συναρτήσεις που μποερέι να χρησημοποιείη κάθε συναρτηση*/
void printfull(int length,char charofshape);
void inverseisotrig(char charofshape,int shapesize);


int main()
{

    drawchooser();
    return 0;
}
char inttochar(int number){
char character;
character = number +'0';
return character;
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
    int shapesize;
    char charofshape;
    while (exitvar == 0)
    {

        choicevar = getchoice();

        shapesize = getsize();
        charofshape ='0';
        switch(choicevar)
        {
        case 0:
            drawsquare( charofshape, shapesize);
            break;
        case 1:
            drawrhombus( charofshape, shapesize);
            break;
        case 2 :
            draworthtrig(charofshape,shapesize);
            break;
        case 3 :
            drawisotrig(charofshape, shapesize,0);
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

return num;}

void printempty(int start,int stop,char charofshape){
    int i;
    printf("%c",charofshape);

    for(i=start ; i< stop;i++){
        printf("-");
    }

    printf("%c",charofshape);
    printf("\n");

}
void printfull(int length,char charofshape){
    int i ;
    for(i=0;i<length;i++){
        printf("%c",charofshape);
    }
    printf("\n");
}

void drawsquare(char charofshape,int shapesize)
{
    int i =1 ;
    printfull(shapesize,inttochar(i));
    for(i=1;i<=shapesize-2;i++){
        printempty(0,shapesize-2,inttochar(i+1));
    }
    printfull(shapesize,inttochar(i+1));


}

void drawrhombus(char charofshape,int shapesize)
{
    int y;
    int x1,x2;

    shapesize = rhombusprep(shapesize);/* με αυτη την μετατροπή θα επιτύχω τον σχεδιασμο ρόμβου ανεξαρτητα με το αν είναι μονό ή ζυγο το input
    που θα έχει διαμετρο getsize αν το getsize είναι περριτο και getsize+1 αρτίο*/

    /*δεν συμπεριλαμβάνω τις παύλες που υπηρχαν στο παράδειγμα ώστε το σχήμα να είναι ρόμβος όπως ζητά η εκφώνηση και για
    να μπορώ να χρησημοποιήσω την drawisotrig*/
    drawisotrig( charofshape,shapesize,1);

    inverseisotrig( charofshape, shapesize);
   return;

}

void draworthtrig(char charofshape,int shapesize)
{
    int y;
    int x1,x2;
    x2 =0;
    y = 0 ;
    /*unused code from isotrig
    /*for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }*/
    printf("%c\n",inttochar(y+1));
    for(y = 1;y<shapesize-1;y++){
        /*for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }*/


        printempty(0,y-1,inttochar(y+1));
        x2++;


   }

   printfull(y+1,inttochar(y+1));



}

void drawisotrig(char charofshape,int shapesize ,int isrhombus)
{
    int y;
    int x1,x2;
    x2 =0;
    y = 0 ;




    for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }
    printf("%c\n",inttochar(y+1));
    for(y = 1;y<shapesize-1;y++){
        for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }


        printempty(0,x2+y,inttochar(y+1));
        x2++;


   }
   if(!isrhombus){
    printf(" ");
    printfull(2*(y+1)-1,inttochar(y+1));}

   else{
    printf(" ");
    printempty(0,x2+y,inttochar(y+1));


   }

}
/*η συνάρτηση δεν είναι ακριβώς ισοσκελές τριγωνο καθώς χρειάζεται μόνο για τον ρόμβο( δεν βολεύει να λειτουργήσει με printempty)*/
void inverseisotrig(char charofshape,int shapesize){
    int y,x2,x1;
    int ycounter;
    ycounter = shapesize-1;
    for(y = shapesize-1;y>0;y--){
        for(x1=y;x1<=shapesize;x1++){
            printf(" ");
        }
        for(x2 = 0;x2<(y*2)-1;x2++){
            if (x2 ==0 || x2 ==(y*2)-2||y==0)
            {
                printf("%c",inttochar(ycounter+2));
            }
            else{printf("-");}

        }
        printf("\n");
        ycounter++;
   }

}

