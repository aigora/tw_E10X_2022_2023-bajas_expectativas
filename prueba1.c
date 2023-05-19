#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef struct
{
float anyo[24];
float media;
float max;
float min;
float porcentajemes;
float porcentajemedia;
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
//plectura = fopen("C:/Users/albag/OneDrive/Documentos/GitHub/tw_E10X_2022_2023-bajas_expectativas/generacion_por_tecnologias_21_22.txt", "r");
plectura = fopen("generacion_por_tecnologias_21_22.txt", "r");
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
fscanf(plectura, "\n\n");
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
	int operacion3;
	int mostrar;
	int acabar;
	int porcentmes;
	float mes1;
	float mes2;
	printf("GENERACIÓN DE ENERGÍAS. \n");
	printf("Este programa le permitira conocer, comparar, modificar u operar con los datos de la generacion de electricidad,\n mediante todos los tipos de energias en España durante los años de 2021 y 2022 (Gwh)\n\n");
do
{
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
				pescritura=  fopen ("generacion_por_tecnologia_21_22_escritura", "w");

					if (pescritura == NULL)
					{
					printf("ERROR AL ABRIR EL FICHERO DE ESCRITURA.\n");
					return -1;
					}
					int cambiar;
					float cambio;
						do
						{
						printf("Se le permitirá cambiar un dato de generacion: \n 1- 01/2021 \n 2- 02/2021 \n 3- 03/2021 \n 4- 04/2021 \n 5- 05/2021 \n 6- 06/2021 \n 7- 07/2021 \n 8- 08/2021 \n 9- 09/2021 \n 10- 10/2021 \n 11- 11/2021 \n 12- 12/2021 \n 13- 01/2022 \n 14- 02/2022 \n 15- 03/2022 \n 16- 04/2022 \n 17- 05/2022 \n 18- 06/2022 \n 19- 07/2022 \n 20- 08/2022 \n 21- 09/2022 \n 22- 10/2022 \n 23- 11/2022 \n 24- 12/2022 \n");
						scanf("%i", &cambiar);
						}while((cambiar<1)||(cambiar>24)); 
							
					cambiar = cambiar - 1;
					printf("El actual es de %f Gwh.\n Escribe el numero por el que desea cambiarlo.\n", tipoenergia[energia1].anyo[cambiar]);
					scanf("%f", &cambio);
					tipoenergia[energia1].anyo[cambiar] = cambio;
					
					for(j = 0; j<18; j++)
					{
					for(k = 0; k<24; k++)
					{
						fprintf(pescritura, "%f", tipoenergia[j].anyo[k]);
						if(k!=23)
						{
						fprintf(pescritura, ", ");
						}
						else
						{
						fprintf(pescritura, "\n\n");
						}
					}
					}
					
				fclose(pescritura);
				
			}
			else if (operacion1==3)
			{
				do
				{
				printf("Indique que tipo de operación estadística desea realizar: \n 1-Indicar el máximo \n 2-Indicar el minímo \n 3-Indicar la media \n 4-Porcentaje \n");
				scanf("%i", &operacion2);
				}while((operacion2<1)||(operacion2>4));
				
				if(operacion2==1)
				{
				tipoenergia[energia1].max = max(tipoenergia[energia1].anyo);
				printf("El maximo es %f GWh.\n", tipoenergia[energia1].max);
				}
				else if(operacion2==2)
				{
				tipoenergia[energia1].min = min(tipoenergia[energia1].anyo);
				printf("El minimo es %f GWh.\n", tipoenergia[energia1].min);
				}
				else if(operacion2==3)
				{
				tipoenergia[energia1].media = media(tipoenergia[energia1].anyo);
				printf("La media es %f GWh. \n", tipoenergia[energia1].media);
				}
				else if(operacion2==4)
				{
				do
				{
				printf("Indica si lo quieres: \n 1-Mes y año \n 2-Media \n");
				scanf("%i", &operacion3);				
				}while((operacion3<1)||(operacion3>2));
					if(operacion3==1)
					{
						do
						{
						printf("Elige el mes y año: \n 1- 01/2021 \n 2- 02/2021 \n 3- 03/2021 \n 4- 04/2021 \n 5- 05/2021 \n 6- 06/2021 \n 7- 07/2021 \n 8- 08/2021 \n 9- 09/2021 \n 10- 10/2021 \n 11- 11/2021 \n 12- 12/2021 \n 13- 01/2022 \n 14- 02/2022 \n 15- 03/2022 \n 16- 04/2022 \n 17- 05/2022 \n 18- 06/2022 \n 19- 07/2022 \n 20- 08/2022 \n 21- 09/2022 \n 22- 10/2022 \n 23- 11/2022 \n 24- 12/2022 \n");
						scanf("%i", &porcentmes);					
						}while((porcentmes<1)||(porcentmes)>24);
						porcentmes = porcentmes - 1;
						float total = 0;
					
						for(j = 0; j<24; j++)
						{
							total = total + tipoenergia[j].anyo[porcentmes];
						}
						
						tipoenergia[energia1].porcentajemes = tipoenergia[energia1].anyo[porcentmes]/total*100;
						
						printf("El porcentaje es del %f porciento \n", tipoenergia[energia1].porcentajemes);
					}
					else if(operacion3==2)
					{
						float medias[18];
						
						for(j = 0; j<18; j++)
						{
						medias[j] = media(tipoenergia[j].anyo);
						}
						
						float total = 0;
						
						for (j = 0; j<18; j++)
						{
						total = total + medias[j];
						}
						
						tipoenergia[energia1].porcentajemedia = medias[energia1]/total*100;
						
						printf("El porcentaje es del %f porciento \n", tipoenergia[energia1].porcentajemedia);
					}
				}
			}
			break;
		case 2:
			printf("Indique si quiere comparar 1 o 2 energías \n"); //podemos poner más pero vamos a empezar por 2 o 3 //A mi me parece una barbaridad comparar 3

			scanf("%i", &comparar);
			if(comparar==1)
			{
				printf("Indique la energía a comparar: \n 1-Hidráulica \n 2-Turbinación bombeo \n 3-Nuclear \n 4-Carbón \n 5-Fuel + Gas \n 6-Motores diésel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroeólica \n 11-Eólica \n 12-Solar fotovoltaica \n 13-Solar térmica \n 14-Otras renovables \n 15-Congeneración \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generación total \n");
			    scanf("%i", &energiac1);
			    printf("Indique qué quiere comparar, primero seleccione: \n 1-Datos del mismo año \n 2-Datos de años distintos \n ");
			    scanf("%i", &comparar);
			    if(comparar==1)
			    {
			    	int anyo;
			    	printf("Indique de qué año quiere hacer la comparativa: \n 1-2021 \n 2-2022 \n");
			    	scanf("%i", &anyo);
			    	if(anyo==1)
					{
					printf("Elige los meses que comparar: \n 1- 01/2021 \n 2- 02/2021 \n 3- 03/2021 \n 4- 04/2021 \n 5- 05/2021 \n 6- 06/2021 \n 7- 07/2021 \n 8- 08/2021 \n 9- 09/2021 \n 10- 10/2021 \n 11- 11/2021 \n 12- 12/2021 \n");	
					scanf("%f %f", &mes1, &mes2);
					printf("Los datos son %f y %f GWh.\n", mes1, mes2);
					}
					else if(anyo==2)
					{
					printf("Elegir el mes que mostrar: \n 1- 01/2022 \n 2- 02/2022 \n 3- 03/2022 \n 4- 04/2022 \n 5- 05/2022 \n 6- 06/2022 \n 7- 07/2022 \n 8- 08/2022 \n 9- 09/2022 \n 10- 10/2022 \n 11- 11/2022 \n 12- 12/2022 \n");	
					scanf("%f %f", &mes1, &mes2);
					printf("Los datos son %f y %f GWh.\n", mes1, mes2);
					}
				}
				else if(comparar==2)
				{
					printf("Se compararán los datos de los años 2021 y 2022");
					
					
				}
			    
			}
			else if(comparar==3)
			{
				printf("Indique las tres energías a comparar: \n 1-Hidráulica \n 2-Turbinación bombeo \n 3-Nuclear \n 4-Carbón \n 5-Fuel + Gas \n 6-Motores diésel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroeólica \n 11-Eólica \n 12-Solar fotovoltaica \n 13-Solar térmica \n 14-Otras renovables \n 15-Congeneración \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generación total \n");
			    scanf("%i %i %i", &energiac1, &energiac2);
			    printf("Indique qué quiere comparar, primero seleccione: \n 1-Datos del mismo año \n 2-Datos de años distintos \n ");
			     scanf("%i", &comparar);
			    if(comparar==1)
			    {
			    	int anyo;
					printf("Indique de qué año quiere hacer la comparativa: \n 1-2021 \n 2-2022");
			    	scanf("%i", &anyo);
			    	if(anyo==2021)
					{
					
					}
					else if(anyo==2022)
					{
						
					}
				}
				else if(comparar==2)
				{
					printf("Se compararán los datos de los años 2021 y 2022");
					
					
				}
			}
			else
			{
				printf("Número no válido, vuelva a ejecutar el progama");
			}
		    break; 	
		//default:       
		  //  printf("Número no válido, vuelva a ejecutar el progama");// no se poner para que vuelva a preguntar lo mismo otra vez. //Hacerlo con un do while como esta anteriormente.    
	}
printf("Seleccione 1 si quiere volver a empezar el programa o cualquier otro numero si quiere acabarlo.\n");
scanf("%i", &acabar);
}while(acabar == 1);

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

