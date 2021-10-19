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
#endif /* INFORMES_H_ */
