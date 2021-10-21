/*
 * salon.h
 *
 *  Created on: 18 oct. 2021
 *      Author: gisel
 */

#ifndef SALON_H_
#define SALON_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct{
	char nombre[30];
	char direccion[50];
	int idSalon;
	int tipoSalon;
	int isEmpty;
}eSalon;


typedef struct{
	int id;
	char tipo[50];
}eTipoSalon;

//--------------- salon
int sal_inicializarArray(eSalon* array,int limite);
int sal_altaForzadaArray(eSalon* array,int limite, int indice, int* id,char* nombre,char* direccion,int tipo);
int cargarDescripTipoSalon(char descripcion[], int idTipo, eTipoSalon tipos[], int tamT);
int sal_imprimirArray(eSalon* array,int limite,eTipoSalon* arrayTipo,int tamT);
int sal_imprimir(eSalon* pElemento,eTipoSalon* arrayTipo,int tamT);
int sal_getEmptyIndex(eSalon* array,int limite);
int sal_altaArray(eSalon* array,int limite, int indice, int* id,eTipoSalon listaT[], int tamT);
int mostrarTiposSal(eTipoSalon* tipos, int tamT);


#endif /* SALON_H_ */
