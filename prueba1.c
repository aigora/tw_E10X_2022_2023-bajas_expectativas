#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef struct
{
float anyo[24];
float media;
float max;
float min;
}energia;

float max(float vector[24]);
float min(float vector[24]);
float media(float vector[24]);

int main()
{
energia tipoenergia[18];
float i;
int j, k;
FILE *plectura;
plectura = fopen("generacion...", "r"); //Escribir el nombre del fichero que cambiemos

if (plectura == NULL)
{
printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
return-1;
}

for (j = 0; j<18; j++)
{
for (k = 0; k<24; k++)
{
fscanf(plectura, "%f,", &tipoenergia[j].anyo[k]);
}
fscanf(plectura, "\n");
}

fclose(plectura);

	setlocale(LC_CTYPE,"spanish");// esto es para poner tildes
	int paso1;
	int energia1;
	int energiac1;
	int energiac2;
	int comparar;
	int operacion1;
	int operacion2;
	int mostrar;
	printf("GENERACIÓN DE ENERGÍAS. \n");
	printf("Este programa le permitira conocer, comparar, modificar u operar con los datos de la generacion de electricidad,\n mediante todos los tipos de energias en España durante los años de 2021 y 2022 (Gwh)\n\n");
	do
	{		
	printf("Indique 1 si quiere hacer una consulta individual o 2 si quiere hacer una comparativa \n");
	scanf("%i", &paso1);
	} while((paso1<1)||(paso1>2));
	switch(paso1)
	{
		case 1:
			do
			{
			printf("Indique la energía a consultar: \n 1-Hidráulica \n 2-Turbinación bombeo \n 3-Nuclear \n 4-Carbón \n 5-Fuel + Gas \n 6-Motores diésel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroeólica \n 11-Eólica \n 12-Solar fotovoltaica \n 13-Solar térmica \n 14-Otras renovables \n 15-Congeneración \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generación total \n");
			scanf("%i", &energia1);
			}while((energia1<1)||(energia1>18));
			energia1 = energia1 - 1;
            
            do
			{
			printf("Indique qué operación desea realizar:\n 1-Mostrar \n 2-Cambiar datos \n 3-Estadística \n");
			scanf("%i", &operacion1);
			} while ((operacion1<1)||(operacion1>3));
			if(operacion1==1)
			{
			do
			{
			printf("Elegir el mes y el año el cual mostrar: \n 1- 01/2021 \n 2- 02/2021 \n 3- 03/2021 \n 4- 04/2021 \n 5- 05/2021 \n 6- 06/2021 \n 7- 07/2021 \n 8- 08/2021 \n 9- 09/2021 \n 10- 10/2021 \n 11- 11/2021 \n 12- 12/2021 \n 13- 01/2022 \n 14- 02/2022 \n 15- 03/2022 \n 16- 04/2022 \n 17- 05/2022 \n 18- 06/2022 \n 19- 07/2022 \n 20- 08/2022 \n 21- 09/2022 \n 22- 10/2022 \n 23- 11/2022 \n 24- 12/2022 \n");
			scanf("%i", &mostrar);
			} while ((mostrar<1)||(mostrar>24));
			mostrar = mostrar - 1;
			printf("El dato es %f GWh.\n", tipoenergia[energia1].anyo[mostrar]);
			}
			else if(operacion1==2)
			{
				
				FILE *pescritura;
				pescritura=  fopen ("C:/Users/Pc/Documents/GitHub/tw_E10X_2022_2023-bajas_expectativas/generacion_por_tecnologias_21_22_escritura.csv", "w");

					if (pescritura == NULL)
					{
					printf("ERROR AL ABRIR EL FICHERO DE ESCRITURA.\n");
					return -1;
					}
						int energia_modificar; //lo de energia para que es, si la energia ya la hemos seleccionado antes.
						int anyo; 
						int mes; 
						int posicion; //Tamp entiendo para que sirve esto
						do
						{
						printf("Se le permitirá cambiar un dato de generacion:\n");
						scanf("%i", &mes);
						scanf("%i", &anyo);
						}while((mes<1)||(mes>12)||(anyo<2021)||(anyo>2022)); //me estoy rayando muchisimo con los de las posiciones con el while ese de despues, en plan wtf, creo que es mas facil con el scanf de arriba, lo hablamos y ponemos la que mejor veamos, ademas creo que no se ejecutaria ninguno de los while siguientes
						
						while ((anyo!=1)&& (anyo!=2)) //aunq con esto evite que se joda el programa si no mete uno de esos dos datos se jode todo en cuanto nos metan un char
						{
						printf("¿A qué año pertenece esa generacion? 1- si es del 2021, 2- si es del 2022\n");
						scanf("%i", &anyo);
						}
							if(anyo==1)
							{
								posicion=posicion;
							}
							
							if(anyo==2)
							{
								posicion=12;
							}
						
						while ((mes!=1)&&(mes!=2)&&(mes!=3)&&(mes!=4)&&(mes!=5)&&(mes!=6)&&(mes!=7)&&(mes!=8)&&(mes!=9)&&(mes!=10)&&(mes!=11)&&(mes!=12)) //seguro que hay una forma mas facil de ponerlo pero no se me ocurre	
						{
						printf("Escriba el numero del mes al que corresponda el dato a modificar:\n");
						scanf("%i", &mes);
						}
						posicion=posicion+mes; //ahora que ya tenemos la posicion solo hay que ir al vector de la energia (energia_modificar) en la posición (posicion) que sea y decirle que esciba algo y ponerlo -aurora
					
				
					
					//aquí también hay que meter algo relacionado con los ficheros
				
			}
			else if (operacion1==3)
			{
				do
				{
				printf("Indique que tipo de operación estadística desea realizar: \n 1-Indicar el máximo \n 2-Indicar el minímo \n 3-Indicar la media \n");
				scanf("%i", &operacion2);
				}while((operacion2<1)||(operacion2>3));
				
				if(operacion2==1)
				{
				tipoenergia[energia1].max = max(tipoenergia[energia1].anyo); //preguntar al profe
				printf("El maximo es %f GWh.\n", tipoenergia[energia1].max);
				}
				else if(operacion2==2)
				{
				tipoenergia[energia1].min = min(tipoenergia[energia1].anyo); //preguntar tamb
				printf("El minimo es %f GWh.\n", tipoenergia[energia1].min);
				}
				else if(operacion2==3)
				{
				tipoenergia[energia1].media = media(tipoenergia[energia1].anyo); //tamb preguntar
				printf("La media es %f GWh. \n", tipoenergia[energia1].media);
				}
			}
			break;
		case 2:
			printf("Indique si quiere comparar 2 o 3 energías \n"); //podemos poner más pero vamos a empezar por 2 o 3 //A mi me parece una barbaridad comparar 3

			printf("Indique si quiere comparar 2 o 3 energías \n"); //podemos poner más pero vamos a empezar por 2 o 3.

			scanf("%i", &comparar);
			if(comparar==2)
			{
				printf("Indique las dos energías a comparar: \n 1-Hidráulica \n 2-Turbinación bombeo \n 3-Nuclear \n 4-Carbón \n 5-Fuel + Gas \n 6-Motores diésel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroeólica \n 11-Eólica \n 12-Solar fotovoltaica \n 13-Solar térmica \n 14-Otras renovables \n 15-Congeneración \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generación total \n");
			    scanf("%i %i", &energiac1, &energiac2);
			    printf("Indique qué quiere comparar:\t");
			    //ponemos opciones o que se pueda escribir?
			}
			else if(comparar==3)
			{
				printf("Indique las dos energías a comparar: \n 1-Hidráulica \n 2-Turbinación bombeo \n 3-Nuclear \n 4-Carbón \n 5-Fuel + Gas \n 6-Motores diésel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroeólica \n 11-Eólica \n 12-Solar fotovoltaica \n 13-Solar térmica \n 14-Otras renovables \n 15-Congeneración \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generación total \n");
			    scanf("%i %i %i", &energiac1, &energiac2);
			    printf("Indique qué quiere comparar:\t");
			    //ponemos opciones o que se pueda escribir?
			}
			else
			{
				printf("Número no válido, vuelva a ejecutar el progama");
			}
		    break; 	
		default:       
		    printf("Número no válido, vuelva a ejecutar el progama");// no se poner para que vuelva a preguntar lo mismo otra vez. //Hacerlo con un do while como esta anteriormente.    
	}
return 0;
}

float max(float vector[24])
{
float max = vector[0];

int i;
for(i = 0; i<24; i++)
{

if(max<vector[i])
{
max = vector[i];
}
else
{
max = max;
}

}
return max;
}

float min(float vector[24])
{
float min = vector[0];

int i;
for(i = 0; i<24; i++)
{

if(min>vector[i])
{
min = vector[i];
}
else
{
min = min;
}

}
return min;
}

float media(float vector[24])
{
float media = 0;

int i;
for(i = 0; i<24; i++)
{
media = media + vector[i];
}

media = media/24;

return media;
}

