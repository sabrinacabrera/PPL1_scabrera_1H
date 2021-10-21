/*
 * informes.c
 *
 *  Created on: 19 oct. 2021
 *      Author: gisel
 */

#include "informes.h"


/**
 * \brief funcion informes que llamo en main
 * arrayA array arcade
 * limiteArc tamanio array arcade
 * tipoS array tipo de sonido
 * arraySalon array de salones
 * tamSalon tamanio array salon
 * tipoSalon array tipo de salon
 * tamTipoSalon tamanio array salon
 *return Retorna 0 (EXITO) y 1 (ERROR)
 */
int total_informes(eArcade* arrayA,int limiteArc,eTipoSonido* tipoS,int tamS,eSalon* arraySalon,int tamSalon,eTipoSalon* tipoSalon,int tamTipoSalon)
{
		char bufferNombre[63];
		char continueS = 's';
		char confirm;
		int  id;
		int idArc;
		int retorno=-1;
		int posicion;
		int posicionArc;

		do
		{
			if(arrayA != NULL && limiteArc > 0  &&arraySalon!=NULL && tamSalon>0){
				switch(menuInformes())
					{
						case 1:
							printf("\n********************************************** \n");
							printf("\n***Listado de salones con más de 4 arcades *** \n");
							printf("\n********************************************** \n");
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
							}else{
								printf("\n No se pudo listar Id de salon\n");
							}

							break;
						case 4:
							arc_imprimirArray(arrayA, limiteArc, tipoS, tamS);
							idArc=utn_getNumero(&idArc,"\n Ingrese el ID del arcade a listar\n ","\n ERROR,Ingrese el ID del arcade a listar\n ", 0, 1000, 3);
							posicionArc= arc_buscarPorId(idArc, arrayA, limiteArc);

							if(idArc==0 && arrayA[posicionArc].idArcade == idArc){
								listar_todosArc(arraySalon, tamSalon, arrayA, limiteArc,idArc, tipoSalon, tamTipoSalon,tipoS, tamS);

								}else{
									printf("\n+++No se pudo listar++++\n");
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
								listar_arcMasDosJugadores(arrayA, limiteArc, arraySalon, tamSalon,tipoSalon, tamTipoSalon);
							break;
						case 9:
							promedio_arcxsalon(arrayA, limiteArc, arraySalon, tamSalon);

							break;
						case 10:
							system("cls");
							printf("\n***** Salir *****\n\n ");
							printf("\n Confirma salida? s/n: \n ");
							fflush(stdin);
							scanf("%c", &confirm);
							if(confirm == 's')
							{
								continueS = 'n';
							}
							break;
						default:
							printf("\n No es una opcion valida.\n");

					}
				retorno=0;
		}
		}while(continueS == 's');

		return retorno;
	}

/*  Lista los salones con más de 4 arcades
 * arraySal array salon
 * limSal tamanio array salon
 * arrayArcade array arcade
 * limArcade tamanio array arcade
 * tipoSalon array de tipo salon
 * tamTipoSalon tamanio del array tipo salon
 * retorna 1 si ERROR, 0 sino
 */
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
				contadorSalon = 0; //reinicio contador x cada salon

				for(j = 0; j < limArcade; j++)
				{
					if(arrayArcade[j].isEmpty == 0 && arrayArcade[j].idSal == arraySal[i].idSalon)
					{
						contadorSalon++; //cuento la cantidad de arcades x salon
					}
				}
				if(contadorSalon > 4) //si contador > 4, imprimo salon
				{
					respuesta = 0;
					sal_imprimir(&arraySal[i], tipoSalon, tamTipoSalon);
				}

			}
		}
	}
	return respuesta;
}

/* funcion Listar los arcades para más de 2 jugadores
 * arrayArc array de arcade
 * limite tamanio de array arcade
 * arraySal array de salones
 * limSal tamanio array salones
 * tipoSonido array tipo sonido
 * tamTs tamanio tipo sonido
 * retorna 1 error,0 sino
 */
