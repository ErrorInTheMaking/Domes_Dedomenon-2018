#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int ListElementType;

typedef struct ListNode *ListPointer;

typedef struct ListNode
{
    ListElementType Data;
    ListPointer Next;
    
}ListNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLimearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);

void menu(int *choice);
void list_insertion(ListPointer *List, int choice1);
void swap(ListPointer *ptr1, ListPointer *ptr2);

void move_element(ListPointer *list, ListPointer PredPtr, int n ,int p);

int main()
{
    ListPointer AList, PredPtr;
    int choice, choice1, size, i, n;
    ListElementType p, Item;
    boolean Found;
    
    CreateList(&AList);
    
    printf("Dose arithmo stoixeion: ");
    scanf("%d", &size);
    
    for (i = 0; i < size; ++i){
        printf("Enter a number for insertion in the list: ");
        scanf("%d", &Item);
        LinkedInsert(&AList, Item, PredPtr);
    }
    printf("\n");
    printf("Arxiki lista: ");
    LinkedTraverse(AList);
    printf("\n");
    
    printf("Dose to stoixeio pou tha alljeis thesi: ");
    scanf("%d", &p);
    LinearSearch(AList,p, &PredPtr, &Found);
    
    while(!Found){
        printf("DATA NOT IN LIST\n");
        printf("Dose to stoixeio pou tha alljeis thesi: ");
        scanf("%d", &p);
        LinearSearch(AList, p, &PredPtr, &Found);
    }
    
    printf("Poses theseis theleis na to metakiniseis?: ");
    scanf("%d", &n);
    while (n > size-1) {
        printf("WRONG INDEX\n");
        printf("Poses theseis theleis na to metakiniseis?: ");
        scanf("%d", &n);
    }
    
    move_element(&AList, PredPtr, n, p);
    
    printf("\n");
    printf("Lista meta tin metatopisi tou %d kata %d theseis: ", p, n);
    LinkedTraverse(AList);
    
    return 0;
}

void move_element(ListPointer *list, ListPointer PredPtr, int n ,int p)
{
    int j = n;
    ListElementType temp;
    boolean Found;
    
    while (j > 0) {
        LinearSearch(*list, p, &PredPtr, &Found);
        temp = PredPtr->Data;
        PredPtr->Data = PredPtr->Next->Data;
        PredPtr->Next->Data = temp;
        j--;
    }
}
void swap(ListPointer *ptr1, ListPointer *ptr2)
{
    ListPointer temp;
    
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    
}
void CreateList(ListPointer *List)
{
    *List = NULL;
}

boolean EmptyList(ListPointer List)
{
    return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
{
    ListPointer TempPtr;
    
    TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
    /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
     &List, List,  &(*List), (*List), TempPtr); */
    TempPtr->Data = Item;
    if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
{
    ListPointer TempPtr;
    
    if (EmptyList(*List))
        printf("EMPTY LIST\n");
    else
    {
        if (PredPtr == NULL)
        {
            TempPtr = *List;
            *List = TempPtr->Next;
        }
        else
        {
            TempPtr = PredPtr->Next;
            PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
{
    ListPointer CurrPtr;
    
    if (EmptyList(List))
        printf("EMPTY LIST\n");
    else
    {
        CurrPtr = List;
        while ( CurrPtr!=NULL )
        {
            printf("%d ",(*CurrPtr).Data);
            CurrPtr = CurrPtr->Next;
        }
        printf("\n");
    }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
{
    ListPointer CurrPtr;
    boolean stop;
    
    CurrPtr = List;
    *PredPtr=NULL;
    stop= FALSE;
    while (!stop && CurrPtr!=NULL )
    {
        if (CurrPtr->Data==Item )
            stop = TRUE;
        else
        {
            *PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
        }
    }
    *Found=stop;
}

void OrderedLimearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
{
    ListPointer CurrPtr;
    boolean DoneSearching;
    
    CurrPtr = List;
    *PredPtr = NULL;
    DoneSearching = FALSE;
    *Found = FALSE;
    while (!DoneSearching && CurrPtr!=NULL )
    {
        if (CurrPtr->Data>=Item )
        {
            DoneSearching = TRUE;
            *Found = (CurrPtr->Data==Item);
        }
        else
        {
            *PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
        }
    }
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Eisagwgh stoixeiwn sth lista\n");
    printf("2. Diasxish stoixeiwn ths listas\n");
    printf("3. Anazhthsh stoixeiou sth lista\n");
    printf("4. Diagrafh stoixeiou apo th lista\n");
    printf("5. Anazhthsh stoixeiou se ordered lista\n");
    printf("6. Telos\n");
    printf("\nEpilogh: ");
    do
    {
        scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

void list_insertion(ListPointer *List,int choice1)
{
    ListElementType Item;
    char ch;
    ListPointer PredPtr;
    boolean Found;
    
    printf("Enter a number for insertion in the list: ");
    scanf("%d", &Item);
    if (choice1==1)
        OrderedLimearSearch(*List, Item, &PredPtr, &Found);
    else{
        //PredPtr= NULL;
        LinkedInsert(List, Item, PredPtr);
    }
}

