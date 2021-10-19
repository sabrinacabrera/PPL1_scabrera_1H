/*
 * informes.c
 *
 *  Created on: 19 oct. 2021
 *      Author: gisel
 */

#include "informes.h"

int menuInformes()
{
	int opcion;

	system("cls");
	printf("***** Informes *****\n");
	printf("1) Listar los salones con más de 4 arcades. \n");
	printf("2)Listar los arcades para más de 2 jugadores\n");
	printf("3) Listar toda la información de un salón en específico ingresando su ID. \n");
	printf("4)Listar todos los arcades de un salón determinado ingresando su ID.s\n");
	printf("5) Imprimir el salón con más cantidad de arcades\n");
	printf("6)mprimir el monto máximo en pesos que puede recaudar el salon\n");
	printf("7)Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen\n");
	printf("8) Salir\n\n");
	utn_getNumero(&opcion,"\n Ingrese la opcion elegida: \n ","\n Ingrese la opcion elegida:\n ", 1, 8, 3);
	return opcion;

}

/**
 * \brief funcion informes que llamo en main

 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int total_informes(eArcade* arrayA,int limiteArc,eTipoSonido* tipoS,int tamS,eSalon* arraySalon,int tamSalon,eTipoSalon* tipoSalon,int tamTipoSalon)
{
	//pasar vector y tamanio necesarios
		//pasar ids necesarios
		int retorno=-1;

		char continueS = 's';
		char confirm;
		int  id;
		int posicion;
			do
			{


				if(arrayA != NULL && limiteArc > 0  &&arraySalon!=NULL && tamSalon>0){
					switch(menuInformes())
						{
							case 1:
								listar_SCuatArcades(arraySalon, tamSalon, arrayA, limiteArc, tipoSalon, tamTipoSalon);
							break;
							case 2:

							listar_ArcadeDJug(arrayA,limiteArc,arraySalon, tamSalon,tipoS,tamS);

							break;
							case 3:

                                id= utn_getNumero(&id, "\n Ingrese el ID del salón a listar\n ","\n ERROR,Ingrese el ID del salón a listar\n ", 0, 100, 3);


                                	 posicion= buscarPorId(id,arraySalon, tamSalon);
                                     listar_UnlSalon(arraySalon,tamSalon, arrayA, limiteArc,id,tipoSalon,tamTipoSalon);


                                break;
							case 4:

							break;
							case 5:

							break;
							case 6:

							break;
							case 7:

							break;
							case 8:
								system("cls");
								printf("\n***** Salir *****\n\n ");
								printf("Confirma salida? s/n: ");
								fflush(stdin);
								scanf("%c", &confirm);
								if(confirm == 's')
								{
									continueS = 'n';
								}
								break;
							default:
								printf("No es una opcion valida.\n");

						}
					retorno=0;
			}
			}while(continueS == 's');

			return retorno;
		}
int listar_SCuatArcades(eSalon* arraySal, int limSal, eArcade* arrayArcade, int limArcade,eTipoSalon* tipoSalon,int tamTipoSalon)
{
	int respuesta = 1;
	int i;
	int j;
	int contadorSalon;

	if(arraySal != NULL && limSal > 0 && arrayArcade != NULL && limArcade > 0)
	{
		for(i = 0; i < limSal; i++)
		{
			if(arraySal[i].isEmpty == 0)
			{
				contadorSalon = 0;

				for(j = 0; j < limArcade; j++)
				{
					if(arrayArcade[j].isEmpty == 0 && arrayArcade[j].idSal == arraySal[i].idSalon)
					{
						contadorSalon++;
					}
				}
				if(contadorSalon > 4)
				{
					respuesta = 0;
					sal_imprimir(&arraySal[i], tipoSalon, tamTipoSalon);
				}

			}
		}
	}
	return respuesta;
}


int listar_ArcadeDJug(eArcade* arrayArc, int limite, eSalon* arraySal, int limSal,eTipoSonido* tipoSonido,int tamTs)
{
	int respuesta = 1;
	int i;
	int pos;


	if(arrayArc != NULL && limite > 0 && arraySal != NULL && limSal > 0)
	{
		respuesta = 0;


		for(i = 0; i < limite; i++)
		{
			if(arrayArc[i].isEmpty == 0 && arrayArc[i].cantJugadores > 2)
			{
				pos = buscarPorId(i,&arraySal[i], limSal);

				printf("Arcade: %d - Jug: %d -%s - Salón: %s\n", arrayArc[i].idArcade, arrayArc[i].cantJugadores, arrayArc[i].nombreJ, arraySal[pos].nombre);
			}
		}

	}
	return respuesta;
}

int listar_UnlSalon(eSalon* listSal, int lenSal, eArcade* listArcade, int lenArcade, int id,eTipoSalon* tipoSalon,int tamTsalon)
{
	int respuesta = 1;
	int i;
	int cont = 0;

	if(listSal != NULL && lenSal > 0 && listArcade != NULL && lenArcade > 0)
	{
		respuesta = 0;

		 if(listSal != NULL && listSal->isEmpty == 0){
			 	 sal_imprimir(&listSal[id], tipoSalon, tamTsalon);

		      }
		for(i = 0; i < lenArcade; i++)
		{
			if(listArcade[i].isEmpty == 0 && listArcade[i].idSal == id)
			{
				cont++;
			}
		}
		printf("Arcades dentro del salon son : %d\n", cont);

	}

	return respuesta;
}

