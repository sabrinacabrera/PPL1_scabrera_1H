/*
 * arcade.c
 *
 *  Created on: 18 oct. 2021
 *      Author: gisel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arcade.h"
#include "utn.h"


/**
 * \briefinicializa array
 * \param array Array
 * \param limite Limite del array
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */

int arc_inicializarArray(eArcade* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un arcade en una posicion del array
 * \param array Array de arcade a ser actualizado
 * \param limite Limite del array de arcade
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la arcade
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int arc_altaForzadaArray(eArcade* array,int limite, int indice, int* id, int idSalon,char* nacionalidad,int tiposonido,int cantjugadores,int maxFichas,char* nombreJ)

{
	int respuesta = -1;
	eArcade bufferArcade;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
			strncpy(bufferArcade.nacionalidad,nacionalidad,30);
		    bufferArcade.tipoSonido=tiposonido;
			bufferArcade.cantJugadores = cantjugadores;
			bufferArcade.maxFichas= maxFichas;
			respuesta = 0;
			bufferArcade.idArcade = *id;
			bufferArcade.idSal =idSalon;
			strncpy(bufferArcade.nombreJ,nombreJ,63);
			bufferArcade.isEmpty = 0;
			array[indice] = bufferArcade;
			(*id)++;
	}
	return respuesta;
}


/**
 * \brief Imprime los datos de una entidad
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int arc_imprimir(eArcade* pElemento,eTipoSonido* arrayTipo,int tamT)
{
	int retorno=-1;
	char descripTipo[20];


	cargarDescripTipoSonido(descripTipo,pElemento->tipoSonido,arrayTipo,tamT);
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\n ID: %d -NOMBRE: %s - NACIONALIDAD: %s - CANT.JUGADORES: %d -MAX.Fichas: %d -Tipo Sonido: %d -%s - ID SAL: %d \n",pElemento->idArcade,pElemento->nombreJ,pElemento->nacionalidad,pElemento->cantJugadores,pElemento->maxFichas,pElemento->tipoSonido,descripTipo,pElemento->idSal);
	}
	return retorno;
}


/**
 * \brief Imprime el array
 * \param array Array
 * \param limite Limite del
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int arc_imprimirArray(eArcade* array,int limite,eTipoSonido* arrayTipo,int tamT)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			arc_imprimir(&array[i],arrayTipo,tamT);
		}
	}
	return respuesta;
}

/**
 * \brief carga descripcioon
 * \param cadena descripcion
 * \param idTipo id correspondiente a descripcion
 * \param tipos array de tipo
 * \param tamT tamanio array tipos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cargarDescripTipoSonido(char descripcion[], int idTipo, eTipoSonido* tipos, int tamT)
{
	int isOk = 0;

	for(int i = 0; i < tamT; i++)
	{
		if(tipos[i].id == idTipo) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
		{
			strcpy(descripcion,tipos[i].tipo); //copio a descripcion la descripcion que tengo en ese sector
			isOk = 1; //exito
			break;
		}
	}

	return isOk;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array
 * \param limite Limite del array
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int arc_getEmptyIndex(eArcade* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}


/**
 * \brief Da de mostrar tipo
 * \param tipo array
 * \return Retorna 1 (EXITO) y 0 (ERROR)
 *
 */
int mostrarTiposSon(eTipoSonido* tipos, int tamT)
{
	int isOk = 0;
	if(tipos != NULL)
	{
		isOk = 1;
		printf("*** Tipos  de Sonido ***\n");
		printf("  ID     Descripcion\n\n");

		for(int i = 0; i < tamT; i++)
		{
			printf("%d   %10s \n", tipos[i].id, tipos[i].tipo);
		}
	}
	return isOk;
}

int menuModif()
{
	int opcion;

	system("cls");
	printf("***** Modificaciones Arcade*****\n");
	printf("1. Cantidad de Jugadores\n");
	printf("2.Juegos que contiene \n");
	printf("3. Salir\n\n");
	utn_getNumero(&opcion," \n Ingrese la opcion elegida: \n ","\n Ingrese la opcion elegida:\n ", 1, 3, 2);
	return opcion;

}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int arc_modificarArray(eArcade* array,int limite, int indice,eTipoSonido* tipoS,int tamS)
{
	//pasar vector y tamanio necesarios
		//pasar ids necesarios
		int retorno=-1;

		char continueS = 's';
		char confirm;

			do
			{	if(array != NULL && limite > 0 && indice != -1){
					switch(menuModif())
						{
							case 1:
								utn_getNumero(&array[indice].cantJugadores,"\n ingrese nueva cantidad de jugadores 1-4: \n","\n ERROR,cantidad invalida \n",1,4,3);

							break;
							case 2:
								mostrarJuegos(array,limite);
								utn_getNombre(array[indice].nombreJ,63,"\n Ingrese nuevo nombre de juego: \n","\nERROR,Nombre invalido \n",2);
								break;

							case 3:
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


int mostrarJuegos(eArcade* tipos, int tamA)
{
	int isOk = 0;


	if(tipos != NULL && tamA>=0)
	{
		isOk = 1;
		printf("*** Nombres de juegos cargados***\n");


		for(int i = 0; i < tamA; i++)
		{	if(tipos[i].isEmpty==0)
			{
				printf("\n Id:%d -%10s \n",tipos[i].idArcade,tipos[i].nombreJ);

			}
		}
	}
	return isOk;
}

int arc_buscarPorId(int id, eArcade* lista, int tam)
	{
		int indice = -1;

		for(int i = 0; i < tam; i++)
		{
			if(lista[i].idArcade == id && lista[i].isEmpty == 0) //si el vec id existe ya, me devuelve donde esta
			{
				indice = i;

				break;
			}
		}

		return indice;
	}

//esta es la funcion que llamo en main para dar de baja:
int arc_baja( eArcade* lista, int tamA,eTipoSonido* tipoS,int tamTipoSonido)
{
	int id;
	int respuesta = -1;

	if(lista != NULL  && tamA > 0) //agregar las listas que sean
	{
		int posicion;
		char eliminar;

		arc_imprimirArray(lista,tamA,tipoS,tamTipoSonido);

		utn_getNumero(&id,"\n ingrese id del arcade al que desea dar de baja: \n","\n ERROR,id invalido \n",0,1000,3);

		posicion=arc_buscarPorId(id,lista,tamA);

		if(posicion != -1){
			printf("\n usted va a eliminar el siguiente arcade:\n");
			arc_imprimir(&lista[id],tipoS,tamTipoSonido);
			printf("Eliminar? s/n:\n ");
			scanf("%c", &eliminar);
			if(eliminar == 's'){
				lista[posicion].isEmpty=1; //eliminar

			}else
			{
				printf("\n No se han realizado cambios.\n");
			}

			respuesta=0;
		}









	}

	return respuesta;
}

//----Imprimir juegos---


int imprimir_juegos(eArcade* array,int limite){

	int resp = 1;
	int i;
	int j;
	int flag;

	if(array != NULL && limite > 0)
	{
		resp = 0;


		for(i = 0; i < limite; i++)
		{
			if(array[i].isEmpty == 0)
			{
				flag = 1;
				for(j = i+1; j < limite; j++)
				{
					if(strcmp(array[i].nombreJ, array[j].nombreJ) == 0)
					{
						flag = 0;
					}
				}
				if(flag == 1)
				{
					printf("id: %d - Nombre: %s\n", array[i].idArcade, array[i].nombreJ);

				}
			}
		}
	}

	return resp;

}
