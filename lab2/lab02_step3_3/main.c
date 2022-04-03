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
void normprinter(int plaka[N][M],int time );
void plakachanger(double plaka[N][M],int * time,int * checkvariable);
double meanvalue(double num1,double num2);
void isbigorsmall(double * big,double *small,double input );
void plakanormalizer(double plaka[N][M], int normplaka[N][M],double big ,double small);
void histoprinter(int normplaka[N][M],int timetostop);
int main()
{
    double tr,tl,tb,tt,tin,plaka[N][M];
    double big , small;

    int time = 0,checkvariable =0,timetostop,normplaka[N][M],i;
    textgiver();
    tt = tempgetter();
    big = tt;
    small = tt;
    tr = tempgetter();
    isbigorsmall(&big,&small,tr);
    tb = tempgetter();
    isbigorsmall(&big,&small,tb);
    tl = tempgetter();
    isbigorsmall(&big,&small,tl);
    tin = tempgetter();
    isbigorsmall(&big,&small,tin);
    printf("please give a time when you would like to see the state of the object");
    scanf("%i",&timetostop);
    printf("initial state\n");
    plakamaker( tt, tl, tb, tr,  tin,plaka);
    plakanormalizer(plaka,normplaka,big,small);
    normprinter(normplaka,time);
    for(i=0;i<timetostop;i++){
       plakachanger(plaka,&time,&checkvariable);
    plakanormalizer(plaka,normplaka,big,small);
    }
    histoprinter(normplaka,timetostop);
    while (!checkvariable){
        plakachanger(plaka,&time,&checkvariable);
        plakanormalizer(plaka,normplaka,big,small);




    }
    printf("\nsteady state!\n");
    normprinter(normplaka,time);




    return 0;
}
void histoprinter(int normplaka[N][M],int timetostop)
{
    int i,j,histovalues[10];
    for(i=0; i<10; i++)
    {
        histovalues[i]=0;
    }
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            switch (normplaka[i][j])
            {
            case 0:
                histovalues[0]++;
                break;
            case 1:
                histovalues[1]++;
                break;
            case 2:
                histovalues[2]++;
                break;
            case 3:
                histovalues[3]++;
                break;
            case 4:
                histovalues[4]++;
                break;
            case 5:
                histovalues[5]++;
                break;
            case 6:
                histovalues[6]++;
                break;
            case 7:
                histovalues[7]++;
                break;
            case 8:
                histovalues[8]++;
                break;
            case 9:
                histovalues[9]++;
                break;
            }
        }

    }
    printf("at the %i time quantum \n",timetostop);
    for(i=0;i<10;i++){
        printf("elements of value %i :%i ",i,histovalues[i]);
        for(j=0;j<histovalues[i];j++){
            printf("=");
        }
        printf("\n");
    }

}

void normprinter(int plaka[N][M],int time ){
    int i,j;
    printf("time : %i\n",time);
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("|%i|  ",plaka[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

}
void isbigorsmall(double * big,double * small,double input){
        if(input > *big){
            *big = input;
        }
        else{
            if(input < *small){
                    *small = input;
            }
        }
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
            printf("|%5.2f|  ",plaka[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

}
void plakachanger(double plaka[N][M],int * time,int * checkvariable){

    double newplaka[N][M],sumofchange;
    int i,j;
    *time += timequantum;

    for( i = 1; i < N-1; i++){
        for( j = 1; j < M-1; j++){
            newplaka[i][j] = 0.1 * (plaka[i-1][j-1] + plaka[i-1][j] + plaka[i-1][j+1] + plaka[i][j-1] + 2 * plaka[i][j] + plaka[i][j+1] + plaka[i+1][j-1] + plaka[i+1][j] + plaka[i+1][j+1]);
        }
    }
    for( i = 1; i <N-1; i++){
        for( j = 1; j < M-1; j++){
            sumofchange += fabs(plaka[i][j] - newplaka[i][j]);
            plaka[i][j] = newplaka[i][j];
        }
    }
    if(sumofchange<=1){
        *checkvariable = 1;
    }
}
void plakanormalizer(double plaka[N][M], int normplaka[N][M],double big,double small){

    int i,j ;
    for( i = 0; i < N; i++){
        for( j = 0; j < M; j++){
            normplaka[i][j] = (int)((plaka[i][j] - small) / (big - small) * 9);
        }
    }
}
