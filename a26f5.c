#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int am;
    char surname[21];
    char name[21];
    char sex;
    int year;
    float vathmos;
    int line;

}BinTreeElementType;

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

void menu(int *);
void create_index(BinTreePointer *root, int*);
void add_student(BinTreePointer *root, int*);
void search(BinTreePointer Root);
void __print__(BinTreePointer root);
void print_mo(BinTreePointer root);

int main(void)
{
    int choice, line;
    BinTreePointer euretirio;
    BinTreeElementType student;

    do
    {
       menu(&choice);
       switch(choice)
       {
           case 1:
            {
                CreateBST(&euretirio);
                create_index(&euretirio, &line);
                break;
            }
            case 2:
            {
                add_student(&euretirio, &line);
                break;
            }
            case 3:
            {
                search(euretirio);
                break;
            }
            case 4:
            {
                __print__(euretirio);
                break;
            }
            case 5:
            {
                print_mo(euretirio);
                break;
            }
       }
    }while(choice!=6);
 
    return 0;
}

void print_mo(BinTreePointer root)
{
    FILE* infile;
    char termch;
    BinTreeElementType stud;
    char n[20], s[20], se;
    int a, e, nscan;
    float v;

    printf("Dose meso oro > ");
    scanf("%f", &(stud.vathmos));

    infile = fopen("foitites.dat", "r");
    
    while(1)
    {
        nscan = fscanf(infile, "%d ,%20[^,], %20[^,] , %c , %d, %f%c", &a, s, n, &se, &e  , &v , &termch);
        if(termch != '\n') 
            printf("Error");
        if(nscan == EOF) break;
        
        if(v > stud.vathmos)
            printf("%d, %s, %s, %c, %d, %.2f\n" , a, s, n,  se,  e, v );
    }

    fclose(infile);

}
void __print__(BinTreePointer Root)
{
    if (Root!=NULL) {
        
        RecBSTInorder(Root->LChild);
        printf("(%d, %d) ",Root->Data.line, Root->Data.am);
        RecBSTInorder(Root->RChild);
    }
}
void search(BinTreePointer Root)
{
    BinTreeElementType student;
    boolean found;
    BinTreePointer loc;
    FILE* infile;
    int nscan, l = 0, a;
    char info[100], termch;

    printf("Dose AM  gia anazitisi: ");
    scanf("%d", &(student.am));

    RecBSTSearch(Root, student, &found, &loc);

    if(found==TRUE)
    {
        infile = fopen("foitites.dat", "r");
        while(1)
        {
            nscan = fscanf(infile, "%d, %60[^\n]%c",&a ,info, &termch);
            if(nscan == EOF) break;
            if(loc->Data.am == a)
            {
                printf("%d, %s",a,  info);
            }
        }
    }
    else{
            printf("%d not in index\n", student.am);
        }
    
    fclose(infile);
}

void menu(int *choice)
{
    puts("\n------------------------------");
    printf("1.Dimiourgia tou index(DDA)\n");
    printf("2.Eisagogi neas eggrafis\n");
    printf("3.Anazitisi eggrafis foithth\n");
    printf("4.Ektuposi olon ton stoixeion(am)\n");
    printf("5.Ektiposi ton foithtwn me meso oro megalitero apo mia timi\n");
    printf("6.Telos\n");
    puts("------------------------------");
   
    printf("\nDialekse mia apo tis parapano epiloges: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 || *choice>6);
    
}
void create_index(BinTreePointer *root, int *line)
{
    FILE* infile;
    int nscan;
    char info[100], termch;

    BinTreeElementType student;

    student.line = 0;

    infile = fopen("foitites.dat", "r");
    if(infile == NULL)
        printf("File is empty...\n");
    
    while(1)
    {
        nscan = fscanf(infile, "%d, %50[^\n]%c", &(student.am), info, &termch);

        if(termch != '\n')
            printf("Error\n");
        if(nscan == EOF) break;
        else
            RecBSTInsert(root, student);
        
        (student.line)++;
    }

    *line = student.line- 1;

    fclose(infile);
}
void add_student(BinTreePointer *root, int *line)
{
    FILE* outfile;
    BinTreeElementType student;
    int i, num;

    student.line = *line;

    outfile = fopen("foitites.dat", "a");

    printf("\nAM: ");
    scanf("%d", &(student.am));
    printf("EPWNYMO: ");
    getchar();
    gets(student.surname);
    printf("ONOMA: ");
    gets(student.name);
    printf("FYLO: ");
    scanf("%c", &(student.sex));
    getchar();
    printf("ETOS: ");
    scanf("%d", &(student.year));
    printf("VATHMOS: ");
    scanf("%f", &(student.vathmos));
    
    fprintf(outfile, "%d, %s, %s, %c, %d, %g\n", student.am, student.surname, student.name, student.sex, student.year, student.vathmos);
    
    student.line++;
    (*line)++;

    RecBSTInsert(root, student);

    fclose(outfile);
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
        (*Root) ->Data.am = Item.am;
        (*Root) ->Data.line = Item.line;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else if (Item.am < (*Root) ->Data.am)
            RecBSTInsert(&(*Root) ->LChild,Item);
    else if (Item.am > (*Root) ->Data.am)
            RecBSTInsert(&(*Root) ->RChild, Item); 
    else
        printf("To %d EINAI HDH STO DDA\n", Item.am);     
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, 
                    boolean *Found, BinTreePointer *LocPtr)
{
    boolean stop;

    if (BSTEmpty(Root))
        *Found=FALSE;
    else 
        if (KeyValue.am < Root->Data.am){
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        }
        else
            if (KeyValue.am > Root->Data.am){
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr)); 
            }
            else 
                {
                    *Found = TRUE;
                    (*LocPtr) = Root;
                }
}
/*
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
                        ���������� ��� �������� ��� ����� ��� ����������
                        ��� ���������� ��� �������� ��� �������� ������ 
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}
*/
void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        
        RecBSTInorder(Root->LChild);
        printf("(%d, %d) ",Root->Data.line, Root->Data.am);
        RecBSTInorder(Root->RChild);
    }
   
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
