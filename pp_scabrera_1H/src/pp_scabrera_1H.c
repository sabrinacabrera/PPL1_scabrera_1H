/*
 ============================================================================
 Name        : pp_scabrera_1H.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "unionArcSal.h"
#include "informes.h"
#include "menu.h"


#define LENSAL 100
#define LENAR 1000
#define LENTSON 2
#define LENTSALON 2


int main(void) {
	setbuf(stdout,NULL);

	//---Definicion Array estructuras
	eSalon arraySalon[LENSAL];
	eArcade arrayArcade[LENAR];

	//---Definicion Array estructuras tipo
	eTipoSalon listaTsalon[LENTSALON] =  {{1,"SHOPPING "},
				{2, "LOCAL"}};

	eTipoSonido listaTson[LENTSON] =  {{1, "MONO"},
					{2, "EST?REO"}};

	int idSalon=0;
	int idArcade=0;
	int flagMenuprincSal=0;
	int flagMenuprincArc=0;

	int auxiliarIndiceSal;

	int auxiliarIndiceArc;
	int auxIdArc;

	char continueS = 's';
	char confirm;

//------- inicializar arrays
		if(sal_inicializarArray(arraySalon,LENSAL) == 0)
			{
				printf("Array Salon inicializado correctamente. \n\n");
			}
		if(arc_inicializarArray(arrayArcade,LENAR) == 0)
					{
						printf("Array Arcade inicializado correctamente. \n\n");
					}
/*/----------------------------------------------------

	sal_altaForzadaArray(arraySalon,LENSAL,0,&idSalon ,"saltitos","juncal 220",1);
	sal_altaForzadaArray(arraySalon,LENSAL,1,&idSalon ,"papita","rondeau 654",2);
	sal_altaForzadaArray(arraySalon,LENSAL,2,&idSalon ,"hamburguesa","lalala 963",1);

   arc_altaForzadaArray(arrayArcade,LENAR, 0,&idArcade,2,"argentina",1,2,2,"mario bros");
   arc_altaForzadaArray(arrayArcade,LENAR, 1,&idArcade,1,"uruguay",2,4,4,"mortal kombat");
   arc_altaForzadaArray(arrayArcade,LENAR, 3,&idArcade,0,"brasil",1,1,3,"don king kong");
   arc_altaForzadaArray(arrayArcade,LENAR, 2,&idArcade,2,"chingolo",3,1,3,"don king kong");
   arc_altaForzadaArray(arrayArcade,LENAR, 4,&idArcade,0,"africa",1,1,3,"mortal kombat");
   arc_altaForzadaArray(arrayArcade,LENAR, 5,&idArcade,1,"china",1,1,4,"kombat");
   arc_altaForzadaArray(arrayArcade,LENAR, 6,&idArcade,0,"mongolia",1,1,3,"counter");

   arc_altaForzadaArray(arrayArcade,LENAR, 7,&idArcade,0,"africa",1,4,3,"mortal 1");
   arc_altaForzadaArray(arrayArcade,LENAR, 8,&idArcade,2,"africa",1,4,3,"mortal 2");
   arc_altaForzadaArray(arrayArcade,LENAR, 9,&idArcade,0,"africa",1,4,3,"mortal 3");
   arc_altaForzadaArray(arrayArcade,LENAR, 10,&idArcade,1,"africa",1,4,3,"mortal 4");

//-----------------------------------------------------------------------------------------/*/

	do{
			system("cls");

			switch(menu())
			{
				case 1:

					auxiliarIndiceSal = sal_getEmptyIndex(arraySalon,LENSAL);
					if(auxiliarIndiceSal >= 0)
					{
						if(sal_altaArray(arraySalon,LENSAL,auxiliarIndiceSal,&idSalon,listaTsalon,LENTSALON) == 0)
						{
							printf("\n Carga salon realizada con exito,su id es : %d \n",idSalon);
							flagMenuprincSal=1;
						}else
						{
							  printf("\n Hubo un error en el alta salon \n");
						}
					}else{
						  printf("\n NO HAY MAS LUGAR \n");
						 }

				break;
				case 2:
					if(flagMenuprincSal==1)
						{
							if(sal_baja(arraySalon,LENSAL,arrayArcade,LENAR,listaTsalon,LENTSALON) == 0)
								{
								  printf("\n Eliminacion de salon realizada con exito \n");
								}else{
										printf("\n Hubo un error en la baja de salon \n");
									 }
						}else{
							printf("\nERROR,primero debe dar de alta un salon para dar de baja\n");
						}
				break;
				case 3:
					if(flagMenuprincSal==1){
						sal_imprimirArray(arraySalon,LENSAL,listaTsalon,LENTSALON);
					}else{

						printf("\nERROR,primero debe dar de alta un salon/es para imprimir\n");
					}

				break;
				case 4:
					if(flagMenuprincSal==1){
						auxiliarIndiceArc = arc_getEmptyIndex(arrayArcade,LENAR);
						if(auxiliarIndiceArc >= 0)
						{
						  if(arc_altaArray(arrayArcade,LENAR,auxiliarIndiceArc,&idArcade,listaTson,LENTSON,arraySalon,LENSAL,listaTsalon,LENTSALON) == 0)
							 {
								printf("\n Carga arcade realizada con exito,su id es : %d \n",idArcade);
								flagMenuprincArc=1;
							 }else{
								 	 printf("\n Hubo un error en el alta arcade \n");
							     }
						}else{
									printf("\n NO HAY MAS LUGAR \n");
								 }
					}else{

						printf("\n Para dar de alta un arcade,debe haber al menos un salon!\n");

					}
				break;
				case 5:
					if(flagMenuprincArc==1){
						arc_imprimirArray(arrayArcade,LENAR,listaTson,LENTSON);
						if(utn_getNumero(&auxIdArc,"\n Indique el ID del Arcade a modificar\n ","\nID invalido \n",0,idArcade,0) == 0)
						{
							auxiliarIndiceArc =arc_buscarPorId(auxIdArc,arrayArcade,LENAR);
							if(	auxiliarIndiceArc >= 0 &&
								arc_modificarArray(arrayArcade,LENAR,auxIdArc,listaTson,LENTSON) == 0){
												printf("\nModificacion realizada con exito\n");
											}
								}
					}else{
						printf("\n Si no hay arcades no se pueden modificar!\n");
					}
				break;
				case 6:
					if(flagMenuprincArc==1)
					{
						if(arc_baja(arrayArcade,LENAR,listaTson,LENTSON) == 0)
						{
							 printf("\n Eliminacion de arcade realizada con exito \n");
						}else{
								printf("\n Hubo un error en la baja de arcade \n");
							}
					}else{
						printf("\nSi no hay arcades no se pueden dar de baja!\n");
					}
				break;
				case 7:
					if(flagMenuprincArc==1 ){
						arc_imprimirArray(arrayArcade,LENAR,listaTson,LENTSON);
					}else{
						printf("\n tiene que haber arcades para imprimir! \n");
					}
				break;

				case 8:
					if(flagMenuprincArc==1 ){
						imprimir_juegos(arrayArcade,LENAR);
					}else{
						printf("No hay juegos para imprimir");
					}
				break;
				case 9:
					if(flagMenuprincSal==1 && flagMenuprincArc==1){
						total_informes(arrayArcade,LENAR,listaTson,LENTSON,arraySalon,LENSAL,listaTsalon, LENTSALON);
					}else{

						printf("\nNo hay datos para informes\n");
					}
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

		}while(continueS == 's');
	return EXIT_SUCCESS;
}




