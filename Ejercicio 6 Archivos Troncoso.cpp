/*
6) Realizar un programa que realice las siguientes acciones
a. Guarde el registro del nombre y el puntaje de un jugador (solicitando el ingreso de los datos del usuario)
b. Muestre el resultado de los 10 mejores jugadores ordenados por mayor puntaje.
c. Realice y muestre una búsqueda de un Nombre y devuelva sus resultados. NOTA: el registro debe permanecer aunque se apague la PC.

Troncoso Fernando G 5°1°
*/

#include <stdio.h>
#include <string.h>

struct jugadores{
	char nombre[50];
	char apellido[50];
	int puntaje;
};

int main(){
	int op;
	
	char Lector[200];
	FILE *dp;
    
    int n;
    
    printf("Ingrese la cantidad de jugadores que hay(el minimo es 10): ");
    scanf("%d", &n);
   /* do{
    	if(n<10){
    		printf("error, el minimo de jugadores es 10, por favor intentar nuevamente.\n");
    		 printf("Ingrese la cantidad de jugadores que hay(el minimo es 10): ");
   			 scanf("%d", &n);
		}	
			
	}while(n<10);*/

		struct jugadores jug[n];

			
	for(int i=0;i<n;i++){
		getchar(); 
			char nombre2[50];
			char apellido2[50];
			int puntaje2;
			int duplicado = 0;

			printf("Ingrese el Nombre del jugador nro %d:\n", i+1);
			fgets(jug[i].nombre , sizeof(jug[i].nombre), stdin);
			jug[i].nombre[strcspn(jug[i].nombre, "\n")] = 0;
			printf("Ingrese el Apellido del jugador nro %d:\n", i+1);
			fgets(jug[i].apellido, sizeof(jug[i].apellido), stdin);
			jug[i].apellido[strcspn(jug[i].apellido, "\n")] = 0;
			printf("Ingrese el puntaje del jugador nro %d:\n", i+1);
			scanf("%d", &jug[i].puntaje);
			

			dp = fopen("DatosPersonales6.txt", "r");
			if (dp != NULL) {
				while (fgets(Lector, sizeof(Lector), dp) != NULL) {
					if (sscanf(Lector, "%s %s %d\n", nombre2, apellido2, &puntaje2) == 3) {
						if (strcmp(jug[i].nombre, nombre2) == 0 && strcmp(jug[i].apellido, apellido2) == 0) {
							printf("Datos ya ingresados. Por favor, ingrese datos nuevos.\n");
							duplicado = 1;
							break;
						}
					}
				}
				fclose(dp);
			}

			if (!duplicado) {
				dp = fopen("DatosPersonales6.txt", "a");
				fprintf(dp, "%s %s %d\n", jug[i].nombre, jug[i].apellido, jug[i].puntaje);
				fclose(dp);
			}
	
	printf("\n");
	}
			
do{
	
	
	printf("\n\n\n\t\t--Elegir una de las Opciones--\t\t");
	
	printf("\n\n\n1-Mostrar los 10 mejores puntajes\t\t\t");
	printf("2-Busqueda de Puntaje\n\n");
	printf("3-Salir del Programa\n\n\n");
	
	
	scanf("%d", &op);
	
	if(op<1||op>3)
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

		struct jugadores temp;

 		for(int i=0;i<n;i++){
			for(int j=0;j<n-1;j++){ 
				if(jug[j].puntaje>jug[j+1].puntaje){
					temp.puntaje=jug[j+1].puntaje;
					jug[j+1].puntaje=jug[j].puntaje;
					jug[j].puntaje = temp.puntaje;

					strcpy(temp.nombre, jug[j+1].nombre);
					strcpy(jug[j+1].nombre, jug[j].nombre);
					strcpy(jug[j].nombre, temp.nombre);

					strcpy(temp.apellido, jug[j+1].apellido);
					strcpy(jug[j+1].apellido, jug[j].apellido);
					strcpy(jug[j].apellido, temp.apellido);
				}
			}
		}
			
	for(int i=10;i>=1;i--){
	printf("%s %s %d\n",jug[i].nombre, jug[i].apellido, jug[i].puntaje);
		}
		
			break;
		}
		
		
		case 2:{
			
			
			char nombrecomp[50];
			char apellidocomp[50];
			char nombre[50];
			char apellido[50];
			int puntaje;
			
			printf("Ingresar nombre y apellido para buscar el respectivo dato:  ");
               printf("\n nombre:");
			    fgets(nombrecomp, sizeof(nombrecomp), stdin);
				nombrecomp[strcspn(nombrecomp, "\n")]=0;
			   printf(" apellido:");
			    fgets(apellidocomp, sizeof(apellidocomp), stdin);
				apellidocomp[strcspn(apellidocomp, "\n")]=0;
                

                dp=fopen("DatosPersonales6.txt", "r");
                int igual=0;
            
		while(fgets(Lector, sizeof(Lector), dp) != NULL){
		
			
                    if (sscanf(Lector, "%s %s %d\n", nombre, apellido, &puntaje)) {
                        if (strcmp(nombre, nombrecomp) == 0 && strcmp(apellido, apellidocomp) == 0) {
                            printf(" Su puntaje es: %d\n", puntaje);
                        	igual=1;
                        break;
                        }
                    }
                }
			
			
                fclose(dp);
                if (!igual) {
                        printf("No se encontro el puntaje para el jugador llamada %s %s.\n", nombrecomp, apellidocomp);
                }

                break;
		}
	}	
	
	
}while(op!=3);
	
	printf("\n--SALIENDO DEL PROGRAMA--\n");
	
	return 0;
}
