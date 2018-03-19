#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define QueueLimit1 3
#define QueueLimit2 21

typedef char Queue1[25];

typedef struct {
	char name[25];
	int num;
	char phone[10];
}Info;

typedef struct {
	int Front, Rear;
	Queue1 name1[QueueLimit1];
}Q1;

typedef struct {
	int Front, Rear;
	Info element2[QueueLimit2];
}Q2;

typedef enum {FALSE, TRUE} boolean;

void CreateQ1(Q1 *Queue);
void CreateQ2(Q2 *Queue);

boolean FullQ1(Q1 Queue);
boolean FullQ2(Q2 Queue);

void AddQ1(Q1 *Queue, Queue1 name);
void AddQ2(Q2 *Queue, Info item);

void newAppointment(int code, Q1 *queue1, Q2 *queue2);
void showQ(int pass, Q1 Queue);
void showWaitingQ(Q2 Queue);

int main(void)
{
	int i, ap;
	char ch;
	
	Q1 Queue[6];
	Q2 QueueR;
	
	for(i=1;i<6;i++)
		CreateQ1(&Queue[i]);
	
	CreateQ2(&QueueR);
		
	srand(time(NULL));	
			
	while(toupper(ch) != 'N'){
		ap = rand() % 5 + 1;
		newAppointment(ap, Queue, &QueueR);	
		printf("Continue (Y/N):");
		scanf("%c", &ch);
		fflush(stdin);
		
	}
	
	for(i=1;i<=5;i++){
		printf("Appointments of clinic %d\n", i);
		showQ(i, Queue[i]);
	}
	puts("Waiting list:" );
	showWaitingQ(QueueR);
	
	return 0;
}

void CreateQ1(Q1 *Queue)
{
    Queue->Front = 0;
	Queue->Rear = 0;
}
void CreateQ2(Q2 *Queue)
{
    Queue->Front = 0;
	Queue->Rear = 0;
}
boolean FullQ1(Q1 Queue)
{
    return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit1));
}
boolean FullQ2(Q2 Queue)
{
    return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit2));
}

void AddQ1(Q1 *Queue, Queue1 name)
{
    int NewRear;

	if(!FullQ1(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit1;
		strcpy(Queue ->name1[Queue ->Rear], name);
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue");
}

void AddQ2(Q2 *Queue, Info item)
{
    int NewRear;

	if(!FullQ2(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit2;
		Queue ->element2[Queue ->Rear] = item;
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue");
}

void newAppointment(int code, Q1 *queue1, Q2 *queue2)
{
	Info customer;
	char name10[25];
	
	printf("Give your name:");
    gets(name10);
        if(!FullQ1(queue1[code])){
            AddQ1(&queue1[code], name10);
            printf("Successful appointment for clinic %d\n", code);
    }else{
	        printf("You are in a waiting list\n");
	        printf("Give your phone number: ");
	        gets(customer.phone);
	        customer.num = code;
	        strcpy(customer.name, name10);
	        AddQ2(queue2, customer);
	}
}

void showQ(int pass, Q1 Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%s \n", Queue.name1[current]);
		current = (current + 1) % QueueLimit1;
	}
	printf("\n");
}
void showWaitingQ(Q2 Queue)
{
	Info customer;
	
	int current;
	current = Queue.Front;
	
	while (current != Queue.Rear) {
		customer = Queue.element2[current];
        printf("%s, %d, %s \n", customer.name, customer.num, customer.phone);
		current = (current + 1) % QueueLimit2;
	}
	printf("\n");
}