int listar_ArcadeDJug(eArcade* arrayArc, int limite, eSalon* arraySal, int limSal,eTipoSonido* tipoSonido,int tamTs)
{
	int respuesta = 1;
	int aux;

	if(arrayArc != NULL && limite > 0 && arraySal != NULL && limSal > 0)
	{
		printf("\n********************************************** \n");
		printf("\n***Lista arcades para mas de 2 jugadores *** \n");
		printf("\n********************************************** \n");
		for(int i = 0; i < limite; i++)
		{
			if(arrayArc[i].isEmpty == 0 && arrayArc[i].cantJugadores > 2)
			{
				aux = buscarPorId(i,&arraySal[i], limSal);

				respuesta = 0;

				printf("Arcade: %d - Jug: %d -%s - Salón: %s\n", arrayArc[i].idArcade, arrayArc[i].cantJugadores, arrayArc[i].nombreJ, arraySal[aux].nombre);
			}
		}
	}
	return respuesta;
}

/*Listar toda la información de un salón en específico ingresando su ID
 *listSal array salon
 *lenSal tamanio array salon
 *listArcade array arcade
 *lenArcade tamanio array arcade
 *id  id pasado a buscar
 *tipoSalon array tipo salon
 *tamTsalon tamanio tipo salon
 * retorna 1 ERROR,0 sino
 */
int listar_UnlSalon(eSalon* listSal, int lenSal, eArcade* listArcade, int lenArcade, int id,eTipoSalon* tipoSalon,int tamTsalon)
{
	int respuesta = 1;
	int i;
	int cont = 0;

	if(listSal != NULL && lenSal > 0 && listArcade != NULL && lenArcade > 0)
	{
		respuesta = 0;

		 if(listSal != NULL && listSal->isEmpty == 0){
			 	 sal_imprimir(&listSal[id], tipoSalon, tamTsalon); //imprimo array de salones

		      }
		for(i = 0; i < lenArcade; i++)
		{	//si el arcade en la posicion i esta lleno && arcade en la posicion i es igual al id ingresado,cuento
			if(listArcade[i].isEmpty == 0 && listArcade[i].idSal == id)
			{
				cont++;
			}
		}
		printf("\n\n Arcades dentro del salon son : %d\n\n", cont);

	}
	return respuesta;
}


/* Listar todos los arcades de un salón determinado ingresando su ID
 *
 *
 *
 *
 *retorna 1 ERROR,0 sino
 */
