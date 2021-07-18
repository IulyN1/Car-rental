#ifndef UI_H
#define UI_H
#pragma once

void adauga_masina_UI();
	/*
	Functie care permite citirea datelor de la tastatura pentru adaugarea unei masini.
	*/

void afiseaza_UI();
	/*
	Functie care permite afisarea masinilor.
	*/

void actualizeaza_masina_UI();
	/*
	Functie care permite actualizarea masinilor pe baza input-ului.
	*/

void inchiriaza_masina_UI();
	/*
	Functie care permite inchirierea unei masini.
	*/

void returneaza_masina_UI();
	/*
	Functie care permite returnarea unei masini.
	*/

void filtrare_categorie_UI();
	/*
	Functie care permite filtrarea dupa o categorie data.
	*/

void filtrare_model_UI();
	/*
	Functie care permite filtrarea dupa un model dat.
	*/

void sortare_UI(int type,int order);
	/*
	Functie care permite sortare.
	type - intreg 1 pt categorie, 2 pt model
	order - intreg 1 pt crescator, 2 pt descrecator
	*/

void menu();
	/*
	Functie care afiseaza meniul.
	*/

void run();
	/*
	Functie care permite rularea programului.
	*/

#endif