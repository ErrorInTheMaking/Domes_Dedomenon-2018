#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 21

typedef int QueueElementType;   /* � ����� ��������� ��� ��������� ��� �����
                                  ���������� ����� int */
typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int QSizeA(QueueType Q);
int QSizeB(QueueType *Q);

int main(void)
{
	int i ,sizeA, sizeB;
    QueueType AQueue;
    QueueElementType AnItem;
    
    CreateQ(&AQueue);
    
    puts("Question a");
    
    for(i=0;i<QueueLimit;i++)
        AddQ(&AQueue, i);
       
	puts("Queue");
    TraverseQ(AQueue);
    
    sizeA=  QSizeA(AQueue);
    sizeB = QSizeB(&AQueue);
    printf("<QSizeA> size of queue %d\n<QSizeB> size of queue %d\n\n", sizeA, sizeB);
    
    for(i=0;i<10;i++)
    	AddQ(&AQueue, i);
    
    puts("Question b");
    
    for(i=10;i<QueueLimit;i++)
    	AddQ(&AQueue, i);
	
	puts("Queue");
	TraverseQ(AQueue);
    puts("Queue");
    
    for(i=0;i<10;i++)
    	RemoveQ(&AQueue, &i);
    TraverseQ(AQueue);
    
    sizeA=  QSizeA(AQueue);
    sizeB = QSizeB(&AQueue);
    printf("<QSizeA> size of queue %d\n<QSizeB> size of queue %d\n\n", sizeA, sizeB);
    
	puts("Question c");
	 
    sizeA=  QSizeA(AQueue);
    sizeB = QSizeB(&AQueue);
    printf("<QSizeA> size of queue %d\n<QSizeB> size of queue %d\n\n", sizeA, sizeB);
    
    return 0;
}
int QSizeA(QueueType Q)
{
	return ((QueueLimit -Q.Front + Q.Rear) % QueueLimit);
}
int QSizeB(QueueType *Q)
{
	int i, counter=0;
	
	if(!EmptyQ(*Q)){
		for(i=0; i<QueueLimit-1;i++){
			RemoveQ(Q, &i);
			counter++;
		}
	}
		
	return counter;
}
void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}

void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ���� 
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����. 
   ����������: ������� �� � ���� ����� ����. 
   ����������: True �� � ���� ����� ����, False �����������  
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����. 
   ����������: ������� �� � ���� ����� ������. 
   ����������: True �� � ���� ����� ������, False �����������  
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����. 
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� ����� 
                �� � ���� ��� ����� ����. 
   ����������: �� �������� Item ��� ��� ������������� ����. 
   ������:     ������ ����� ���� �� � ���� ����� ���� 
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ���� Queue ��� ��� �������� Item. 
   ����������: ��������� �� �������� Item ���� ���� Queue 
                �� � ���� ��� ����� ������. 
   ����������: ��� ������������� ����. 
   ������:     ������ ������� ����� �� � ���� ����� ������  
*/
{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit; 
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue\n");
}
