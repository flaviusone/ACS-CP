#include "GrDinamic.h"

int main () {
	char c; 
	TGrupa g;
	AGrupa aloc;
	FILE *f;
	int nrnote;
	char numefis[21], *nf = numefis;

	printf("\nNume fisier : ", numefis); gets(numefis);
	f = fopen(nf, "rt");
	if (!f)
	{ printf("Eroare deschidere fisier %s\n", nf);
		return -1;
	}

	fscanf(f, "%i", &nrnote);
	aloc = AlocGrupa(32,nrnote);
	aloc->nrstud = CitStud(f,aloc);
	aloc->nrnote = nrnote;
	printf("\nPrintare tabel de studenti\n");
	TabelStud(aloc);
	printf("\n-- Rezultatul sortarii dupa nume si prenume --\n\n");
	qsort(aloc->std,aloc->nrstud,sizeof(TStud),OrdNP);
	TabelStud(aloc);
	printf("\n-- Rezultatul sortarii dupa data nasterii --\n\n");
	qsort(aloc->std,aloc->nrstud,sizeof(TStud),OrdD);
	TabelStud(aloc);
	ElibGrupa(&aloc);   
	return 0;   
}
