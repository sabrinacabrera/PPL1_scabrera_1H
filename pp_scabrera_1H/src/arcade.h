/*
 * arcade.h
 *
 *  Created on: 18 oct. 2021
 *      Author: gisel
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include "utn.h"

//----------- Estructuras------------
typedef struct{
	char nacionalidad[30];
	int tipoSonido;
	int cantJugadores;
	int maxFichas;
	int idSal;
	char nombreJ[63];
	int idArcade;
	int isEmpty;
}eArcade;

typedef struct{
	int id;
	char tipo[50];
}eTipoSonido;


//---------------- Prototipos -------------

int menuModif();
int arc_inicializarArray(eArcade* array,int limite);
int arc_altaForzadaArray(eArcade* array,int limite, int indice, int* id, int idSalon,char* nacionalidad,int tiposonido,int cantjugadores,int maxFichas,char* nombreJ);
int cargarDescripTipoSonido(char descripcion[], int idTipo, eTipoSonido* tipos, int tamT);
int arc_imprimirArray(eArcade* array,int limite,eTipoSonido* arrayTipo,int tamT);
int arc_imprimir(eArcade* pElemento,eTipoSonido* arrayTipo,int tamT);
int arc_getEmptyIndex(eArcade* array,int limite);
int mostrarTiposSon(eTipoSonido* tipos, int tamT);
int mostrarJuegos(eArcade* tipos, int tamA);
int arc_modificarArray(eArcade* array,int limite, int indice,eTipoSonido* tipoS,int tamS);
int arc_buscarPorId(int id, eArcade* lista, int tam);
int arc_baja( eArcade* lista, int tamA,eTipoSonido* tipoS,int tamTipoSonido);
int imprimir_juegos(eArcade* array,int limite);


#endif /* ARCADE_H_ */
