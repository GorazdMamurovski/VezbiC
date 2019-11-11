#include <stdio.h>
// Zadacata e resena pod B so rekurzija
void sort(int niza[20],int);
void sortRek(int niza[], int i, int n);
int main()
{
    int niza1[20]={33,45,4,5,6,23,41,23,6,8,32,1,3,6,8,123,43,2,7,1};
    int niza2[20]={33,45,4,5,6,23,41,23,6,8,32,1,3,6,8,123,43,2,7,1};
    sort(niza1,20);
    for(int i=0;i<20;i++)
    {
        printf("%d ",niza1[i]);
    }
    printf("%\n ");
    sortRek(niza2,0,20);
    for(int i=0;i<20;i++)
    {
        printf("%d ",niza2[i]);
    }
    return 0;
}
void sort(int niza[20],int n){
    int nov;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            if(niza[j]<niza[i]){
                nov=niza[i];
                niza[i]=niza[j];
                niza[j]=nov;
            }
        }
    }
}
void sortRek(int niza[], int i, int n)
{
    int min = 0,nov;
    for(int j=i;j<n;j++){
        if(niza[j]<niza[min]){
            min=j;
        }
    }
    nov=niza[min];
    niza[min]=niza[i];
    niza[i]=nov;
    if(i<n){
        sortRek(niza,i+1,n);
    }
}
