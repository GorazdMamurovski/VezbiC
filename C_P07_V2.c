#include <stdio.h>
void vreme(int,int,int);
int main()
{
    int sekundi,minuti,casovi;
    printf("Vnesi sekundi,minuti,csaovi \n");
    scanf("%d%d%d",&sekundi,&minuti,&casovi);
    while(1){
        if(sekundi>60)
        {
             printf("Vnesi tocni sekundi \n");
             scanf_s("%d",&sekundi);
        }
        if(minuti>60){
            printf("Vnesi tocni minuti \n");
            scanf_s("%d",&minuti);
        }
        if(casovi>12)
        {
            printf("Vnesi tocni casovi \n");
            scanf_s("%d",&casovi);
        }
        if(sekundi<=60 && minuti<=60 && casovi <=12)
            break;
    }
    vreme(sekundi,minuti,casovi);
    return 0;
}
void vreme(int sekundi,int minuti,int casovi)
{
    printf("Do 12 saatot ima uste %d saati %d minuti %d sekundi",12-casovi,60-minuti,60-sekundi);
}

