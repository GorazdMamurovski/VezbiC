#include <stdio.h>

int main()
{
    int broj;

    for(int i=0;i<10;i++)
    {
        printf("%vnesi broj: \n");
        scanf("%d",&broj);
        if(paren(broj))
        {
            printf("Brojot %d e paren\n",broj);
        }
        else{
            printf("Brojot %d e ne paren\n",broj);
        }
    }

}

int paren(int broj){
    if(broj%2==0)
    {
        return 1;
    }
    else{
        return 0;
    }
}

