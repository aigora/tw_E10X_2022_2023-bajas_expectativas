#include <stdio.h>
#include <math.h>
#include <locale.h>
#define N 24
#define I 18 // Soy alba, he estado 3 horas, no he hecho casi nada pero he llegado a la conclusion de que no entiendo ni la mitad de tres cuartos y que nos hemos organizado mal, mañana hablo por el grupo para ver si alguien opina lo mismo.
//N seria 24 en vez de 2898 porque solo tenemos 24 fechas
//Es mas facil hacer un vector de estructura para cada energia con vectores, vector mostrar es para guardar en cada posicion los años, variable media para calcular esa estadistica, y lo que veais que necsitemos de cada energia ponerlo ahi.

typedef struct
{
float mostrar[N];
float media;
float max;
float min;
float moda;
float mediana; 
} tipoenergia[I];


int main()
{
	setlocale(LC_CTYPE,"spanish");// esto es para poner tildes
	int paso1;
	int energia1;
	int energiac1;
	int energiac2;
	int energiac3;
	int comparar;
	int operacion1;
	int operacion2;
	printf("GENERACIÓN DE ENERGÍAS \n");
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
			int tip = energia1 - 1;
			//creo que aquí hay que meter los ficheros
			FILE *plectura;
            FILE *pescritura;
            int i = 0;
            // Abrir el archivo de lectura
            plectura = fopen("C:/Users/Pc/Documents/GitHub/tw_E10X_2022_2023-bajas_expectativas/generacion_por_tecnologias_21_22.csv", "r"); //con esta direccion deberia de poder abrirsenos bien el archivo en todos los portatiles  
			
			if (plectura == NULL)
			{
			 printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
			 return-1;
			  }
			  
			else
			{
			  	for (i = 0; i < N; i++);
			    {
			    	fscanf(plectura, "Título,ESTRUCTURA DE LA GENERACIÓN POR TECNOLOGÍAS_01-01-2021_31-12-2022...%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", tipoenergia[tip].mostrar[0], .... );
				}
				//Aqui creo que deberiamos pasar toda la informacion a otro fichero más facil de leer porque aqui hay que escribir mucho fijandonos que todo este bien, lo hablamos en clase.
				// Se ha terminado de leer, luego se cierra el archivo
                fclose(plectura);    //si hay que cerrarlo porque ya hemos leido toda la info que queriamos
            }
            do
			{
			printf("Indique qué operación desea realizar:\t 1-Mostrar y cambiar datos \t 2-Estadística \n");
			scanf("%i", &operacion1);
			} while ((operacion1<1)||(operacion1>2))
			if(operacion1==1)
			{
				pescritura=  fopen ("C:/Users/Pc/Documents/GitHub/tw_E10X_2022_2023-bajas_expectativas/generacion_por_tecnologias_21_22_escritura.csv", "w");

					if (pescritura == NULL)
					{
					printf("Error al abrir el fichero.\n");
					return -1;
					}
					
					else
					{
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
					}
				
					
					//aquí también hay que meter algo relacionado con los ficheros
			}
			else if(operacion1==2)
			{
				printf("Indique que tipo de operación estadística desea realizar: \n 1-Indicar el máximo \n 2-Indicar el minímo \n 3-Indicar la moda \n 4-Indicar la mediana \n 5-Realizar la media \n");//máx,mín,moda de qué exactamente?
				scanf("%i", &operacion2); //creo que aqui sobran cosas de estadistica, y tamb creo que todo esto tendriamos que calcularlo al principio y leer el fichero tamb al principio antes de todo el menu y todo.
				if(operacion2==1)
				{
					//para indicar el máx hay que haber puesto el fichero
				}
				else if(operacion2==2)
				{
					//igual que antes
				}
				else if(operacion2==3)
				{
					//
				}
				else if(operacion2==4)
				{
					//
				}
				else if(operacion2==5)
				{
					//
				}
				else
				{
					printf("El número introducido no es válido");
				}
			}
			break;
		case 2:
			printf("Indique si quiere comparar 2 o 3 energías \n"); //podemos poner más pero vamos a empezar por 2 o 3 //A mi me parece una barbaridad comparar 3
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
				printf("Indique las tres energías a comparar: \n 1-Hidráulica \n 2-Turbinación bombeo \n 3-Nuclear \n 4-Carbón \n 5-Fuel + Gas \n 6-Motores diésel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroeólica \n 11-Eólica \n 12-Solar fotovoltaica \n 13-Solar térmica \n 14-Otras renovables \n 15-Congeneración \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generación total \n");
			    scanf("%i %i %i", &energiac1, &energiac2, &energiac3);
			    printf("Indique qué quiere comparar:\t");
			    //ponemos opciones o que se pueda escribir?
			}
			else
			{
				printf("Número no válido, vuelva a ejecutar el progama");
			}
		    break; 	
		default:       
		    printf("Número no válido, vuelva a ejecutar el progama");// no se poner para que vuelva a preguntar lo mismo otra vez.    
	}
}


