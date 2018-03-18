#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QueueLimit1 3
#define QueueLimit2 21

typedef char Queue1;
typedef char Queue2;

typedef struct {
	int Front, Rear;
	Queue1 name1[QueueLimit1-1][25];
}Q1;

typedef struct {
	int Front, Rear;
	int pin;
	Queue2 name2[QueueLimit2 -1 ][25];
	Queue2 phone[QueueLimit2 -1 ][10];
}Q2;

typedef enum {FALSE, TRUE} boolean;

void CreateQ1(Q1 *Queue);
void CreateQ2(Q2 *Queue);

boolean FullQ1(Q1 Queue);
boolean FullQ2(Q2 Queue);

void AddQ1(Q1 *Queue, Queue1 *name);
void AddQ2(Q2 *Queue, Queue2 *name, Queue2 *number, int pass);

void newAppointment(int code, Q1 *queue1, Q2 *queue2);






int main(void)
{












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
void AddQ1(Q1 *Queue, Queue1 *name)
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
void AddQ2(Q2 *Queue, Queue2 *name, Queue2 *number, int pass)
{
    int NewRear;

	if(!FullQ2(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit2;
		strcpy(Queue ->name2[Queue ->Rear], name);
		strcpy(Queue ->phone[Queue ->Rear], number);
		Queue ->pin = pass;
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue");
}
void newAppointment(int code, Q1 *queue1, Q2 *queue2)
{
    switch(code)
    {
        case 1:
            printf("Give your name:");
            gets(*queue1[1].name1);
            if(!FullQ1(*queue1)){
                AddQ1(&queue1[1], queue1[1].name1);
                puts("Successful appointment for clinic 1");
            }else{
                printf("You are in a waiting list\n");
                printf("Give your phone number: ");
                gets(*queue2[1].phone);
                queue2[1]->pin = 1;
                AddQ2(&queue2[1], &queue2[1].name, &queue2[1].number, &queue2[1].pin );


            }













    }
}
