#ifndef DOMAIN_H
#define DOMAIN_H
#pragma once

typedef struct {
	/*
	Structura masina ce contine atribute specifice acesteia.
	*/
	char* nr_inmat;
	char* model;
	char* categorie;
	char* status;
}Masina;

Masina* init_masina();
	/*
	Functie care initializeaza un obiect tip Masina*.
	returneaza masina - tip Masina*
	*/

void destruct_masina(Masina* masina);
	/*
	Functie care distruge un obiect de tip Masina*.
	*/

char* get_nr_inmat(Masina* masina);
	/*
	Functie care returneaza nr_inmatriculare al masinii.
	masina - tip Masina*
	return nr_inmat - int
	*/

char* get_model(Masina* masina);
	/*
	Functie care returneaza modelul masinii.
	masina - tip Masina*
	return model - string
	*/

char* get_categorie(Masina* masina);
	/*
	Functie care returneaza categoria masinii.
	masina - tip Masina*
	return categorie - string
	*/

void set_model(char* model, Masina* masina);
	/*
	Functie care seteaza modelul masinii.
	model - sir de caractere nevid
	masina - tip Masina*
	*/

void set_categorie(char* categorie, Masina* masina);
	/*
	Functie care seteaza categoria masinii.
	categorie - sir de caractere nevid
	masina - tip Masina*
	*/

char* get_status(Masina* masina);
	/*
	Functie care returneaza statusul masinii.
	masina - tip Masina*
	return status - string
	*/

void set_status(char* status, Masina* masina);
	/*
	Functie care seteaza categoria masinii.
	status - sir de caractere egal cu "inchiriat" sau "neinchiriat"
	masina - tip Masina*
	*/

void set_nr_inmat(char* nr_inmat, Masina* masina);
	/*
	Functie care seteaza nr de inmatriculare al masinii.
	nr_inmat - sir de caractere
	masina - tip Masina*
	*/

#endif