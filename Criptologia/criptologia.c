#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int op_menu();
int op_encriptar();
int op_diccionari(int quantitat);

int main()
{

	char cad[100], cadAux[100];
	int quantitat, i = 0, j = 0, k = 0, op = 0, opcio = 0, diccionari = 0;

	do {

		op = op_menu();

		// Switch Principal - Menú
		switch(op) {

			case 1: //Transposició
			{
				printf("\n\nTransposició!\n");
				opcio = op_encriptar();

				printf("\nCada quants caràcters? ");
				getchar();
				scanf("%d", &quantitat);
				int posicions[quantitat];
				int posicio = 0, actual = 0, longitud = 0;

				switch(opcio) //Encriptar o desencriptar?
				{
					case 1:
					{
						for (i = 0; i < quantitat; i++) {
							printf("\nEntra el %d dígit per l'ordre: ", i+1);
							scanf("%d", &posicions[i]);
						}

						printf("\nEntra la paraula a encriptar: ");
						getchar();
						gets(cad);

						if (strlen(cad) % quantitat == 0) longitud = strlen(cad);
						else longitud = strlen(cad) + (quantitat - (strlen(cad) % quantitat));

						for (i = 0; i < longitud; i++) {
							if (posicio >= quantitat) posicio = 0;

							// La posición actual de cada bloque (quantitat). Bloque x, posición x.
							// Del primer bloque de quantitat(3), la posición 0.
							actual = i - posicio + posicions[posicio] - 1;
							cadAux[actual] = cad[i];

							if (!isalpha(cadAux[actual]) && cadAux[actual] != ' ' && !isdigit(cadAux[actual])) cadAux[actual] = '-';

							posicio++;
						}

						cadAux[i] = '\0';
						puts(cadAux);

					}
					break;
					case 2:
					{

						for (i = 0; i < quantitat; i++) {
							printf("\nEntra el %d dígit per l'ordre: ", i+1);
							scanf("%d", &posicions[i]);
						}

						printf("\nEntra la paraula a desencriptar: ");
						getchar();
						gets(cad);

						if (strlen(cad) % quantitat == 0) longitud = strlen(cad);
						else longitud = (strlen(cad) % quantitat) * quantitat;

						for (i = 0; i < longitud; i++) {
							if (posicio >= quantitat) posicio = 0;

							actual = i - posicio;
							cadAux[i] = cad[actual+posicions[posicio]-1];

							if (cadAux[i] == '-') cadAux[i] = ' ';

							posicio++;
						}

						cadAux[i] = '\0';
						puts(cadAux);

					} break;
				} //End Switch Encriptar - Desencriptar

			} break;
			case 2: //Substitució Simple!
			{

				printf("\n\nSubstitució Simple!\n");

				opcio = op_encriptar();

				printf("\nQuants caràcters vols? ");
				getchar();
				scanf("%d", &quantitat);

				switch(opcio) //Switch Encriptar - Desencriptar
				{
					case 1:
					{

						printf("\nEntra la paraula a encriptar: ");
						getchar();
						gets(cad);

						for (i = 0; i < strlen(cad); i++) {

							cadAux[i] = cad[i] + quantitat;

							if (cadAux[i] == (32 + quantitat)) {
								cadAux[i] = 32; //Si es un espacio.
							}
							else if ((cadAux[i] > 122 && cad[i] < 123) || (cadAux[i] > 90 && cad[i] < 91)) {

								//Si se pasa de la Z o z
								cadAux[i] = cadAux[i] - 26;

							}

							if (!isalpha(cadAux[i]) && cadAux[i] != ' ' && !isdigit(cadAux[i])) cadAux[i] = '-';
						}

						cadAux[i] = '\0';
						puts(cadAux);

					} break;
					case 2:
					{
						printf("\nEntra la paraula a desencriptar: ");
						getchar();
						gets(cad);

						for (i = 0; i < strlen(cad); i++) {

							cadAux[i] = cad[i] - quantitat;

							if (cadAux[i] == (32 - quantitat)) { //Si es un espacio
								cadAux[i] = 32;
							}
							else if ((cadAux[i] < 65 && cad[i] > 64) || (cadAux[i] < 97 && cad[i] > 96)) {
								//Si se pasa el abecedario
								cadAux[i] = cadAux[i] + 26;
							}

							if (!isalpha(cadAux[i]) && cadAux[i] != ' ' && !isdigit(cadAux[i])) cadAux[i] = '-';
						}

						cadAux[i] = '\0';
						puts(cadAux);
					} break;
				} //End Switch Encriptar - Desencriptar

			} break;
			case 3: //Substitució Homofònica!
			{

				printf("\n\nSubstitució Homofònica!\n");

				opcio = op_encriptar();
				diccionari = op_diccionari(2);

				int abc[26][3], zyx[26][3], repetides[26] = {0}, cont = 0, aux;

				//Imprimir los diccionarios.
				for (i = 0; i < 26; i++) {
					//printf("%c - ", i+65);
					for (j = 0; j < 3; j++) {
						abc[i][j] = cont;
						//printf("%d ", abc[i][j]);
						cont++;
					}
					//printf("\n");
				}
				//printf("\n\n\n");
				cont = 26*3;
				for (i = 0; i < 26; i++) {
					//printf("%c - ", i+65);
					for (j = 0; j < 3; j++) {
						zyx[i][j] = cont;
						//printf("%d ", zyx[i][j]);
						cont--;
					}
					//printf("\n");
				}

				switch(opcio) //Switch Encriptar - Desencriptar
				{
					case 1:
					{

						printf("\nEntra la paraula a encriptar: ");
						getchar();
						gets(cad);

						printf("\nResultat: ");

						switch(diccionari) {

							case 1: //Diccionari 1
								for (i = 0; i < strlen(cad); i++) {
									if (isalpha(cad[i])) {
										aux = tolower(cad[i]) - 'a';
										printf("%d ",abc[aux][repetides[aux]]);
										repetides[aux]++;
										if (repetides[aux] == 3) repetides[aux] = 0;
									}
									else printf("- ");
								}
								break;
							case 2: //Diccionari 2
								for (i = 0; i < strlen(cad); i++) {
									if (isalpha(cad[i])) {
										aux = tolower(cad[i]) - 'a';
										printf("%d ",zyx[aux][repetides[aux]]);
										repetides[aux]++;
										if (repetides[aux] == 3) repetides[aux] = 0;
									}
									else printf("- ");
								}
								break;

						}



					} break;
					case 2:
					{
						printf("\nEntra la paraula a desencriptar: ");
						getchar();
						gets(cad);

						printf("\nResultat: ");

						switch(diccionari) {

							case 1: //Diccionari 1
								quantitat = 0; j = 0;
								for (i = 0; i < strlen(cad); i++) { //Recorremos la cadena
									if (cad[i] == ' ' && j > 0) { //Si es un espacio y no es el primero
										for (k = 0; k < 26; k++) { //Recorremos el diccionario buscando el numero
											for (j = 0; j < 3; j++) {
												if (abc[k][j] == quantitat){ //Si lo encuentra, imprimimos la letra que es.
													printf("%c", k + 'a');
													j = 3; k = 26;
												}
											}
										}

										quantitat = 0;
										j = 0;
									}
									else {
										quantitat = atoi(&cad[i]);
										if (quantitat > 9)	i++;
										j++;
									}
								}
								break;
							case 2: //Diccionari 2
								quantitat = 0; j = 0;
								for (i = 0; i < strlen(cad); i++) {
									if (cad[i] == ' ' && j > 0) {
										for (k = 0; k < 26; k++) {
											for (j = 0; j < 3; j++) {
												if (zyx[k][j] == quantitat){
													printf("%c", k + 'a');
													j = 3; k = 26;
												}
											}
										}

										quantitat = 0;
										j = 0;
									}
									else {
										quantitat = atoi(&cad[i]);
										if (quantitat > 9)	i++;
										j++;
									}
								}
								break;

						} //End Switch Diccionari

					} break;
				} //End Switch Encriptar - Desencriptar

				printf("\n\n");

			} break;
			case 4: //Substitució Polifabètica!
			{

				char diccionaris[6][26], rotor[10], clau[3], lletra, abc;
				int cont, j, rotors = 5;

				lletra = 'A';

				printf("\n\nSubstitució Polifabètica!\n");

				//Creamos los diccionarios
				for (i = 0; i < rotors*2; i++) {
					abc = lletra;
					for (j = 0; j < 26; j++) {
						diccionaris[i][j] = abc++;
						if (abc == 'Z') abc = 'A';
					}
					lletra++;
					if (lletra == 'Z') lletra = 'A';
				}

				//Imprimir los diccionarios.
				for (i = 0; i < rotors*2; i++) {
					printf("Diccionari %c -> ", i + 'A');
					for (j = 0; j < 26; j++) {
						printf("%c ",diccionaris[i][j]);
					}
					printf("\n");
				}

				opcio = op_encriptar();

				switch(opcio) //Switch Encriptar - Desencriptar
				{
					case 1:
					{

						printf("\nEntra la clau (MAX 5 lletres) ");
						getchar();
						gets(clau);

						rotors = strlen(clau);

						//Guardamos las letras por las que empezará cada rotor.
						for (i = 0; i < strlen(clau); i++) rotor[i] = toupper(clau[i]);

						printf("\nEntra la paraula a encriptar: ");
						gets(cad);
						printf("\n\t");

						for (i = 0; i < strlen(cad); i++) {
							lletra = toupper(cad[i]);
							printf("\nLletra %c ", lletra);

							cont = 0;
							for (j = 0; j < rotors; j++) {
								if (isalpha(lletra)) lletra = diccionaris[rotor[j]%2+cont][lletra-'A'];
								printf("| ROTOR %d -> %c ", j+1, lletra);
								cont += 2;
							}

							cadAux[i] = lletra;

							// Le subimos una vuelta al rotor que haga falta

							cont = 0;
							for (j = rotors-1; j >= 0 && cont == 0; j--) {
								if (rotor[j] != 'Z') {
									rotor[j]++;
									cont = 1;
								}
								else {
									rotor[j] = 'A';
									cont = 0;
								}
							}
						}
						cadAux[i] = '\0';
						printf("\n\n\tRESULTAT: %s", cadAux);

						printf("\n\n\tCLAU: ");
						for (i = 0; i < rotors; i++) {
							printf("%c", rotor[i]);
						}


					} break;
					case 2:
					{
						printf("\nEntra la clau (MAX 5 lletres) ");
						getchar();
						gets(clau);

						rotors = strlen(clau);

						//Guardamos las letras por las que empezará cada rotor.
						for (i = 0; i < strlen(clau); i++) rotor[i] = toupper(clau[i]);

						printf("\nEntra la paraula a desencriptar: ");
						gets(cad);
						printf("\n\t");

						for(i=0; i<strlen(cad)-1; i++){

							cont = 0;
							for (j = rotors-1; j >= 0 && cont == 0; j--) {
								if (rotor[j] != 'Z') {
									rotor[j]++;
									cont = 1;
								}
								else {
									rotor[j] = 'A';
									cont = 0;
								}
							}
						}

						printf("\n\tPalabra clave actualizada: ");

						for (i = 0; i < rotors; i++) {
							printf("%c", rotor[i]);
						}
						printf("\n\n");

						for(i=strlen(cad)-1; i>=0; i--){

							lletra = cad[i];
							printf("\nLletra %c ", lletra);
							cont = rotors*2-2;
							for (j = 0; j < rotors; j++) {
								if (isalpha(lletra)){
									lletra = lletra-(rotor[rotors-j-1]%2+cont);
									if (lletra < 'A') lletra = 'Z' - ('A' - lletra);
								}
								printf("| ROTOR %d -> %c ", rotors-j, lletra);
								cont -= 2;
							}

							cont = 0;
							for (j = rotors-1; j >= 0 && cont == 0; j--) {
								if (rotor[j] != 'A') {
									rotor[j]--;
									cont = 1;
								}
								else {
									rotor[j] = 'Z';
									cont = 0;
								}
							}

							cadAux[i] = lletra;
						}

						cadAux[strlen(cad)] = '\0';
						printf("\n\n\tRESULTAT: %s", cadAux);

					} break;
				} //End Switch Encriptar - Desencriptar
				printf("\n\n");
			} break;
		} //End Swtich Menú

	} while (op != 5);

    return 0;
}

int op_menu() {

	int op = 0;

	do {
		printf("\nEscull una opció: ");
		printf("\n1 - Transposició\n2 - Substitució Simple\n3 - Substitució Homofónica\n4 - Substitució Polifabética\n5 - Sortir\n\n\tOpció: ");
		scanf("%d", &op);
	}
	while(op < 1 || op > 5);

	return op;

}

int op_encriptar() {

	int opcio;
	do {
		printf("\n Que vols? \n1- Encriptar\n2 - Desencriptar\nOpció: ");
		scanf("%d", &opcio);
	} while(opcio < 1 || opcio > 2);

	return opcio;

}

int op_diccionari(int quantitat) {

	int opcio;
	do {
		printf("\n Quin diccionari vols? (1 - %d)\nOpció: ", quantitat);
		scanf("%d", &opcio);
	} while(opcio < 1 || opcio > quantitat);

	return opcio;

}
