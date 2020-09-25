#include "Encabezado.h"

int caso(void ){
	int horainicio,horacierre;
	FILE *ptr;
	time_t ahora;
	struct tm *hora;
	time(&ahora);
	hora = localtime(&ahora);
	ptr=fopen("config.txt","rt");
	while(!feof(ptr)){
		fread(&horainicio,sizeof(horainicio),1,ptr);
 		fread(&horacierre,sizeof(horacierre),1,ptr);
	}
	fclose(ptr);
	if ((hora->tm_hour)>=horainicio && (hora->tm_hour)<horacierre){
		return 1;
	}
	if ((hora->tm_hour)<horainicio || (hora->tm_hour)>=horacierre ){
		return 2;
	}
}

int horarioapertura(void){
	time_t ahora;
	struct tm *hora;
	time(&ahora);
	hora = localtime(&ahora);
	
	int  horainicio,horacierre,sensoraf,sensorad,boton;
	FILE *ptr;
	ptr=fopen("config.txt","rt");
	while(!feof(ptr)){
		fread(&horainicio,sizeof(horainicio),1,ptr);
 		fread(&horacierre,sizeof(horacierre),1,ptr);
	}
	fclose(ptr);
	
	while((hora->tm_hour)>=horainicio && (hora->tm_hour)<horacierre){
		printf("\nHay personas afuera queriendo entrar?");
		scanf("%d",&sensoraf);
		fflush(stdin);
		printf("\nHay personas dentro queriendo salir?");
		scanf("%d",&sensorad);
		abierto(sensorad,sensoraf);
		printf("\nEn caso de emergencia pulse 1 sino presione otro numero");
		scanf("%d",&boton);
		if(boton==1){
			return 3;
		}
	}
	return caso();
}
		
int horariocierre(void){
	int  horainicio,horacierre,sensoraf,sensorad;
	FILE *ptr;
	ptr=fopen("config.txt","rt");
	while(!feof(ptr)){
		fread(&horainicio,sizeof(horainicio),1,ptr);
 		fread(&horacierre,sizeof(horacierre),1,ptr);
	}
	fclose(ptr);
	
	time_t ahora;
	struct tm *hora;
	time(&ahora);
	hora = localtime(&ahora);
	while((hora->tm_hour)<horainicio || (hora->tm_hour)>=horacierre ){
		sensoraf=0;
		printf("\nHay personas adentro queriendo salir?\n");
		scanf("%d",&sensorad);
		cierre(sensorad,sensoraf);
	}
	return caso();
}

int emergencia(void){
		printf("\nLa puerta se abrira por un caso de emergencia\n");
 return caso();
}

int cargahorarios(void) {
	int  horainicio,horacierre,enable;
	printf("Quiere configurar los horarios de la puerta?");
	scanf("%d",&enable);
	if(enable==1){
	FILE *ptr;
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
	 	return caso();
}

void abierto (int sensorad, int sensoraf){
		if (sensorad==0 && sensoraf==0){
			printf("la puerta permanecera cerrada\n");
		}
		if (sensorad==1 || sensoraf==1 ){
			printf("la puerta se abrira\n");
		}
}

void cierre(int sensorad, int sensoraf){
		if(sensorad==0){
			printf("la puerta esta cerrada\n");
		}
		else{
			printf("la puerta se abrira\n");	
		}
	return;
}

