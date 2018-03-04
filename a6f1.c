#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define arxi  65
#define megisto_plithos 91          //μέγιστο πλήθος στοιχείων συνόλου

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Katholiko(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean KenoSynolo(typos_synolou synolo);
boolean IsaSynola(typos_synolou s1, typos_synolou s2);
boolean Yposynolo(typos_synolou s1, typos_synolou s2);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);
void menu(int *choice);
void displayset(typos_synolou set);
void createAlphabetSet(typos_synolou set);
void createVowelSet(typos_synolou set);
boolean isVowel(char x, typos_synolou set);
int vowelCount(char v[16], typos_synolou set);

int main()
{
    typos_synolou alphabet, vowels;
    char ch, str[16];
    int i, j;
    boolean result;
    stoixeio_synolou vCount;
    
	Dimiourgia(alphabet);
	createAlphabetSet(alphabet);
	//displayset(alphabet); 
	
	Dimiourgia(vowels);
	createVowelSet(vowels);
	
	puts("To programma auto metra ton arithmo ton fwnhenton mias sumvoloseiras 16 xaraktiron, gia eksodo patiste <exit>");
	
	while(TRUE){
		
		vCount = 0;
		
		printf("Parakalw eisagete mia sumvoloseira KEFALAIWN TO POLY 16 XARAKTHRWN:");
		gets(str);
		
		if(strcmp(str, "exit") == 0 ) exit(0);
		
		for(i=0;i<strnlen(str, 16);i++){
			
			if(Melos(str[i], alphabet) ==FALSE){
				for(j=0;j<127;j++)
					if( str[i] == j) printf("Invalid character detected: %d\n", j);
			}
			if(isVowel(str[i], vowels) == TRUE){
				vCount = vowelCount(str, vowels);
		    }
			
		}
		printf("Number of vowels: %d\n", vCount);
		
		for(i=0;i<16;i++) 
			str[i]= 0;
	}
		
	return 0;
}
int vowelCount(char v[16], typos_synolou set)
{
	int count=0;
	int i;
	
	for( i=0; i<16; i++)
		if(Melos(v[i], set) == TRUE) count++;
	return count;
}
void createAlphabetSet(typos_synolou set)
{
	stoixeio_synolou i;
	
	for(i=arxi; i< megisto_plithos; ++i)
		set[i] = TRUE;
}
boolean isVowel(char x, typos_synolou set)
{
	stoixeio_synolou i;
	
	if(Melos(x, set)) return TRUE;
	else return FALSE;
}
void createVowelSet(typos_synolou set)
{
	stoixeio_synolou ch;
	
	for(ch=arxi; ch<megisto_plithos; ++ch)
		if (ch=='A' || ch=='E' || ch=='I' ||ch=='O' ||  ch=='U' || ch=='Y')
			set[ch] = TRUE;

}
void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Katholiko(typos_synolou synolo)
/* Δέχεται:     Ένα σύνολο.
   Λειτουργία: Δημιουργεί ένα σύνολο με όλα τα στοιχεία παρόντα,
                έτσι όπως ορίστηκε στο τμήμα δηλώσεων του προγράμματος.
   Επιστρέφει: Το καθολικό σύνολο που δημιουργήθηκε
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}

void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:     Ένα σύνολο και ένα στοιχείο.
   Λειτουργία:  Διαγράφει το στοιχείο από το σύνολο.
   Επιστρέφει:  Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = FALSE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}

boolean KenoSynolo(typos_synolou synolo)
/*
Δέχεται: Ένα σύνολο.
 Λειτουργία: Ελέγχει αν το σύνολο είναι κενό.
 Επιστρέφει: Επιστρέφει TRUE αν το σύνολο είναι κενό και FALSE διαφορετικά
*/
{
    stoixeio_synolou i;
    boolean keno;

    keno=TRUE;
    i = 0;

    while (i < megisto_plithos  && keno) {
        if (Melos(i, synolo))
            keno = FALSE;
        else
            i++;
    }
    return keno;
}

