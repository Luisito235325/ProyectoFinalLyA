Proceso Calendario_Disponibilidad
	Definir habitacion,diaInicio,diaFin,dia Como Entero;
	Definir opcion Como Caracter;
	Definir hab1_1,hab1_2,hab1_31 Como Logico;
	Definir hab2_1,hab2_2,hab2_31 Como Logico;
	hab1_1 <- Verdadero; hab1_2 <- Verdadero;
	hab2_1 <- Verdadero; hab2_2 <- Verdadero;
	opcion <- 'S';
	Mientras opcion='S' O opcion='s' Hacer
		Escribir 'Ingrese el número de habitación (1-10): ';
		Leer habitacion;
		Escribir 'Ingrese el día de inicio de la reserva (1-31): ';
		Leer diaInicio;
		Escribir 'Ingrese el día de fin de la reserva (1-31): ';
		Leer diaFin;
		Si habitacion=1 Entonces
			Para dia<-diaInicio Hasta diaFin Hacer
				Si dia=1 Entonces
					hab1_1 <- Falso;
				FinSi
				Si dia=2 Entonces
					hab1_2 <- Falso;
				FinSi
				// Hasta dia 31
			FinPara
		SiNo
			Si habitacion=2 Entonces
				Para dia<-diaInicio Hasta diaFin Hacer
					Si dia=1 Entonces
						hab2_1 <- Falso;
					FinSi
					Si dia=2 Entonces
						hab2_2 <- Falso;
					FinSi
				FinPara
			FinSi
		FinSi
		Borrar Pantalla;
		Escribir 'Calendario de Disponibilidad Actualizado:';
		Escribir 'Habitación ',habitacion,': ';
		Si habitacion=1 Entonces
			Si hab1_1 Entonces
				Escribir 'D1: Disponible';
			SiNo
				Escribir 'D1: Ocupado';
			FinSi
			Si hab1_2 Entonces
				Escribir 'D2: Disponible';
			SiNo
				Escribir 'D2: Ocupado';
			FinSi
		SiNo
			Si habitacion=2 Entonces
				Si hab2_1 Entonces
					Escribir 'D1: Disponible';
				SiNo
					Escribir 'D1: Ocupado';
				FinSi
				Si hab2_2 Entonces
					Escribir 'D2: Disponible';
				SiNo
					Escribir 'D2: Ocupado';
				FinSi
			FinSi
		FinSi
		Escribir '¿Desea registrar otra reserva? (S/N): ';
		Leer opcion;
	FinMientras
FinProceso
