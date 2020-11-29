#include <stdlib.h>
#include <stdio.h>

#include "tab.h"

#define TAILLEDEPART 100
#define TAILLEPLUS 50
 
int* myTab2 = NULL;

int main() {

	myTab2 = (int*)malloc(TAILLEDEPART * sizeof(int));
	int TAB2SIZE = TAILLEDEPART;

	if (myTab2 != NULL) {
		InitialisationTableau(myTab2, TAB2SIZE); // initialisation tableau 
	}
	else {
		printf("mémoire insuffisante");
		return(-1);
	}
	for (int i = 0; i < TAILLEDEPART; i++) {   //remplissage 
		*(myTab2 + i) = i + 1;
	}
	AfficheTableau(myTab2, TAB2SIZE, 20);  //affichage valeur


	free(myTab2);  // libération mémoire mémoire

}