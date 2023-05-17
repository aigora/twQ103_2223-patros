#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void banner();
int registrar();
int iniciosesion();
void contrasenaOK();
void temporizador();
void cookies();
int menu2();
int operaciones ();

typedef struct {
	char nombre[50];
	char apellido[50];
	int edad;
	char codpostal[50];
	char nombreusuario[50];
	char contrasena[50];
}registro;

typedef struct {
	char nombreusuario[50];
	char contrasena[50];
}sesion;

// funcion principal
int main(){
	
	banner();
	printf("\n\n\n");
	cookies();
	
	char respuesta1;
	int respuesta2;

	printf("Bienvenido a ABM (Agua de los Barrios de Madrid).\t");
	printf("Somos una aplicacion dedicada a proporcionar informacion facil y directa acerca de la calidad del agua de los barrios de Madrid.");
	printf("Dividimos los datos segun las fuentes de cada barrio, facilitando al usuario su ph, conductividad, turbidez y coliformes\n\n");
	
	printf("\n");
	
	printf("Si desea continuar y obtener la informacion anteriormente mencionada, seleccione S (SI) o N (NO)\n");
	scanf("%s", &respuesta1);
	
	//menu principal
		if(respuesta1=='S' || respuesta1=='s'){
		    printf("Elige entre una de las siguientes opciones: \n");
		    printf("(1) Registrar\n");
		    printf("(2) Iniciar sesion\n");
		    scanf("%d", &respuesta2);
		
		switch(respuesta2) {
			case 1:
				registrar();
				menu2();
				break;
			case 2:
				iniciosesion();
				menu2();
				break;
		}
	
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
	
	printf("Este sitio web utiliza cookies para mejorar su experiencia. ?Acepta el uso de cookies? (S/N)\n");
	scanf(" %c", &respuesta);
	
	if(respuesta=='S' || respuesta=='s') {
		printf("Gracias por aceptar el uso de cookies. Continuemos con el programa.\n");
	} else {
		printf("Lamentablemente, no podemos continuar sin su consentimiento para el uso de cookies.\n");
		exit(0);
	}
}


int registrar() {
	
	FILE *pf;
	registro reg;
	sesion ses;
	
	
	// se abre el archivo en modo escritura para guardar los datos al final del archivo
	pf=fopen("datos.txt","a");
	
	if(pf==NULL) {
		perror("No se ha podido abrir el archivo");
		return 0;
	}
	
	// lee los datos del usuario
	printf("Introduce tu nombre: ");
	fgets(reg.nombre,50,stdin);
	reg.nombre[strcspn(reg.nombre, "\n")] ='\0';
	printf("Introduce tu apellido: ");
	fgets(reg.apellido, 50, stdin);
    reg.apellido[strcspn(reg.apellido, "\n")] = '\0';
	printf("Introduce tu edad: ");
	scanf("%d", &reg.edad);
    getchar();
	printf("Introduce tu codigo postal: ");
	fgets(reg.codpostal, 50, stdin);
    reg.codpostal[strcspn(reg.codpostal, "\n")] = '\0';
	printf("Introduce tu nombre de usuario: ");
    reg.nombreusuario[strcspn(reg.nombreusuario, "\n")] = '\0';
	fgets(reg.nombreusuario, 50, stdin);
	printf("Introduce tu contrasena: ");
	fgets(reg.contrasena, 50, stdin);
    reg.contrasena[strcspn(reg.contrasena, "\n")] = '\0';
	
	fprintf(pf,"%s; %s; %d; %s; %s; %s \n", reg.nombre, reg.apellido, reg.edad, reg.codpostal, reg.nombreusuario, reg.contrasena );
	
	// se cierra el archivo con la informacion
	fclose(pf);
	
	printf("Muchas gracias por registrarte. Recuerda tu usuario y contrasena para la proxima vez. \n");
	
	//menu2();
	
}

int iniciosesion() {
	
	int numIntentos = 3, aux = 0, crono = 0;
	FILE *pf;
	registro reg;
	sesion ses;
	
	//se abre el fichero de los datos y los lee
	pf=fopen("datos.txt","r");
	
	if (pf==NULL) {
		perror("No se ha podido abrir el archivo");
		return 1;
	}
	
	// comprueba si los datos son correctos o no
	
	printf("\n 2.Inicia sesion: ");
	
	do {
		
	    do {
	    	printf("\nIntroduzca su nombre de usuario: ");
	    	fflush(stdin);
	    	fgets(ses.nombreusuario, 50, stdin);
	    	printf("Introduzca su contrasena: ");
	    	fflush(stdin);
	    	fgets(ses.contrasena, 50, stdin);
		
		while (fscanf(pf, "%[^;]; %[^;]; %d; %[^;]; %[^;]; %s", reg.nombre, reg.apellido, &reg.edad, reg.codpostal, reg.nombreusuario, reg.contrasena) == 6) {
                if (strcmp(reg.nombreusuario, ses.nombreusuario) == 0 && strcmp(reg.contrasena, ses.contrasena) == 0) {
                    printf("\nBienvenido a AMB, %s %s!", reg.nombre, reg.apellido);
                    fclose(pf);
                    aux = 0;
                    return;
                }
            }

            printf("Datos incorrectos. Por favor, intentelo de nuevo.\n");
            numIntentos--;
            aux = 1;
            fseek(pf, 0, SEEK_SET); // Volver al inicio del archivo para leer nuevamente
        } while (numIntentos > 0 && aux == 1);
	
	    if(numIntentos == 0) {
	    	printf("Has fallado 3 veces, intentelo de nuevo en 15 segundos\n");
	    	temporizador(numIntentos);
	    	numIntentos = 3;
    	}
		else {
		    crono = 1;
    	}
	} while(crono == 0);
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
    
    printf("A continuación le vamos a mostrar la lista de los barrios sobre los que tenemos información:\n");
    printf("1. Embajadores\n");
    printf("2. Lavapiés\n");
    printf("3. Moncloa\n");
    printf("4. Pozuelo\n");
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
	
	printf("A continuacion, le mostraremos distinta información que podra obtener sobre el barrio seleccionado:\n");
	printf("1. Media\n");
	printf("2. Minimo\n");
	printf("3. Maximo\n");
	printf("4. Elegir otro barrio\n");
	printf("5. Salir del programa\n");
	scanf("%d", &opcion);
	
	switch (opcion) {
		case 1:
			do{
			    printf("¿Sobre que dato le gustaria saber la media? \n");
		    	printf(" 1) Ph\n 2) Conductividad\n 3) Turbidez\n 4) Coliforme\n");
		    	scanf("%d", &num);
			} while (opcion != 2 || opcion != 3 || opcion != 4 || opcion != 5);
		case 2:
			do{
			    printf("¿Sobre que dato le gustaria saber el minimo? \n");
		    	printf(" 1) Ph\n 2) Conductividad\n 3) Turbidez\n 4) Coliforme\n");
		    	scanf("%d", &num);
		    
			}while (opcion != 1 || opcion != 3 || opcion != 4 || opcion != 5);

		case 3:
			do{
			    printf("¿Sobre que dato le gustaria saber el maximo? \n");
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

// calculo de la media 
int media() {
	
	return media;
}

// calculo del minimo
int minimo() {
	
	return minimo;
}

// calculo del maximo
int maximo() {
	
	return maximo;
}

