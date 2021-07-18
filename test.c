#include <assert.h>
#include "domain.h"
#include "infrastructure.h"
#include "service.h"
#include "validation.h"
#include <string.h>

void ruleaza_teste_domeniu() {
	Masina* masina = init_masina();
	strcpy(masina->nr_inmat,"VL 01 ABC");
	strcpy(masina->model, "Audi");
	strcpy(masina->categorie, "Sedan");
	char* model_nou = "BMW";
	char* categorie_noua = "SUV";
	char* status_nou = "inchiriat";
	char* nr_nou = "AB 12 CAJ";
	assert(strcmp(get_nr_inmat(masina), "VL 01 ABC") == 0);
	assert(strcmp(get_model(masina),"Audi") == 0);
	assert(strcmp(get_categorie(masina), "Sedan") == 0);
	assert(strcmp(get_status(masina), "neinchiriat") == 0);
	set_model(model_nou, masina);
	set_categorie(categorie_noua, masina);
	set_status(status_nou, masina);
	set_nr_inmat(nr_nou, masina);
	assert(strcmp(masina->nr_inmat, "AB 12 CAJ") == 0);
	assert(strcmp(masina->model,"BMW")==0);
	assert(strcmp(masina->categorie, "SUV") == 0);
	assert(strcmp(masina->status, "inchiriat") == 0);
	destruct_masina(masina);
}

void ruleaza_teste_infrastructure() {
	masini = init_repo();
	Masina* masina = init_masina();
	Masina* masina2 = init_masina();
	Masina* masina3 = init_masina();
	strcpy(masina->nr_inmat, "VL 01 ABC");
	strcpy(masina->model, "Audi");
	strcpy(masina->categorie, "Sedan");
	Masina* gasit = cauta(masini,masina->nr_inmat);
	assert(gasit == 0);
	adauga(masini, masina);
	assert(masini->lungime == 1);
	gasit = cauta(masini,masina->nr_inmat);
	assert(strcmp(gasit->nr_inmat,"VL 01 ABC") == 0);
	assert(strcmp(gasit->model,"Audi")==0);
	assert(strcmp(gasit->categorie, "Sedan") == 0);
	char* model_nou = "BMW";
	char* categorie_noua = "SUV";
	set_model(model_nou, masina);
	set_categorie(categorie_noua, masina);
	actualizeaza(masini,masina);
	assert(strcmp(get_model(masina),"BMW")==0);
	assert(strcmp(get_categorie(masina), "SUV") == 0);
	strcpy(masina2->nr_inmat, "VL 02 ABC");
	strcpy(masina2->model, "Audi");
	strcpy(masina2->categorie, "Sedan");
	adauga(masini, masina2);
	strcpy(masina3->nr_inmat, "VL 03 ABC");
	strcpy(masina3->model, "Audi");
	strcpy(masina3->categorie, "Suv");
	adauga(masini, masina3);
	assert(masini->capacitate == 4);
	destruct_repo(masini);
}

