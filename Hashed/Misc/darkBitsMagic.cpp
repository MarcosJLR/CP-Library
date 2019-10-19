273 typedef unsigned int uint;
831 uint nextMask(uint mask){
792 	uint t = mask | (mask - 1);
775 	return  (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(mask) + 1));
399 }
399 // Iterar sobre todos las mascaras de tamano N con m bits prendidos
711 for(uint mask = (1<<m)-1; !(mask & (1<<N)); mask = nextMask(mask)){}
711 
711 //Iterar sobre todas las submascaras de mask de forma creciente (no incluye vacio)
810 for(uint s = 0 ; s = s - mask & mask ;) {}
810 
810 //Iterar sobre todas las submascaras de mask de forma decreciente (no incluye vacio)
751 for(uint s = (mask-1) & mask ; s; s = (s-1) & mask )  {
1016591513105544751
