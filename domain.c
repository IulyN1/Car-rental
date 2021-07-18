#include <string.h>
#include "domain.h"
#include <stdlib.h>

Masina* init_masina() {
	Masina* masina;
	masina = (Masina*)malloc(1*sizeof(Masina));
	masina->nr_inmat = (char*)malloc(20 * sizeof(char));
	masina->model = (char*)malloc(20*sizeof(char));
	masina->categorie = (char*)malloc(20*sizeof(char));
	masina->status = (char*)malloc(20 * sizeof(char));
	strcpy(masina->status, "neinchiriat");
	return masina;
}

void destruct_masina(Masina* masina) {
	free(masina->nr_inmat);
	free(masina->model);
	free(masina->categorie);
	free(masina->status);
	free(masina);
}

char* get_nr_inmat(Masina* masina) {
	return masina->nr_inmat;
}

char* get_model(Masina* masina) {
	return masina->model;
}

char* get_categorie(Masina* masina) {
	return masina->categorie;
}

void set_model(char* model,Masina* masina) {
	strcpy(masina->model, model);
}

void set_categorie(char* categorie, Masina* masina) {
	strcpy(masina->categorie, categorie);
}

char* get_status(Masina* masina) {
	return masina->status;
}

void set_status(char* status, Masina* masina) {
	strcpy(masina->status, status);
}

void set_nr_inmat(char* nr_inmat, Masina* masina) {
	strcpy(masina->nr_inmat, nr_inmat);
}