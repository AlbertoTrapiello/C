// DIMACs.cpp : Defines the entry point for the console application.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int read_DIMACs(char * nombre, int matriz[200][200], int *nodos, int *aristas);

int main()
{
	int i,j;
	int matriz[200][200],nodos,aristas;
	char nombre[50] = "mygraph.txt";


	int r = read_DIMACs(nombre, matriz, &nodos, &aristas);
	for (i = 0; i < nodos; i++)
		for (j = 0; j < nodos; j++)
			printf("%d", matriz[i][j]);

    return 0;
}

int read_DIMACs(char * nombre,int matriz[200][200],int *nodos,int *aristas)
{
	puts(nombre);
	FILE *f = fopen(nombre, "r");
	char line[200];
	int r = 1,fil,col,cont;

	if (!f)
	{
		perror("Error al leer el archivo\n");
		return r=0;
	}
	else
	{
		while (!feof(f))
		{
			fgets(line, 250, f);//guarda el retorno de carro, con strchr puedes hacerle buscar \n y quitarlo
			if (ferror(f))
			{
				perror("error al leer la linea ");
				puts("termino la lectura...");
				return r=0;
			}
			if (line[0] == '\n' || line[0] == '\0') continue;
			
			switch (line[0])
			{
				case 'c':
				{
					puts(line);
					break;
				}
				case 'e':
				{
					//aristas
					scanf("%d %d", fil, col);
					matriz[fil][col] = 1;
					break;
				}
				case 'p':
				{
					//numero de nodos y aristas
					scanf("%d %d", nodos, aristas);
					if (cont > 1)
					{
						puts("errror de portocolo\n");
						r = 0;
						//funcion de error, encargada de liberar toda la memoria
					}

					break;
				}
				default:
				{
					puts("PROTOCOLO ERRONEO. Dejo de leer...\n");

					//funcion de error, encargada de liberar toda la memoria
					break;
				}
				
			}

		}

		fclose(f);
	}

	return r;
}

