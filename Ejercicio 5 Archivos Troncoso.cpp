/*
5) Guardar Los cambios en un archivo con nombre pertinente sin modificar el original y pudiendo tener acceso a los mismos


Troncoso Fernando G 5°1°
*/

#include <stdio.h>
#include <string.h>


int main(){
	int op;
	
	char Lector[200];
	FILE *dp1;
    FILE *dp2;
do{
	
	
	printf("\n\n\n\t\t--Elegir una de las Opciones--\t\t");
	
	printf("\n\n\n1-Ingresar Datos Personales\t\t\t");
	printf("2-Busqueda de Datos por DNI\n\n\n");
	printf("3-Busqueda de Datos por nombre y apellido\t");
	printf("4-Salir del Programa\n\n\n");
	
	
	scanf("%d", &op);
	
	if(op<1||op>4)
	{

		do{
			printf("Opcion no valida, por favor intentar nuevamente\n");
				scanf("%d", &op);
		}while(op<1||op>4);
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

			dp1 = fopen("DatosPersonales5Copia.txt", "r");
			if (dp1 != NULL) {
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
				dp1 = fopen("DatosPersonales5Copia.txt", "a");
				dp2 = fopen("DatosPersonales5Original.txt", "a");
				fprintf(dp1, "%s %s %d\n", nombre1, apellido1, DNI1);
				fclose(dp1);
				fprintf(dp2, "%s %s %d\n", nombre1, apellido1, DNI1);
				fclose(dp2);
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

                dp1=fopen("DatosPersonales5Copia.txt", "r");
                int igual=0;
            
		while(fgets(Lector, sizeof(Lector), dp1) != NULL){
		
                    if (sscanf(Lector, "%s %s %d\n", nombre1, apellido1, &DNI1)) {
                        if (DNI1 == DNIcomp) {
                            printf("/n Su Nombre es: %s\n", nombre1);
                            printf(" Su Apellido es: %s\n", apellido1);
                            printf(" Su DNI es: %d\n", DNI1);
                        	igual=1;
                        break;
                        }
                    }
                }
			
			
                fclose(dp1);
                if (!igual) {
                        printf("No se encontraron datos para el DNI %d.\n", DNIcomp);
                }
                 
                
                break;
		}
		
		case 3:{
			
			char nombrecomp[50];
			char apellidocomp[50];
			char nombre[50];
			char apellido[50];
			int DNI;
			
			printf("Ingresar nombre y apellido para buscar el respectivo dato:  ");
               printf("\n nombre:");
			    fgets(nombrecomp, sizeof(nombrecomp), stdin);
				nombrecomp[strcspn(nombrecomp, "\n")]=0;
			   printf(" apellido:");
			    fgets(apellidocomp, sizeof(apellidocomp), stdin);
				apellidocomp[strcspn(apellidocomp, "\n")]=0;
                

                dp1=fopen("DatosPersonales5Copia.txt", "r");
                int igual=0;
            
		while(fgets(Lector, sizeof(Lector), dp1) != NULL){
		
			
                    if (sscanf(Lector, "%s %s %d\n", nombre, apellido, &DNI)) {
                        if (strcmp(nombre, nombrecomp) == 0 && strcmp(apellido, apellidocomp) == 0) {
                        	printf("\n Su Nombre es: %s\n", nombre);
                            printf(" Su Apellido es: %s\n", apellido);
                            printf(" Su DNI es: %d\n", DNI);
                        	igual=1;
                        break;
                        }
                    }
                }
			
			
                fclose(dp1);
                if (!igual) {
                        printf("No se encontro el DNI para la persona llamada %s %s.\n", nombrecomp, apellidocomp);
                }

                break;
		}
	}	
	
	
}while(op!=4);
	
	printf("\n--SALIENDO DEL PROGRAMA--\n");
	
	return 0;
}
