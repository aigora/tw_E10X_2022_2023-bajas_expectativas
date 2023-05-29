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
void comparar2(float comp1, float comp2);

int main()
{
energia tipoenergia[18];
int i=0;
float x;
int j, k;
FILE *plectura;

plectura = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
if (plectura == NULL)
{
printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
return-1;
}


fscanf(plectura, "Título,ESTRUCTURA DE LA GENERACIÓN POR TECNOLOGÍAS_01-01-2021_31-12-2022,,,,,,,,,,,,,,,,,,,,,,,\n");

fscanf(plectura, "Sistema eléctrico,Nacional,,,,,,,,,,,,,,,,,,,,,,,\n");

fscanf(plectura, "Magnitudes,GWh,,,,,,,,,,,,,,,,,,,,,,,\n");

fscanf(plectura, " ,,,,,,,,,,,,,,,,,,,,,,,,\n");

fscanf(plectura, "Fecha,1-2021,2-2021,3-2021,4-2021,5-2021,6-2021,7-2021,8-2021,9-2021,10-2021,11-2021,12-2021,1-2022,2-2022,3-2022,4-2022,5-2022,6-2022,7-2022,8-2022,9-2022,10-2022,11-2022,12-2022\n");

for(j = 0; j<18; j++)
{
if (j == 0)
{
fscanf(plectura, "Hidráulica");
}
else if(j == 1)
{
fscanf(plectura, "Turbinación bombeo");
}
else if(j == 2)
{
fscanf(plectura, "Nuclear");
}
else if(j == 3)
{
fscanf(plectura, "Carbón");
}
else if(j == 4)
{
fscanf(plectura, "Fuel + Gas");
}
else if(j == 5)
{
fscanf(plectura, "Motores diésel");
}
else if(j == 6)
{
fscanf(plectura, "Turbina de gas");
}
else if(j == 7)
{
fscanf(plectura, "Turbina de vapor");
}
else if(j == 8)
{
fscanf(plectura, "Ciclo combinado");
}
else if(j == 9)
{
fscanf(plectura, "Hidroeólica");
}
else if(j == 10)
{
fscanf(plectura, "Eólica");
}
else if(j == 11)
{
fscanf(plectura, "Solar fotovoltaica");
}
else if(j == 12)
{
fscanf(plectura, "Solar térmica");
}
else if(j == 13)
{
fscanf(plectura, "Otras renovables");
}
else if(j == 14)
{
fscanf(plectura, "Cogeneración");
}
else if(j == 15)
{
fscanf(plectura, "Residuos no renovables");
}
else if(j == 16)
{
fscanf(plectura, "Residuos renovables");
}
else if(j == 17)
{
fscanf(plectura, "Generación total");
}
for(k=0;k<24;k++)
{
fscanf(plectura,",%f", &tipoenergia[j].anyo[k]);	
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
	int operacion3;
	int mostrar;
	int acabar;
	int porcentmes;
	float mes1;
	float mes2;
	printf("GENERACIÓN DE ENERGÍAS. \n");
	printf("Por: \n Carla María Perez Alfonso \n Eva Sancho Pavón \n Pilar Aurora Miguel Palacios \n Alba Garrido Caballero \n");
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
			printf("Indique la energía a consultar: \n 1-Hidráulica \n 2-Turbinación bombeo \n 3-Nuclear \n 4-Carbón \n 5-Fuel + Gas \n 6-Motores diésel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroeólica \n 11-Eólica \n 12-Solar fotovoltaica \n 13-Solar térmica \n 14-Otras renovables \n 15-Cogeneración \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generación total \n");
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
					
					fprintf(pescritura, "Título,ESTRUCTURA DE LA GENERACIÓN POR TECNOLOGÍAS_01-01-2021_31-12-2022,,,,,,,,,,,,,,,,,,,,,,,\n");

					fprintf(pescritura, "Sistema eléctrico,Nacional,,,,,,,,,,,,,,,,,,,,,,,\n");

					fprintf(pescritura, "Magnitudes,GWh,,,,,,,,,,,,,,,,,,,,,,,\n");

					fprintf(pescritura, " ,,,,,,,,,,,,,,,,,,,,,,,,\n");

					fprintf(pescritura, "Fecha,1-2021,2-2021,3-2021,4-2021,5-2021,6-2021,7-2021,8-2021,9-2021,10-2021,11-2021,12-2021,1-2022,2-2022,3-2022,4-2022,5-2022,6-2022,7-2022,8-2022,9-2022,10-2022,11-2022,12-2022\n");

					
					for(j = 0; j<18; j++)
					{
						if (j == 0)
						{
						fprintf(pescritura, "Hidráulica");
						}
						else if(j == 1)
						{
						fprintf(pescritura, "Turbinación bombeo");
						}
						else if(j == 2)
						{
						fprintf(pescritura, "Nuclear");
						}
						else if(j == 3)
						{
						fprintf(pescritura, "Carbón");
						}
						else if(j == 4)
						{
						fprintf(pescritura, "Fuel + Gas");
						}
						else if(j == 5)
						{
						fprintf(pescritura, "Motores diésel");
						}
						else if(j == 6)
						{
						fprintf(pescritura, "Turbina de gas");
						}
						else if(j == 7)
						{
						fprintf(pescritura, "Turbina de vapor");
						}
						else if(j == 8)
						{
						fprintf(pescritura, "Ciclo combinado");
						}
						else if(j == 9)
						{
						fprintf(pescritura, "Hidroeólica");
						}
						else if(j == 10)
						{
						fprintf(pescritura, "Eólica");
						}
						else if(j == 11)
						{
						fprintf(pescritura, "Solar fotovoltaica");
						}
						else if(j == 12)
						{
						fprintf(pescritura, "Solar térmica");
						}
						else if(j == 13)
						{
						fprintf(pescritura, "Otras renovables");
						}
						else if(j == 14)
						{
						fprintf(pescritura, "Cogeneración");
						}
						else if(j == 15)
						{
						fprintf(pescritura, "Residuos no renovables");
						}
						else if(j == 16)
						{
						fprintf(pescritura, "Residuos renovables");
						}
						else if(j == 17)
						{
						fprintf(pescritura, "Generación total");
						}
					for(k = 0; k<24; k++)
					{
					fprintf(pescritura, ",%f", tipoenergia[j].anyo[k]);
					}
					fprintf(pescritura, "\n");
					}
					
				fclose(pescritura);
				
			}
			else if (operacion1==3)
			{
				do
				{
				printf("Indique que tipo de operación estadística desea realizar: \n 1-Indicar el máximo \n 2-Indicar el minímo \n 3-Indicar la media \n 4-Indicar porcentaje \n 5-Indicar precio de la energia que se genera.\n");
				scanf("%i", &operacion2);
				}while((operacion2<1)||(operacion2>5));
				
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
				else if (operacion2==5)
				{
					int an;
					
					do
					{
					printf("Introduce el mes y el año:  \n 1- 01/2021 \n 2- 02/2021 \n 3- 03/2021 \n 4- 04/2021 \n 5- 05/2021 \n 6- 06/2021 \n 7- 07/2021 \n 8- 08/2021 \n 9- 09/2021 \n 10- 10/2021 \n 11- 11/2021 \n 12- 12/2021 \n 13- 01/2022 \n 14- 02/2022 \n 15- 03/2022 \n 16- 04/2022 \n 17- 05/2022 \n 18- 06/2022 \n 19- 07/2022 \n 20- 08/2022 \n 21- 09/2022 \n 22- 10/2022 \n 23- 11/2022 \n 24- 12/2022 \n");
					scanf("%i", &an);
					}while((an<1)||(an>24));
					an = an - 1;
					
					float energiamgh= tipoenergia[energia1].anyo[an]*1000;
					float precio = energiamgh*86;
					
					printf("Como el precio del Mgh es de 86 euros aprox, serían %f euros.\n", precio);
				}				
			}
			break;
		case 2:
			do
			{
			printf("Indique que quiere comparar:\n 1-En una misma energia.\n 2-Dos energías diferentes.\n");
			scanf("%i", &comparar);
			}while((comparar<1)||(comparar>2));
			
			if(comparar==1)
			{
			do
			{
			printf("Indique la energía a comparar: \n 1-Hidráulica \n 2-Turbinación bombeo \n 3-Nuclear \n 4-Carbón \n 5-Fuel + Gas \n 6-Motores diésel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroeólica \n 11-Eólica \n 12-Solar fotovoltaica \n 13-Solar térmica \n 14-Otras renovables \n 15-Congeneración \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generación total \n");
		    scanf("%i", &energiac1);			
			}while((energiac1<1)||(energiac1>18));
			
		    energiac1=energiac1 - 1;
		    int fechac1, fechac2;
		    
			do
			{
			printf("Indique las fechas que desea comparar:\n 1- 01/2021 \n 2- 02/2021 \n 3- 03/2021 \n 4- 04/2021 \n 5- 05/2021 \n 6- 06/2021 \n 7- 07/2021 \n 8- 08/2021 \n 9- 09/2021 \n 10- 10/2021 \n 11- 11/2021 \n 12- 12/2021 \n 13- 01/2022 \n 14- 02/2022 \n 15- 03/2022 \n 16- 04/2022 \n 17- 05/2022 \n 18- 06/2022 \n 19- 07/2022 \n 20- 08/2022 \n 21- 09/2022 \n 22- 10/2022 \n 23- 11/2022 \n 24- 12/2022 \n");
			scanf("%i", &fechac1);
			scanf("%i", &fechac2);			
			}while((fechac1<1)||(fechac1>24)||(fechac2<1)||(fechac2>24)||(fechac1==fechac2));
			
			fechac1=fechac1-1;
			fechac2=fechac2-1;
			
			comparar2(tipoenergia[energiac1].anyo[fechac1], tipoenergia[energiac1].anyo[fechac2]);

			}
			else if(comparar==2)
			{
			do 
			{
			printf("Indique las energias a comparar:\n 1-Hidráulica \n 2-Turbinación bombeo \n 3-Nuclear \n 4-Carbón \n 5-Fuel + Gas \n 6-Motores diésel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroeólica \n 11-Eólica \n 12-Solar fotovoltaica \n 13-Solar térmica \n 14-Otras renovables \n 15-Congeneración \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generación total \n");
			scanf("%i", &energiac1);
			scanf("%i", &energiac2);
			}while((energiac1<1)||(energiac1>18)||(energiac2<1)||(energiac2>18)||(energiac1==energiac2));	
			
			energiac1=energiac1-1;
			energiac2=energiac2-1;
			
			int comp;
			
			do
			{
			printf("Indique si quiere:\n 1-Comparar de dos energías diferentes la misma fecha.\n 2-Comparar de dos energías diferentes la media.\n");
			scanf("%i", &comp);
			}while((comp<1)||(comp>2));
			
			if(comp==1)
			{
			int fecha;
			do
			{
			printf("Indique la fecha que desea comparar:\n 1- 01/2021 \n 2- 02/2021 \n 3- 03/2021 \n 4- 04/2021 \n 5- 05/2021 \n 6- 06/2021 \n 7- 07/2021 \n 8- 08/2021 \n 9- 09/2021 \n 10- 10/2021 \n 11- 11/2021 \n 12- 12/2021 \n 13- 01/2022 \n 14- 02/2022 \n 15- 03/2022 \n 16- 04/2022 \n 17- 05/2022 \n 18- 06/2022 \n 19- 07/2022 \n 20- 08/2022 \n 21- 09/2022 \n 22- 10/2022 \n 23- 11/2022 \n 24- 12/2022 \n");
			scanf("%i", &fecha);			
			}while((fecha<1)||(fecha>24));
			
			fecha = fecha - 1;
			
			comparar2(tipoenergia[energiac1].anyo[fecha], tipoenergia[energiac2].anyo[fecha]);
			}
			else if(comp==2)
			{
			tipoenergia[energiac1].media=media(tipoenergia[energiac1].anyo);
			tipoenergia[energiac2].media=media(tipoenergia[energiac2].anyo);
			
			comparar2(tipoenergia[energiac1].media, tipoenergia[energiac2].media);
			}
			    
			}
		    break; 	   
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
void comparar2(float comp1, float comp2)
{
if(comp1>comp2)
{
printf("La primera opción, %f, es mayor que la segunda, %f.\n", comp1, comp2);
}
else if(comp2>comp1)
{
printf("La segunda opción, %f, es mayor que la primera, %f.\n", comp2, comp1);
}
}

