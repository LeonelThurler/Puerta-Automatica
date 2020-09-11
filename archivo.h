#ifndef archivo
#define archivo
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void puerta_automatica (int sensorad, int sensoraf,int cierre);

void cargahorarios(void);

void cargahorarios(void){
	int  horainicio,horacierre;
	FILE *ptr;
	ptr=fopen("config.txt","wt");
	
	 		if(ptr==NULL){
	 		printf("no se pudo crear el archivo");
	 		}
	 		
			horainicio=8;
			fwrite(&horainicio,sizeof(horainicio),1,ptr);
			horacierre=19;
			fwrite(&horacierre,sizeof(horacierre),1,ptr);
	 		fclose(ptr);
	 		
	 	return;
}


void puerta_automatica (int sensorad, int sensoraf,int cierre){
if(cierre==0){
		if (sensorad==0 && sensoraf==0){
			printf("la puerta permanecera cerrada\n");
		}
		if (sensorad==1 || sensoraf==1){
			printf("la puerta se abrira\n");
		}
}
else{
	if(sensoraf==0){
		printf("la puerta esta cerrada");
	}
	else{
		printf("la puerta se abrira");	
	}
}
	return;
}



#endif
