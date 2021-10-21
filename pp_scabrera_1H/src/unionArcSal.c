/*
 * unionArcSal.c
 *
 *  Created on: 19 oct. 2021
 *      Author: gisel
 */

#include "unionArcSal.h"


/**
 * \brief Da de alta  en una posicion del array
 * \param array Array  a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int arc_altaArray(eArcade* array,int limite, int indice, int* id,eTipoSonido listaT[], int tamT,eSalon* arrayS,int limiteSalon,eTipoSalon* arrayTipoSalon, int tamTipoSalon)
{
	int respuesta = -1;
	eArcade buffer;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{

		if(utn_getDescripcion(buffer.nombreJ, 63, "\n Ingrese Nombre de juego: \n", "\nERROR,Nombre invalido \n",2) == 0 &&
		   utn_getDescripcion(buffer.nacionalidad, 30, "\n Ingrese nacionalidad de juego: \n", "\nERROR,nacionalidad invalida \n",2) == 0 &&
		   utn_getNumero(&buffer.cantJugadores,"\n ingrese cantidad de jugadores 1-4: \n","\n ERROR,cantidad invalida \n",1,4,3) == 0 &&
		   utn_getNumero(&buffer.maxFichas,"\n ingrese maximo de fichas 1-10: \n","\n ERROR,maximo invalido \n",1,10,3) == 0

				)
		{
			sal_imprimirArray(arrayS,limiteSalon,arrayTipoSalon,tamTipoSalon);
			utn_getNumero(&buffer.idSal,"\n ingrese id del salon al que pertenece: \n","\n ERROR,id invalido \n",0,999,3);

			int posicion;

			posicion=buscarPorId(buffer.idSal,arrayS,limiteSalon);
			while(posicion== -1){

				utn_getNumero(&buffer.idSal,"\n ingrese id del salon: \n","\n ERROR,id invalido \n",0,999,3);

			}

			mostrarTiposSon(listaT, tamT); //muestra los tipos

			if(utn_getNumero(&buffer.tipoSonido, "Ingrese tipo de sonido : \n", "El tipo ingresado no es valido.\n", 1, 2,3) == 0)
			  {
								respuesta = 0;
								buffer.idArcade = *id;
								buffer.isEmpty = 0;
								array[indice] = buffer;
								(*id)++;
			 }
		}
	}
	return respuesta;
}

int buscarPorId(int id, eSalon* lista, int tam)
{
	int indice = -1;

	for(int i = 0; i < tam; i++)
	{
		if(lista[i].idSalon == id && lista[i].isEmpty == 0) //si el vec id existe ya, me devuelve donde esta
		{
			indice = i;

			break;
		}
	}

	return indice;
}



//esta es la funcion que llamo en main para dar de baja:
int sal_baja( eSalon* listaS, int tamS, eArcade* listaA, int tamA,eTipoSalon* tipoS,int tamTipoSalon)
{
	int id;
	int respuesta = -1;

	if(listaS != NULL && listaA != NULL && tamS > 0 && tamA > 0) //agregar las listas que sean
	{

		sal_imprimirArray(listaS,tamS,tipoS,tamTipoSalon);

		utn_getNumero(&id,"\n ingrese id del salon al que pertenece: \n","\n ERROR,id invalido \n",0,999,3);

		int posicion;

		posicion=buscarPorId(id,listaS,tamS);
		while(posicion== -1){

			utn_getNumero(&id,"\n ingrese id del salon: \n","\n ERROR,id invalido \n",0,999,3);

		}

		listaS[posicion].isEmpty=1;

		respuesta=0;

		for(int i;i<tamA;i++){
			if(listaA[i].isEmpty==0 && listaA[i].idSal==id){
				listaA[i].isEmpty=1;

			}

		}
	}

	return respuesta;
}
