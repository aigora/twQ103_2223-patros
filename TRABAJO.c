#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void banner();
void registrar();
void iniciosesion();
void temporizador();
void cookies();
int menu2();
int operaciones();

struct Registro {
	char nombre[50];
	char apellido[50];
	int edad[50];
	int codpostal[50];
    char nombreusuario[50];
    char contrasena[50];
};

struct Sesion {
    char nombreusuario[20];
    char contrasena[20];
};

// funcion principal
int main(){
	
	cookies();
	printf("\n\n\n");
	banner();
	
	char respuesta1;
	int respuesta2;

	printf("Bienvenido a ABM (Agua de los Barrios de Madrid).\n");
	printf("Somos una aplicacion dedicada a proporcionar informacion facil y directa acerca de la calidad del agua de los barrios de Arganzuela, Madrid.");
	printf("Dividimos los datos segun las fuentes de cada barrio, facilitando al usuario su ph, conductividad, turbidez y coliformes\n\n");
	
	printf("\n");
	
	printf("Si desea continuar y obtener la informacion anteriormente mencionada, seleccione S (S/N)\n");
	scanf("%s", &respuesta1);
	
	//menu principal
		if(respuesta1=='S' || respuesta1=='s'){
		    printf("Inicia tu resgitro: \n");
				registrar();
				iniciosesion();
				menu2(); 
		}
		else{
				printf("Muchas gracias por habernos elegido\n");
				printf("Esperamos servirle de ayuda en otro momento\n");
			}
			
		return 0;
}	



	
void banner() {
	printf ("            *********         *****************       ******             ****** \n");
	printf ("         ******   ******      ******************      *******           ******* \n");
	printf ("         ******   ******      ******       *****      ********         ******** \n");
	printf ("         ******   ******      ******      ******      *********       ********* \n");
	printf ("         ******   ******      ******     ******       ***** ****     **** ***** \n");
	printf ("         ******   ******      ***************         *****  **********   ***** \n");
	printf ("         ***************      ***************         *****    *******    ***** \n");
	printf ("         ***************      ******     ******       *****     *****     ***** \n"); 
	printf ("         ******   ******      ******      ******      *****               ***** \n");
	printf ("         ******   ******      ******       *****      *****               ***** \n");
	printf ("         ******   ******      ******************      *****               ***** \n");
	printf ("         ******   ******      *****************       *****               ***** \n");
	printf("\n");
}



void cookies() {
	char respuesta;
	
	printf("Este sitio web utiliza cookies para mejorar su experiencia. Acepta el uso de cookies? (S/N)\n");
	scanf(" %c", &respuesta);
	
	if(respuesta=='S' || respuesta=='s') {
		printf("Gracias por aceptar el uso de cookies.\n");
	} else {
		printf("Lamentablemente, no podemos continuar sin su consentimiento para el uso de cookies.\n");
		exit(0);
	}
}


