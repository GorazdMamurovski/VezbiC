#include <stdio.h>

int main()
{
    float plata,prodalR;
    plata = 200;
    while(1)
    {
        printf("Vnesi promet vo evra (-1 za kraj):\n");
        scanf("%f",&prodalR);
        if(prodalR==-1.00)
        {
            break;
        }
        printf("%.02f\n",plata+(prodalR*0.09));

    }


    return 0;
}
