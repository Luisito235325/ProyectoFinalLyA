Proceso Hotel
    
    habitacionesTotales <- 100; // número de habitaciones totales del hotel
    habitacionesOcupadas <- 0; // número de habitaciones ocupadas
    habitacionesDisponibles <- 0; // número de habitaciones disponibles
	
   
    habitaciones <- Nuevo arreglo[habitacionesTotales] de booleano;
	
 
    Para i <- 1 hasta habitacionesTotales hacer
        habitaciones[i] <- Falso;
    FinPara
	
    // Función para ocupar una habitación
    Proceso OcuparHabitacion(numHabitacion)
        Si numHabitacion > 0 y numHabitacion <= habitacionesTotales entonces
            Si habitaciones[numHabitacion] = Falso entonces
                habitaciones[numHabitacion] <- Verdadero;
                habitacionesOcupadas <- habitacionesOcupadas + 1;
                habitacionesDisponibles <- habitacionesDisponibles - 1;
            FinSi
        FinSi
FinProceso

// Función para liberar una habitación
Proceso LiberarHabitacion(numHabitacion)
	Si numHabitacion > 0 y numHabitacion <= habitacionesTotales entonces
		Si habitaciones[numHabitacion] = Verdadero entonces
			habitaciones[numHabitacion] <- Falso;
			habitacionesOcupadas <- habitacionesOcupadas - 1;
			habitacionesDisponibles <- habitacionesDisponibles + 1;
		FinSi
	FinSi
FinProceso

// Mostrar estado de las habitaciones
Proceso MostrarEstado
	Escribir "Habitaciones ocupadas: ", habitacionesOcupadas;
	Escribir "Habitaciones disponibles: ", habitacionesDisponibles;
FinProceso

// Ejemplo de uso
OcuparHabitacion(10);
OcuparHabitacion(20);
LiberarHabitacion(10);
MostrarEstado();
FinProceso
