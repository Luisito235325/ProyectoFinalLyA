Algoritmo RegistroPagosHuespedes
	Definir opcion Como Entero;
	Definir numApartamento Como Entero;
	Definir nombreHuesped Como Cadena;
	Definir facturaPagada Como Cadena;
	Definir totalPagado Como Real;
	Definir numHuespedes Como Entero;
	numHuespedes <- 0;
	Repetir
		Escribir '1. Ingresar pago';
		Escribir '2. Generar recibo';
		Escribir '3. Salir';
		Escribir 'Seleccione una opción: ';
		Leer opcion;
		Segun opcion Hacer
			1:
				Escribir 'Ingrese el nombre del huésped: ';
				Leer nombreHuesped;
				Escribir 'Ingrese el número de apartamento: ';
				Leer numApartamento;
				Escribir '¿La factura está pagada? (Si/No): ';
				Leer facturaPagada;
				Si facturaPagada='Si' Entonces
					Escribir 'Ingrese el total pagado: ';
					Leer totalPagado;
				SiNo
					totalPagado <- 0;
				FinSi
				Escribir 'Pago registrado para el huésped: ', nombreHuesped;
				Escribir 'Número de apartamento: ', numApartamento;
				Si facturaPagada='Si' Entonces
					Escribir 'Factura pagada.';
				SiNo
					Escribir 'Factura no pagada.';
				FinSi
				numHuespedes <- numHuespedes+1;
			2:
				Escribir 'Recibos generados:';
				Si numHuespedes>0 Entonces
					Escribir 'Huésped: ', nombreHuesped;
					Escribir 'Apartamento: ', numApartamento;
					Si totalPagado>0 Entonces
						Escribir 'Total pagado: $', totalPagado;
					SiNo
						Escribir 'No se ha realizado el pago.';
					FinSi
				SiNo
					Escribir 'No hay pagos registrados.';
				FinSi
			3:
				Escribir '¡Hasta luego!';
			De Otro Modo:
				Escribir 'Opción inválida';
		FinSegun
	Hasta Que opcion=3
FinAlgoritmo
