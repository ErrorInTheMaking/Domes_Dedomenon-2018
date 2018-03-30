//  a1f4search.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10
#define NilValue -1

typedef int ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateLList(ListPointer *List);
boolean EmptyLList(ListPointer List);
boolean FullLList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);

void menu(int *choice);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

void Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, boolean *found, ListPointer *PredPtr);

int main()
{
    ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;
    boolean found;
    
    ListElementType AnItem;
    
    int choice;
    char ch;
    
    InitializeStoragePool(Node, &FreePtr);
    printAll(AList, FreePtr, Node);
    do
    {
        menu(&choice);
        switch(choice)
        {
            case 1: CreateLList(&AList);          //DHMIOYRGIA LISTAS
                break;
            case 2:    do
            {
                printf("FreePtr=%d\n",FreePtr);
                printf("DWSE ARITHMO GIA EISAGWGH STH LISTA: ");
                scanf("%d", &AnItem);
                /*H EISAGWGH STOIXEIOY GINETAI PANTA STHN ARXH THS LISTAS (STO PX SYMPERIFERETAI WS STOIBA)
                 * SE PERIPTWSH POY 8ELW PX  TAXINOMHMENH LISTA 8A PREPEI NA YLOPOIHSW EPIPLEON SYNARTHSH SEARCH
                 * POY 8A EPISTREFEI TH TIMH THS PredPtr
                 */
                Search(FreePtr, AList, Node, AnItem, &found, &PredPtr);
                Insert(&AList, Node,&FreePtr, PredPtr, AnItem); //EISAGWGH STOIXEIOY META TH 8ESH POS STH LISTA
                printf("AList=%d\n",AList);
                printf("\nContinue Y/N: ");
                do
                {
                    scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
                printAll(AList, FreePtr, Node);
                break;
            case 3:    printf("FreePtr=%d\n",FreePtr);
                TraverseLinked(AList, Node);      //DIASXISH LISTAS
                break;
            case 4:   if (EmptyLList(AList))
                printf("Empty List\n");
            else
            {
                printAll(AList, FreePtr, Node);
                printf("DWSE TO STOIXEIO GIA DIAGRAFH: ");
                scanf("%d", &AnItem);
                Search(FreePtr, AList, Node, AnItem, &found, &PredPtr);
                Delete(&AList, Node, &FreePtr, PredPtr);  //DIAGRAFH STOIXEIOY META TH 8ESH POS STH LISTA
                printAll(AList, FreePtr, Node);
            }
                break;
            case 5:   if (EmptyLList(AList))
                printf("Empty List\n");
            else printf("Not an Empty List\n");
                break;
            case 6:   if (FullLList(FreePtr))
                printf("Full List\n");
            else printf("Not a Full List\n");
                break;
            case 7:    printAll(AList, FreePtr, Node);     //EMFANISH STORAGE POOL
                break;
            case 8:
                fprintf(stdout, "Enter an item to search in list: ");
                scanf("%d" ,&AnItem);
                Search(FreePtr, AList, Node, AnItem, &found, &PredPtr);
                if (found == FALSE) fprintf(stdout, "%d not found...\n", AnItem);
                else fprintf(stdout, "%d found!Previous position is %d\n", AnItem, PredPtr);
                break;
            
        }
    } while (choice!=9);
    //system("pause");
    return 0;
}

void Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, boolean *found, ListPointer *PredPtr)
{
    ListPointer CurrPtr;
    boolean stop = FALSE;
    
    *PredPtr = NilValue;
    
    if(!EmptyLList(List)){
        CurrPtr = List; 
        while (CurrPtr != NilValue && stop == FALSE) {
            if(Item <= Node[CurrPtr].Data){
                *found = (Item == Node[CurrPtr].Data);
                stop = TRUE;
            }
            else{
                *PredPtr = CurrPtr;
                CurrPtr = Node[CurrPtr].Next;
            }
        }
        
    }
    else fprintf(stdout, "Empty List\n");
}
void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create List\n");
    printf("2. Insert an element to List\n");
    printf("3. Traverse List\n");
    printf("4. Delete an element from the List\n");
    printf("5. Check if List is empty\n");
    printf("6. Check if List is full\n");
    printf("7. Print storage pool\n");
    printf("8. Search an item\n");
    printf("9. Exit\n");
    printf("\nChoice 1-9 : ");
    do
    {
        scanf("%d", choice);
    } while (*choice<1 && *choice>8);
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}
void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* ¢€¯ÂÙ·È:   ∆ÔÓ ›Ó·Î· Node Î·È ÙÔÓ ‰Â›ÎÙË FreePtr Ô˘ ‰Â›¯ÓÂÈ ÛÙÔÓ
 ÚÒÙÔ ‰È·ı€ÛÈÌÔ ÎﬁÌ‚Ô.
 §ÂÈÙÔ˘ÚÁ›·: ∞Ú¯ÈÎÔÔÈÂ› ÙÔÓ ›Ó·Î· Node ˆ˜ Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ· Û˘Ó‰€ÔÓÙ·˜ ÌÂÙ·Í‡
 ÙÔ˘˜ ‰È·‰Ô¯ÈÎ€˜ ÂÁÁÚ·Ê€˜ ÙÔ˘ ›Ó·Î·,
 Î·È ·Ú¯ÈÎÔÔÈÂ› ÙÔÓ ‰Â›ÎÙË FreePtr .
 ∂ÈÛÙÚ€ÊÂÈ: ∆ÔÓ ÙÚÔÔÔÈËÌ€ÓÔ ›Ó·Î· Node Î·È ÙÔÓ
 ‰Â›ÎÙË FreePtr ÙÔ˘ ÚÒÙÔ˘ ‰È·ı€ÛÈÌÔ˘ ÎﬁÌ‚Ô˘
 */
{
    int i;
    
    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=NilValue;
    *FreePtr=0;
}

