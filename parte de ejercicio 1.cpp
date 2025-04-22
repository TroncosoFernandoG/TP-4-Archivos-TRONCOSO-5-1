/*
1) Realizar un programa en el cual se ingresen los siguientes datos Nombre, Apellido y DNI
a) Crear un menú donde se ingresen los datos y los guarde en un archivo
b) Otro ítem donde se pueda realizar una búsqueda por DNI y devuelva los datos de Nombre y apellido
c) Salir del mismo

*/

#include <stdio.h>
#include <string.h>

int main()
{

int op;
int x=1;
FILE*fp;


do{
	
	
	printf("elegi la opcion\n");
	scanf("%d", &op);
	do{

	if(op<1||op>3){
	printf("opcion no valida\n");
	scanf("%d", &op);	
	}
		}while(op<1||op>3);
		getchar();
	switch(op){
		
		case 1:
		
		char nombre[50];
		char apellido[50];
		int DNI;
		
		
		
		fp=fopen("archivo.txt", "a");
		
		printf("Ingrese el Nombre\n");
		fgets(nombre, sizeof(nombre), stdin);
		printf("Ingrese el Apellido\n");
		fgets(apellido, sizeof(apellido), stdin);
		printf("Ingrese el DNI\n");
		scanf("%d", &DNI);
		
		fputs(nombre, fp);
		fputs(apellido, fp);
		fprintf(fp, "%d \n", DNI);
		
		fclose(fp);
		
			break;
		
		
		
		case 2:
			fp=fopen("archivo.txt", "a");
			
		fscanf(fp, "%s %s %d", nombre, apellido, &DNI);
		printf("%s %s %d\n", nombre, apellido, DNI);
		
		fclose(fp);
			break;
		
		
	}
	

	
	x++;
	
	
}while(op!=3);

printf("Saliendo del programa");

return 0;	
}
