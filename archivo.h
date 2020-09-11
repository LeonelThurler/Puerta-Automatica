#ifndef archivo
#define archivo
#include <stdio.h>
#include <stdlib.h>
void puerta_automatica (int sensorad, int sensoraf);

void puerta_automatica (int sensorad, int sensoraf){
	if (sensorad==0 || sensoraf==0){
		printf("la puerta permanecera cerrada");
	}
	else{
	printf("la puerta se abrira");
	}
	return;
}



#endif
