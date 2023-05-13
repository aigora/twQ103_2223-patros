#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *data;
    int filas;
    int columnas;
}datos;

datos *dat;
void graficos(datos *dat);

int main() {
    FILE *fp;
    char filename[50];
    char c;
    int filas = 0, columnas = 0, k = 0;
    
    printf("Introduce el nombre del archivo (XXXXYY_barrio.txt ; XXXX = year, YY = month): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error al abrir archivo.\n");
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

