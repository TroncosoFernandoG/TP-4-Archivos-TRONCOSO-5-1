/*
2) Modificar el programa anterior de manera que se puedan realizar búsquedas por Apellido y por nombre a la vez.

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
			
			dp=fopen("DatosPersonales2.txt", "a");
			
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
			char nombrecomp[50];
			char apellidocomp[50];
			
			
			printf("Ingresar nombre y apellido para buscar el respectivo dato:  ");
               printf("\n nombre:");
			    fgets(nombrecomp, sizeof(nombrecomp), stdin);
				nombrecomp[strcspn(nombrecomp, "\n")]=0;
			   printf(" apellido:");
			    fgets(apellidocomp, sizeof(apellidocomp), stdin);
				apellidocomp[strcspn(apellidocomp, "\n")]=0;
                

                dp=fopen("DatosPersonales2.txt", "r");
                int igual=0;
            
		while(fgets(Lector, sizeof(Lector), dp) != NULL){
		
			
                    if (sscanf(Lector, "%s %s %d\n", nombre, apellido, &DNI)) {
                        if (strcmp(nombre, nombrecomp) == 0 && strcmp(apellido, apellidocomp) == 0) {
                            printf("Su DNI es: %d\n", DNI);
                        	igual=1;
                        break;
                        }
                    }
                }
			
			
                fclose(dp);
                if (!igual) {
                        printf("No se encontro el DNI para la persona llamada %s %s.\n", nombrecomp, apellidocomp);
                }

                break;
		
	}	
	
	
}while(op!=3);
	
	printf("\n--SALIENDO DEL PROGRAMA--\n");
	
	return 0;
}
