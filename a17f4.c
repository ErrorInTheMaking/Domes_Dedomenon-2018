#include <stdio.h>
#include <stdlib.h>

typedef int QueueElementType;          

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

void TraverseQ(QueueType Queue);
void josephus(QueueType *AQueue, int N, int M);

int main()
{
    QueueType AQueue;
    int prisoners, interval, i;

    printf("Arithmos fulakismenon: ");
    scanf("%d", &prisoners);
    printf("Ana posous fulakismenous ginetai ektelesi: ");
    scanf("%d", &interval);
    while (interval<=1)
        scanf("%d", &interval);
    
    CreateQ(&AQueue);

    for(i = 1; i <= prisoners; ++i)
    {
        AddQ(&AQueue, i); 
    }
    
    printf("\nQueue :");
    TraverseQ(AQueue);
    printf("\n");
    
    josephus(&AQueue, prisoners, interval);
    
	return 0;
}
void josephus(QueueType *AQueue, int N, int M)
{
    QueuePointer CurrPtr;
    
    int count = N;
    int i;
    CurrPtr = AQueue->Front;
    
    do
    {
        i = 1;
        while(i < M)
        {
            while(CurrPtr->Data==0)
                CurrPtr = CurrPtr->Next;
            
            if(CurrPtr->Data!=0){
                printf("%d ", CurrPtr->Data);
                CurrPtr = CurrPtr->Next;
                if(CurrPtr->Data == 0)
                {
                    while(CurrPtr->Data==0)
                        CurrPtr = CurrPtr->Next;
                }
            }
            i++;
        }
        printf("%d 'EXECUTION %d'\n", CurrPtr->Data, CurrPtr->Data);
        CurrPtr->Data = 0;
        
        --count;
        
    }while(count > 1);
    
    do {
        CurrPtr = CurrPtr->Next;
    } while (CurrPtr->Data==0);
    
    printf("'SURVIVAL %d'\n", CurrPtr->Data);
    
}
void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
        do
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }while (CurrPtr != Queue.Front);
   }
    printf("\n");
}

void CreateQ(QueueType *Queue)
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    
    Queue->Rear=TempPtr;
    Queue->Rear->Next = Queue->Front;
}
void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
    QueuePointer TempPtr;
    
    if (EmptyQ(*Queue))
   	    printf("EMPTY Queue\n");
    if (Queue->Front==Queue->Rear)   
    {
        *Item = Queue->Front->Data;   
        free(Queue->Front); 
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        Queue->Rear->Next = Queue->Front;
        
        free(TempPtr);
    }  
}
