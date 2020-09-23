#ifndef Encabezado
#define Encabezado
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef enum {
   apertura = 1,
   cerrado = 2 ,
   panico = 3 ,
   carga = 4
} posiblesestados_t;

int emergencia(int boton);

int horarioapertura(void);

int horariocierre(void);

void puerta_automatica (int sensorad, int sensoraf,int cierre);

int cargahorarios(void);

int caso(int);


#endif
