#include <stdio.h>

void registrar();
void iniciosesion();
void contrasenaOK();

// funcion principal
int main(){
	
	
	char respuesta1;
	int respuesta2;
	
	
	printf("Bienvenido a ABM (Agua de los Barrios de Madrid).\n\n");
	printf("Somos una aplicacion dedicada a proporcionar informacion facil y directa acerca de la calidad del agua de los barrios de Madrid.");
	printf("Dividimos los datos segun las fuentes de cada barrio, facilitando al usuario su ph, conductividad, turbidez y coliformes\n\n");
	
	printf("Si desea continuar y obtener la informacion anteriormente mencionada seleccione una letra S (SI) o N (NO)\n");
	scanf("%c", &respuesta1);
	
	//menu principal
	if(respuesta1=='S' || respuesta1=='s'){
		printf("Elige entre una de las siguientes opciones: \n");
		printf("(1) Registrar\n");
		printf("(2) Iniciar sesion\n");
		scanf("%d", &respuesta2);
		
		switch(respuesta2) {
			case 1:
				registrar();
				//menu2();
				
			case 2:
				iniciosesion();
				//menu2();
				
		}
	
	}else{
		printf("Muchas gracias por habernos elegido\n");
		printf("Esperamos servirle de ayuda en otro momento\n");
	}
	
	return 0;
}


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

void registrar() {
	
	FILE *pf;
	registro reg;
	sesion ses;
	
	
	// se abre el archivo en modo escritura para guardar los datos
	pf=fopen("datos.txt","w");
	
	if(pf==NULL) {
		perror("No se ha podido abrir el archivo");
		return 1;
	}
	
	// lee los datos del usuario
	printf("Introduce tu nombre: ");
	fflush(stdin);
	fgets(reg.nombre, 50, stdin);
	printf("Introduce tu apellido: ");
	fflush(stdin);
	fgets(reg.apellido, 50, stdin);
	printf("Introduce tu edad: ");
	scanf("%d", &reg.edad);
	printf("Introduce tu codigo postal: ");
	fflush(stdin);
	fgets(reg.codpostal, 50, stdin);
	printf("Introduce tu nombre de usuario: ");
	fflush(stdin);
	fgets(reg.nombreusuario, 50, stdin);
	printf("Introduce tu contrasena: ");
	fflush(stdin);
	fgets(reg.contrasena, 50, stdin);
	
	fprintf(pf,"%s; %s; %d; %s; %s; %s \n", reg.nombre, reg.apellido, reg.edad, reg.codpostal, reg.nombreusuario, reg.contrasena );
	
	// se cierra el archivo con la informacion
	fclose(pf);
	
	printf("Muchas gracias por registrarte. Recuerda tu usuario y contrasena para la proxima vez. \n");
	
	//menu2();
	
}

void iniciosesion() {
	
	int numIntentos = 3, aux = 0;
	FILE *pf;
	registro reg;
	sesion ses;
	
	//se abre el fichero de los datos y los lee
	pf=fopen("datos.txt","r");
	
	if (pf==NULL) {
		perror("No se ha podido abrir el archivo");
		return 1;
	}
	
	/*do {
		printf("Introduzca su nombre de usuario: ");
		fflush(stdin);
		fgets(ses.nombreusuario, 50, stdin);
		printf("Introduzca su contrasena: ");
		fflush(stdin);
		fgets(ses.contrasena, 50, stdin);
		
	} while(strcmp(reg.nombreusuario, ses.nombreusuario)!=0 || strcmp(reg.contrasena, ses.contrasena)!=0); */
	
	// comprueba si los datos son correctos o no
	do {
		printf("Introduzca su nombre de usuario: ");
		fflush(stdin);
		fgets(ses.nombreusuario, 50, stdin);
		printf("Introduzca su contrasena: ");
		fflush(stdin);
		fgets(ses.contrasena, 50, stdin);
		
		if(strcmp(reg.nombreusuario, ses.nombreusuario)!=0 || strcmp(reg.contrasena, ses.contrasena)!=0) {
			printf("Datos incorrectos. Por favor, intentelo de nuevo.\n");
			numIntentos--;
			aux = 1;
			
		}
		else {
			printf("Bienvenido a AMB, %s!\n", reg.nombre);
			fclose(pf);
			aux = 0;
			return 1;
		}
		
	} while(numIntentos > 0 && aux == 1);
	
	if(numIntentos == 0) {
		printf("Has fallado 3 veces, intentalo mas tarde\n");
	}	
}


/*
void menu2() {
	
	
} */






