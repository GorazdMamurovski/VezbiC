#include <stdio.h>

int main()
{
    int proizvod,broj,i;
    i=0;
    char stop;
    float p1,p2,p3,p4,p5,vkupnoP1,vkupnoP2,vkupnoP3,vkupnoP4,vkupnoP5,vkupnoSite;
    p1=50.5;
    p2=45.6;
    p3=32.8;
    p4=65.3;
    p5=20.0;
    vkupnoP1=0;
    vkupnoP2=0;
    vkupnoP3=0;
    vkupnoP4=0;
    vkupnoP5=0;
    vkupnoSite=0;
    while (1){
        scanf("%d",&proizvod);
        scanf("%d",&broj);
        switch (proizvod) {
        case 1:
                vkupnoP1=vkupnoP1+(p1*broj);
            break;
        case 2:
                vkupnoP2=vkupnoP2+(p2*broj);
            break;
        case 3:
                vkupnoP3=vkupnoP3+(p3*broj);
            break;
        case 4:
                vkupnoP4=vkupnoP4+(p4*broj);
            break;
        case 5:
                vkupnoP5=vkupnoP5+(p5*broj);
            break;
        default:
            printf("gresen broj na proizvod\n");
        }
        printf("Prekin? (Vnesi n za prekin)\n");
        scanf("%c",&stop);
        if (stop == 'n')
        {
            break;
        }
    }
    printf("Vkupna prodadena vrednost P1 = %.2f\n",vkupnoP1);
    printf("Vkupna prodadena vrednost P2 = %.2f\n",vkupnoP2);
    printf("Vkupna prodadena vrednost P3 = %.2f\n",vkupnoP3);
    printf("Vkupna prodadena vrednost P4 = %.2f\n",vkupnoP4);
    printf("Vkupna prodadena vrednost P5 = %.2f\n",vkupnoP5);
    vkupnoSite=vkupnoP1+vkupnoP2+vkupnoP3+vkupnoP4+vkupnoP5;
    printf("Vkupna prodadena vrednost na site = %.2f",vkupnoSite);
    return 0;
}
