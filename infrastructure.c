#include "domain.h"
#include "infrastructure.h"
#include <stdlib.h>
#include <string.h>

MasiniRepo* init_repo() {
	MasiniRepo* masini;
	masini = (MasiniRepo*)malloc(sizeof(MasiniRepo));
	masini->lungime = 0;
	masini->capacitate = 2;
	masini->elemente = (Masina**)malloc(masini->capacitate*sizeof(Masina*));	
	return masini;
}

void destruct_repo(MasiniRepo* masini) {
	int i;
	for (i = 0; i < masini->lungime; i++) {
		destruct_masina(masini->elemente[i]);
	}
	free(masini->elemente);
	free(masini);
}

void resize(MasiniRepo* masini) {
	int capacitate_noua = 2 * masini->capacitate;
	Masina** copie_masini = (Masina**)malloc(capacitate_noua * sizeof(Masina*));
	for (int i = 0; i < masini->lungime; i++) {
		copie_masini[i] = masini->elemente[i];
	}
	free(masini->elemente);
	masini->elemente = copie_masini;
	masini->capacitate = capacitate_noua;
}

void adauga(MasiniRepo* masini,Masina* masina) {
	int lung = masini->lungime;
	if (lung == masini->capacitate) {
		resize(masini);
	}
	masini->elemente[lung] = masina;
	masini->lungime++;
}

Masina* cauta(MasiniRepo* masini,char* nr_inmat) {
	int i;
	for (i = 0; i < masini->lungime; i++) {
		if (strcmp(get_nr_inmat(masini->elemente[i]),nr_inmat) == 0) {
			return masini->elemente[i]; } }
	return 0;
}

void actualizeaza(MasiniRepo* masini,Masina* masina_noua) {
	char* nr_inmat = get_nr_inmat(masina_noua);
	Masina* masina = cauta(masini,nr_inmat);
	char* model = get_model(masina_noua);
	char* categorie = get_categorie(masina_noua);
	set_model(model, masina);
	set_categorie(categorie, masina);
}
