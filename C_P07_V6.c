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
    if( broj2 == 0)
    {

        return broj1;
    }
    else
    {
        printf("%d",broj1);
        nzd( broj2, broj1%broj2);
    }

}

