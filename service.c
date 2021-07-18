#include <string.h>
#include "validation.h"
#include "infrastructure.h"
#include "domain.h"
#include <stdio.h>
#include "utils.h"

void adauga_masina(char* nr_inmat, char* model, char* categorie) {
	Masina* masina;
	masina = init_masina();
	strcpy(masina->nr_inmat, nr_inmat);
	strcpy(masina->model, model);
	strcpy(masina->categorie, categorie);
	Validator valid = valideaza(masina);
	if (valid.ok == 1) {
		if (cauta(masini,nr_inmat) != 0) {
			printf("ID existent!\n");
			destruct_masina(masina);
			return;
		}
		adauga(masini,masina);
	}
	else {
		printf("%s", valid.error);
		destruct_masina(masina);
	}
}

void actualizeaza_masina(char* nr_inmat, char* model, char* categorie) {
	Masina* masina;
	masina = init_masina();
	strcpy(masina->nr_inmat, nr_inmat);
	strcpy(masina->model, model);
	strcpy(masina->categorie, categorie);
	Validator valid = valideaza(masina);
	if (valid.ok == 1) {
		if (cauta(masini,nr_inmat) == 0) {
			printf("ID inexistent!\n");
			destruct_masina(masina);
			return;
		}
		actualizeaza(masini, masina);
	}
	else {
		printf("%s", valid.error);
	}
	destruct_masina(masina);
}

void inchiriere_masina(char* nr_inmat) {
	Masina* masina = cauta(masini,nr_inmat);
	if (cauta(masini,nr_inmat) != 0) {
		set_status("inchiriat", masina);
	}
	else {
		printf("ID inexistent!\n");
	}
}

void returnare_masina(char* nr_inmat) {
	Masina* masina = cauta(masini,nr_inmat);
	if (cauta(masini,nr_inmat) != 0) {
		set_status("neinchiriat", masina);
	}
	else {
		printf("ID inexistent!\n");
	}
}

Masina* copie_masina(Masina* masina) {
	Masina* masina_copy = init_masina();
	set_nr_inmat(get_nr_inmat(masina), masina_copy);
	set_model(get_model(masina), masina_copy);
	set_categorie(get_categorie(masina), masina_copy);
	set_status(get_status(masina), masina_copy);
	return masina_copy;
}

MasiniRepo* filtreaza_categorie(char* categorie) {
	MasiniRepo* masini_good = init_repo();
	for (int i = 0; i < masini->lungime; i++) {
		if (strcmp(get_categorie(masini->elemente[i]), categorie) == 0) {
			Masina* masina_copie = copie_masina(masini->elemente[i]);
			adauga(masini_good, masina_copie);
		}
	}
	return masini_good;
}

MasiniRepo* filtreaza_model(char* model) {
	MasiniRepo* masini_good = init_repo();
	for (int i = 0; i < masini->lungime; i++) {
		if (strcmp(get_model(masini->elemente[i]), model) == 0) {
			Masina* masina_copie = copie_masina(masini->elemente[i]);
			adauga(masini_good, masina_copie);
		}
	}
	return masini_good;
}

MasiniRepo* copie_masini(MasiniRepo* masini_repo) {
	MasiniRepo* masini_copy = init_repo();
	for (int i = 0; i < masini_repo->lungime; i++) {
		Masina* masina_copie = copie_masina(masini_repo->elemente[i]);
		adauga(masini_copy, masina_copie);
	}
	return masini_copy;
}

int compara(Masina* masina1, Masina* masina2, int type) {
	if (type == 1) {
		return strcmp(masina1->categorie, masina2->categorie)>0;}
	else{
		return strcmp(masina1->model, masina2->model)>0;
	}
}

MasiniRepo* sorteaza(int type,int order){
	MasiniRepo* copy_masini = copie_masini(masini);
	MasiniRepo* masini_sorted = sort(copy_masini,compara,type,order);
	return masini_sorted;
}
