#include<stdio.h>
#include<stdlib.h>
struct listNode{
    char karakter;
    int broj;
    struct listNode *nextPtr;
};
typedef struct listNode ListNode; /* sinonim za strukturata listNode */
typedef ListNode *ListNodePtr; /* sinonim za ListNode* */
void vnesiElement( ListNodePtr *sPtr, char karakter ,int broj);
void printList( ListNodePtr currentPtr );
void pecatiListaNanazad( ListNodePtr currentPtr );
void recursiveReverse(ListNodePtr* head, ListNodePtr** headRef);
void reverse(ListNodePtr** head);
int main()
{
     ListNodePtr startPtr = NULL;

     while(1)
     {
         char karakter;
         int broj;
         printf("vnesi broj i karakter e(0 za kraj)\n");
         scanf("%d",&broj);
         if(broj==0)
         {
             break;
         }
         scanf(" %c",&karakter);
         vnesiElement(&startPtr,karakter,broj);

     }
     printList(startPtr);
     reverse(&startPtr);
     pecatiListaNanazad(startPtr);
     return 0;
}

void vnesiElement( ListNodePtr *sPtr, char karakter ,int broj )
{
   ListNodePtr newPtr;      /* pointer do nov jazel */
   ListNodePtr previousPtr; /* pokazhuvach do prethodniot jazel vo listata */
   ListNodePtr currentPtr;  /* pokazhuvach do tekovniot jazel */

   newPtr = malloc( sizeof( ListNode ) ); /* sozdadi jazel */

   if ( newPtr != NULL ) { /* ako ima mesto */
      newPtr->karakter = karakter; /* stavi vrednost vo jazelot */
      newPtr->broj = broj;
      newPtr->nextPtr = NULL; /* jazelot ne e povrzan so drug jazel */

      previousPtr = NULL;
      currentPtr = *sPtr;

      /* vrti dodeka ne ja najdesh tochnata pozicija vo listata */
      while ( currentPtr != NULL && karakter > currentPtr->karakter ) {
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
      printf( "%c ne e vnesen. Nema dovolno memorija.\n", karakter );
   } /* kraj else */

}

void reverse(ListNodePtr** head)
{
    recursiveReverse(*head, head);
}

void recursiveReverse(ListNodePtr* head, struct ListNodePtr** headRef)
{
    ListNodePtr first;
    ListNodePtr rest;

    // empty list base case
    if (head == NULL)
       return;

    first = head;		  // suppose first = {1, 2, 3}
    rest = first->nextPtr;	// rest = {2, 3}

    // base case: List has only one node
    if (rest == NULL)
    {
        // fix the head pointer here
        *headRef = first;
         return;
    }

    // Recursively reverse the smaller {2, 3} case
    // after: rest = {3, 2}
    recursiveReverse(rest, headRef);

    // put the first elem on the end of the list
    rest->nextPtr = first;
    first->nextPtr = NULL;	// (tricky step -- make a drawing)
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
         printf( "%c ", currentPtr->karakter );
         printf( "%d --> ", currentPtr->broj );
         currentPtr = currentPtr->nextPtr;
      } /* kraj while */

      printf( "NULL\n\n" );
   } /* kraj else */

}

void pecatiListaNanazad( ListNodePtr currentPtr )
{

   if ( currentPtr == NULL ) {
      return;
   } /* kraj if */
   else {
      printf( "%c ", currentPtr->karakter );
      printf( "%d --> ", currentPtr->broj );
      pecatiListaNanazad(currentPtr->nextPtr);
   } /* kraj else */
}


