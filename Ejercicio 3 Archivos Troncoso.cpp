/*
3) Agregar validación de datos de manera que no se repitan cuando sea necesario.


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
		case 1:{
		
		
			char nombre1[50];
			char apellido1[50];
			int DNI1;
			char nombre2[50];
			char apellido2[50];
			int DNI2;
			int duplicado = 0;

			printf("Ingrese el Nombre\n");
			fgets(nombre1, sizeof(nombre1), stdin);
			nombre1[strcspn(nombre1, "\n")] = 0;
			printf("Ingrese el Apellido\n");
			fgets(apellido1, sizeof(apellido1), stdin);
			apellido1[strcspn(apellido1, "\n")] = 0;
			printf("Ingrese el DNI\n");
			scanf("%d", &DNI1);
			getchar(); 

			dp = fopen("DatosPersonales3.txt", "r");
			if (dp != NULL) {
				 while (fgets(Lector, sizeof(Lector), dp) != NULL) {
				     if (sscanf(Lector, "%s %s %d\n", nombre2, apellido2, &DNI2) == 3) {
					if (DNI1 == DNI2 || strcmp(nombre1, nombre2) == 0 || strcmp(apellido1, apellido2) == 0) {
					printf("Datos ya ingresados. Por favor, ingrese datos nuevos.\n");
					duplicado = 1;
					break;
				    }
				}
			    }
				fclose(dp);
			}

			if (!duplicado) {
				dp = fopen("DatosPersonales3.txt", "a");
				fprintf(dp, "%s %s %d\n", nombre1, apellido1, DNI1);
				fclose(dp);
			}

			break;
		}
		
		case 2:{
		
			char nombre1[50];
			char apellido1[50];
			int DNI1;
			int DNIcomp;
			
			
			printf("Ingresar DNI para buscar los respectivos datos:  ");
                scanf("%d", &DNIcomp);

                dp=fopen("DatosPersonales3.txt", "r");
                int igual=0;
            
		while(fgets(Lector, sizeof(Lector), dp) != NULL){
		
                    if (sscanf(Lector, "%s %s %d\n", nombre1, apellido1, &DNI1)) {
                        if (DNI1 == DNIcomp) {
                            printf("Su Nombre es: %s\n", nombre1);
                            printf("Su Apellido es: %s\n", apellido1);
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
	}	
	
	
}while(op!=3);
	
	printf("\n--SALIENDO DEL PROGRAMA--\n");
	
	return 0;
}
