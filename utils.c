#include "infrastructure.h"
#include <string.h>
#include "service.h"

MasiniRepo* sort(MasiniRepo* masini_repo, int(compara)(Masina* masina_1, Masina* masina_2, int type),int type,int order) {
	int i, ok = 1;
	Masina* aux;
	while (ok == 1) {
		ok = 0;
		for (i = 0; i < masini_repo->lungime - 1; i++) {
			if (order == 1) {
				if (compara(masini_repo->elemente[i], masini_repo->elemente[i + 1], type) > 0) {
					aux = masini_repo->elemente[i];
					masini_repo->elemente[i] = masini_repo->elemente[i + 1];
					masini_repo->elemente[i + 1] = aux;
					ok = 1;
				}
			}
			else {
				if (compara(masini_repo->elemente[i + 1], masini_repo->elemente[i], type) > 0) {
					aux = masini_repo->elemente[i];
					masini_repo->elemente[i] = masini_repo->elemente[i + 1];
					masini_repo->elemente[i + 1] = aux;
					ok = 1;
				}
			}
		}
	}
	return masini_repo;
}
