#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef char BinTreeElementType[15];      

typedef struct BinTreeNode *BinTreePointer;

struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
};

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType Item, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

void CreateDictionary(BinTreePointer *Root);
void SpellingCheck(BinTreePointer Root);

int main(int argc, char** argv)
{
    BinTreePointer myTree, CurrPtr;

    CreateBST(&myTree);
    CreateDictionary(&myTree);
    SpellingCheck(myTree);

   // InorderTraversal(myTree);

    return 0;
}

void SpellingCheck(BinTreePointer Root)
{
    FILE* infile;
    char my_word[15], termch;
    int nscan;
    boolean found;
    BinTreePointer *LocPtr;

    infile = fopen("check.txt", "r"); /***********I111F5.TXT***************/ 
    if(infile == NULL)
        printf("Error\n");

    printf("NOT in Dictionary\n---------------------\n");
    while(1)
    {
        nscan = fscanf(infile, "%s%c", my_word, &termch);
        if(nscan == EOF)
            break;
        if(termch != '\n') break;
        else
        {
            BSTSearch(Root, my_word, &found, LocPtr);
            if(!found)
                printf("%s\n", my_word);
        }
    }
    puts("");
    fclose(infile);
}

void CreateDictionary(BinTreePointer *Root)
{
    FILE* infile;
    char word[15];
    int nscan;

    infile = fopen("input.txt", "r"); /***********I112F5.TXT***************/
    if(infile == NULL) 
        printf("file empty...\n");

    while(1)
    {
        nscan  = fscanf(infile, "%s", word);
        if(nscan == EOF) break;
        else
            BSTInsert(Root, word);
    }
    fclose(infile);

}
void CreateBST(BinTreePointer *Root) 
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{   
    return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item) 
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (strcmp(Item, (LocPtr)->Data) < 0)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item, (LocPtr)->Data) > 0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %s EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr ->Data, Item);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item, Parent->Data) < 0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, 
                BinTreePointer *LocPtr)
{
  
    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue, (*LocPtr)->Data) < 0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue, (*LocPtr)->Data) > 0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    } 
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, 
    BinTreePointer *LocPtr, BinTreePointer *Parent)
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (KeyValue < (*LocPtr)->Data) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue > (*LocPtr)->Data) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
{

   BinTreePointer  
   n,                   //������� ���� ����� ��� �������� ��� ���� KeyValue *)
   Parent,              // ������� ��� n � ��� nNext
   nNext,               // ����������������� �������� ��� n 
   SubTree;             // ������� ���� ��������� ��� n
   boolean Found;       // TRUE AN TO �������� KeyValue EINAI ������� ��� ��� *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %s DEN EINAI STO DDA\n", KeyValue);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // ������ ���� �������� �� ��� ������
                 //���� ��� ���������������� ������� ��� ��� ������ ���
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* ��������� ��� ������������ ��� nNext ���� n ��� 
                ������ ��� n ���� �� ������� ���� ������� */
                strcpy(n->Data, nNext->Data);
               // n->Data = nNext->Data;
                n = nNext;
          } //����������� �� ��� ��������� ��� � ������ ���� �� ���� 1 �����
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)      
                  Parent->LChild = SubTree;
               else                            
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s\n",Root->Data);
        InorderTraversal(Root->RChild);
    }
}