711 double f(double x){	}
711 //simpsons rule
039 double integral(double a, double b){
918 	int n = 10000; //PAR
248 	double I = f(a) + f(b), h = (b-a)/n;
424 	FOR(i,0,n)
507 		I += ((i&1) ? 2:4) * f(a + h*i); 
121 	return I * h/3;
458 
-79252181393109542
