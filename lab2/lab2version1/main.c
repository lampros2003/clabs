#include <stdio.h>
#include <stdlib.h>
#define M 10
#define N 20
#define timequantum 1
/*οι μεταβλητες ονομάστηκαν με την εξής λογική: t: temperature , r : right side l:left side t:top b bottom,in inside
exaple : ttr temperature top right corner
*/
double tempgetter(void);
void plakamaker(double ttr,double ttl,double tbr,double tbl, double tin,double plaka[N][M]);
void textgiver(void);
void plakaprinter(double plaka[N][M]);
void plakachanger(double plaka[N][M],int quantum);
int main()
{
    double ttr,ttl,tbr,tbl,tin,plaka[N][M];
    textgiver();

    ttr = tempgetter();
    ttl = tempgetter();
    tbr = tempgetter();
    tbl = tempgetter();
    tin = tempgetter();
    plakamaker( ttr, ttl, tbr, tbl,  tin,plaka);
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
void plakamaker(double ttr,double ttl,double tbr,double tbl, double tin,double plaka[N][M])
{

    int i,j ;

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            plaka[i][j]= tin;
        }
    }
    plaka[0][0]=ttl;
    plaka[0][M-1]=ttr;
    plaka[N-1][0]=tbl;
    plaka[N-1][M-1]=tbr;

    return;
}
void textgiver(void){
    printf("lorem ipsum\n");
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

