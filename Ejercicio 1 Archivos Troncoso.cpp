/*1) Realizar un programa en el cual se ingresen los siguientes datos Nombre, Apellido y DNI
a) Crear un menú donde se ingresen los datos y los guarde en un archivo
b) Otro ítem donde se pueda realizar una búsqueda por DNI y devuelva los datos de Nombre y apellido
c) Salir del mismo

Troncoso Fernando G 5°1°
*/

#include <stdio.h>
#include <string.h>


int main(){
	int op;
	
	char Lector[200];
	FILE *dp;

do{
	
	
	printf("\n\n\n\t\t--Elegir una de las Opciones--\t\t");
	
	printf("\n\n\n1-Ingresar Datos Personales\t\t");
	printf("2-Busqueda de Datos\n\n\n");
	printf("3-Salir del Programa\n\n\n");
	
	
	scanf("%d", &op);
	
	if(op<1||op>3)
	{

		do{
			printf("Opcion no valida, por favor intentar nuevamente\n");
				scanf("%d", &op);
		}while(op<1||op>3);
	}
	
	getchar();
	
	switch(op)
	{
		case 1:
			char nombre[50];
			char apellido[50];
			int DNI;
			
			dp=fopen("DatosPersonales.txt", "a");
			
	    	printf("Ingrese el Nombre\n");
				fgets(nombre, sizeof(nombre), stdin);
				nombre[strcspn(nombre, "\n")]=0;
			printf("Ingrese el Apellido\n");
				fgets(apellido, sizeof(apellido), stdin);
				apellido[strcspn(apellido, "\n")]=0;
			printf("Ingrese el DNI\n");
				scanf("%d", &DNI);
		
			fprintf(dp,"%s %s %d\n", nombre, apellido, DNI);
				
			fclose(dp);
			
			break;
		
		case 2:
			int DNIcomp;
			
			
			printf("Ingresar DNI para buscar los respectivos datos:  ");
                scanf("%d", &DNIcomp);
                getchar();

                dp=fopen("DatosPersonales.txt", "r");
                int igual=0;
            
		while(fgets(Lector, sizeof(Lector), dp) != NULL){
		
			
                    if (sscanf(Lector, "%s %s %d\n", nombre, apellido, &DNI)) {
                        if (DNI == DNIcomp) {
                            printf("Su Nombre es: %s\n", nombre);
                            printf("Su Apellido es: %s\n", apellido);
                        	igual=1;
                        break;
                        }
                    }
                }
			
			
                fclose(dp);
                if (!igual) {
                        printf("No se encontraron datos para el DNI %d.\n", DNIcomp);
                }
                 
                
                break;
		
	}	
	
	
}while(op!=3);
	
	printf("\n--SALIENDO DEL PROGRAMA--\n");
	
	return 0;
}