void ruleaza_teste_service() {
	masini = init_repo();
	Masina* masina = init_masina();
	char* nr_inmat = "VL 01 ABC";
	char* categorie = "Sedan";
	char* model = "Tesla";
	set_model("Tesla", masina);
	set_categorie("SUV", masina);
	adauga_masina(nr_inmat, masina->model, masina->categorie);
	assert(masini->lungime == 1);
	char* nr_inmat_bad = "01 01 ABC";
	adauga_masina(nr_inmat_bad, masina->model, masina->categorie);
	assert(masini->lungime == 1);
	adauga_masina(nr_inmat, masina->model, masina->categorie);
	assert(masini->lungime == 1);
	char* model_nou = "Renault";
	char* categorie_noua = "Scenic";
	actualizeaza_masina(nr_inmat,model_nou,categorie_noua);
	Masina* masina_gasita = cauta(masini,nr_inmat);
	assert(strcmp(get_model(masina_gasita), model_nou)==0);
	assert(strcmp(get_categorie(masina_gasita), categorie_noua) == 0);
	actualizeaza_masina("01 01 ABC", "Tesla", "SUV");
	masina_gasita = cauta(masini,"01 01 ABC");
	assert(masina_gasita == 0);
	masina_gasita = cauta(masini,"VL 02 ABC");
	assert(masina_gasita == 0);
	masina_gasita = cauta(masini,nr_inmat);
	inchiriere_masina(nr_inmat);
	assert(strcmp(get_status(masina_gasita), "inchiriat") == 0);
	returnare_masina(nr_inmat);
	assert(strcmp(get_status(masina_gasita), "neinchiriat") == 0);
	masina_gasita = cauta(masini,"VL 03 ABC");
	inchiriere_masina("VL 03 ABC");
	assert(masina_gasita == 0);
	returnare_masina("VL 03 ABC");
	assert(masina_gasita == 0);
	actualizeaza_masina("VL 10 ADC", "Tesla", "SUV");
	masina_gasita = cauta(masini, "VL 10 ADC");
	assert(masina_gasita == 0);
	strcpy(masina->nr_inmat,nr_inmat);
	strcpy(masina->categorie, categorie);
	strcpy(masina->model, model);
	Masina* masina_copie = copie_masina(masina);
	assert(strcmp(get_nr_inmat(masina_copie), "VL 01 ABC") == 0);
	assert(strcmp(get_model(masina_copie), "Tesla") == 0);
	assert(strcmp(get_categorie(masina_copie), "Sedan") == 0);
	MasiniRepo* masini_copie = copie_masini(masini);
	assert(strcmp(get_nr_inmat(masini_copie->elemente[0]),"VL 01 ABC") == 0);
	MasiniRepo* masini_fil = filtreaza_categorie("Scenic");
	assert(strcmp(get_nr_inmat(masini_fil->elemente[0]), "VL 01 ABC") == 0);
	masini_fil = filtreaza_model("Renault");
	assert(strcmp(get_nr_inmat(masini_fil->elemente[0]), "VL 01 ABC") == 0);
	adauga_masina("CJ 11 DAC","Audi","Sedan");
	adauga_masina("CJ 18 DEC", "Cooper", "Mini");
	MasiniRepo* masini_sort = sorteaza(1,1);
	assert(strcmp(get_nr_inmat(masini_sort->elemente[0]), "CJ 18 DEC") == 0);
	assert(strcmp(get_nr_inmat(masini_sort->elemente[1]), "VL 01 ABC") == 0);
	assert(strcmp(get_nr_inmat(masini_sort->elemente[2]), "CJ 11 DAC") == 0);
	masini_sort = sorteaza(1,2);
	assert(strcmp(get_nr_inmat(masini_sort->elemente[0]), "CJ 11 DAC") == 0);
	assert(strcmp(get_nr_inmat(masini_sort->elemente[1]), "VL 01 ABC") == 0);
	assert(strcmp(get_nr_inmat(masini_sort->elemente[2]), "CJ 18 DEC") == 0);
	masini_sort = sorteaza(2,1);
	assert(strcmp(get_nr_inmat(masini_sort->elemente[0]), "CJ 11 DAC") == 0);
	assert(strcmp(get_nr_inmat(masini_sort->elemente[1]), "CJ 18 DEC") == 0);
	assert(strcmp(get_nr_inmat(masini_sort->elemente[2]), "VL 01 ABC") == 0);
	masini_sort = sorteaza(2,2);
	assert(strcmp(get_nr_inmat(masini_sort->elemente[0]), "VL 01 ABC") == 0);
	assert(strcmp(get_nr_inmat(masini_sort->elemente[1]), "CJ 18 DEC") == 0);	
	assert(strcmp(get_nr_inmat(masini_sort->elemente[2]), "CJ 11 DAC") == 0);
	destruct_masina(masina);
	destruct_masina(masina_copie);
	destruct_repo(masini_fil);
	destruct_repo(masini_sort);
	destruct_repo(masini);
}

void ruleaza_teste_validare() {
	Masina* masina = init_masina();
	char* nr_inmat_bad = "01 02 ABC";
	char* model_bad = "";
	char* categorie_bad = "";
	strcpy(masina->nr_inmat,nr_inmat_bad);
	set_model(model_bad,masina);
	set_categorie(categorie_bad, masina);
	Validator valid = valideaza(masina);
	assert(strcmp(valid.error, "Nr. inmatriculare invalid!\nModel invalid!\nCategorie invalida!\n") == 0);
	char* nr_inmat_bad2 = "01 02ad ABC";
	strcpy(masina->nr_inmat, nr_inmat_bad2);
	valid = valideaza(masina);
	assert(strcmp(valid.error, "Nr. inmatriculare invalid!\nModel invalid!\nCategorie invalida!\n") == 0);
	char* nr_inmat_good = "B 123 ABC";
	strcpy(masina->nr_inmat, nr_inmat_good);
	valid = valideaza(masina);
	assert(strcmp(valid.error, "Model invalid!\nCategorie invalida!\n") == 0);
	destruct_masina(masina);
}

void ruleaza_toate_testele() {
	ruleaza_teste_domeniu();
	ruleaza_teste_infrastructure();
	ruleaza_teste_service();
	ruleaza_teste_validare();
}
