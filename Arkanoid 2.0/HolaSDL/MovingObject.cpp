#include "MovingObject.h"

// Metodo comun a los moving objects que actualiza su posicion segun su direccion y velocidad
 void MovingObject:: move()
 { 
	 pos = pos + (dir * speed); 
 }