void CreateLList(ListPointer *List)
/* §ÂÈÙÔ˘ÚÁ›·: ¢ËÌÈÔ˘ÚÁÂ› ÌÈ· ÎÂÓ‹ Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ·.
 ∂ÈÛÙÚ€ÊÂÈ: ŒÓ·Ó (ÌË‰ÂÓÈÎﬁ) ‰Â›ÎÙË Ô˘ ‰Â›¯ÓÂÈ ÛÂ ÎÂÓ‹ Ï›ÛÙ·
 */
{
    *List=NilValue;
}

boolean EmptyLList(ListPointer List)
/* ¢€¯ÂÙ·È:    ŒÓ·Ó ‰Â›ÎÙË List Ô˘ ‰Â›¯ÓÂÈ ÛÂ ÌÈ· Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ·.
 §ÂÈÙÔ˘ÚÁ›·: ∂Ï€Á¯ÂÈ ·Ó Ë Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ· Â›Ó·È ÎÂÓ‹.
 ∂ÈÛÙÚ€ÊÂÈ: True ·Ó Ë Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ· Â›Ó·È ÎÂÓ‹ Î·È false ‰È·ÊÔÚÂÙÈÎ¿
 */
{
    return (List==NilValue);
}

boolean FullLList(ListPointer FreePtr)
/* ¢€¯ÂÙ·È:    ªÈ· Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ·.
 §ÂÈÙÔ˘ÚÁ›·: ∂Ï€Á¯ÂÈ ·Ó Ë Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ· Â›Ó·È ÁÂÌ¿ÙË.
 ∂ÈÛÙÚ€ÊÂÈ: True ·Ó Ë Û˘Ó‰Â‰ÂÌ€ÓËÏ›ÛÙ· Â›Ó·È ÁÂÌ¿ÙË, false ‰È·ÊÔÚÂÙÈÎ¿
 */
{
    return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* ¢€¯ÂÙ·È:   ∆ÔÓ ›Ó·Î· Node Î·È ÙÔÓ ‰Â›ÎÙË FreePtr.
 §ÂÈÙÔ˘ÚÁ›·: ∞ÔÎÙ¿ €Ó·Ó "ÂÏÂ‡ıÂÚÔ" ÎﬁÌ‚Ô Ô˘ ÙÔÓ ‰Â›¯ÓÂÈ Ô ‰Â›ÎÙË˜ P.
 ∂ÈÛÙÚ€ÊÂÈ: ∆ÔÓ ‰Â›ÎÙË P Î·È ÙÔÓ ÙÚÔÔÔÈËÌ€ÓÔ  ‰Â›ÎÙË FreePtr
 Ô˘ ‰ÂÈÎÙÔ‰ÔÙÂ› ÛÙÔ ÚÒÙÔ ‰È·ı€ÛÈÌÔ ÎﬁÌ‚Ô
 */
{
    *P = *FreePtr;
    if (!FullLList(*FreePtr))
        *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* ¢€¯ÂÙ·È:    ∆ÔÓ ›Ó·Î· Node, Ô˘ ·Ó··ÚÈÛÙ¿ ÙË ‰ÂÍ·ÌÂÓ‹ ÙˆÓ ‰È·ı€ÛÈÌˆÓ ÎﬁÌ‚ˆÓ,
 €Ó·Ó ‰Â›ÎÙË TempPtr Î·È ÙÔÓ ‰Â›ÎÙË FreePtr.
 §ÂÈÙÔ˘ÚÁ›·: ∂ÈÛÙÚ€ÊÂÈ ÛÙË ‰ÂÍ·ÌÂÓ‹ ÙÔÓ ÎﬁÌ‚Ô ÛÙÔÓ ÔÔ›Ô ‰Â›¯ÓÂÈ Ô TempPtr.
 ∂ÈÛÙÚ€ÊÂÈ: ∆ÔÓ ÙÚÔÔÔÈËÌ€ÓÔ ›Ó·Î· Node Î·È ÙÔÓ ‰Â›ÎÙË FreePtr
 */
{
    Node[P].Next =*FreePtr;
    Node[P].Data = -1; /* √¯È ·Ó·ÁÎ·›· ÂÓÙÔÏ‹, ‚ÔËıËÙÈÎ‹ ÁÈ· Ó· Ê·›ÓÔÓÙ·È ÛÙËÓ
                        ÂÎÙ‡ˆÛË ÔÈ ‰È·ÁÚ·ÌÌ€ÓÔÈ ÎﬁÌ‚ÔÈ */
    *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* ¢€¯ÂÙ·È:    ªÈ· Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ·, ÙÔÓ ›Ó·Î· Node, ÙÔÓ ‰Â›ÎÙË PredPtr Î·È
 €Ó· ÛÙÔÈ¯Â›Ô Item.
 §ÂÈÙÔ˘ÚÁ›·: ∂ÈÛ¿ÁÂÈ ÛÙË Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ·, ·Ó ‰ÂÓ Â›Ó·È ÁÂÌ¿ÙË, ÙÔ ÛÙÔÈ¯Â›Ô
 Item ÌÂÙ¿ ·ﬁ ÙÔÓ ÎﬁÌ‚Ô ÛÙÔÓ ÔÔ›Ô ‰Â›¯ÓÂÈ Ô ‰Â›ÎÙË˜ PredPtr.
 ∂ÈÛÙÚ€ÊÂÈ: ∆ËÓ ÙÚÔÔÔÈËÌ€ÓË Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ·, ÙÔÓ ÙÚÔÔÔÈËÌ€ÓÔ ›Ó·Î· Node
 Î·È ÙÔÓ ‰Â›ÎÙË FreePtr.
 ∂ÍÔ‰Ô˜:     ª‹Ó˘Ì· ÁÂÌ¿ÙË˜ Ï›ÛÙ·˜, ·Ó Ë Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ· Â›Ó·È ÁÂÌ¿ÙË
 */
{
    ListPointer TempPtr;
    GetNode(&TempPtr,FreePtr,Node);
    if (!FullLList(TempPtr)) {
        if (PredPtr==NilValue)
        {
            Node[TempPtr].Data =Item;
            Node[TempPtr].Next =*List;
            *List =TempPtr;
        }
        else
        {
            Node[TempPtr].Data =Item;
            Node[TempPtr].Next =Node[PredPtr].Next;
            Node[PredPtr].Next =TempPtr;
        }
    }
    else
        printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* ¢€¯ÂÙ·È:   ªÈ· Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ· Î·È ÙÔÓ ‰Â›ÎÙË PredPtr Ô˘ ‰Â›¯ÓÂÈ
 ÛÙÔÓ ÚÔËÁÔ‡ÌÂÓÔ ÎﬁÌ‚Ô ·ﬁ ·˘ÙﬁÓ Ô˘ ı· ‰È·ÁÚ·ÊÂ›.
 §ÂÈÙÔ˘ÚÁ›·: ¢È·ÁÚ¿ÊÂÈ ·ﬁ ÙË Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ·, ·Ó ‰ÂÓ Â›Ó·È ÎÂÓ‹,
 ÙÔÓ ÚÔËÁÔ‡ÌÂÓÔ ÎﬁÌ‚Ô ·ﬁ ·˘ÙﬁÓ ÛÙÔÓ ÔÔ›Ô ‰Â›¯ÓÂÈ Ô PredPtr.
 ∂ÈÛÙÚ€ÊÂÈ: ∆ËÓ ÙÚÔÔÔÈËÌ€ÓË Ï›ÛÙ· Î·È ÙÔ ‰Â›ÎÙË FreePtr.
 ŒÍÔ‰Ô˜:     ª‹Ó˘Ì· ÎÂÓ‹˜ Ï›ÛÙ·˜, ·Ó Ë Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ· Â›Ó·È ÎÂÓ‹
 */
{
    ListPointer TempPtr ;
    
    if (!EmptyLList(*List))
        if (PredPtr == NilValue)
        {
            TempPtr =*List;
            *List =Node[TempPtr].Next;
            ReleaseNode(Node,TempPtr,FreePtr);
        }
        else
        {
            TempPtr =Node[PredPtr].Next;
            Node[PredPtr].Next =Node[TempPtr].Next;
            ReleaseNode(Node,TempPtr,FreePtr);
        }
        else
            printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* ¢€¯ÂÙ·È:    ªÈ· Û˘Ó‰Â‰ÂÌ€ÓË Ï›ÛÙ·.
 §ÂÈÙÔ˘ÚÁ›·: ∫¿ÓÂÈ ‰È¿Û¯ÈÛË ÙË˜ Û˘Ó‰Â‰ÂÌ€ÓË˜ Ï›ÛÙ·˜, ·Ó ‰ÂÓ Â›Ó·È ÎÂÓ‹.
 ŒÍÔ‰Ô˜:     ∂Í·ÚÙ¿Ù·È ·ﬁ ÙËÓ ÂÂÍÂÚÁ·Û›·
 */
{
    ListPointer CurrPtr;
    
    if (!EmptyLList(List))
    {
        CurrPtr =List;
        while (CurrPtr != NilValue)
        {
            printf("(%d: %d,%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
            CurrPtr=Node[CurrPtr].Next;
        }
        printf("\n");
    }
    else printf("Empty List ...\n");
}



