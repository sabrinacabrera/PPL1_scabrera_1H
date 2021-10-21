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
	printf("8) Listar los salones que  posee al menos 8 arcades de mas de 2 jugadores\n");
	printf("9) Imprimir el promedio de arcades por salón.\n");

	printf("10) Salir\n\n");
	utn_getNumero(&opcion,"\n Ingrese la opcion elegida: \n ","\n Ingrese la opcion elegida:\n ", 1, 10, 3);
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
		int idArc;
		int posicion;
		int posicionArc;
		char bufferNombre[63];

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
								sal_imprimirArray(arraySalon,tamSalon,tipoSalon, tamTipoSalon);


                                id= utn_getNumero(&id,"\n Ingrese el ID del salón a listar\n ","\n ERROR,Ingrese el ID del salón a listar\n ", 0, 100, 3);
                                posicion= buscarPorId(id,arraySalon, tamSalon);
                                if(id==0 && arraySalon[posicion].idSalon == id){
                                	listar_UnlSalon(arraySalon,tamSalon, arrayA, limiteArc,id,tipoSalon,tamTipoSalon);
                                }

                                break;
							case 4:
								arc_imprimirArray(arrayA, limiteArc, tipoS, tamS);
								idArc=utn_getNumero(&idArc,"\n Ingrese el ID del arcade a listar\n ","\n ERROR,Ingrese el ID del arcade a listar\n ", 0, 1000, 3);
								posicionArc= arc_buscarPorId(idArc, arrayA, limiteArc);

								if(idArc==0 && arrayA[posicionArc].idArcade == idArc){
									listar_todosArc(arraySalon, tamSalon, arrayA, limiteArc,idArc, tipoSalon, tamTipoSalon,tipoS, tamS);

								    }
								break;
							case 5:
								listar_SalonMasCantidad(arrayA, limiteArc, arraySalon, tamSalon, tipoSalon, tamTipoSalon);
							break;
							case 6:
								imprimir_montoMaxSalon(arraySalon, tamSalon, arrayA, limiteArc, tipoSalon, tamTipoSalon);
							break;
							case 7:
								if(utn_getDescripcion(bufferNombre,63,"\nIngrese nombre del juego \n ","\n ERROR,Ingrese nombre del juego:\n\n",3)==0){

									printf("\n La cantidad de arcades con el juego %s son %d\n",bufferNombre, contador_juegos(arrayA, limiteArc, bufferNombre));
								}
							break;
							case 8:

								break;
							case 9:
								break;
							case 10:
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
	int pos;


	if(arrayArc != NULL && limite > 0 && arraySal != NULL && limSal > 0)
	{


		for(int i = 0; i < limite; i++)
		{
			if(arrayArc[i].isEmpty == 0 && arrayArc[i].cantJugadores > 2)
			{
				pos = buscarPorId(i,&arraySal[i], limSal);

				respuesta = 0;

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
		printf("\n Arcades dentro del salon son : %d\n\n", cont);

	}

	return respuesta;
}


//------------------
int listar_todosArc(eSalon* listSal, int lenSal, eArcade* listArcade, int lenArcade, int id,eTipoSalon* tipoSalon,int tamTsalon,eTipoSonido* tipoSonido,int tamTson)
{
	int respuesta = 1;

	if(listArcade != NULL && listArcade > 0 && listArcade != NULL && lenArcade > 0)
	{
		respuesta = 0;
		for(int i = 0; i < lenArcade; i++){

		    if( listArcade[i].isEmpty == 0 && listArcade[i].idSal == id){

			   arc_imprimir(&listArcade[i],tipoSonido, tamTson);


		     }
		}

	}

	return respuesta;
}

int listar_SalonMasCantidad(eArcade* arrayArcade, int lenArcade, eSalon* arraySalon, int tamSalon,eTipoSalon* tipoSalon,int tamTsalon)
{
	int respuesta = 1;
	int i;
	int j;
	int cont;
	int idMax;
	int cMax;
	int flag = 1;

	if(arrayArcade != NULL && lenArcade > 0 && arraySalon != NULL && tamSalon > 0)
	{
		respuesta = 0;
		for(i = 0; i < tamSalon; i++)
		{
			if(arraySalon[i].isEmpty == 0)
			{
				cont = 0;
				for(j = 0; j < lenArcade; j++)
				{
					if(arrayArcade[j].isEmpty == 0 && arrayArcade[j].idSal == arraySalon[i].idSalon)
					{
						cont++;
					}
				}
				if(flag == 1 || cont > cMax)
				{
					idMax = i;
					cMax = cont;
					flag = 0;
				}
			}
		}

		sal_imprimir(&arraySalon[idMax], tipoSalon, tamTsalon);
		printf(" \n\n Este salon posee : %d arcades \n\n", cMax);

	}

	return respuesta;
}

int contador_juegos(eArcade* arrayArcade,int limiteArc,char* juegoA){
	int contador=0;

	if(arrayArcade != NULL && arrayArcade > 0 && arrayArcade != NULL && limiteArc > 0){
	      for(int i= 0; i < limiteArc; i++){
	       if(arrayArcade[i].isEmpty==1){
				 break;
			}else{

				if(strcmp(arrayArcade[i].nombreJ,juegoA) == 0 ) //si el vec juego existe ya, me devuelve 0
				{
					contador=contador+1;
				 }
	      }
		}
	}

	return contador;

}

int imprimir_montoMaxSalon(eSalon* arraySalon,int limite,eArcade* arrayArcade,int limiteArcade,eTipoSalon* arrayTsalon,int tamTsalon){
	int respuesta=1;
	int auxId;
	int auxIndeceSal;
	float valorFicha;
	int sumaFichas=0;
	float multiplicoFichas;

	if(arrayArcade != NULL && limite > 0 && arraySalon != NULL && limiteArcade > 0){

	  sal_imprimirArray(arraySalon, limite, arrayTsalon, tamTsalon);

	  if(utn_getNumero(&auxId,"\n Indique el ID del salon a imprimir: \n","\n ERROR,ID invalido,ingrese nuevamente: \n",0,limite,0) == 0){
		respuesta=0;
		auxIndeceSal =buscarPorId(auxId, arraySalon, limite);

		if(	auxIndeceSal >= 0 ){
			if(utn_getNumeroFlotante(&valorFicha,"\nIngrese el valor de la ficha  mayor a 0: \n","\nERROR,Ingrese nuevamente el valor de la ficha mayor a 0: \n", 0.1, 9999,3)==0)
			{

			 for(int i = 0; i < limiteArcade; i++){

				if(arrayArcade[i].isEmpty==1){
					 break;
				}else{
						  if(arrayArcade[i].isEmpty == 0 && arrayArcade[i].idSal == arraySalon[i].idSalon && arraySalon[i].idSalon == auxId){
						   	sumaFichas=sumaFichas+ arrayArcade[i].maxFichas;
						 }
			    }
			 }
				 multiplicoFichas=(sumaFichas*valorFicha);
			}
			printf("\n El monto máximo en pesos que puede recaudar el salón %d es:$ %.2f \n",auxId,multiplicoFichas);

		}else{

			printf("\nNo existe ID ingresado \n");
	  }
	 }
	}

	return respuesta;
}

//-----------------------
