int listar_todosArc(eSalon* listSal, int lenSal, eArcade* listArcade, int lenArcade, int id,eTipoSalon* tipoSalon,int tamTsalon,eTipoSonido* tipoSonido,int tamTson)
{
	int respuesta = 1;

	if(listArcade != NULL && listArcade > 0 && listArcade != NULL && lenArcade > 0)
	{
		respuesta = 0;
		for(int i = 0; i < lenArcade; i++)
		{
			//si el arcade esta ocupado y arcade es == a id ingresado, lo muestro
		    if( listArcade[i].isEmpty == 0 && listArcade[i].idSal == id)
		    {
			   arc_imprimir(&listArcade[i],tipoSonido, tamTson);
		    }
		}
	}
	return respuesta;
}
/* funcion  Imprimir el salón con más cantidad de arcades
 *
 *
 * retorna 1 ERROR,cero sino
 */
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
			if(arraySalon[i].isEmpty == 0) //si array salon en posicion i esta ocupado...
			{
				cont = 0;
				for(j = 0; j < lenArcade; j++) //recorro los arcades
				{
					if(arrayArcade[j].isEmpty == 0 && arrayArcade[j].idSal == arraySalon[i].idSalon)
					{
						cont++; //sumo
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
/* Por el nombre de un juego cuenta cuantos arcades lo contienen
 *
 *  retorna contador
 */
int contador_juegos(eArcade* arrayArcade,int limiteArc,char* juegoA){
	int contador=0;

	if(arrayArcade != NULL && arrayArcade > 0 && arrayArcade != NULL && limiteArc > 0)
	{
	  for(int i= 0; i < limiteArc; i++){
	   if(arrayArcade[i].isEmpty==1) {
			 break;
		}else{
			//si se encuentra que la cadena ingresada y el nombre en la posicion i son iguales, suma contador
			if(strcmp(arrayArcade[i].nombreJ,juegoA) == 0 )
			{
				contador=contador+1;
			}
	    }
	 }
	}

	return contador;

}
/* funcion que  Ingresar el ID de un salón, y el valor en pesos de una ficha,
 *  e imprimir el monto máximo en pesos que puede recaudar el salón
 *
 * retorna 1 ERROR, 0 sino
 */
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
						 for(int i = 0; i < limiteArcade; i++)
							 {
								if(arrayArcade[i].isEmpty==1)
									{
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

/*listar salon posee al menos 8 arcades de mas de 2 jugadores.
 *
 *
 *retorna 1 si ERROR,0 sino
 */

int listar_arcMasDosJugadores(eArcade* arrayArcade,int limiteArcade,eSalon* arraySalon,int limiteSalon,eTipoSalon* arrayTipo,int tamT ){

	int retorno=1;
	int contador=0;
	if(arrayArcade != NULL  && limiteArcade > 0){
	retorno=0;
		printf("\n***listado de salon/es que posee al menos 8 arcades de mas de 2 jugadores***\n");
		for(int j = 0; j < limiteSalon; j++){

			contador=0;
			if(arraySalon[j].isEmpty==1){

				break;

			}else
				{

					for(int i= 0; i < limiteArcade; i++){

					   if(arrayArcade[i].cantJugadores > 2 && arrayArcade[i].isEmpty==0 && arrayArcade[i].idSal == arraySalon[j].idSalon ) //pregutno si array en posicion i tiene >2 jugadores
							{
								contador=contador+1; //si es si suma 1

							}
				}

			  }

				if(contador>=8 )
				{
					 sal_imprimir(&arraySalon[j], arrayTipo, tamT);
				}else{
					printf("\n\n NO hay salon/es que  posee al menos 8 arcades de mas de 2 jugadores \n\n");

				}
		 }

	}


	return retorno;
}
/* funcion cuenta cantidad de salones totales
 *  retorna contador
 */
int contador_salones(eSalon* arraySalon,int limite){

	int contador=0;

	if(arraySalon  != NULL && limite > 0 ){

		for(int i= 0; i < limite; i++){

			if(arraySalon[i].isEmpty==1)
			{
				break;
			}else
			{
				contador=contador+1;
		    }
		}
	}
	return contador;
}

/* funcion cuenta cantidad de arcades totales
 *  retorna contador
 */
int contador_Arcades(eArcade* arrayArcade,int limite){

	int contador=0;

	if(arrayArcade  != NULL && limite > 0 ){

		for(int i= 0; i < limite; i++){

			if(arrayArcade[i].isEmpty==1)
			{
				break;
			}else
			{
				contador=contador+1;
		    }
		}
	}
	return contador;
}

/*funcion Imprimir el promedio de arcades por salon
 *
 *retorna 1 si ERROR, 0 sino
 */
int promedio_arcxsalon(eArcade* arrayArcade,int limiteArc,eSalon* arraySalon,int limiteSalon){
	int retorno=1;
	float promedio;
	if( arrayArcade !=NULL && limiteArc>0 && arraySalon !=NULL && limiteSalon>0)
	{
		retorno=0;
		promedio=(float)contador_Arcades(arrayArcade, limiteArc)/contador_salones(arraySalon, limiteSalon);

		printf("\n El promedio de arcades por salón es : %.2f \n",promedio);
	}else{
		printf("\n No se pudo realizar el promedio\n");
	}
	return retorno;
}







