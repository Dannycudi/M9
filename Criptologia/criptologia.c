#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int op_menu();

int main()
{

	char cad[100], cadAux[100];
	int quantitat;
	int i = 0, op = 0;

	do {

		op = op_menu();
		switch(op) {

		case 1:

			printf("\nCada quants caràcters? ");
			getchar();
			scanf("%d", &quantitat);

			int posicions[quantitat];
			int posicio = 0, actual = 0;

			for (i = 0; i < quantitat; i++) {
				printf("\nEntra el %d dígit per l'ordre: ", i+1);
				scanf("%d", &posicions[i]);
			}

			printf("\nEntra la paraula a encriptar: ");
			getchar();
			gets(cad);

			int aux = (strlen(cad) % quantitat) * quantitat;

			for (i = 0; i < aux; i++) {
				if (posicio >= quantitat) posicio = 0;

				actual = i - posicio;
				cadAux[i] = cad[actual+posicions[posicio]-1];

				if (!isalpha(cadAux[i])) cadAux[i] = '-';

				posicio++;
			}

			cadAux[i] = '\0';
			puts(cadAux);
			printf("\n\t%d\n", aux);

			break;

		}
	} while (op != 6);

    return 0;
}

int op_menu() {

	int op = 0;

	do {
		printf("\nEscull una opció: ");
		printf("\n1 - Transposició\n2 - Substitució Simple\n3 - Substitució Homofónica\n4 - Substitució Polifabética\n5 - Sortir\n\n\tOpció: ");
		scanf("%d", &op);
	}
	while(op < 1 && op > 5);

	return op;

}