boolean IsaSynola(typos_synolou s1, typos_synolou s2)
/* Δέχεται:     Δύο σύνολα s1 και s2.
   Λειτουργία: Ελέγχει αν τα δύο σύνολα είναι ίσα.
   Επιστρέφει: Επιστρέφει TRUE αν τα δύο σύνολα έχουν τα ίδια στοιχεία και FALSE διαφορετικά
*/
{
    stoixeio_synolou i;
    boolean isa;

    isa = TRUE;
    i=0;
    while (i < megisto_plithos && isa)
        if (Melos(i,s1) != Melos(i,s2))
            isa = FALSE;
        else
            i++;
    return isa;
}

boolean Yposynolo(typos_synolou s1, typos_synolou s2)
/* Δέχεται:     Δύο σύνολα s1 και s2.
   Λειτουργία: Ελέγχει αν το σύνολο s1 είναι υποσύνολο του s2.
   Επιστρέφει: Επιστρέφει true αν το σύνολο s1 είναι ένα υποσύνολο του s2,
                δηλαδή αν κάθε στοιχείο του s1 είναι και στοιχείο του s2
*/
{
    stoixeio_synolou i;
    boolean yposyn;

    yposyn = TRUE;
    i=0;
    while (i < megisto_plithos && yposyn)
        if (Melos(i, s1) && !Melos(i, s2))
            yposyn = FALSE;
        else
            i++;
    return yposyn;
}

void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi)
/* Δέχεται:     Δύο σύνολα s1 και s2.
   Λειτουργία: Δημιουργεί ένα νέο σύνολο με τα στοιχεία που ανήκουν ή στο s1 ή
                στο s2 ή και στα δύο σύνολα.
   Επιστρέφει: Επιστρέφει το σύνολο enosi που προκύπτει από την ένωση των συνόλων s1 και s2
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        enosi[i] = Melos(i, s1) || Melos(i, s2);
}

void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi)
/* Δέχεται:     Δύο σύνολα s1 και s2.
   Λειτουργία: Δημιουργεί ένα νέο σύνολο με τα στοιχεία που ανήκουν και στα δύο σύνολα s1 και s2.
   Επιστρέφει: Επιστρέφει το σύνολο tomi που προκύπτει από την τομή των συνόλων s1 και s2
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        tomi[i] = Melos(i, s1) && Melos(i, s2);
}

void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora)
/* Δέχεται: Δύο σύνολα s1 και s2.
 Λειτουργία: Δημιουργεί ένα νέο σύνολο με τα στοιχεία που ανήκουν στο σύνολο s1 και δεν ανήκουν στο s2.
 Επιστρέφει: Επιστρέφει το σύνολο diafora που προκύπτει από την διαφορά των συνόλων s1-s2.
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        diafora[i] = Melos(i, s1) && (!Melos(i, s2));
}
void menu(int *choice)
{
  printf("\nXRHSIMOPOIHSE TIS PARAKATW ENTOLES GIA NA ELEGJEIS TO unit SetADT\n");
  printf("1 ---- DHMIOYRGIA SYNOLOU\n");
  printf("2 ---- KA8OLIKO\n");
  printf("3 ---- EISAGWGH\n");
  printf("4 ---  DIAGRAFH\n");
  printf("5 ---  MELOS\n");
  printf("6 ---- KENO SYNOLO\n");
  printf("7 ---- ISA SYNOLA\n");
  printf("8 ---- YPOSYNOLO\n");
  printf("9 ---- ENOSH 2 SYNOLWN\n");
  printf("10 ---- TOMH 2 SYNOLWN\n");
  printf("11 ---- DIAFORA SYNOLOU\n");
  printf("12 ---- EXIT\n");
  printf("\nChoice 1-12: ");
  do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>12);
}


void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=arxi;i < megisto_plithos;i++)
	{
		if(set[i])
			printf(" %c", i);
	}
	printf("\n");
}

