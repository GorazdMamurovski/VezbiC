#include <stdio.h>
// Zadacata e resena pod B so rekurzija
void rek(int n,int m,int s,int flag);
int main()
{
    int n;
    printf("Vnesi broj n \n");
    scanf("%d",&n);
    rek(n,n,1,1);
    return 0;
}
void rek(int n,int m,int s,int flag){
    if(m==0 && flag==1){
        flag = 0;
        m=n;
    }
    if(flag==0 && m==0){
        return;
    }
    if(m>0){
        if(flag==1){
            for(int i=0;i<=n;i++){
                if(i>=m){
                    printf("%d ",i);
                }
            }
            printf("\n");
            rek(n,m-1,s,1);
        }
        if(flag==0){
            for(int i=0;i<=n;i++){
                if(i>s)
                {
                    printf("%d ",i);
                }
            }
            printf("\n");
            rek(n,m-1,s+1,0);
        }

    }
}

