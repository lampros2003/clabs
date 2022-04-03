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
void plakaprinter(double plaka[N][M]);
void plakachanger(double plaka[N][M],int quantum);
double meanvalue(double oneval ,double twoval);
int main()
{
    double tr,tt,tb,tl,tin,plaka[N][M];
    textgiver();
    tt = tempgetter();
    tr = tempgetter();

    tb = tempgetter();
    tl = tempgetter();
    tin = tempgetter();
    plakamaker( tr, tl, tb, tt,  tin,plaka);
    plakaprinter(plaka);
    plakachanger(plaka,timequantum);
    return 0;
}
double meanvalue(double oneval ,double twoval){
    double mean ;
    mean = (double)(oneval + twoval)/2;
    return mean;


}
double tempgetter(void)
{
    double tempgotten;
    printf("input a temp");

    scanf("%lf", &tempgotten);
    return (double)tempgotten;

}
void plakamaker(double tr,double tl,double tb,double tt, double tin,double plaka[N][M])
{

    int i,j ;

    for(i=1 ;i<N-1;i++){
        plaka[i][0]=tl;
        plaka[i][M-1]=tr;
        }
    for(j=1; j<M-1; j++)
        {
            plaka[0][j]= tt;
            plaka[N-1][j] = tb;
        }
    for(i=1; i<N-1; i++)
    {

        for(j=1; j<M-1; j++)
        {
            plaka[i][j]= tin;
        }
    }
    plaka[N-1][M-1] = meanvalue(tr,tb);
    plaka[0][0]=meanvalue(tt,tl);
    plaka[N-1][0]=meanvalue(tb,tl);
    plaka[0][M-1]=meanvalue(tr,tt);


    return;
}
void textgiver(void){
    printf("Please input the temperatures of the sides of the object in clockwise order staring from the top and then input the initial inside temperature of the object \n");
}
void plakaprinter(double plaka[N][M] ){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("|%6.4lf|   ",plaka[i][j]);
        }
        printf("\n");
    }

}
void plakachanger(double plaka[N][M],int quantum){
    printf("plaka changed!");

}




