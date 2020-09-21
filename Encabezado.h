#ifndef Encabezado
#define Encabezado
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int  horainicio,horacierre,sensorad,sensoraf,cierre,boton,opcion,tiempo;
FILE *ptr;

void emergencia(int boton);

void horarioapertura(void);

void horariocierre(void);

void puerta_automatica (int sensorad, int sensoraf,int cierre);

void cargahorarios(void);

int caso(void);


#endif
