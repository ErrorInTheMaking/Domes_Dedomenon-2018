#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char BinTreeElementType;             /*� ����� ��� ��������� ��� ���
                                                ���������� ����� int */
typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum{
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);

void IdenticalBSTs(BinTreePointer root1, BinTreePointer root2, boolean*);


int main(void)
{
    BinTreePointer tree1, tree2, tree3;
    boolean t1, t2;

    CreateBST(&tree1);
    CreateBST(&tree2);
    CreateBST(&tree3);

    RecBSTInsert(&tree1, 'S');
    RecBSTInsert(&tree1, 'A');
    RecBSTInsert(&tree1, 'M'); 
    RecBSTInsert(&tree1, 'E');
    
    RecBSTInsert(&tree2, 'S');
    RecBSTInsert(&tree2, 'A');
    RecBSTInsert(&tree2, 'M'); 
    RecBSTInsert(&tree2, 'E');

    RecBSTInsert(&tree3, 'N');
    RecBSTInsert(&tree3, 'O');
    RecBSTInsert(&tree3, 'T');

    
    IdenticalBSTs(tree1 , tree2, &t1);
    if(t1) 
        printf("TREE 1 IS IDENTICAL TO TREE 2\n");
    else
        printf("TREE 1 IS NOT IDENTICAL TO TREE 2\n");

    IdenticalBSTs(tree2, tree3, &t2);
    if(t2)
        printf("TREE 2 IS IDENTICAL TO TREE 3\n");
    else
        printf("TREE 2 IS NOT IDENTICAL TO TREE 3\n");
    
    return 0;
}

void IdenticalBSTs(BinTreePointer root1, BinTreePointer root2, boolean *res)
{
    if(root1 != NULL && root2 != NULL)
    {
        if(root1->Data == root2->Data)
        {
            IdenticalBSTs(root1->LChild, root2->LChild, res);
            IdenticalBSTs(root1->RChild, root2->RChild, res);
            if(root1->LChild == root2->LChild && root1->RChild == root2->RChild)
                *res = TRUE;
        }
       
    }
}

void CreateBST(BinTreePointer *Root) 
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item) 
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else    
        if (Item < (*Root) ->Data)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item > (*Root) ->Data)
            RecBSTInsert(&(*Root) ->RChild,Item); 
        else
            printf("To %c EINAI HDH STO DDA\n", Item);     
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, 
                    boolean *Found, BinTreePointer *LocPtr)
{
    boolean stop;

    if (BSTEmpty(Root))
        *Found=FALSE;
    else 
        if (KeyValue < Root->Data)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue > Root->Data)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr)); 
            else 
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //* ����� ������ �� KeyValue �� �� ������ *)
        printf("to %d DeN BRE8HKe STO DDA\n", KeyValue);
     else
         //* ��������� ���������� ��� ����� ��� �������� ��� ���� KeyValue ��� �������� ��� 
          if (KeyValue < (*Root)->Data)  
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //* �������� ��������� *
          else 
            if (KeyValue > (*Root)->Data) 
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //* ����  ��������� *
            else                                       //* TO KeyValue ������� �������� ��� ������ *)
                if ((*Root)->LChild ==NULL)   
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //* ��� ���� �������� ����� *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL) 
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //* ���� �������� �����, ���� ��� ���� *)
                        free(TempPtr);
                   }
                   else                               //* ���� 2 ������ *)
                   {
                        //* ������ ��� INORDER �������� ��� *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL) 
                              TempPtr = TempPtr->LChild;
                        /* ���������� ��� �������� ��� ����� ��� ����������
                        ��� ���������� ��� �������� ��� �������� ������ */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        printf("L");
        RecBSTInorder(Root->LChild);
        printf("/%c ",Root->Data);
        printf("R");
        RecBSTInorder(Root->RChild);
    }
    printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        printf("/%c ",Root->Data);
        printf("L");
        RecBSTPreorder(Root->LChild);
        printf("R");
        RecBSTPreorder(Root->RChild);
    }
    printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        printf("L");
        RecBSTPostorder(Root->LChild);
        printf("R");
        RecBSTPostorder(Root->RChild);
        printf("/%c ",Root->Data);        
    }
    printf("U");
}