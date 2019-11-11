#include <stdio.h>
void nizaProst(int niza[],int n);
int main()
{
    int n,i,niza[1000];
    printf("Vnesi broj N \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        niza[i]=1;
    }
    nizaProst(niza,n);
    printf("Prosti broevi do n se : \n");
    for(i=0;i<n;i++)
    {
        if(niza[i]==0)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}

void nizaProst(int niza[],int n)
{
    int i,j;

    for(i=3;i<n;i++){
        for(j=2;j<i;j++){
            if(i%j==0){
                niza[i]=1;
                break;
            }
            else {
                niza[i]=0;
            }
        }
    }
}
