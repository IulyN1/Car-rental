#include "service.h"
#include <stdio.h>
#include <stdlib.h>
#include "infrastructure.h"
#include <string.h>

void adauga_masina_UI() {
	int ret;
	char nr_inmat[20];
	char model[20];
	char categorie[20];
	printf("Nr_inmatriculare: ");
	ret = scanf("\n%[^\n]s", nr_inmat);
	printf("Model: ");
	ret = scanf("\n%[^\n]s",model);
	printf("Categorie: ");
	ret = scanf("\n%[^\n]s",categorie);
	adauga_masina(nr_inmat, model, categorie);
}

void afiseaza_UI() {
	int i;
	if (masini->lungime == 0) {
		printf("Nu exista masini!\n");
		return;
	}
	for (i = 0; i < masini->lungime; i++) {
		printf("Nr_inmat: %s, Model: %s, Categorie: %s, Status: %s\n", get_nr_inmat(masini->elemente[i]),
			get_model(masini->elemente[i]), get_categorie(masini->elemente[i]),
			get_status(masini->elemente[i]));
	}
}

void actualizeaza_masina_UI() {
	int ret;
	char nr_inmat[20];
	char model[20];
	char categorie[20];
	printf("Nr_inmatriculare: ");
	ret = scanf("\n%[^\n]s", nr_inmat);
	printf("Model nou: ");
	ret = scanf("\n%[^\n]s", model);
	printf("Categorie noua: ");
	ret = scanf("\n%[^\n]s", categorie);
	actualizeaza_masina(nr_inmat, model, categorie);
}

void inchiriaza_masina_UI() {
	int ret;
	char nr_inmat[20];
	printf("Nr_inmatriculare: ");
	ret = scanf("\n%[^\n]s", nr_inmat);
	inchiriere_masina(nr_inmat);
}

void returneaza_masina_UI() {
	int ret;
	char nr_inmat[20];
	printf("Nr_inmatriculare: ");
	ret = scanf("\n%[^\n]s", nr_inmat);
	returnare_masina(nr_inmat);
}

void filtrare_categorie_UI() {
	char categorie[20];
	int ret;
	printf("Categorie: ");
	ret = scanf("\n%[^\n]s", categorie);
	MasiniRepo* masini_repo = filtreaza_categorie(categorie);
	if (masini_repo->lungime == 0) {
		printf("Nu exista masini de aceasta categorie!\n");
		return;
	}
	for (int i = 0; i < masini->lungime; i++) {
		printf("Nr_inmat: %s, Model: %s, Categorie: %s, Status: %s\n", get_nr_inmat(masini->elemente[i]),
			get_model(masini->elemente[i]), get_categorie(masini->elemente[i]),
			get_status(masini->elemente[i]));
	}
	destruct_repo(masini_repo);
}

void filtrare_model_UI() {
	char model[20];
	int ret;
	printf("Model: ");
	ret = scanf("\n%[^\n]s", model);
	MasiniRepo* masini_repo = filtreaza_model(model);
	if (masini_repo->lungime == 0) {
		printf("Nu exista masini de acest model!\n");
		return;
	}
	for (int i = 0; i < masini_repo->lungime; i++) {
		printf("Nr_inmat: %s, Model: %s, Categorie: %s, Status: %s\n", get_nr_inmat(masini_repo->elemente[i]),
			get_model(masini_repo->elemente[i]), get_categorie(masini_repo->elemente[i]),
			get_status(masini_repo->elemente[i]));
	}
	destruct_repo(masini_repo);
}

void sortare_UI(int type,int order) {
	MasiniRepo* masini_repo = sorteaza(type,order);
	for (int i = 0; i < masini_repo->lungime; i++) {
		printf("Nr_inmat: %s, Model: %s, Categorie: %s, Status: %s\n", get_nr_inmat(masini_repo->elemente[i]),
			get_model(masini_repo->elemente[i]), get_categorie(masini_repo->elemente[i]), 
			get_status(masini_repo->elemente[i]));
	}
	destruct_repo(masini_repo);
}

void menu() {
	printf("0. Exit\n");
	printf("1. Afiseaza masini\n");
	printf("2. Adaugare masina\n");
	printf("3. Actualizare masina\n");
	printf("4. Inchiriere/returnare masina\n");
	printf("5. Vizualizare masini dupa criteriu\n");
	printf("6. Sortare masini dupa criteriu\n\n");
}

void run() {
	int ret;
	char optiune[100],tip[100];
	menu();
	printf("Optiune: ");
	ret = scanf("%s", optiune);
	while (strcmp(optiune,"0") != 0) {
		if (strcmp(optiune, "1") == 0) {
			afiseaza_UI();
		}
		else if (strcmp(optiune, "2") == 0) {
			adauga_masina_UI();
		}
		else if (strcmp(optiune, "3") == 0) {
			actualizeaza_masina_UI();
		}
		else if (strcmp(optiune, "4") == 0) {
			printf("1. Inchiriere\n2. Returnare\n");
			printf("Optiune inchiriere/returnare: ");
			ret = scanf("%s", tip);

			if (strcmp(tip, "1") == 0) {
				inchiriaza_masina_UI();
			}
			else if (strcmp(tip, "2") == 0) {
				returneaza_masina_UI();
			}
			else {
				printf("Optiune invalida!\n");
			}			
		}
		else if (strcmp(optiune, "5") == 0) {
			printf("1. Filtrare dupa categorie\n2. Filtrare dupa model\n");
			printf("Optiune filtrare: ");
			ret = scanf("%s", tip);

			if (strcmp(tip, "1") == 0) {
				filtrare_categorie_UI();
			}
			else if (strcmp(tip, "2") == 0) {
				filtrare_model_UI();
			}
			else {
				printf("Optiune invalida!\n");
			}
		}
		else if (strcmp(optiune, "6") == 0) {
			printf("1. Sortare dupa categorie\n2. Sortare dupa model\n");
			printf("Optiune sortare categorie/model: ");
			ret = scanf("%s", tip);

			if (strcmp(tip, "1") == 0) {
				printf("1. Sortare crescatoare\n2. Sortare descrescatoare\n");
				printf("Optiune sortare crescator/descrescator: ");
				ret = scanf("%s", tip);

				if (strcmp(tip, "1") == 0) {
					sortare_UI(1,1);
				}
				else if (strcmp(tip, "2") == 0) {
					sortare_UI(1,2);
				}
				else {
					printf("Optiune invalida!\n");
				}
			}
			else if (strcmp(tip, "2") == 0) {
				printf("1. Sortare crescatoare\n2. Sortare descrescatoare\n");
				printf("Optiune sortare crescator/descrescator: ");
				ret = scanf("%s", tip);

				if (strcmp(tip, "1") == 0) {
					sortare_UI(2,1);
				}
				else if (strcmp(tip, "2") == 0) {
					sortare_UI(2,2);
				}
				else {
					printf("Optiune invalida!\n");
				}
			}
			else {
				printf("Optiune invalida!\n");
			}
		}
		else {
			printf("Comanda invalida!\n");
		}
		printf("Optiune: ");
		ret = scanf("%s", optiune);
	}
	printf("Bye!");
}