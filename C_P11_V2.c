#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *den,*mesec,*godina,broj[50];
    char normalenBroj[10];
    int i,denI,mesecI,godinaI;
    i=0;
    char *podelenDatum;
    while (1){
        denI = 0;
        mesecI=0;
        godinaI=0;
        podelenDatum = NULL;
        i=0;
        gets( broj );
        if (strcmp( broj, "Kraj" ) == 0)
        {
            break;
        }
        podelenDatum = strtok( broj,"/" );
        while ( podelenDatum != NULL ) {
            if(i==0)
            {
                den = podelenDatum;
            }
            if(i==1)
            {
                mesec = podelenDatum;
            }
            if(i==2)
            {
                godina= podelenDatum;
            }
              i++;
              podelenDatum = strtok( NULL, "/" ); /* zemi go sledniot del */
           }
        denI = atoi(den);
        mesecI = atoi(mesec);
        godinaI = atoi(godina);
        switch (mesecI) {
                case 1:
                    printf("%d januari %d\n",denI,godinaI);
                    break;
                case 2:
                    printf("%d februari %d\n",denI,godinaI);
                    break;
                case 3:
                    printf("%d mart %d\n",denI,godinaI);
                    break;
                case 4:
                    printf("%d arpil %d\n",denI,godinaI);
                    break;
                case 5:
                    printf("%d maj %d\n",denI,godinaI);
                    break;
                case 6:
                    printf("%d juni %d\n",denI,godinaI);
                    break;
                case 7:
                    printf("%d juli %d\n",denI,godinaI);
                    break;
                case 8:
                    printf("%d avgust %d\n",denI,godinaI);
                    break;
                case 9:
                    printf("%d septemvri %d\n",denI,godinaI);
                    break;
                case 10:
                    printf("%d oktomvri %d\n",denI,godinaI);
                    break;
                case 11:
                    printf("%d noemvri %d\n",denI,godinaI);
                    break;
                case 12:
                    printf("%d dekemvri %d\n",denI,godinaI);
                    break;
        default:
                printf("Gresen mesec\n ",denI,mesecI,godinaI);
            }

        printf("Vnesi Kraj za kraj\n");
    }


    return 0;
}

