#include <stdio.h>
#include <math.h>
#include <locale.h>
#define N 2898
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
	printf("GENERACI�N DE ENERG�AS \n");
	printf("Este programa le permitira conocer, comparar, modificar u operar con los datos de la generacion de electricidad,\n mediante todos los tipos de energias en Espa�a durante los a�os de 2021 y 2022 (Gwh)\n\n");
	printf("Indique 1 si quiere hacer una consulta individual o 2 si quiere hacer una comparativa \n");
	scanf("%i", &paso1);
	switch(paso1)
	{
		case 1:
			printf("Indique la energ�a a consultar: \n 1-Hidr�ulica \n 2-Turbinaci�n bombeo \n 3-Nuclear \n 4-Carb�n \n 5-Fuel + Gas \n 6-Motores di�sel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroe�lica \n 11-E�lica \n 12-Solar fotovoltaica \n 13-Solar t�rmica \n 14-Otras renovables \n 15-Congeneraci�n \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generaci�n total \n");
			scanf("%i", &energia1);
			//creo que aqu� hay que meter los ficheros
			FILE *plectura;
            FILE *pescritura;
            // Defino un vector para cada variable a leer del fichero	
            float hidraulica[N];
            float turbinacion_bombeo[N];
            float nuclear[N];
            float carbon[N];
            float fuel_y_gas[N];
            float motores_diesel[N];
            float turbina_de_gas[N];
            float turbina_de_vapor[N];
            float ciclo_combinado[N];
            float hidroeolica[N];
            float eolica[N];
            float solar_fotovoltaica[N];
            float solar_termica[N];
            float otras_renovables[N];
            float congeneracion[N];
            float residuos_no_renobables[N];
            float residuos_renovables[N];
            float generacion_total[N];
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
			    	fscanf(plectura, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &hidraulica[i], &turbinacion_bombeo[i], &nuclear[i], &carbon[i], &fuel_y_gas[i], &motores_diesel[i], &turbina_de_gas[i], &turbina_de_vapor[i], &ciclo_combinado[i], &hidroeolica[i], &eolica[i], &solar_fotovoltaica[i], &solar_termica[i], &otras_renovables[i], &congeneracion[i], &residuos_no_renobables[i], &residuos_renovables[i], &generacion_total[i]);
				}
				// Se ha terminado de leer, luego se cierra el archivo
                //fclose(plectura);    //creo q no hay que cerrarlo, por eso lo pongo como en comentario -aurora
            }
             
			printf("Indique qu� operaci�n desea realizar:\t 1-Mostrar y cambiar datos \t 2-Estad�stica \n");
			scanf("%i", &operacion1);
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
						printf("Se le permitir� cambiar un dato de generacion:\n");
						int energia_modificar;
						int anyo;
						int mes;
						int posicion;
						while ((anyo!=1)&& (anyo!=2)) //aunq con esto evite que se joda el programa si no mete uno de esos dos datos se jode todo en cuanto nos metan un char
						{
						printf("�A qu� a�o pertenece esa generacion? 1- si es del 2021, 2- si es del 2022\n");
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
						posicion=posicion+mes; //ahora que ya tenemos la posicion solo hay que ir al vector de la energia (energia_modificar) en la posici�n (posicion) que sea y decirle que esciba algo y ponerlo -aurora
					}
				
					
					//aqu� tambi�n hay que meter algo relacionado con los ficheros
			}
			else if(operacion1==2)
			{
				printf("Indique que tipo de operaci�n estad�stica desea realizar: \n 1-Indicar el m�ximo \n 2-Indicar el min�mo \n 3-Indicar la moda \n 4-Indicar la mediana \n 5-Realizar la media \n");//m�x,m�n,moda de qu� exactamente?
				scanf("%i", &operacion2);
				if(operacion2==1)
				{
					//para indicar el m�x hay que haber puesto el fichero
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
					printf("El n�mero introducido no es v�lido");
				}
			}
			break;
		case 2:
			printf("Indique si quiere comparar 2 o 3 energ�as \n"); //podemos poner m�s pero vamos a empezar por 2 o 3
			scanf("%i", &comparar);
			if(comparar==2)
			{
				printf("Indique las dos energ�as a comparar: \n 1-Hidr�ulica \n 2-Turbinaci�n bombeo \n 3-Nuclear \n 4-Carb�n \n 5-Fuel + Gas \n 6-Motores di�sel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroe�lica \n 11-E�lica \n 12-Solar fotovoltaica \n 13-Solar t�rmica \n 14-Otras renovables \n 15-Congeneraci�n \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generaci�n total \n");
			    scanf("%i %i", &energiac1, &energiac2);
			    printf("Indique qu� quiere comparar:\t");
			    //ponemos opciones o que se pueda escribir?
			}
			else if(comparar==3)
			{
				printf("Indique las tres energ�as a comparar: \n 1-Hidr�ulica \n 2-Turbinaci�n bombeo \n 3-Nuclear \n 4-Carb�n \n 5-Fuel + Gas \n 6-Motores di�sel \n 7-Turbina de gas \n 8-Turbina de vapor \n 9-Ciclo combinado \n 10-Hidroe�lica \n 11-E�lica \n 12-Solar fotovoltaica \n 13-Solar t�rmica \n 14-Otras renovables \n 15-Congeneraci�n \n 16-Residuos no renovables \n 17-Residuos renovables \n 18-Generaci�n total \n");
			    scanf("%i %i %i", &energiac1, &energiac2, &energiac3);
			    printf("Indique qu� quiere comparar:\t");
			    //ponemos opciones o que se pueda escribir?
			}
			else
			{
				printf("N�mero no v�lido, vuelva a ejecutar el progama");
			}
		    break; 	
		default:       
		    printf("N�mero no v�lido, vuelva a ejecutar el progama");// no se poner para que vuelva a preguntar lo mismo otra vez.    
	}
}


