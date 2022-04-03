#include <stdio.h>
#include <stdlib.h>
#define M 10
#define N 20
#define timequantum 1
/*οι μεταβλητες ονομάστηκαν με την εξής λογική: t: temperature , r : right side l:left side t:top b bottom,in inside
exaple : tt temperature top
*/
double tempgetter(void);
void plakamaker(double ttr,double ttl,double tbr,double tbl, double tin,double plaka[N][M]);
void textgiver(void);
void plakaprinter(double plaka[N][M],int time);
void plakachanger(double plaka[N][M],int * time);
double meanvalue(double num1,double num2);
int main()
{
    double tr,tl,tb,tt,tin,plaka[N][M];

    int time;
    textgiver();
    tt = tempgetter();
    tr = tempgetter();
    tb = tempgetter();
    tl = tempgetter();
    tin = tempgetter();
    plakamaker( tt, tl, tb, tr,  tin,plaka);
    plakaprinter(plaka,time);
    plakachanger(plaka,&time);
    plakaprinter(plaka,time);
    return 0;
}
double meanvalue(double num1,double num2){
    double returnvalue;
    returnvalue = (num1+num2)/2;
    return returnvalue;

}
double tempgetter(void){
    double tempgotten;
    printf("input a temp");

    scanf("%lf", &tempgotten);
    return (double)tempgotten;

}
void plakamaker(double tt,double tl,double tb,double tr, double tin,double plaka[N][M]){

    int i,j ;
    for(i=1;i<N;i++){
        plaka[i][0] = tl    ;

        plaka[i][M-1] = tr;
    }
    for(j=1;j<M;j++){

        plaka[0][j] = tt ;
        plaka[N-1][j] = tb;
    }



    for(i=1; i<N-1; i++)
    {
        for(j=1; j<M-1; j++)
        {
            plaka[i][j]= tin;
        }
    }
    plaka[0][0]= meanvalue(tt,tl);
    plaka[N-1][0]= meanvalue(tb,tl);
    plaka[0][M-1] = meanvalue(tr,tt);
    plaka[N-1][M-1] = meanvalue(tr,tt);




    return;
}
void textgiver(void){
    printf("Please input tempratures in a clockwise order starting from the top\n");
}
void plakaprinter(double plaka[N][M],int time ){
    int i,j;
    printf("time : %i\n",time);
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("|%6.4f|   ",plaka[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

}
void plakachanger(double plaka[N][M],int * time){

    double newplaka[N][M];
    int i,j;
    *time += timequantum;

    for( i = 1; i < N-1; i++){
        for( j = 1; j < M-1; j++){
            newplaka[i][j] = 0.1 * (plaka[i-1][j-1] + plaka[i-1][j] + plaka[i-1][j+1] + plaka[i][j-1] + 2 * plaka[i][j] + plaka[i][j+1] + plaka[i+1][j-1] + plaka[i+1][j] + plaka[i+1][j+1]);
        }
    }
    for( i = 1; i <N-1; i++){
        for( j = 1; j < M-1; j++){
            plaka[i][j] = newplaka[i][j];
        }
    }
}
