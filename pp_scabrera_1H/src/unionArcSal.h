/*
 * unionArcSal.h
 *
 *  Created on: 19 oct. 2021
 *      Author: gisel
 */

#ifndef UNIONARCSAL_H_
#define UNIONARCSAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arcade.h"
#include "salon.h"

int arc_altaArray(eArcade* array,int limite, int indice, int* id,eTipoSonido listaT[], int tamT,eSalon* arrayS,int limiteSalon,eTipoSalon* arrayTipoSalon, int tamTipoSalon);
int buscarPorId(int id, eSalon* lista, int tam);
int sal_baja( eSalon* listaS, int tamS, eArcade* listaA, int tamA,eTipoSalon* tipoS,int tamTipoSalon);


#endif /* UNIONARCSAL_H_ */
