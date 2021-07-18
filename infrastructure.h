#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H
#pragma once
#include "domain.h"

typedef struct {
	/*
	Structura de repository care are o lista de masini si lungimea acesteia.
	*/
	Masina** elemente;
	int lungime;
	int capacitate;
}MasiniRepo;

MasiniRepo* masini;

MasiniRepo* init_repo();
	/*
	Functie care initializeaza repo-ul de masini.
	*/

void destruct_repo(MasiniRepo* masini);
	/*
	Functie care distruge repo-ul de masini la terminarea programului.
	masini - repository de masini
	*/

void resize(MasiniRepo* masini);
	/*
	Functie care dubleaza capacitatea repo-ului de masini cand este nevoie de mai mult spatiu.
	masini - repository de masini
	*/

void adauga(MasiniRepo* masini,Masina* masina);
	/*
	Functie care adauga o masina in repository.
	masini - repository de masini
	masina - tip Masina*
	*/

Masina* cauta(MasiniRepo* masini, char* nr_inmat);
	/*
	Functie care cauta o masina in repository-ul de masini dupa numarul de inmatriculare.
	nr_inmat - sir de caractere
	Post:
	returneaza masina daca o gaseste sau mesaj de eroare daca nu
	*/

void actualizeaza(MasiniRepo* masini,Masina* masina_noua);
	/*
	Functie care actualizeaza o masina in repository-ul de masini.
	masini - repository de masini
	masina_noua - tip Masina*
	*/


#endif