void registrar() {
    struct Registro reg;
    
    printf("Ingrese tu nombre: ");
    scanf("%s", &reg.nombre);
    
    printf("Ingrese tu apellido: ");
    scanf("%s", &reg.apellido);
    
    printf("Ingrese tu edad: ");
    scanf("%s", &reg.edad);
    
    printf("Ingrese tu codigo postal: ");
    scanf("%s", &reg.codpostal);
    
    printf("Ingrese el nombre de usuario: ");
    scanf("%s", &reg.nombreusuario);
    
    printf("Ingrese la contrasena: ");
    scanf("%s", &reg.contrasena);
    
    FILE* archivo = fopen("datos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    
    fprintf(archivo, "%s %s", reg.nombreusuario, reg.contrasena);
    fclose(archivo);
    
    printf("Registro exitoso.\n\n");
}

void iniciosesion() {
    struct Sesion ses;
    int numIntentos = 3, aux = 0, crono = 0;
    
    do {
    	do {
   			printf("Ingrese el nombre de usuario: ");
    		scanf("%s", &ses.nombreusuario);
    
    		printf("Ingrese la contrasena: ");
    		scanf("%s", &ses.contrasena);
    
    		FILE* archivo = fopen("datos.txt", "r");
    		if (archivo == NULL) {
    	    	printf("Error al abrir el archivo.\n");
    	    	return;
    		}
    
    		struct Registro reg;
    		fscanf(archivo, "%s %s", reg.nombreusuario, reg.contrasena);
    		fclose(archivo);
    

    		if (strcmp(ses.nombreusuario, reg.nombreusuario) == 0 && strcmp(ses.contrasena, reg.contrasena) == 0) {
        		printf("Usuario y contrasena correctos.\n\n");
       		 aux = 1;
       		 crono = 1;
    		}
			else {
        		printf("Nombre de usuario o contrasena incorrectos. Intentalo de nuevo\n\n");
        		numIntentos--;
        		aux = 0;
    		}
    		if(numIntentos == 0) {
    			printf("Has fallado 3 veces. Intentalo de nuevo en 15 segundos\n\n");
    			temporizador(numIntentos);	
    			numIntentos = 3;
			}
		} while(numIntentos > 0 && aux == 0);

	} while(crono = 0);
}


void temporizador(int numIntentos) {
	int seg, x = 1000;
	
	for(seg = 15; seg <= 15 && seg >= 0; seg--) {
		printf("%02d\r", seg);
		Sleep(x);
	}
}


typedef struct {
    char *data;
    int filas;
    int columnas;
}datos;

datos *dat;
void graficos(datos *dat);



// funcion donde eliges el barrio
int menu2() {
    FILE *fp;
    char filename[50];
    char c;
    int filas = 0, columnas = 0, k = 0;
    
    printf("A continuacion le vamos a mostrar la lista de los barrios sobre los que tenemos informacion del distrito de Arganzuela:\n");
    printf("1. Atocha\n");
    printf("2. Delicias\n");
    printf("3. Embajadores\n");
    printf("4. Legazpi\n");
    printf("\n\n"); 
    printf("Disponemos de los datos analizados desde el comienzo de la aplicacion hasta ahora.\n Por favor, selecciona uno de los siguientes tres anos: 2021, 2022 o 2023.\n Luego, indica el periodo en el que deseas consultar esta informacion. Utiliza el numero 01 para referirte a principios de ano (enero), 06 para mediados de ano (junio) y 12 para finales de ano (diciembre).\n\n ");
    printf("Introduce el nombre del archivo que deseas analizar (XXXXYY_barrio.txt ; XXXX = year, YY = month): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("No se ha podido abrir el archivo.\n");
        exit(1);
    }

    // Contar filas y columnas
    while ((c = fgetc(fp)) != EOF) {
        columnas++;
        if (c == '\n') {
            filas++;
        }
    }

    dat = (datos*)malloc(sizeof(datos));
    dat->filas = filas;
    dat->columnas = columnas;
    dat->data = malloc(filas * columnas * sizeof(char));

    rewind(fp);

    // Leer archivo y guardar datos
    while ((c = fgetc(fp)) != EOF) {
        *(dat->data + k) = c;
        k++;
    }
    
    fclose(fp);
    
    graficos(dat);

    free(dat->data);
    free(dat);
    
    operaciones();

    return 0;
}



void graficos(datos *dat) {
    int i, j;
    for (i = 0; i < dat->filas; i++) {
        for (j = 0; j < dat->columnas; j++) {
            printf("%c", *(dat->data + i * dat->columnas + j));
        }
        printf("\n");
    }
}



// funcion en la cual eliges que informacion quieres
int operaciones () {
	
	int opcion, num;
	
	printf("A continuacion, le mostraremos distinta informacion que podra obtener sobre el barrio seleccionado:\n");
	printf("1. Media\n");
	printf("2. Minimo\n");
	printf("3. Maximo\n");
	printf("4. Elegir otro barrio\n");
	printf("5. Salir del programa\n");
	scanf("%d", &opcion);
	
	switch (opcion) {
		case 1:
			do{
			    printf("�Sobre que dato le gustaria saber la media? \n");
		    	printf(" 1) Ph\n 2) Conductividad\n 3) Turbidez\n 4) Coliforme\n");
		    	scanf("%d", &num);
			} while (opcion != 2 || opcion != 3 || opcion != 4 || opcion != 5);
		case 2:
			do{
			    printf("�Sobre que dato le gustaria saber el minimo? \n");
		    	printf(" 1) Ph\n 2) Conductividad\n 3) Turbidez\n 4) Coliforme\n");
		    	scanf("%d", &num);
		    
			}while (opcion != 1 || opcion != 3 || opcion != 4 || opcion != 5);

		case 3:
			do{
			    printf("�Sobre que dato le gustaria saber el maximo? \n");
		    	printf(" 1) Ph\n 2) Conductividad\n 3) Turbidez\n 4) Coliforme\n");
		    	scanf("%d", &num);
		    
			}while (opcion != 1 || opcion != 2 || opcion != 4 || opcion != 5);

		case 4:
			printf("Perfecto.\t");
			menu2();
		break;
		case 5:
			banner();
			printf("\n\n\n");
			printf("Muchas gracias por haber elegido ABM. Esperamos volverle a ver. \n");
		break;
			
	}
	
}



// calculo de la media segun el barrio que elijas
/*int media() {
	
	return media;
}


// calculo del minimo segun el barrio que elijas
int minimo() {
	
	return minimo;
}


// calculo del maximo segun el barrio que elijas
int maximo() {
	
	return maximo;
}*/



