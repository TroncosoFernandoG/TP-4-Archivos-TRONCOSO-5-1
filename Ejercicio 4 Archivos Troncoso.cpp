/*
4) Modificar dicho programa de manera que me muestre los datos de manera ordenada
Según se desee por nombre y apellido o por DNI


Troncoso Fernando G 5°1°
*/

#include <stdio.h>

int main(){
	int op;
do{
	
	
	printf("\n\n\n\t\t--Elegir una de las Opciones--\t\t");
	
	printf("\n\n\nIngresar Datos Personales\t\t");
	printf("Busqueda de Datos\n\n\n");
	printf("Salir del Programa\n\n\n");
	
	
	scanf("%d", &op);
	
	if(op<1||op>3)
	{

		do{
			printf("Opcion no valida, por favor intentar nuevamente\n");
			scanf("%d", &op);
		}while(op<1||op>3);
	}
	
	switch(op)
	{
		case 1:{
			printf("tu\n");
			break;
		}
		case 2:{
			printf("vie\n");
			break;
		}	
	}	
	
}while(op!=3);
	
	printf("\n--SALIENDO DEL PROGRAMA--\n");
	
	return 0;
}
