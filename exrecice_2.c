#include <stdlib.h>
#include <stdio.h>
#define TAILLEINITIALE 10

typedef struct Tableau {
	int* elt;	
	int size;	
	int eltsCount;	
} TABLEAU;

TABLEAU newArray() {
	TABLEAU tab;                                           
	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));  
	tab.size = TAILLEINITIALE;                             
	tab.eltsCount = 0;                                     
	for (int i = 0; i < tab.size; i++) {	               
		*(tab.elt + i) = 0;
	}
	return(tab);
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	tab->elt = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));
	for (int i = tab->size; i < tab->size + incrementValue; i++) {
		*(tab->elt + i) = 0;		
	}
	tab->size = tab->size + incrementValue;
	if (tab->elt == NULL) {  
		return(-1);
	}
	else {                  
		return(tab->size);
	}
}

int setElement(TABLEAU* tab, int pos, int element) {
	if (tab->elt == NULL) {		
		return(0);
	}
	else {                      
		if (pos > tab->size) {  
			incrementArraySize(tab, pos - tab->size);
			for (int i = tab->size; i <= pos - tab->size; i++) {
				*(tab->elt + i) = 0;
			}
			tab->size += (pos - tab->size);
		}
		if (*(tab->elt + pos - 1) == 0) {  
			tab->eltsCount += 1;
		}
		*(tab->elt + pos - 1) = element;
		return(pos);
	}
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {

	if (tab->elt == NULL) {
		return(-1);
	}
	else {
		int tmp;
		if (startPos > endPos) {
			tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		for (tmp = startPos - 1; tmp < endPos; tmp++) {
			printf_s("%d", *(tab->elt + tmp));
		}
		return(0);
	}
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	int tmp;
	if (tab->elt == NULL) {
		return(-1);
	}
	else {
		if (startPos > endPos) {
			tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		for (tmp = 0; tmp < tab->size - endPos; tmp++) {
			*(tab->elt + startPos - 1 + tmp) = *(tab->elt + endPos + tmp);
		}
		tab->elt = (int*)realloc(tab->elt, (tab->size - endPos + startPos) * sizeof(int));
		tab->size = tab->size - endPos + startPos;
		return(tab->size);
	}
}

void main() {
	TABLEAU tab;
	tab = newArray();
	printf("\n");
	displayElements(&tab, 1, TAILLEINITIALE); //affichage vleur

	printf("\n");
	incrementArraySize(&tab, 2);
	displayElements(&tab, 1, TAILLEINITIALE + 2); //augmentation taille

	printf("\n"); 
	setElement(&tab, 9, 5); // ajout de valeur
	displayElements(&tab, 1, TAILLEINITIALE + 2);

	printf("\n");
	deleteElements(&tab, 9, 10); // supprsion element 
	displayElements(&tab, 1, TAILLEINITIALE);

	free(tab.elt);
}