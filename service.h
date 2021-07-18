#ifndef SERVICE_H
#define SERVICE_H
#include "infrastructure.h"
#pragma once

void adauga_masina(char* nr_inmat, char* model, char* categorie);
	/*
	Functie care permite adaugarea unei masini pe baza datelor din input.
	Pre:
	nr_inmat - sir de caractere de forma unui nr de inamtriculare
	model - sir de caractere nevid
	categorie - sir de caractere nevid
	Post:
	afiseaza mesajele de eroare daca nu este valida masina, altfel este adaugata
	*/

void actualizeaza_masina(char* nr_inmat, char* model, char* categorie);
	/*
	Functie care permite actualizarea unei masini pe baza datelor din input.
	Pre:
	nr_inmat - sir de caractere de forma unui nr de inamtriculare
	model - sir de caractere nevid
	categorie - sir de caractere nevid
	Post:
	afiseaza mesajele de eroare daca nu este valida masina, altfel este actualizata
	*/

void inchiriere_masina(char* nr_inmat);
	/*
	Functie care permite inchirierea unei masini.
	nr_inmat - sir de caractere de forma unui nr de inamtriculare
	*/

void returnare_masina(char* nr_inmat);
	/*
	Functie care permite inchirierea unei masini.
	nr_inmat - sir de caractere de forma unui nr de inamtriculare
	*/

MasiniRepo* filtreaza_categorie(char* categorie);
	/*
	Functie care returneaza masinile de o categorie data.
	categorie - sir de caractere
	returneaza lista cu masini corespunzatoare filtrului
	*/

MasiniRepo* filtreaza_model(char* model);
	/*
	Functie care returneaza masinile de un model dat.
	model - sir de caractere
	returneaza lista cu masini corespunzatoare filtrului
	*/

Masina* copie_masina(Masina* masina);
	/*
	Functie care copiaza o masina.
	masina - obiect Masina*
	returneaza copie masina
	*/

MasiniRepo* copie_masini(MasiniRepo* masini);
	/*
	Functie care copiaza repository-ul de masini.
	masini - repository de masini
	returneaza copie masini
	*/

MasiniRepo* sorteaza(int type,int order);
	/*
	Functie care sorteaza crescator o copie a masinilor dupa categorie.
	type - intreg 1 pt categorie, 2 pt model
	order - intreg 1 pt crescator, 2 pt descrecator
	returneaza lista sortata
	*/

int compara(Masina* masina1, Masina* masina2, int type);
	/*
	Functie care compara 2 masini.
	masina1 - Masina* 
	masina2 - Masina* 
	type - intreg 1 pt categorie, 2 pt model
	returneaza 1 daca camp masina1 este mai mare decat masina2, 0 altfel
	*/

#endif 