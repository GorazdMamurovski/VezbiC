/* Program p13_02.c
   Program za stek (magacin) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* samo-referencirachka struktura */
struct stackNode {
   char data;                  /* definiraj int podatoci */
   struct stackNode *nextPtr; /* stackNode pokazhuvach */
}; /* kraj na strukturata stackNode */

typedef struct stackNode StackNode; /* sinonim za struct stackNode */
typedef StackNode *StackNodePtr; /* sinonim za StackNode* */

/* prototipovi */
void push( StackNodePtr *topPtr, char info );
int pop( StackNodePtr *topPtr );
int isEmpty( StackNodePtr topPtr );
void printStack( StackNodePtr currentPtr );
void instructions( void );

/* pochetok na izvrshuvanjeto */
int main()
{
   StackNodePtr stackPtr = NULL; /* pokazhuva na vrvot na stekot */
   char zbor[50];
   fgets (zbor, 100, stdin);
   for(int i=0;i<strlen(zbor);i++)
   {
       push(&stackPtr,zbor[i]);
   }
   printStack(stackPtr);
   return 0; /* uspeshen kraj */

} /* kraj main */

void push( StackNodePtr *topPtr, char info )
{
   StackNodePtr newPtr; /* pokazhuvach do noviot jazel */

   newPtr = malloc( sizeof( StackNode ) );

   /* vnesi jazel na vrvot na stekot */
   if ( newPtr != NULL ) {
      newPtr->data = info;
      newPtr->nextPtr = *topPtr;
      *topPtr = newPtr;
   } /* kraj if */
   else { /* nema mesto */
      printf( "%c ne e vnesen. Nema dovolno memorija.\n", info );
   } /* kraj else */

} /* kraj na funkcijata push */

/* Izvadi jazel od vrvot na stekot */
int pop( StackNodePtr *topPtr )
{
   StackNodePtr tempPtr; /* pokazhuvach do privremen jazol */
   char popValue; /* vrednost na jazelot */

   tempPtr = *topPtr;
   popValue = ( *topPtr )->data;
   *topPtr = ( *topPtr )->nextPtr;
   free( tempPtr );

   return popValue;

} /* kraj na funkcijata pop */

/* Ispechati go stekot */
void printStack( StackNodePtr currentPtr )
{

   /* ako stekot e prazen */
   if ( currentPtr == NULL ) {
      printf( "Stekot e prazen.\n\n" );
   } /* kraj if */
   else {
      printf( "Stekot e:\n" );

      /* dodeka ne e kraj na stekot */
      while ( currentPtr != NULL ) {
         printf( "%c --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;
      } /* kraj while */

      printf( "NULL\n\n" );
   } /* kraj else */

} /* kraj na funkcijata printList */

/* Vrati 1 ako stekot e prazen,0 inaku */
int isEmpty( StackNodePtr topPtr )
{
   return topPtr == NULL;

}
