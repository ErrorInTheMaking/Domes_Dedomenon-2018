#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define HMax 10         
#define VMax 30             
#define EndOfList -1        
                                
typedef char ListElementType[7];  

typedef struct {
	char RecKey[8];
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   
    int Size;                
	int SubListPtr;         
    int StackPtr;           
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(char key[]);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList, char KeyArg[],int *Loc,int *Pred);
void SearchHashList(HashListType HList,char KeyArg[],int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,char DelKey[]);

void Print_HashList(HashListType HList);
void menu(int *choice);
void PrintPinakes(HashListType HList);
long to_ascii(char arr[]);
void read_file(HashListType *hash);
int findAverage(char arr[]);
void Search(HashListType HList, char KeyArg[8], char password[7], int *found);

int main(void)
{
    HashListType user;
    char ch;
    ListElm new_user;
    int loc, pred, found;
    
    CreateHashList(&user);
    
    read_file(&user);

    do
    {
        printf("USERNAME: ");
        scanf("%s", new_user.RecKey);
        printf("PASSWORD: ");
        scanf("%s", new_user.Data);
     
        Search(user, new_user.RecKey, new_user.Data, &found);
        if(found == 1)
            printf("You have logged in to the system\n");
        else if(found == 2 || found == 0)
            printf("Access is forbidden: Wrong user ID\n");
        else if(found == 3)
            printf("Access is forbidden: Wrong password\n");
        getchar();
        
        printf("New entry? (y/n): ");
        scanf("%c", &ch);
        if(toupper(ch) == 'Y') continue;

    }while(toupper(ch) != 'N');
    
    return 0;
}
void read_file(HashListType *hash)
{
    FILE* infile;
    char termch;
    int nscan;
    ListElm info;

    infile = fopen("I5f6.txt", "r");
    if(infile == NULL) printf("Error\n");

    while(1)
    {
        nscan = fscanf(infile , "%s%s", info.RecKey, info.Data);
        info.Link = EndOfList;
        if(nscan == EOF)
            break;
        else
            AddRec(hash, info);
        
    }
    fclose(infile);
}

int findAverage(char arr[])
{
    int size = strlen(arr);
    int i , v[size];
    int ascii;

    for( i = 0 ; i < size; ++i)
        v[i] = arr[i];
    
    ascii = (arr[0]  + arr[size-1])/2;

    return ascii;
}
long to_ascii(char arr[])
{
    int size = strlen(arr);
    int i , v[size];
    char string_arr[size][3];
    char s[20] = "\0";
    long long ascii;

    for( i = 0 ; i < size; ++i)
        v[i] = arr[i];
    for (i = 0; i < size; i++) {
        sprintf(string_arr[i], "%d", v[i]); 
        strcat(s, string_arr[i]);
    }
    ascii = atoll(s);

    return ascii;
}

int HashKey(char Key[])
{
    int avg = findAverage(Key);
	return avg%HMax;
}

void CreateHashList(HashListType *HList)
{
	int index;

	HList->Size=0;           //���������� ��� ���� �����
	HList->StackPtr=0;       

    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		strcpy(HList->List[index].Data, "NULL");
		index=index+1;
	}
	HList->List[index].Link=EndOfList;

	/*printf("HashTable\n");
	for (index=0;index<HMax;index++)
	   printf("%d: %d\n",index,HList->HashTable[index]);

    printf("List of keys\n");
	for (index=0;index<=VMax-1;index++)
	   printf("%d\t%d\n",index,HList->List[index].Link);
    */
}

boolean FullHashList(HashListType HList)
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList, char KeyArg[8],int *Loc,int *Pred)
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey, KeyArg) == 0)
        {
            *Loc = Next;
            Next = EndOfList;
        }
        else{
            *Pred = Next;
            Next = HList.List[Next].Link;
        }
	}
}
void SearchHashList(HashListType HList, char KeyArg[8],int *Loc,int *Pred)
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
{
	int Loc, Pred, New, HVal, found;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New] = InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}


void Print_HashList(HashListType HList)
{
   int i, SubIndex;

     printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
          for (i=0; i<HMax;i++)
              printf("%d| ",i);
          printf("\n");
          for (i=0; i<HMax;i++)
              printf("%d| ",HList.HashTable[i]);
          printf("\n");

          printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   printf("[%s, %s, %d]",HList.List[SubIndex].RecKey,HList.List[SubIndex].Data,HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
              printf("TELOS % dHS YPO-LISTAS\n", i);
          }

          printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
          SubIndex = HList.StackPtr;
          while ( SubIndex != EndOfList )
          {
                printf("%d <= ",SubIndex);
                SubIndex = HList.List[SubIndex].Link;
          }
          printf("TELOS\n");

          printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
          printf("========================================\n");
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. EISAGWGH EGGRAFHS\n");
    printf("2. DIAGRAFH EGGRAFHS\n");
    printf("3. ANAZHTHSH EGGRAFHS\n");
    printf("4. EMFANISH DOMHS\n");
    printf("5. EMFANISH PINAKWN (BOH8HTIKH\n");
    printf("6. EXIT\n");
    printf("\nCHOICE: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d| ",i);
    printf("\n");
    for (i=0; i<HMax;i++)
         printf("%d| ",HList.HashTable[i]);
    printf("\n");


	printf("Hash List\n");
    for (i=0;i<=HList.Size-1;i++)
	   printf("%d) %s, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");
}
void Search(HashListType HList, char KeyArg[8], char password[7], int *found)
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*found = 0;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
	
        int Next;
        Next=HList.SubListPtr;

        while(Next!=EndOfList)
        {
            if (strcmp(HList.List[Next].RecKey, KeyArg) == 0 && strcmp(HList.List[Next].Data, password) == 0)
            {

                Next = EndOfList;
                *found = 1;
            }
            else if(strcmp(HList.List[Next].RecKey, KeyArg) != 0)
            {
                
                Next = EndOfList;
                *found = 2;
                
            }
            else if((strcmp(HList.List[Next].RecKey, KeyArg) == 0) && (strcmp(HList.List[Next].Data, password) != 0))
            {
               
                Next = EndOfList;  
                *found = 3;  
            }
            else{
                Next = HList.List[Next].Link;
            }
        }
    }
}