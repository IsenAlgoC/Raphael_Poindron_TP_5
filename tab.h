#pragma once

#include <stdlib.h>
#include <stdio.h>

#define TAILLEDEPART 100
#define TAILLEPLUS 50

int InitialisationTableau(int* tab, int size) {
	if (tab == NULL || size < 0) {  // initialisation du tableau impossible
		return(-1);
	}

	else {                                      // si possible
		for (int i = 0; i < size; i++) {         // initialisation des zéros
			*(tab + i) = 0;
		}
		return(size);
	}
}

int AfficheTableau(int* tab, int size, int nbElts) {
	if (tab == NULL || size < 0 || size < nbElts) { //affichage impossible
		return(-1);
	}
	else {
		for (int i = 0; i < nbElts; i++) {   // affichage de chaque element
			printf(" %d", *(tab + i));        
		}
		return(0);
	}
}

int AjoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	int i = 0;
	if (size < 0 || tab == NULL) {
		return -1;
	}
	else {
		if (*nbElts >= *size) {
			int* test_tab = tab;
			tab = (int*)realloc(tab, (*size + TAILLEPLUS) * sizeof(int));
			if (test_tab == NULL) {
				tab = test_tab;
				return -1;
			}
			for (int i = 0; i < TAILLEPLUS; i++) {
				*(tab + *size + i) = 0;
			}
			*size += TAILLEPLUS;
		}
		*(tab + *nbElts) = element;
		*nbElts += 1;
		return *nbElts;
	}
}
