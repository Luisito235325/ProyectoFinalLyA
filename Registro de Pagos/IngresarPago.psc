Algoritmo IngresarPago
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
FinAlgoritmo
