#include <stdio.h>
#include <stdlib.h>

typedef struct  {
    float ph;
    int conductividad;
    int turbidez;
    int coliformes;
}Tdatos;

void Embajadores();

int main() {
    Tdatos dato[4];
    int respuesta;

    do {
        printf("A continuación le vamos a mostrar la lista de los que poseemos información:\n");
        printf("1. Embajadores\n");
        printf("2. Lavapiés\n");
        printf("3. Moncloa\n");
        printf("4. Pozuelo\n");
        printf("5. Salir\n");
        scanf("%d", &respuesta);

        switch (respuesta) {
            case 1:
                Embajadores();
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                printf("Hasta pronto.\n");
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }
    } while (respuesta != 5);

    return 0;
}

void Embajadores() {
    int respuesta;
    do {
        printf("Elija el año:\n");
        printf("1. 2021\n");
        printf("2. 2022\n");
        printf("3. 2023\n");
        scanf("%d", &respuesta);

        switch (respuesta) {
            case 1:
                do {
                    printf("Elija un mes de los siguientes:\n");
                    printf("1. Enero\n");
                    printf("2. Junio\n");
                    printf("3. Diciembre\n");
                    scanf("%d", &respuesta);

                    switch (respuesta) {
                        case 1:
                            FILE *fentrada;
                            fentrada = fopen("Embajadores_2021_Enero.txt", "r");
                            if (fentrada == NULL) {
                                printf("Error leyendo el fichero\n");
                                return;
                            }

                            int i = 0;
                            while (fscanf(fentrada, "%f %f %f %f", &datos[i].ph , &datos[i].conductividad, &datos[i].turbidez, &datos[i].coliformes) != EOF) {
                                i++;
                            }

                            fclose(fentrada);
                            
                            for(i=0; i<4; i++){
                            	printf("%.2f\n", datos[i].ph)
							}

                            break;

                        case 2:
                            break;

                        case 3:
                            break;

                        default:
                            printf("Opción inválida. Intente nuevamente.\n");
                            break;
                    }
                } while (respuesta != 1 && respuesta != 2 && respuesta != 3);

                break;

            case 2:
                break;

            case 3:
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }
    } while (respuesta != 1 && respuesta != 2 && respuesta != 3);
}
