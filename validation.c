#include <string.h>
#include "domain.h"
#include "validation.h"
#include <ctype.h>
#include <stdio.h>

int valideaza_nr_inmat(char* nr_inmat) {
	int lung = strlen(nr_inmat)+1;
	if(lung != 10) {
		return 0;
	}
	char space = ' ';
	if (isupper(nr_inmat[0]) && isupper(nr_inmat[1])) {
		if (nr_inmat[2] == space) {
			if (isdigit(nr_inmat[3]) && isdigit(nr_inmat[4])){
				if (nr_inmat[5] == space) {
					if (isupper(nr_inmat[6]) && isupper(nr_inmat[7]) && isupper(nr_inmat[8])) {	
						return 1;
					}
				}
			}
		}
	}
	if (nr_inmat[0]=='B') {
		if (nr_inmat[1] == space) {
			if (isdigit(nr_inmat[2]) && isdigit(nr_inmat[3]) && isdigit(nr_inmat[4])) {
				if (nr_inmat[5] == space) {
					if (isupper(nr_inmat[6]) && isupper(nr_inmat[7]) && isupper(nr_inmat[8])) {
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

Validator valideaza(Masina* masina) {
	Validator valid;
	valid.ok = 1;
	strcpy(valid.error,"");
	if (valideaza_nr_inmat(get_nr_inmat(masina)) == 0 ) {
		strcat(valid.error,"Nr. inmatriculare invalid!\n");
		valid.ok = 0;
	}
	if (strcmp(get_model(masina),"") == 0) {
		strcat(valid.error, "Model invalid!\n");
		valid.ok = 0;
	}
	if (strcmp(get_categorie(masina), "") == 0) {
		strcat(valid.error, "Categorie invalida!\n");
		valid.ok = 0;
	}
	return valid;
}