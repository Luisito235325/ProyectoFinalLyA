Algoritmo IngresarPago
	Escribir 'Ingrese el nombre del hu�sped: ';
	Leer nombreHuesped;
	Escribir 'Ingrese el n�mero de apartamento: ';
	Leer numApartamento;
	Escribir '�La factura est� pagada? (Si/No): ';
	Leer facturaPagada;
	Si facturaPagada='Si' Entonces
		Escribir 'Ingrese el total pagado: ';
		Leer totalPagado;
	SiNo
		totalPagado <- 0;
	FinSi
	Escribir 'Pago registrado para el hu�sped: ', nombreHuesped;
	Escribir 'N�mero de apartamento: ', numApartamento;
	Si facturaPagada='Si' Entonces
		Escribir 'Factura pagada.';
	SiNo
		Escribir 'Factura no pagada.';
	FinSi
	numHuespedes <- numHuespedes+1;
FinAlgoritmo
