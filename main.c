// Problema 4. Inchirieri masini
// Aplicatie realizata de: Popa Iulian-Alexandru

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 
#include <stdio.h>
#include "ui.h"
#include "infrastructure.h"
#include "test.h"

int main() {
	/*
	Functia principala de rulare a programului.
	*/
	//ruleaza_toate_testele();
	masini = init_repo();
	run();
	destruct_repo(masini);
	_CrtDumpMemoryLeaks();

	return 0;
}