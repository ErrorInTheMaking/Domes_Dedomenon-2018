#include <stdio.h>
#include <stdlib.h>

#define StackLimit 50   // το ήςιο νεηΫυοωχ τθχ στοέβαχ, εξδειλτιλΐ έσο νε 50


typedef int StackElementType;   // ο τΰποχ τφξ στοιψεέφξ  τθχ στοέβαχ
                                //εξδειλτιλΐ τΰποχ int
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

void FilterStack(StackType *Stack, StackElementType Item);

int main(int argc, char *argv[])
{
    StackElementType item;
    StackType stack;

    CreateStack(&stack);

    Push(&stack, 1);
    Push(&stack, 7);
    Push(&stack, 5);
    Push(&stack, 10);
    Push(&stack, 13);
    Push(&stack, 2);

    TraverseStack(stack);

    FilterStack(&stack, 5);

    TraverseStack(stack);

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

// °ΛΖΈ Έ ¶ΊΆΓªΈ ¶»Ό°ΑΉ·¶Ή Ζ° ªTOIXEIA ΖΈª ªΖΓΉµ°ª °¦Γ ΖΈ £¶ªΈ TOP-0

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");
}
 /*
 °ΛΖΈ Έ ¶ΊΆΓªΈ ¶ΉΑ°Ή ªΖΉª ªΈ»¶ΉΏª¶Ήª Ί°Ή ¶»Ό°ΑΉ·¶Ή Ζ° STOIXEIA ΖΈª ªΖΓΉµ°ª °¦Γ ΖΈ £¶ªΈ 0-TOP
 void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");
}
*/
void CreateStack(StackType *Stack)
/* ¤ειτοωςηέα: Άθνιοωςηεέ νια λεξά στοέβα.
   ¶πιστςΫζει: Ίεξά ªτοέβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* ΆΫψεται: »ια στοέβα Stack.
   ¤ειτοωςηέα: ¶μΫηψει αξ θ στοέβα Stack εέξαι λεξά.
   ¶πιστςΫζει: True αξ θ Stack εέξαι λεξά, False διαζοςετιλΐ
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* ΆΫψεται: »ια στοέβα Stack.
   ¤ειτοωςηέα: ¶μΫηψει αξ θ στοέβα Stack εέξαι ηενΐτθ.
   ¶πιστςΫζει: True αξ θ Stack εέξαι ηενΐτθ, False διαζοςετιλΐ
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* ΆΫψεται: »ια στοέβα Stack λαι Ϋξα στοιψεέο Item.
   ¤ειτοωςηέα: ¶ισΐηει το στοιψεέο Item στθξ στοέβα Stack αξ θ Stack δεξ εέξαι ηενΐτθ.
   ¶πιστςΫζει: Ζθξ τςοποποιθνΫξθ Stack.
   Ξκοδοχ: »άξωνα ηενΐτθχ στοέβαχ, αξ θ στοέβα Stack εέξαι ηενΐτθ
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* ΆΫψεται: »ια στοέβα Stack.
   ¤ειτοωςηέα: Άιαηςΐζει το στοιψεέο Item απή τθξ λοςωζά τθχ ªτοέβαχ αξ θ ªτοέβα δεξ εέξαι λεξά.
   ¶πιστςΫζει: Ζο στοιψεέο Item λαι τθξ τςοποποιθνΫξθ Stack.
   Ξκοδοχ:  »άξωνα λεξάχ στοέβαχ αξ θ Stack εέξαι λεξά
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void FilterStack(StackType *Stack, StackElementType Item)
{
    StackType TempStack;

    CreateStack(&TempStack);

    for(int i=Stack -> Top;i>=0; i--){
        if(Item!=Stack -> Element[i] && !EmptyStack(*Stack) ){
            Pop(Stack, &Stack -> Element[i]);
            Push(&TempStack, Stack -> Element[i]);
        }else{
            printf("Popped %d from stack", Item);
            Pop(Stack, &Item);
        }
    }
    for(int i=TempStack.Top;i>=0; i--)
        Push(Stack, TempStack.Element[i]);
}
