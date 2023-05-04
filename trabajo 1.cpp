#include <stdio.h>


typedef struct {
	char nombre[50];
	char apellidos[50];
	int edad[20];
	int codigopostal[50];
	int nombreusuario[50];
	int contrasena[50];
}registro;

typedef struct {
	int nombreusuario[50];
	int contrasena[50];
}iniciosesion;

void darregistro();
void darinsesion();

int main(){
	char respuesta1;
	int respuesta2;
	
	registro regist;
	darregistro(&regist);
	
	printf("Bienvenido a ABM (Agua de los Barrios de Madrid).\n");
	printf("Somos una aplicacion dedicada a proporcionar informacion facil y directa a cerca de la calidad del agua de los barrios de Madrid.\n");
	printf("Dividimos los datos segun las fuentes de cada barrio, facilitando al usuario su ph, conductividad, turbidez y coliformes\n");
	
	printf("Si desea continuar y obtener la informacion anteriormente mencionada seleccione una letra S (Sí) o N (No)\n");
	scanf("%c", &respuesta1);
	
	if(respuesta1=='S' || respuesta1=='s'){
		printf("Elige entre una de las siguientes opciones: \n");
		printf("(1) Registrar\n");
		printf("(2) Iniciar sesion\n");
		scanf("%d", &respuesta2);
		
		switch (respuesta2) {
			case 1:
				registrar();
			case 2:
				insesion();
				break;
			default:
				printf("Opción incorrecta. Intente de nuevo.\n");
				break;
		}
		
	}else{
		printf("Muchas gracias por habernos elegido\n");
		printf("Esperamos servirle de ayuda en otro momento\n");
	}
	
	return 0;
}



void darregistro() {
	printf("Introduce tu nombre: \n");
	scanf("%c", &registro.nombre);
	printf("Introduce tu apellido: \n");
	scanf("%c", &registro.apellidos);
	printf("Introduce tu edad: \n");
	scanf("%d", &registro.edad);
	printf("Introduce tu codigo postal: \n");
	scanf("%c", &registro.postal);
	printf("Introduce tu nombre de usuario: \n");
	scanf("%c", &registro.nombreusuario);
	printf("Introduce tu contrasena: \n");
	scanf("%c", &registro.contrasena);
}

void darinsesion() {
	




