#include "Encabezado.h"

main(){
	
posiblesestados_t estado = carga;

while(opcion==0){
switch(estado){	
	case apertura:
		estado=horarioapertura();
		o=1;
	break;
	
	case cerrado:
		estado=horariocierre();
		o=1;
	break;
	
    case panico:
		estado=emergencia(0);
		o=0;
	break;
	
	case carga:
		estado=cargahorarios();
		o=1;
	break;
	}
  }
}

