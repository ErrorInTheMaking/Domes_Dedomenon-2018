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

void merge_list(ListPointer *List1, ListPointer *List2, ListPointer PredPtr);

int main()
{
    ListPointer List1, List2, PredPtr;
    int choice, choice1=1, i, n1, n2;
    ListElementType keyvalue;
    boolean Found;
    
    CreateList(&List1);
    CreateList(&List2);
    
    printf("Dose arithmo stoixeion 1hs listas: ");
    scanf("%d", &n1);
    
    for (i = 0; i < n1; ++i)
        list_insertion(&List1, choice1);
    printf("\n");
    
    printf("Dose arithmo stoixeion 2hs listas: ");
    scanf("%d", &n2);
    
    for (i = 0; i < n2; ++i)
        list_insertion(&List2, choice1);
    
    printf("\nPrin to merge\n");
    printf("List 1: "); LinkedTraverse(List1);
    printf("List 2: "); LinkedTraverse(List2);
    
    merge_list(&List1, &List2, PredPtr);
    
    printf("\nMeta to merge\n");
    LinkedTraverse(List1);
    
    return 0;
}
void merge_list(ListPointer *List1, ListPointer *List2, ListPointer PredPtr)
{
    ListPointer CurrPtr;
    int Item;
    boolean Found;
    
    CurrPtr = *List2;
    while (CurrPtr!=NULL) {
        Item = CurrPtr->Data;
        OrderedLimearSearch(*List1, Item, &PredPtr, &Found);
        LinkedInsert(List1, Item, PredPtr);
        
        CurrPtr = CurrPtr->Next;
    }
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
            printf("%d ", (*CurrPtr).Data);
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
    
    printf("Enter a number for insertion in the list: "); scanf("%d", &Item);
    if (choice1==1){
        OrderedLimearSearch(*List, Item, &PredPtr, &Found);
        LinkedInsert(List, Item, PredPtr);
    }else{
        PredPtr= NULL;
        LinkedInsert(List, Item, PredPtr);
    }
}
