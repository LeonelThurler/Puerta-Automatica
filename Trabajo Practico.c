#include "Encabezado.h"

main(){
	
posiblesestados_t estado = carga;

int opcion=0;

while(opcion==0){
switch(estado){	
	case apertura:
		estado=horarioapertura();
	break;
	
	case cerrado:
		estado=horariocierre();
	break;
	
    case panico:
		estado=emergencia(0);
	break;
	
	case carga:
		estado=cargahorarios();
	break;
	}
  }
}


