#include <stdio.h>
#include <iostream> 
#include <stdlib.h>

using namespace std;

int main(){
	
	do{
		int respuesta;
		printf("1.Registrarse\n");
		printf("2\n");
		printf("3\n");
		printf("4.Salir\n");
		scanf("%d", &respuesta);
		
		switch(respuesta){
			case 1:
				break;
			
			case 2:
				break;
				
			case 3:
				break;
			
			case 4:
				printf("Hasta pronto\n");
				break;
				
		}
	}while(respuesta !=4);
	system ("pause");
}
