#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    int num;
    char date[11];
} StackElementType;

typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

void TraverseStack(StackPointer Stack);
void menu(int *choice);

int sort_warehouse(StackPointer warehouse1, StackPointer warehouse2, StackPointer warehouse3);
int count_warehouse(StackPointer warehouse);

int main()
{
    StackPointer warehouse1, warehouse2, warehouse3;
    StackElementType info;
    int i, plithos, noumero;

    CreateStack(&warehouse1);
    CreateStack(&warehouse2);
    CreateStack(&warehouse3);

    printf("Plithos fortiwn:");
    scanf("%d", &plithos);

    for(i = 0; i < plithos; i++)
    {
        printf("Arithmos kivwtiwn gia to %do fortio:", i+1);
        scanf("%d", &info.num);
        printf("Imeromhnia liksis gia to %do fortio:", i+1);
        scanf("%s", info.date);
        noumero = sort_warehouse(warehouse1, warehouse2, warehouse3);

        if(i==0)  Push(&warehouse1, info); //tropopihsh ths sort oste na exei tin periptosi tis count1 = count 2 =count 3 ...
        if(i ==1)  Push(&warehouse2, info);
        if(i==2)  Push(&warehouse3, info);

        if(i > 2){
        if(noumero == 1)
            Push(&warehouse1, info);
        else if(noumero == 2)
            Push(&warehouse2, info);
        else
            Push(&warehouse3, info);
        }
    }

    TraverseStack(warehouse1);
    TraverseStack(warehouse2);
    TraverseStack(warehouse3);


	return 0;
}
int count_warehouse(StackPointer warehouse)
{
    StackPointer CurrPtr;
    int count = 0;

    CurrPtr = warehouse;
    while ( CurrPtr!=NULL )
        {
      	     count += CurrPtr->Data.num;
             CurrPtr = CurrPtr->Next;
        }


    return count;

}

int sort_warehouse(StackPointer warehouse1, StackPointer warehouse2, StackPointer warehouse3)
{
    int warehouse_num = 0;
    int count1, count2, count3;

    count1 = count_warehouse(warehouse1);
    count2 = count_warehouse(warehouse2);
    count3 = count_warehouse(warehouse3);

    if(count1 > count2)
    {
        if(count1 > count3)
        {
            if(count2 > count3)
            {
                warehouse_num = 3;
            }
            else
            {
                warehouse_num = 2;
            }
        }
        else
        {
            warehouse_num = 2;
        }
    }
    else
    {
         if(count1 < count3)
         {
             warehouse_num = 1;
         }
         else
         {
             warehouse_num = 3;
         }
    }

    return warehouse_num;
}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d\n%s\n", CurrPtr->Data.num, CurrPtr->Data.date);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void CreateStack(StackPointer *Stack)
/* ����������: ���������� ��� ���� ����������� ������.
   ����������: ��� ���� ����������� ������, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* �������:     ��� ����������� ������, Stack.
   ����������:  ������� �� � Stack ����� ����.
   ����������:  TRUE �� � ������ ����� ����, FALSE �����������
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ���
                ������ Stack ��� ��� �������� Item.
   ����������: ������� ���� ������ ��� ������������ �������, �� �������� Item.
   ����������: ��� ������������� ����������� ������
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ��� ������ Stack.
   ����������: ������� ��� ��� ������ ��� ������������ �������,
                �� � ������ ��� ����� ����, �� �������� Item.
   ����������: ��� ������������� ����������� ������ ��� �� �������� Item.
   ������:     ������ ����� �������, �� � ����������� ������ ����� ����
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
