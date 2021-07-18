#ifndef VALIDATION_H
#define VALIDATION_H
#include "domain.h"
#pragma once

typedef struct {
	int ok;
	char error[100];
}Validator;

Validator valideaza(Masina* masina);
	/*
	Functie care valideaza campurile unei masini.
	masina - tip Masina*
	Post:
	returneaza valid - tip Validator
	*/

int valideaza_nr_inmat(char* nr_inmat);
	/*
	Functie care valideaza numarul de inmatriculare al unei masini.
	nr_inmat - sir de caractere de forma unui nr de inamtriculare
	Post:
	returneaza 0 daca nu este valid, si 1 daca este
	*/
#endif