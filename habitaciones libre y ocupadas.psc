Proceso Hotel
    
    habitacionesTotales <- 100; // n�mero de habitaciones totales del hotel
    habitacionesOcupadas <- 0; // n�mero de habitaciones ocupadas
    habitacionesDisponibles <- 0; // n�mero de habitaciones disponibles
	
    // Inicializar arreglo de habitaciones
    habitaciones <- Nuevo arreglo[habitacionesTotales] de booleano;
	
    // Inicializar arreglo con todos los valores en falso (habitaciones disponibles)
    Para i <- 1 hasta habitacionesTotales hacer
        habitaciones[i] <- Falso;
    FinPara
	
    // Funci�n para ocupar una habitaci�n
    Proceso OcuparHabitacion(numHabitacion)
        Si numHabitacion > 0 y numHabitacion <= habitacionesTotales entonces
            Si habitaciones[numHabitacion] = Falso entonces
                habitaciones[numHabitacion] <- Verdadero;
                habitacionesOcupadas <- habitacionesOcupadas + 1;
                habitacionesDisponibles <- habitacionesDisponibles - 1;
            FinSi
        FinSi
FinProceso

// Funci�n para liberar una habitaci�n
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