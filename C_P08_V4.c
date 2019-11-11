#include <stdio.h>
void vnesiMatrica(int matrica[10][10],int i,int j,int r);
void pecatiMatrica(int matrica[10][10],int i,int j,int r);
int t=0;
int main()
{
    int i,j,matrica[10][10],m,n;
    printf("Vnesi Red i Kolina\n");
    scanf("%d%d",&i,&j);
    m=i;
    n=j;
    matrica[i][j];
    vnesiMatrica(matrica,i-1,j-1,n);
    pecatiMatrica(matrica,i-1,j-1,n);
    return 0;
}

void vnesiMatrica(int matrica[10][10],int i,int j,int r){
    if(i==0 && j==0)
    {
        printf("Vnesi broj vo matricata na pozicija\n");
        scanf("%d",&matrica[i][j]);
        return;
    }
    if(j==0)
    {
        printf("Vnesi broj vo matricata na pozicija \n");
        scanf("%d",&matrica[i][j]);
        i=i-1;
        j=r-1;
    }
    printf("Vnesi broj vo matricata na pozicija \n");
    scanf("%d",&matrica[i][j]);
    vnesiMatrica(matrica,i,j-1,r);
}

void pecatiMatrica(int matrica[10][10],int i,int j,int r){
    if(i==0 && j==0)
    {

        printf("%d\n",matrica[i][j]);
        return;
    }
    if(j==0)
    {

        printf("%d\n",matrica[i][j]);
        i=i-1;
        j=r-1;
    }

    printf("%d ",matrica[i][j]);
    pecatiMatrica(matrica,i,j-1,r);
}

