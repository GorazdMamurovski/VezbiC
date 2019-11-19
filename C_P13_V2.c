#include<stdio.h>
#include<stdlib.h>
struct listNode{
    int broj;
    struct listNode *nextPtr;
};
typedef struct listNode ListNode; /* sinonim za strukturata listNode */
typedef ListNode *ListNodePtr; /* sinonim za ListNode* */
void vnesiElement( ListNodePtr *sPtr,int broj );
void printList( ListNodePtr currentPtr );
void sortOpagjanje (ListNodePtr *sPtr);
void sortRastenje  (ListNodePtr *sPtr);
void swap(ListNodePtr a, ListNodePtr b);
int main()
{
     ListNodePtr startPtr = NULL;
     int brojBrisenje;
     while(1)
     {
         int broj;
         printf("vnesi broj (0 za kraj)");
         scanf("%d",&broj);
         if(broj==0)
         {
             break;
         }
         vnesiElement(&startPtr,broj);

     }
     printList(startPtr);
     sortOpagjanje(startPtr);
     printList(startPtr);
     sortRastenje (startPtr);
     printList(startPtr);


     printf( "Vnesi karakter za brishenje: " );
     scanf( "\n%d", &brojBrisenje );
     if ( delete( &startPtr, brojBrisenje ) ) {
         printf( "%c deleted.\n", brojBrisenje );
         printList( startPtr );
     }
     else {
             printf( "%c ne e vo listata.\n\n", brojBrisenje );
     }





     return 0;
}

void vnesiElement( ListNodePtr *sPtr,int broj )
{
   ListNodePtr newPtr;      /* pointer do nov jazel */
   ListNodePtr previousPtr; /* pokazhuvach do prethodniot jazel vo listata */
   ListNodePtr currentPtr;  /* pokazhuvach do tekovniot jazel */

   newPtr = malloc( sizeof( ListNode ) ); /* sozdadi jazel */

   if ( newPtr != NULL ) { /* ako ima mesto */
      newPtr->broj = broj;
      newPtr->nextPtr = NULL; /* jazelot ne e povrzan so drug jazel */

      previousPtr = NULL;
      currentPtr = *sPtr;

      /* vrti dodeka ne ja najdesh tochnata pozicija vo listata */
      while ( currentPtr != NULL) {
         previousPtr = currentPtr;          /* odi do ...   */
         currentPtr = currentPtr->nextPtr;  /* ... sledniot jazel */
      } /* kraj while */

      /* vnesi nov jazel na pochetokot na listata */
      if ( previousPtr == NULL ) {
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      } /* kraj if */
      else { /* vnesi nov jazel megju previousPtr i currentPtr */
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } /* kraj else */

   } /* kraj if */
   else {
      printf( "%d ne e vnesen. Nema dovolno memorija.\n", broj );
   } /* kraj else */

}


void sortRastenje  (ListNodePtr *sPtr)
{
    int temp;
    ListNodePtr Ptr1;
    ListNodePtr Ptr2 = NULL;
    int swaped,i;
    if(sPtr == NULL){
        return;
    }
    do{
        swaped=0;
        Ptr1 = sPtr;
        while(Ptr1->nextPtr != Ptr2){
            if(Ptr1->broj< Ptr1->nextPtr->broj){
                    swap(Ptr1, Ptr1->nextPtr);
                    swaped=1;
            }
            Ptr1 = Ptr1->nextPtr;
        }
        Ptr2=Ptr1;

    }
    while(swaped);
}

void sortOpagjanje (ListNodePtr *sPtr)
{
    int temp;
    ListNodePtr Ptr1;
    ListNodePtr Ptr2 = NULL;
    int swaped,i;
    if(sPtr == NULL){
        return;
    }
    do{
        swaped=0;
        Ptr1 = sPtr;
        while(Ptr1->nextPtr != Ptr2){
            if(Ptr1->broj> Ptr1->nextPtr->broj){
                    swap(Ptr1, Ptr1->nextPtr);
                    swaped=1;
            }
            Ptr1 = Ptr1->nextPtr;
        }
        Ptr2=Ptr1;

    }
    while(swaped);
}

void swap(ListNodePtr a, ListNodePtr b)
{
    int temp = a->broj;
    a->broj = b->broj;
    b->broj = temp;
}

void printList( ListNodePtr currentPtr )
{

   /* ako listata e prazna */
   if ( currentPtr == NULL ) {
      printf( "Listata e prazna.\n\n" );
   } /* kraj if */
   else {
      printf( "Listata e:\n" );

      /* dodeka ne e kraj na listata */
      while ( currentPtr != NULL ) {
         printf( "%d --> ", currentPtr->broj );
         currentPtr = currentPtr->nextPtr;
      } /* kraj while */

      printf( "NULL\n\n" );
   } /* kraj else */

}


int delete( ListNodePtr *sPtr, int value )
{
   ListNodePtr previousPtr; /* pokazhuvach do prethodniot element vo listata */
   ListNodePtr currentPtr;  /* pokazhuvach do tekovniot jazel */
   ListNodePtr tempPtr;     /* pokazhuvach do privremen element */

   /* izbrishi go prviot jazel */
   if ( value == ( *sPtr )->broj ) {
      tempPtr = *sPtr; /* chuvaj go jazelot shto se brishe */
      *sPtr = ( *sPtr )->nextPtr; /* sredi ja listata */
      free( tempPtr ); /* oslobodi go nepotrebniot jazel */
      return value;
   } /* kraj if */
   else {
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      /* vrti dodeka ne ja najdesh tochnata pozicija */
      while ( currentPtr != NULL && currentPtr->broj != value ) {
         previousPtr = currentPtr;         /* odi do ...   */
         currentPtr = currentPtr->nextPtr; /* ... sledniot jazel */
      } /* kraj while */

      /* izbrishi go jazelot na currentPtr */
      if ( currentPtr != NULL ) {
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         return value;
      } /* kraj if */

   } /* kraj else */

   return '\0';

}

