#include <stdio.h>
int nzd(int);
int main()
{
    int broj;
    printf("vnesi broj na zvezdi:\n");
    scanf("%d",&broj);
    zvezdi(broj);
    return 0;
}
int zvezdi(int broj){
    if(broj==0)
    {
        return broj;
    }
    else
    {
        for(int i=0;i<broj;i++)
        {
            printf("*");
        }
        printf("\n");
        return zvezdi(broj-1);
    }

}

