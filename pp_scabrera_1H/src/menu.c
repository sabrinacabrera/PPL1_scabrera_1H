/*
 * menu.c
 *
 *  Created on: 21 oct. 2021
 *      Author: gisel
 */

#include "menu.h"

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



int menuInformes()
{
	int opcion;

	system("cls");
	printf("***** Informes *****\n");
	printf("1) Listar los salones con más de 4 arcades. \n");
	printf("2)Listar los arcades para más de 2 jugadores\n");
	printf("3) Listar toda la información de un salón en específico ingresando su ID. \n");
	printf("4)Listar todos los arcades de un salón determinado ingresando su ID\n");
	printf("5) Imprimir el salón con más cantidad de arcades\n");
	printf("6)mprimir el monto máximo en pesos que puede recaudar el salon\n");
	printf("7)Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen\n");
	printf("8) Listar los salones que  posee al menos 8 arcades de mas de 2 jugadores\n");
	printf("9) Imprimir el promedio de arcades por salón.\n");

	printf("10) Salir\n\n");
	utn_getNumero(&opcion,"\n Ingrese la opcion elegida: \n ","\n Ingrese la opcion elegida:\n ", 1, 10, 3);
	return opcion;

}


