Algoritmo GenerarRecibo
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
FinAlgoritmo
