#include "archivo.h"
main(){
int  puerta,hsf,hsa,hsa2,hsf2,emergencia,horaactual,sensorad,sensoraf,h=4;
FILE *ptr,*ptr2;
printf("Quiere configurar la hora de la puerta?si=1,no=0");
scanf("%d",&puerta);
	while(puerta!=0){
	printf("\nCaso 1: configuracion de horarios de apertura de la puerta\n");
	printf("Caso 2: configuracion de horarios de cierre de la puerta\n");
	scanf ("%d",&puerta);
	switch (puerta){
		case 1:
	 		ptr=fopen("config.txt","wt+");
	 		if(ptr==NULL){
	 		printf("no se pudo crear el archivo");
	 		}	
			printf("Coloque el horario de inicio ");
			scanf("%d",&hsa);
			fflush(stdin);
			fwrite(&hsa,sizeof(hsa),1,ptr);
			printf("\nColoque horario cierre ");
			scanf("%d",&hsf);
			fwrite(&hsf,sizeof(hsf),1,ptr);
	 		fclose(ptr);
		break;
		
		case 2:
	 		ptr2=fopen("config2.txt","wt+");
	 		if(ptr2==NULL){
	 		printf("no se pudo crear");
	 		}	
			printf("Coloque el horario de inicio del cierre ");
			scanf("%d",&hsa2);
			fflush(stdin);
			fwrite(&hsa2,sizeof(hsa2),1,ptr2);
			printf("\nColoque horario de finalizacion del cierre ");
			scanf("%d",&hsf2);
			fwrite(&hsf2,sizeof(hsf2),1,ptr2);
	 		fclose(ptr2);
		break;
		}
	}
	printf("En caso de emergencia pulse 1 sino presione otro numero");
	scanf("%d",&emergencia);	
	while(emergencia==1){
		sensorad=1;
		sensoraf=1;
		puerta_automatica(sensorad,sensoraf);
		printf("\nPaso el estado de emergencia? si=1, no=0\n");
		scanf("%d",&emergencia);
		fflush(stdin);
	}

	while(h=!0){
	printf("\nIngrese la hora actual\n");
			scanf("%d",&horaactual);
			fflush(stdin);
			ptr=fopen("config.txt","rt+");
			while(!feof(ptr)){
	 			fread(&hsa,sizeof(hsa),1,ptr);
	 			fread(&hsf,sizeof(hsf),1,ptr);
	 		}
	 		fclose(ptr);
	 		ptr2=fopen("config2.txt","rt+");
	 		while(!feof(ptr)){
	 			fread(&hsa2,sizeof(hsa2),1,ptr);
	 			fread(&hsf2,sizeof(hsf2),1,ptr);
	 		}
	  		fclose(ptr2);
			if(horaactual>hsa2 || horaactual<hsf2){
				sensorad=0;
				sensoraf=1;
				puerta_automatica(sensorad,sensoraf);
			}
			else{
				if(horaactual>=hsa && horaactual<=hsf){
				sensorad=1;
				sensoraf=1;
				puerta_automatica(sensorad,sensoraf);
				}else{
				printf("Depende de los sensores de la puerta");
				}
			}
		}
}
