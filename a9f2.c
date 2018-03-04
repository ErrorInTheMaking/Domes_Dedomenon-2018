#include <stdio.h>
#include <stdlib.h>

#define StackLimit 5
#define ArrayLimit 10


typedef int StackElementType;   // � ����� ��� ���������  ��� �������
                                //���������� ����� int
typedef struct  {
    int Top1;
	int Top2;
    StackElementType Element[ArrayLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack, int stackNum) ;
boolean EmptyStack(StackType Stack, int stackNum);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item  ,int stackNum) ;
void Pop(StackType *Stack, StackElementType *Item,  int stackNum);

void TraverseStack(StackType Stack);

int main(int argc, char* argv[])
{
	StackType stack;
	StackElementType Item;
	int stackNum;

    //dimiourgia 2 stack
	CreateStack(&stack, 1);
	CreateStack(&stack, 2);

    //elegxos an ta duo stack einai adeia
	if( EmptyStack(stack, 1) == TRUE) printf("EMPTY STACK\n");
	if (EmptyStack(stack, 2) == TRUE) printf("EMPTY STACK\n");

    //gemisma 1ou stack
	Push(&stack, 5,  1);
	Push(&stack, 10, 1);
	Push(&stack, 15, 1);
	Push(&stack, 20 ,1);
	Push(&stack, 25 ,1);

    //gemisma 2ou stack
	Push(&stack, 10 ,2);
	Push(&stack, 20 ,2);
	Push(&stack, 30 ,2);
	Push(&stack, 40 ,2);
	Push(&stack, 50 ,2);

    fputs("\nprostheto epipleon stoixeia ston stack1 kai stack2", stdout);
	Push(&stack, 25, 1);
	Push(&stack, 50, 2);

    //afairo ta top stoixeia ton 2 stack
	Pop(&stack, &Item, 1);
	Pop(&stack, &Item, 2);

    //diasxisi pinaka
	TraverseStack(stack);

    return 0;
}

void CreateStack(StackType *Stack, int stackNum)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
   // printf("Dose ton arithmo tis stoivas:<1 h 2>");
   // scanf("%d", stackNum);

	if(stackNum == 1)
		Stack -> Top1 = -1;
	if(stackNum == 2)
		Stack -> Top2 = 10;
}

boolean EmptyStack(StackType Stack, int stackNum)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
	//printf("Dose ton arithmo tis stoivas gia na deis an einai adeia:<1 h 2>");
	//scanf("%d", stackNum);

	if(stackNum ==1) return (Stack.Top1 == -1);
	else 			 return (Stack.Top2 == ArrayLimit);
}

boolean FullStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top1 == Stack.Top2);
}

void Push(StackType *Stack, StackElementType Item, int stackNum)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
*/
{

	//printf("Dose ton arithmo tis stoivas:<1 h 2>");
	//scanf("%d", stackNum)
	if(stackNum==1){

		if (Stack -> Top1 != Stack -> Top2 - 1) {
	        Stack -> Top1++;
	        Stack -> Element[Stack -> Top1] = Item;
	    } else
	    	printf("\nStack 1 is Full!\n");
		}
	    else{

			if(Stack -> Top2 != Stack -> Top1 + 1  ){
			 	Stack-> Top2--;
	         	Stack -> Element[Stack -> Top2] = Item;
       }    else
                printf("Stack 2 is Full!\n");
	}
}


void Pop(StackType *Stack, StackElementType *Item,  int stackNum)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
*/
{

	//printf("Dose ton arithmo tis stoivas:<1 h 2>");
	//scanf("%d", stackNum);

	if(stackNum==1){

        if (!EmptyStack(*Stack, stackNum)) {
            *Item = Stack -> Element[Stack -> Top1];
            Stack -> Top1--;
        }else
            printf("Empty Stack...");
	}
	if(stackNum==2){

        if (!EmptyStack(*Stack, stackNum)) {
            *Item = Stack-> Element[Stack -> Top2];
            Stack -> Top2++;
    }   else
            printf("Empty Stack...");
	}
}
void TraverseStack(StackType Stack)
{
    int i;

    printf("\nplithos sto stack 1: %d\n",Stack.Top1+1);
    for (i=0;i<=Stack.Top1;i++) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");

    printf("\nplithos sto stack 2: %d\n",Stack.Top2 );
    for (i=ArrayLimit -1;i>=Stack.Top2;i--) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");
}
