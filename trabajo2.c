#include <stdio.h>


// funcion principal
int main(){
	
	
	char respuesta1;
	int respuesta2;
	
	
	printf("Bienvenido a ABM (Agua de los Barrios de Madrid).\n\n");
	printf("Somos una aplicacion dedicada a proporcionar informacion facil y directa acerca de la calidad del agua de los barrios de Madrid.");
	printf("Dividimos los datos segun las fuentes de cada barrio, facilitando al usuario su ph, conductividad, turbidez y coliformes\n\n");
	
	printf("Si desea continuar y obtener la informacion anteriormente mencionada seleccione una letra S (Sí) o N (No)\n");
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
				menu2();
				
			case 2:
				iniciosesion();
				menu2();
				
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

void registrar() {
	
	FILE *pf;
	registro reg;
	
	
	// se abre el archivo en modo escritura para guardar los datos
	pf=fopen("datos.txt","w");
	
	if(pf==NULL) {
		perror("No se ha podido abrir el archivo");
		return 1;
	}
	
	// lee los datos del usuario
	printf("Introduce tu nombre: \n");
	scanf("%s", reg.nombre);
	printf("Introduce tu apellido: \n");
	scanf("%s", reg.apellido);
	printf("Introduce tu edad: \n ");
	scanf("%d", &reg.edad);
	printf("Introduce tu codigo postal: \n");
	scanf("%s", reg.codpostal);
	printf("Introduce tu nombre de usuario: \n");
	scanf("%s", reg.nombreusuario);
	printf("Introduce tu contrasena: \n");
	scanf("%s", reg.contrasena);
	
	fprintf(pf,"%s; %s; %d; %s; %s; %s \n", reg.nombre, reg.apellido, reg.edad, reg.codpostal, reg.nombreusuario, reg.contrasena );
	
	// se cierra el archivo con la informacion
	fclose(pf);
	
	printf("Muchas gracias por registrarte. Recuerda tu usuario y contrasena para la proxima vez. \n");
	
	menu2();
	
}

void iniciosesion() {
	
	FILE *pf;
	registro reg;
	
	//se abre el fichero de los datos y los lee
	pf=fopen("datos.txt","r");
	
	if (pf==NULL) {
		perror("No se ha podido abiri el archivo");
		return 1;
	}
	
	printf("Introduzca su nombre de usuario: \n");
	scanf("%s", reg.nombreusuario);
	printf("Introduzca su contraseña: \n");
	scanf("%s", reg.contrasena);
	
	// comprueba si los datos son correctos o no
	while (scanf(pf, "%*s %*s %*d %*s %s %s", reg.nombreusuario, reg.contrasena)==2) {
		if (strcmp(reg.nombreusuario, reg.nombreusuario)==0 && strcmp(reg.contrasena, reg.contrasena)==0) {
			printf("Bienvenido a AMB, %s!! \n", reg.nombreusuario);
			fclose(pf);
			return 0;
		}
	}
	
	// Si pasa aqui, es que los datos introducidos son incorrectos
	printf("Datos incorrectos. Por favor, intentelo de nuevo.\n");
	fclose(pf);
	return 1;
	
}


void menu2() {
	
	
}






