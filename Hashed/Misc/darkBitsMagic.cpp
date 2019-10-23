540 typedef unsigned int uint;
750 uint nextMask(uint mask){
463 	uint t = mask | (mask - 1);
760 	return  (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(mask) + 1));
477 }
477 // Iterar sobre todos las mascaras de tamano N con m bits prendidos
660 for(uint mask = (1<<m)-1; !(mask & (1<<N)); mask = nextMask(mask)){}
660 
660 //Iterar sobre todas las submascaras de mask de forma creciente (no incluye vacio)
880 for(uint s = 0 ; s = s - mask & mask ;) {}
880 
880 //Iterar sobre todas las submascaras de mask de forma decreciente (no incluye vacio)
049 for(uint s = (mask-1) & mask ; s; s = (s-1) & mask )  {
794355049
