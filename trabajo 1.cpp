#include <stdio.h>

int main(){
	char respuesta;
	
	printf("Bienvenido a ABM (Agua de los Barrios de Madrid).\n");
	printf("Somos una aplicacion dedicada a proporcionar informacion facil y directa a cerca de la calidad del agua de los barrios de Madrid.\n");
	printf("Dividimos los datos segun las fuentes de cada barrio, facilitando al usuario su ph, conductividad, turbidez y coliformes\n");
	
	printf("Si desea continuar y obtener la informacion anteriormente mencionada seleccione una letra S (Sí) o N (No)\n");
	scanf("%c", &respuesta);
	
	if(respuesta=='S' || respuesta=='s'){
		
	}else{
		printf("Muchas gracias por habernos elegido\n");
		printf("Esperamos servirle de ayuda en otro momento\n");
	}
	
	return 0;
}
