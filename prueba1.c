#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_CTYPE,"spanish");
	int paso1;
	int paso;
	printf("TITULO \n");
	printf("Indique 1 si quiere hacer una consulta individual o 2 si quiere hacer una comparativa \n");
	scanf("%i", &paso);
	switch(paso)
	{
		case 1:
			printf("Indique la energía a consultar: \n 1-Hidráulica \n 2-Turbinación bombeo \n 3- ");
			break;
		case 2:
		    break; 	
		default: 
		    printf("Número no válido, vuelva a poner el progama");// no se poner para que vuelva al inicio    
	}
}

