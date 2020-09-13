#ifndef archivo
#define archivo
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void puerta_automatica (int sensorad, int sensoraf,int cierre);

void cargahorarios(void);

void cargahorarios(void){
	int  horainicio,horacierre,config;
	FILE *ptr;
	printf("Quiere configurar los horarios de apertura? si=1,no=0 ");
	scanf("%d",&config);
	if(config==1){
	ptr=fopen("config.txt","wt");
	 		if(ptr==NULL){
	 		printf("no se pudo crear el archivo");
	 		}
	 		printf("Coloque horario de inicio de la apertura ");
			scanf("%d",&horainicio);
			fwrite(&horainicio,sizeof(horainicio),1,ptr);
			printf("Coloque horario de cierre de la apertura ");
			scanf("%d",&horacierre);
			fwrite(&horacierre,sizeof(horacierre),1,ptr);
	 		fclose(ptr);
	}
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
	if(sensorad==0){
		printf("la puerta esta cerrada");
	}
	else{
		printf("la puerta se abrira");	
	}
}
	return;
}



#endif
