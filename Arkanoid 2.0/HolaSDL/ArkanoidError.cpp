#include "ArkanoidError.h"

/*
a la hora de catchear exceptions siempre poner primero lo mas especifico y luego lo mas general
podemos meterle mierda a los constructores como el nombre del file
ej:
if color es < 1 o color es > 6 throw fileformat error
*/