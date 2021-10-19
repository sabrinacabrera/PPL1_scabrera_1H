/*
 * salon.c
 *
 *  Created on: 18 oct. 2021
 *      Author: gisel
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "salon.h"
#include "utn.h"

/**
 * \briefinicializa array
 * \param array Array
 * \param limite Limite del array
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */

int sal_inicializarArray(eSalon* array,int limite)
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
 * \brief Da de alta un salon en una posicion del array
 * \param array Array de salon a ser actualizado
 * \param limite Limite del array de salon
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la salon
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int sal_altaForzadaArray(eSalon* array,int limite, int indice, int* id,char* nombre,char* direccion,int tipo)

{
	int respuesta = -1;
	eSalon bufferSalon;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
			strncpy(bufferSalon.nombre,nombre,30);
			strncpy(bufferSalon.direccion,direccion,50);
			bufferSalon.tipoSalon = tipo;
			respuesta = 0;
			bufferSalon.idSalon = *id;
			bufferSalon.isEmpty = 0;
			array[indice] = bufferSalon;
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
int sal_imprimir(eSalon* pElemento,eTipoSalon* arrayTipo,int tamT)
{
	int retorno=-1;
	char descripTipo[20];

	cargarDescripTipoSalon(descripTipo,pElemento->tipoSalon,arrayTipo,tamT);
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\n ID:%d -NOMBRE: %s -DIRECCION: %s -TIPO: %d - %s \n",pElemento->idSalon,pElemento->nombre,pElemento->direccion,pElemento->tipoSalon,descripTipo);
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
int sal_imprimirArray(eSalon* array,int limite,eTipoSalon* arrayTipo,int tamT)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			sal_imprimir(&array[i],arrayTipo,tamT);
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
int cargarDescripTipoSalon(char descripcion[], int idTipo, eTipoSalon* tipos, int tamT)
{
	int isOk = 0;

	for(int i = 0; i < tamT; i++)
	{
		if(tipos[i].id == idTipo) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
		{
			strcpy(descripcion, tipos[i].tipo); //copio a descripcion la descripcion que tengo en ese sector
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
int sal_getEmptyIndex(eSalon* array,int limite)
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
 * \brief Da de alta  en una posicion del array
 * \param array Array  a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int sal_altaArray(eSalon* array,int limite, int indice, int* id,eTipoSalon listaT[], int tamT)
{
	int respuesta = -1;
	eSalon buffer;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(utn_getNombre(buffer.nombre,30,"\n Ingrese Nombre : \n","\nERROR,Nombre invalido \n",2) == 0 &&
		   utn_getDescripcion(buffer.direccion,50,"\n ingrese direccion : \n","\n ERROR,direccion invalido \n",2) == 0

				)
		{
			mostrarTiposSal(listaT, tamT); //muestra los tipos

			if(utn_getNumero(&buffer.tipoSalon, "Ingrese tipo de salon : \n", "El tipo ingresado no es valido.\n", 1, 2,3) == 0)
			  {
								respuesta = 0;
								buffer.idSalon = *id;
								buffer.isEmpty = 0;
								array[indice] = buffer;
								(*id)++;
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
int mostrarTiposSal(eTipoSalon* tipos, int tamT)
{
	int isOk = 0;
	if(tipos != NULL)
	{
		isOk = 1;
		printf("*** Tipos  Salon***\n");
		printf("  ID     Descripcion\n\n");

		for(int i = 0; i < tamT; i++)
		{
			printf("%d   %10s \n", tipos[i].id, tipos[i].tipo);
		}
	}
	return isOk;
}

