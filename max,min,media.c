#include <stdio.h>
struct dato {
	float ph;
	int conductividad;
    int turbidez;
    int coliformes;
};

int maxph(struct Tdato datos[], int dim) {
	
	struct Tdato datoMayorExtension;
	int i, posMax;
	
	//Calrcular el barrio con mayor ph:
	datoMayorExtension = datos[0];
	posMax = 0;
	for (i=1; i<5; i++) {
		if (datos[i].ph > datoMayorExtension.ph) {
			datoMayorExtension = datos[i];
			posMax = i;
		}
	}
	return posMax;
}
