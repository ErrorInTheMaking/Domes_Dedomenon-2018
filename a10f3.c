#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define QueueLimit 20
#define random 20

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

void artiosperittos(QueueType *Queue1, QueueType *Queue2);
int random_number(int min_num, int max_num);

int main()
{
    QueueType artioi, perittoi;

    artiosperittos(&artioi, &perittoi);

	return 0;
}

void artiosperittos(QueueType *Queue1, QueueType *Queue2)
{
    QueueElementType count1=0, count2=0;

    int i, r, remove1, remove2, r2;

    CreateQ(Queue1);
    CreateQ(Queue2);

    for(i=0; i<QueueLimit;i++){
        r = random_number(i, 20);
        if(r%2==0){
            AddQ(Queue1, r);
            count1++;
        }else{
            AddQ(Queue2, r);
            count2++;
        }
        r=0;
    }

    printf("Size of EvenQueue: %d\n", count1);
    TraverseQ(*Queue1);
    printf("Size of OddQueue: %d\n", count2);
    TraverseQ(*Queue2);

    remove1 = random_number(0,count1-1);
    remove2 = random_number(0,count2-1);

    r = random_number(0, 20);

    for(i=0;i<remove1;i++)
        RemoveQ(Queue1, &r);
    for(i=0;i<remove2;i++)
        RemoveQ(Queue2, &r);

    int j;
    i=count1-remove1;

    for(j=0;j<=100; j++){
        r2 = rand()%20;
        if(r2%2==0){
            while(i<count1){
                AddQ(Queue1, r2);
                break;
            }
            i++;
        }
    }

    r2=0;
    i=0;

    i=count2 - remove2;

    for(j=0;j<=100; j++){
        r2 = rand()%20;
        if(r2%2!=0){
            while(i<count2){
                AddQ(Queue2, r2);
                break;
            }
            i++;
        }
    }

    printf("Random number of items %d\n", remove1);
    TraverseQ(*Queue1);
    printf("Random number of items %d\n", remove2);
    TraverseQ(*Queue2);
}
int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1;
    } else {
        low_num = max_num + 1;
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
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
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
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
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)

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
