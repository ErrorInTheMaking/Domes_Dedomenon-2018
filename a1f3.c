//filename TestQueue.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MaxA 19

typedef int QueueElementType;           /*ï ôàðï÷ ôöî óôïéøåÝöî ôè÷ óùîäåäåíÛîè÷ ïùòÀ÷
                                        åîäåéëôéëÀ ôàðïù int*/
typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

int QSizeA(QueueType *Q);
int QSizeB(QueueType *Q);

void TraverseQ(QueueType Queue);

int main()
{
    int i, sizeA, sizeB;
    QueueType AQueue;
    QueueElementType AnItem;

    CreateQ(&AQueue);

    //Queue A
    puts("Queation a");
    for(i=0;i<20;i++){
        AddQ(&AQueue, i);
        if(i==19) printf("Full Queue\n");
    }
    puts("Queue");
    TraverseQ(AQueue);

    sizeA=  QSizeA(&AQueue);
    printf("<QSizeA> size of queue %d\n", sizeA);

    for(i=0;i<20;i++)
        RemoveQ(&AQueue, &i);
     TraverseQ(AQueue);

    //QueueB
    puts("Queation b");

    for(i=0;i<10;i++)
        AddQ(&AQueue, i);

     for(i=10;i<20;i++){
        AddQ(&AQueue, i);
        if(i==19) puts("Full Queue");
     }
     puts("Queue");
     TraverseQ(AQueue);

     puts("Queue");
     for(i=0;i<10;i++)
        RemoveQ(&AQueue, &i);
     TraverseQ(AQueue);

     sizeA = QSizeA(&AQueue);
     printf("<QSizeA> size of queue %d\n", sizeA);


     //Queue C

     printf("\nQueation c");
     for(i=0;i<20;i++)
        RemoveQ(&AQueue, &i);
     TraverseQ(AQueue);

     sizeA = QSizeA(&AQueue);
     printf("<QSizeA> size of queue %d\n", sizeA);

	 return 0;
}
int QSizeA(QueueType *Queue)
{

   QueuePointer CurrPtr;
   int size=0;

   if (EmptyQ(*Queue))
    {
   	    size=0;
    }
   else
   {
   	     CurrPtr = Queue->Front;
         while ( CurrPtr!=NULL )
        {
             CurrPtr = CurrPtr->Next;
             size++;
        }
   }
   return size;

}
/*int QSizeB(QueueType *Queue)
{
    int size=0;
    QueuePointer p;



    return size;


}
*/
void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("");
    }
   else
   {
   		 CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void CreateQ(QueueType *Queue)
/* ¤åéôïùòçÝá: ¢èíéïùòçåÝ íéá ëåîÜ óùîäåäåíÛîè ïùòÀ.
   ¶ðéóôòÛæåé: »éá ëåîÜ óùîäåäåíÛîè ïùòÀ
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* ¢Ûøåôáé:    »éá óùîäåäåíÛîè ïùòÀ.
   ¤åéôïùòçÝá: ¶ìÛçøåé áî è óùîäåäåíÛîè ïùòÀ åÝîáé ëåîÜ.
   ¶ðéóôòÛæåé: True áî è ïùòÀ åÝîáé ëåîÜ, false  äéáæïòåôéëÀ
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* ¢Ûøåôáé:    »éá óùîäåäåíÛîè ïùòÀ Queue ëáé Ûîá  óôïéøåÝï Item.
   ¤åéôïùòçÝá: ¦òïóõÛôåé ôï óôïéøåÝï Item óôï ôÛìï÷ ôè÷ óùîäåäåíÛîè÷ ïùòÀ÷ Queue.
   ¶ðéóôòÛæåé: Æèî ôòïðïðïéèíÛîè ïùòÀ
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* ¢Ûøåôáé:    »éá óùîäåäåíÛîè ïùòÀ.
   ¤åéôïùòçÝá: °æáéòåÝ ôï óôïéøåÝï Item áðÞ ôèî  ëïòùæÜ ôè÷ óùîäåäåíÛîè÷ ïùòÀ÷,
                áî äåî åÝîáé  ëåîÜ.
   ¶ðéóôòÛæåé: Æï óôïéøåÝï Item ëáé ôèî ôòïðïðïéèíÛîè óùîäåäåíÛîè ïùòÀ.
   Îêïäï÷:     »Üîùíá ëåîÜ÷ ïùòÀ÷, áî è ïùòÀ åÝîáé  ëåîÜ
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}
