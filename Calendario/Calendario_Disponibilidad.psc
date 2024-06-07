Proceso Calendario_Disponibilidad
	// Definir variables principales
	Definir habitacion,diaInicio,diaFin,dia Como Entero;
	Definir opcion Como Caracter;
	// Inicializar disponibilidad de habitaciones
	Definir hab1_1,hab1_2,hab1_31 Como Logico;
	Definir hab2_1,hab2_2,hab2_31 Como Logico;
	// Registro de reservas
	Mientras opcion='S' O opcion='s' Hacer
		Escribir 'Ingrese el número de habitación (1-10): ';
		Leer habitacion;
		Escribir 'Ingrese el día de inicio de la reserva (1-31): ';
		Leer diaInicio;
		Escribir 'Ingrese el día de fin de la reserva (1-31): ';
		Leer diaFin;
		Escribir '¿Desea registrar otra reserva? (S/N): ';
		Leer opcion;
	FinMientras
	// DefinirDisponibilidad
	// Inicializar la disponibilidad de todas las habitaciones para todos los días
	// RegistrarReserva
	// Leer datos de la reserva: número de habitación, día de inicio, día de fin
	// ActualizarDisponibilidad
	// Actualizar la disponibilidad de la habitación según la reserva
	// MostrarDisponibilidad
	// Mostrar la disponibilidad actualizada de las habitaciones
FinProceso
