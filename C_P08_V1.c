#include <stdio.h>

/* pochetok na izvrshuvanjeto */
float prosTemp(int niza[],int broj);
int main()
{
    int niza[31],mesec,a;
    printf("Vnesi mesec \n");
    scanf("%d",&mesec);
    switch (mesec) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
        case 11:
            for(a =0 ; a < 31 ; a++)
            {
                printf("Vnesi temperatura za %d den \n",a+1);
                scanf("%d",&niza[a]);
            }
            printf("Prosecna temperatura za mesec %d e %.2f\n",mesec,prosTemp(niza,31));
        break;
        case 2:
        for(a =0 ; a < 28 ; a++)
        {
            printf("Vnesi temperatura za %d den \n",a+1);
            scanf("%d",&niza[a]);
        }
            printf("Prosecna temperatura za mesec %d e %.2f\n",mesec,prosTemp(niza,28));
        break;
        case 4:
        case 6:
        case 8:
        case 10:
        case 12:
            for(a =0 ; a < 30 ; a++)
            {
                printf("Vnesi temperatura za %d den \n",a+1);
                scanf("%d",&niza[a]);
            }
            printf("Prosecna temperatura za mesec %d e %.2f\n",mesec,prosTemp(niza,30));
        break;
    }
    return 0;
}

float prosTemp(int niza[],int denovi){
    int s;
    float pros;
    pros = 0.0;
    for(s = 0 ; s < denovi ; s++)
    {
        pros+=niza[s];
    }
    return pros/denovi;
}
