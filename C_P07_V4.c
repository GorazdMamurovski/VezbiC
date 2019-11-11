#include <stdio.h>
int nzd(int,int);
int main()
{
    int broj1,broj2;
    printf("vnesi broevi:\n");
    scanf("%d%d",&broj1,&broj2);
    printf("na broevite %d i %d nzd e %d\n",broj1,broj2,nzd(broj1,broj2));
    return 0;
}
int nzd(int broj1,int broj2){
    int nzd,delitel;
    nzd = 1;
    delitel=2;
    while(1)
    {
        if(broj1%delitel==0 && broj2%delitel==0)
        {
            nzd*=delitel;
            broj1=broj1/delitel;
            broj2=broj2/delitel;
        }
        else
        {
            delitel++;
        }
        if(delitel>broj1 || delitel>broj2)
        {
            break;
        }
    }
    return nzd;
}

