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
int main()
{
    double tr,tl,tb,tt,tin,plaka[N][M];
    textgiver();

    tt = tempgetter();
    tl = tempgetter();
    tb = tempgetter();
    tr = tempgetter();
    tin = tempgetter();
    plakamaker( tt, tl, tb, tr,  tin,plaka);
    plakaprinter(plaka);
    plakachanger(plaka,timequantum);
    return 0;
}
double tempgetter(void)
{
    double tempgotten;
    printf("input a temp");

    scanf("%lf", &tempgotten);
    return (double)tempgotten;

}
void plakamaker(double tt,double tl,double tb,double tr, double tin,double plaka[N][M])
{

    int i,j ;
    for(i=1;i<N;i++){
        plaka[i][0] = tl    ;
        plaka[0][i] = tt;
        plaka[N-1][i] = tb;
        plaka[i][M-1] = tr;
    }
    for(i=1; i<N-1; i++)
    {
        for(j=1; j<M-1; j++)
        {
            plaka[i][j]= tin;
        }
    }


    return;
}
void textgiver(void){
    printf("top left bottom right\n");
}
void plakaprinter(double plaka[N][M] ){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("|%.4lf|   ",plaka[i][j]);
        }
        printf("\n");
    }

}
void plakachanger(double plaka[N][M],int quantum){
    printf("plaka changed!");

}

