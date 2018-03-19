#include <stdio.h>
#include <stdlib.h>

#define StackLimit 20

typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

void TraverseStack(StackType Stack);
void menu(int *choice);

int main(int argc, char *argv[])
{
    StackElementType item ,n, x, x1;
    StackType stack, temp;
    int i;

    CreateStack(&stack);
    CreateStack(&temp);

    for(i=0;i<StackLimit;i++)
        Push(&stack, i);
    TraverseStack(stack);


    printf("\nGive n <n=19> ");
    scanf("%d", &n);
    while(n>stack.Top){
        printf("\nGive n <n=19> ");
        scanf("%d", &n);
    }

    //(a)

    Pop(&stack, &item);
    Pop(&stack, &item);

    printf("a->%d\n", item);

    //(b)

   	Pop(&stack, &item);
   	x = item;   
	Pop(&stack, &item);
	x1 = item;
	
	printf("b->%d\n", x1);
	
	Push(&stack, x1);
    Push(&stack, x);
    
	//(c)
	
    for(i=0;i<n;i++){
		Pop(&stack, &item);
		x = item;
	}
    printf("c->%d\n", x);

    //(d)
	
	for(i=0;i<n;i++){
		Pop(&stack, &item);
		x = item;
		Push(&temp, x);
	}
    printf("d->%d\n", x);
    
    while(!EmptyStack(temp)){
    	Pop(&temp, &item);
    	Push(&stack, item);
	}
	
    //(e)
   while(!EmptyStack(stack)){
	   Pop(&stack, &item);
	   x = item;
	   Push(&temp, item);   	
	}
	printf("e->%d\n", x);
	
   while(!EmptyStack(temp)){
	   Pop(&temp, &item);
	   x = item;
	   Push(&stack, item);	
	}

    //(f)
	
	i = stack.Top;
    while(stack.Element[i] >= 2){
    	Pop(&stack, &item);
    	x = item;
    	Push(&temp, item);
    	i--;
	}
	printf("f->%d\n", x);
	
	while(!EmptyStack(temp)){
		Pop(&temp, &item);
		Push(&stack, item);
	}
	//(g)

    while(!EmptyStack(stack)){
        Pop(&stack, &item);
        x = item;
    }
    printf("g->%d\n", x);
    //if(EmptyStack(stack)==TRUE) printf("Empty stack...\n");

    return 0;
}

void menu(int *choice)
{
  printf("\nXRHSIMOPOIHSE TIS PARAKATW ENTOLES GIA NA ELEGJEIS TO unit StackADT\n");
  printf("1 ---- DHMIOYRGIA STOIBAS\n");
  printf("2 ---- ADEIASMA THS STOIBAS\n");
  printf("3 ---- ELEGXOS KENHS STOIBAS\n");
  printf("4 ---  POP STOIXEIOY APO TH KORYFH THS STOIBA\n");
  printf("5 ---  PUSH STH KORYFH THS STOIBAS\n");
  printf("6 ---- EMFANISH STOIXEIWN STOIBAS (BOH8HTHKH)\n");
  printf("7 ---- EXIT\n");
  do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}
/*
void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");
}
*/

 void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");
}

void CreateStack(StackType *Stack)

{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)

{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)

{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)

{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

