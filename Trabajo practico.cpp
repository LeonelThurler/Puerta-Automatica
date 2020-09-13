#include "archivo.h"
main(){
int  puerta,horainicio,horacierre,h,emergencia,sensorad,sensoraf,cierre;
FILE *ptr;
cargahorarios();
time_t ahora;
struct tm *hora;
time(&ahora);
hora = localtime(&ahora);

printf("En caso de emergencia pulse 0 sino presione otro numero");
scanf("%d",&emergencia);	
while(emergencia==0){
		sensorad=1;
		sensoraf=1;
		cierre=1;
		puerta_automatica(sensorad,sensoraf,cierre);
		printf("\nPaso el estado de emergencia? si=1, no=0\n");
		scanf("%d",&emergencia);
		fflush(stdin);
}
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
while((hora->tm_hour)<horainicio || (hora->tm_hour)>=horacierre ){
	cierre=1;
	sensoraf=0;
	printf("Hay personas adentro queriendo salir?\n");
	scanf("%d",&sensorad);
	puerta_automatica(sensorad,sensoraf,cierre);
 }
}
