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
#include "salon.h"
#include "arcade.h"
#include "unionArcSal.h"
#include "informes.h"


#define LENSAL 100
#define LENAR 1000
#define LENTSON 2
#define LENTSALON 2


//prototipos de funciones
int menu();

int main(void) {
	setbuf(stdout,NULL);

	//---Definicion Array estructuras
	eSalon arraySalon[LENSAL];
	eArcade arrayArcade[LENAR];

	//---Definicion Array estructuras tipo
	eTipoSalon listaTsalon[LENTSALON] =  {{1,"SHOPPING "},
				{2, "LOCAL"}};

	eTipoSonido listaTson[LENTSON] =  {{1, "MONO"},
					{2, "ESTÉREO"}};

	int idSalon=0;
	int idArcade=0;

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
//----------------------------------------------------

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
						}else
						{
							  printf("\n Hubo un error en el alta salon \n");
						}
					}else{
						  printf("\n NO HAY MAS LUGAR \n");
						 }

				break;
				case 2:

					  if(sal_baja(arraySalon,LENSAL,arrayArcade,LENAR,listaTsalon,LENTSALON) == 0)
						{
						  printf("\n Eliminacion de salon realizada con exito \n");
							}else{
									printf("\n Hubo un error en la baja de salon \n");
							}

					break;

				case 3:

					sal_imprimirArray(arraySalon,LENSAL,listaTsalon,LENTSALON);


					break;

				case 4:
					auxiliarIndiceArc = arc_getEmptyIndex(arrayArcade,LENAR);
					if(auxiliarIndiceArc >= 0)
					{
					  if(arc_altaArray(arrayArcade,LENAR,auxiliarIndiceArc,&idArcade,listaTson,LENTSON,arraySalon,LENSAL,listaTsalon,LENTSALON) == 0)
					 {
						printf("\n Carga arcade realizada con exito,su id es : %d \n",idArcade);
					 }else{
							 printf("\n Hubo un error en el alta arcade \n");
						}
						}else{
								printf("\n NO HAY MAS LUGAR \n");
					 }
					break;
				case 5:
					arc_imprimirArray(arrayArcade,LENAR,listaTson,LENTSON);
					if(utn_getNumero(&auxIdArc,"\n Indique el ID del Arcade a modificar\n ","\nID invalido \n",0,idArcade,0) == 0)
					{
						auxiliarIndiceArc =arc_buscarPorId(auxIdArc,arrayArcade,LENAR);
						if(	auxiliarIndiceArc >= 0 &&
							arc_modificarArray(arrayArcade,LENAR,auxIdArc,listaTson,LENTSON) == 0){
											printf("\nModificacion realizada con exito\n");
										}
							}
					break;
				case 6:
					if(arc_baja(arrayArcade,LENAR,listaTson,LENTSON) == 0)
					{
						 printf("\n Eliminacion de arcade realizada con exito \n");
					}else{
							printf("\n Hubo un error en la baja de arcade \n");
						}

				    break;

				case 7:
					arc_imprimirArray(arrayArcade,LENAR,listaTson,LENTSON);
				    break;

				case 8:
				    imprimir_juegos(arrayArcade,LENAR);
				    break;
				case 9:
					total_informes(arrayArcade,LENAR,listaTson,LENTSON,arraySalon,LENSAL,listaTsalon, LENTSALON);
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


int menu()
{
	int opcion;

	system("cls");
	printf("\n ***** MENU *****\n\n");
	printf("1. ALTA DE SALON\n");
	printf("2. ELIMINAR SALON\n");
	printf("3. IMPRIMIR SALONES\n");
	printf("4. INCORPORAR ARCADE\n");
	printf("5. MODIFICAR ARCADE\n");
	printf("6. ELIMINAR ARCADE \n");
	printf("7. IMPRIMIR ARCADES\n");
	printf("8. IMPRIMIR JUEGOS\n");
	printf("9. INFORMES\n");

	printf("10. SALIR\n\n");

	utn_getNumero(&opcion, "Ingrese la opcion elegida: \n", "Error, no es una opcion valida.\n", 1, 10,3);

	return opcion;

}



