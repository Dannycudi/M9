#include <stdio.h>

int op_menu();

int main()
{

	int op = op_menu();
	char cad[100], cadAux[100];
	int quantitat;
	int i = 0;

	switch(op) {

	case 1:

		printf("\nCada quants caràcters? ");
		getchar();
		scanf("%d", &quantitat);

		int posicions[quantitat];
		int posicio = 0;

		for (i = 0; i < quantitat; i++) {
			printf("\nEntra el %d dígit: ", i+1);
			scanf("%d", &posicions[i]);
		}

		printf("\nEntra la paraula a encriptar: ");
		getchar();
		gets(cad);

		for (i = 0; i < strlen(cad); i++, posicio++) {
			if (posicio >= quantitat) posicio = 0;
			cadAux[i] = cad[i] + (int)posicions[posicio];
		}

		cadAux[i] = '\0';
		puts(cadAux);

		break;

	}

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
