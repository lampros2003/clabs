#include <stdio.h>
#include <stdlib.h>
/*μετέτρεψα τις συναρτήσεις ώστε να δέχονται το μεγεθος και χαρακτήρα ως ορίσματα για να μπορούν να καούν η μια την άλλη*/

int rhombusprep(int);
void drawsquare(int intofline,int shapesize);
void drawrhombus(int intofline,int shapesize);
void draworthtrig(int intofline,int shapesize);
void drawisotrig(int intofline,int shapesize,int isrhombus);
int getchoice(void);
int getsize(void);
char getinputchar(void);
void drawchooser(void);
void printempty(int start,int stop,int intofline);/*το printempτy και printfull ειναι συναρτήσεις που μποερέι να χρησημοποιείη κάθε συναρτηση*/
void printfull(int length,int intofline);
void inverseisotrig(int intofline,int shapesize);


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
    int shapesize;
    int intofline;
    while (exitvar == 0)
    {

        choicevar = getchoice();

        shapesize = getsize();
        /*intofline =getinputchar(); useless*/
        switch(choicevar)
        {
        case 0:
            drawsquare( intofline, shapesize);
            break;
        case 1:
            drawrhombus( intofline, shapesize);
            break;
        case 2 :
            draworthtrig(intofline,shapesize);
            break;
        case 3 :
            drawisotrig(intofline, shapesize,0);
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

void printempty(int start,int stop,int intofline){
    int i;
    printf("%i",intofline+1);
    if (intofline <9){
    for(i=start ; i< stop;i++){
        printf("-");
    }}
    else{if(intofline <99){
            for(i=start ; i< stop-2;i++){
                printf("-");
        }}
        else{
            for(i=start ; i< stop-4;i++){
                printf("-");
        }}}

    printf("%i",intofline+1);
    printf("\n");

}
void printfull(int length,int intofline){
    int i ;
    if (intofline <9){
        for(i=0;i<length;i++){
        printf("%i",intofline+1);
        }}
    else{if(intofline <99){
            for(i=0;i<length/2;i++){
            printf("%i",intofline+1);
        }}
        else{
            for(i=0;i<length/3;i++){
            printf("%i",intofline+1);
        }}}
printf("\n");}

void drawsquare(int intofline,int shapesize)
{
    int i =0 ;
    printfull(shapesize,i);
    for(i=1;i<=shapesize-2;i++){
        printempty(0,shapesize-2,i);
    }
    printfull(shapesize,i);;


}

void drawrhombus(int intofline,int shapesize)
{


    shapesize = rhombusprep(shapesize);/* με αυτη την μετατροπή θα επιτύχω τον σχεδιασμο ρόμβου ανεξαρτητα με το αν είναι μονό ή ζυγο το input
    που θα έχει διαμετρο getsize αν το getsize είναι περριτο και getsize+1 αρτίο*/

    /*δεν συμπεριλαμβάνω τις παύλες που υπηρχαν στο παράδειγμα ώστε το σχήμα να είναι ρόμβος όπως ζητά η εκφώνηση και για
    να μπορώ να χρησημοποιήσω την drawisotrig*/
    drawisotrig( 0,shapesize,1);

    inverseisotrig( 0, shapesize);
   return;

}

void draworthtrig(int intofline,int shapesize)
{
    int y;
    int x1,x2;
    x2 =0;
    y = 1 ;
    /*unused code from isotrig
    /*for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }*/
    printf("%i\n",y);
    for(y = 1;y<shapesize-1;y++){
        /*for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }*/


        printempty(0,y-1,y);
        x2++;


   }

   printfull(y+1,y);



}

void drawisotrig(int intofline,int shapesize ,int isrhombus)
{
    int y;
    int x1,x2;
    x2 =0;
    y = 1 ;




    for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }
    printf(" %i\n",y);
    for(y = 1;y<=shapesize-2;y++){
        for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }


        printempty(0,x2+y,y);
        x2++;


   }
   if(!isrhombus){
    printf(" ");
    printfull(2*(y+1)-1,y);}

   else{
    printf(" ");
    printempty(0,x2+y,y);


   }

}
/*η συνάρτηση δεν είναι ακριβώς ισοσκελές τριγωνο καθώς χρειάζεται μόνο για τον ρόμβο( δεν βολεύει να λειτουργήσει με printempty)*/
void inverseisotrig(int intofline,int shapesize){
    int y,x2,x1,ycounter;
    ycounter=shapesize+1;
    for( y = shapesize-1;y>0;y-- ,ycounter++){
        for(x1=y;x1<=shapesize;x1++){
            printf(" ");
        }
        for(x2 = 0;x2<(y*2)-1;x2++){
            if (x2 ==0 || x2 ==(y*2)-2||y==0)
            {
                printf("%i",ycounter);
            }
            else{printf("-");}
        }
        printf("\n");
   }

}
