#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* prototipovi */
void meshaj( int wDeck[][ 13 ] );
void deli( const int wDeck[][ 13 ], const char *wFace[],
           const char *wSuit[], const int brojKarti);

int main()
{
    int brojKarti;
    brojKarti = 5;
   /* inicijaliziraj ja nizata na boi */
   const char *boja[ 4 ] = { "Srce", "Karo", "List", "Detelina" };

   /* inicijaliziraj ja nizata na brojki */
   const char *brojka[ 13 ] =
      { "As", "Dva", "Tri", "Chetiri",
        "Pet", "Shest", "Sedum", "Osum",
        "Devet", "Deset", "Dzandar", "Dama", "Pop" };

   /* inicijaliziraj niza na spil */
   int spil[ 4 ][ 13 ] = { 0 };

   srand( time( 0 ) ); /* generator na sluchajni broevi */


       meshaj( spil );
       deli( spil, brojka, boja ,brojKarti);


   return 0; /* uspeshen kraj */

} /* kraj main */

/* meshaj gi kartite vo shpilot */
void meshaj( int wDeck[][ 13 ] )
{
   int row;    /* broj na red */
   int column; /* broj na kolona */
   int card;   /* brojach */

   /* za sekoja od 52-te karti,
   odberi sluchajno mesto vo shpilot */
   for ( card = 1; card <= 52; card++ ) {

      /* biraj nova sluchajna lokacija dodeka ne najdesh
      slobodno mesto */
      do {
         row = rand() % 4;
         column = rand() % 13;
      } while( wDeck[ row ][ column ] != 0 ); /* kraj do...while */

      /* pojtavi ja kartata na izbranoto mesto vo spilot */
      wDeck[ row ][ column ] = card;
   } /* kraj for */
} /* kraj na funkcijata meshaj */

/* deli gi kartite vo shpilot */
void deli( const int wDeck[][ 13 ], const char *wFace[],
           const char *wSuit[] ,const int brojKarti)
{
   int card;   /* brojach na karti */
   int row;    /* brojach na redovi */
   int column,redKenta; /* brojach na koloni */
   int m;
   int min;
   int flagKentaVistinsko;
   int flagPar,flagDvaPara,flagTriling,flagCetiriIsti,flagBoja,flagKenta,flag;
   flagPar=0;
   m=0;
   flagBoja=0;
   flagKenta=0;
   flagKentaVistinsko=0;
   flagDvaPara=0;
   flagTriling=0;
   flagCetiriIsti=0;
   flag=0;
   min=100;
   char *broevi[5];
   char *boja[5];
   char *kenta[13];
   for(int i=0;i<13;i++){
       kenta[i]=wFace[i];
   }
   int s;
   /* podeli ja sekoja od 52-te karti */
   for ( card = 1; card <= brojKarti; card++ ) {

      /* pomini niz redovite na wDeck */
      for ( row = 0; row <= 3; row++ ) {

         /* pomini niz kolonite na wDeck za tekovniot red */
         for ( column = 0; column <= 12; column++ ) {

            /* ako mestoto ja sodrzhi tekovnata karta, prikazhi ja kartata */
            if ( wDeck[ row ][ column ] == card ) {
               broevi[m] = wFace[ column ];
               boja[m] = wSuit[row];
               if(column<min){
                   redKenta=column;
                   min=redKenta;
               }
               m++;
            } /* kraj if */
         } /* kraj for */
      } /* kraj for */
   } /* kraj for */
    printf("5 Karti za poker: \n");
    for(int i=0;i<5;i++){
        printf("%s %s\n",broevi[i],boja[i]);
    }
    flag=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(broevi[i]==kenta[redKenta+j])
                flagCetiriIsti += 1;
        }

    }
    if(flagCetiriIsti==5){
        flagKentaVistinsko=1;
    }

    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(broevi[i]==broevi[j] && flagPar==0){
                flagPar=1;
                if(flag==0){
                    flag=1;
                    s=i;
                }

            }
            else if(broevi[i]==broevi[j] && flagPar==1 && broevi[s]==broevi[i]){
                flagTriling=1;
                flagPar=0;


            }
            else if(broevi[i]==broevi[j] && flagTriling==1 && broevi[s]==broevi[i]){
                flagKenta=1;
                flagTriling =0 ;

            }
            if(broevi[i]==broevi[j] && broevi[s]!=broevi[i] && flagPar==1){
                flagDvaPara=1;

            }
            if(boja[i]!=boja[j])
            {
                flagBoja=1;

            }



        }
    }

    if(!flagBoja){
        if(flagKentaVistinsko==1 && flagPar==0 && flagDvaPara==0){
            printf("Se Padna kenta \n");
        }
        else
        {
            printf("Se padna Boja\n");
        }

    }
    else
    {
        if(flagKenta==1){
            (printf("Se padna Cetiri Isti\n"));
        }
        else if(flagTriling==1){
            (printf("Se padna Triling\n"));
        }
        else if(flagPar==1 && flagDvaPara==0){
            (printf("Se padna Par\n"));
        }
        else if(flagDvaPara){
            (printf("Se padnaa Dva Para\n"));
        }
        else
        {
            printf("Nisto ne se padna \n");
        }
    }




} /* kraj na funkcijata deli */

