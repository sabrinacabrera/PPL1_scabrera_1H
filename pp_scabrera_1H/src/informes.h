/*
 * informes.h
 *
 *  Created on: 19 oct. 2021
 *      Author: gisel
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "unionArcSal.h"

int menuInformes();
int total_informes(eArcade* arrayA,int limiteArc,eTipoSonido* tipoS,int tamS,eSalon* arraySalon,int tamSalon,eTipoSalon* tipoSalon,int tamTipoSalon);
int listar_SCuatArcades(eSalon* arraySal, int limSal, eArcade* arrayArcade, int limArcade,eTipoSalon* tipoSalon,int tamTipoSalon);
int listar_ArcadeDJug(eArcade* arrayArc, int limite, eSalon* arraySal, int limSal,eTipoSonido* tipoSonido,int tamTs);
int listar_UnlSalon(eSalon* listSal, int lenSal, eArcade* listArcade, int lenArcade, int id,eTipoSalon* tipoSalon,int tamTsalon);
int listar_todosArc(eSalon* listSal, int lenSal, eArcade* listArcade, int lenArcade, int id,eTipoSalon* tipoSalon,int tamTsalon,eTipoSonido* tipoSonido,int tamTson);
int listar_SalonMasCantidad(eArcade* arrayArcade, int lenArcade, eSalon* arraySalon, int tamSalon,eTipoSalon* tipoSalon,int tamTsalon);
int contador_juegos(eArcade* arrayArcade,int limiteArc,char* juegoA);
int imprimir_montoMaxSalon(eSalon* arraySalon,int limite,eArcade* arrayArcade,int limiteArcade,eTipoSalon* arrayTsalon,int tamTsalon);
int listar_arcMasDosJugadores(eArcade* arrayArcade,int limiteArcade,eSalon* arraySalon,int limiteSalon,eTipoSalon* arrayTipo,int tamT);
int contador_salones(eSalon* arraySalon,int limite);
int contador_Arcades(eArcade* arrayArcade,int limite);
int promedio_arcxsalon(eArcade* arrayArcade,int limiteArc,eSalon* arraySalon,int limiteSalon);

#endif /* INFORMES_H_ */
