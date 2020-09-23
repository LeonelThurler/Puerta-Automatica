#include "Encabezado.h"

int caso(int botonbloqueado){
	int horainicio,horacierre,l;
	FILE *ptr;
	time_t ahora;
	struct tm *hora;
	time(&ahora);
	hora = localtime(&ahora);
	if(botonbloqueado==1){
	}
	else{
	printf("En caso de emergencia pulse 1 sino presione otro numero");
	scanf("%d",&l);
	if(l==1){
		return 3;
		}
	}
	ptr=fopen("config.txt","rt");
	while(!feof(ptr)){
		fread(&horainicio,sizeof(horainicio),1,ptr);
 		fread(&horacierre,sizeof(horacierre),1,ptr);
	}
	fclose(ptr);
	if ((hora->tm_hour)>=horainicio && (hora->tm_hour)<horacierre){;
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
	
	int  horainicio,horacierre,cierre,sensoraf,sensorad;
	FILE *ptr;
	ptr=fopen("config.txt","rt");
	while(!feof(ptr)){
		fread(&horainicio,sizeof(horainicio),1,ptr);
 		fread(&horacierre,sizeof(horacierre),1,ptr);
	}
	fclose(ptr);
	
	while((hora->tm_hour)>=horainicio && (hora->tm_hour)<horacierre){
		cierre=0;
		printf("\nHay personas afuera queriendo entrar?");
		scanf("%d",&sensoraf);
		fflush(stdin);
		sensorad=0;
		puerta_automatica(sensorad,sensoraf,cierre);
		printf("\nHay personas dentro queriendo salir?");
		scanf("%d",&sensorad);
		sensoraf=0;
		puerta_automatica(sensorad,sensorad,cierre);
	}
	return caso(0);
}
		
int horariocierre(void){
	int  horainicio,horacierre,cierre,sensoraf,sensorad;
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
		cierre=1;
		sensoraf=0;
		printf("Hay personas adentro queriendo salir?\n");
		scanf("%d",&sensorad);
		puerta_automatica(sensorad,sensoraf,cierre);
	}
	return caso(0);
}

int emergencia(int boton){
	int sensorad,sensoraf,cierre;
	while(boton==0){
		sensorad=1;
		sensoraf=1;
		cierre=1;
		puerta_automatica(sensorad,sensoraf,cierre);
		printf("\nPaso el estado de emergencia? si=1, no=0\n");
		scanf("%d",&boton);
		fflush(stdin);
	}
 return caso(1);
}

int cargahorarios(void) {
	int  horainicio,horacierre,enable;
	printf("Quiere configurar los horarios?");
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
	 	return caso(0);
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
			printf("la puerta esta cerrada\n");
		}
		else{
			printf("la puerta se abrira\n");	
		}
	}
	return;
}
