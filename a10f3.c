#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define QueueLimit 20

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

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
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά 
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά. 
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή. 
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά  
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά. 
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη. 
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά  
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά. 
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς 
                αν η ουρά δεν είναι κενή. 
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά. 
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή 
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
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item. 
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue 
                αν η ουρά δεν είναι γεμάτη. 
   Επιστρέφει: Την τροποποιημένη ουρά. 
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη  
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
		printf("Full Queue");
}





