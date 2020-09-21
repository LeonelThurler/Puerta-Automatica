#include "Encabezado.h"

main(){
	
while(opcion==0){
switch(caso()){	
	case 1:
		horarioapertura();
	break;
	
	case 2:
		horariocierre();
	break;
	
    case 3:
		emergencia(0);
	break;
	
	case 4:
		cargahorarios();
	break;
	}
  }
}

