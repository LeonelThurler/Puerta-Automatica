Mi proyecto consistira en una puerta automatica con un sensor arriba de cada lado de la puerta que me indica cuando hay una persona en alguno de los dos lados para abrir la puerta, tendra como archivo de configuración horarios de cierre para anular la apertura desde uno de los lados, el de afuera. Tambien tendra la opcion de configurarle el tiempo en el que permance abierta y un estado de emergencia que las abra. A continuacion adjunto el diagrama del mismo
![./recursos/diagrama.png](https://github.com/LeonelThurler/Puerta-Automatica/blob/master/Diagrama.png)

Archivo de configuracion
```c
#ifndef archivo
#define archivo
#include <stdio.h>
#include <stdlib.h>
int sensorad=0,sensoraf=0;
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
```

Funcion principal

```c
#include "archivo.h"
int puerta=1,hsf,hsa,hsa2,hsf2,emergencia,horaactual;
FILE *ptr,*ptr2;
main(){
	while(puerta!=0){
	printf("\nCaso 1: configuracion de horarios de apertura de la puerta\n");
	printf("Caso 2: configuracion de horarios de cierre de la puerta\n");
	printf("Caso 3: abrir la puerta en caso de emergencia\n"); 
	printf("Caso 4: simulacion de un dia normal\n");
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
		
		case 3:
		emergencia=9;
		while(emergencia!=1){
		sensorad=1;
		sensoraf=1;
		puerta_automatica(sensorad,sensoraf);
		printf("\nPaso el estado de emergencia? si=1, no=0\n");
		scanf("%d",&emergencia);
		fflush(stdin);
		}
		sensorad=0;
		sensoraf=0;
		puerta_automatica(sensorad,sensoraf);
		break;
		
		case 4:
			printf("Ingrese la hora actual\n");
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
				sensorad=1;
				sensoraf=0;
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
		break;
    		}
	}
}
```

