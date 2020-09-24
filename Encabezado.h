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

int emergencia(void);

int horarioapertura(void);

int horariocierre(void);

void abierto (int sensorad, int sensoraf);

void cierre (int sensorad, int sensoraf);

int cargahorarios(void);

int caso(void);

#endif
