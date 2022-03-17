#include <stdio.h>
#include <stdlib.h>
/*μετέτρεψα τις συναρτήσεις ώστε να δέχονται το μεγεθος και χαρακτήρα ως ορίσματα για να μπορούν να καούν η μια την άλλη*/
char inttocharacter(int)/*με αυτή την συνάρτηση μπορω να πιλύσω το ερώτημα της version 4 χωρις να χρέιαστει να αλλάξω τις σύναρτήσεις που έχω φτιάξει*/
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
char inttocharacter(int num){/*προφανώς η συνάρτηση καθώς και το ερώτημα έψουν νόημα μόνο για num<10 καθώς αν num>10 θα έπιανε δύο ψηφία και τα σχήματα δεν θα μπορούσαν να σχεδιασοτούν*/
char character ;
character = num;
return character;
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
    int shapesize;
    int intofline;
    while (exitvar == 0)
    {

        choicevar = getchoice();

        shapesize = getsize();
        intofline =getinputchar();
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
    printf("%c",i);

    for(i=start ; i< stop;i++){
        printf("-");
    }

    printf("%c",i);
    printf("\n");

}
void printfull(int length,int intofline){
    int i ;
    for(i=0;i<length;i++){
        printf("%c",intofline);
    }
    printf("\n");
}

void drawsquare(int intofline,int shapesize)
{
    int i =0 ;
    printfull(shapesize,intofline);
    for(i=0;i<shapesize-2;i++){
        printempty(0,shapesize-2,intofline);
    }
    printfull(shapesize,intofline);;


}

void drawrhombus(int intofline,int shapesize)
{
    int y;
    int x1,x2;

    shapesize = rhombusprep(shapesize);/* με αυτη την μετατροπή θα επιτύχω τον σχεδιασμο ρόμβου ανεξαρτητα με το αν είναι μονό ή ζυγο το input
    που θα έχει διαμετρο getsize αν το getsize είναι περριτο και getsize+1 αρτίο*/

    /*δεν συμπεριλαμβάνω τις παύλες που υπηρχαν στο παράδειγμα ώστε το σχήμα να είναι ρόμβος όπως ζητά η εκφώνηση και για
    να μπορώ να χρησημοποιήσω την drawisotrig*/
    drawisotrig( intofline,shapesize,1);

    inverseisotrig( intofline, shapesize);
   return;

}

void draworthtrig(int intofline,int shapesize)
{
    int y;
    int x1,x2;
    x2 =0;
    y = 0 ;
    /*unused code from isotrig
    /*for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }*/
    printf("%c\n",intofline);
    for(y = 1;y<shapesize-1;y++){
        /*for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }*/


        printempty(0,y-1,intofline);
        x2++;


   }

   printfull(y+1,intofline);



}

void drawisotrig(int intofline,int shapesize ,int isrhombus)
{
    int y;
    int x1,x2;
    x2 =0;
    y = 0 ;




    for(x1=y;x1<shapesize;x1++){
            printf(" ");
        }
    printf("%c\n",y);
    for(y = 1;y<shapesize-1;y++){
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
/*η συνάρτηση δεν είναι ακριβώς ισοσκελές τριγωνο καθώς χρειάζεται μόνο για τον ρόμβο*/
void inverseisotrig(int intofline,int shapesize){
    int y,x2,x1
    ;
    for(y = shapesize-1;y>0;y--){
        for(x1=y;x1<=shapesize;x1++){
            printf(" ");
        }
        for(x2 = 0;x2<(y*2)-1;x2++){
            if (x2 ==0 || x2 ==(y*2)-2||y==0)
            {
                printf("%c",y);
            }
            else{printf("-");}
        }
        printf("\n");
   }

}
