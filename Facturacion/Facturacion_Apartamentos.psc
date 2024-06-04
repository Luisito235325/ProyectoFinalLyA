Proceso Facturacion_Apartamentos
	Definir numeroFactura,nombreCliente,fechaEstancia,numeroCuarto,montoAPagar,montoPagado,opcion Como Caracter;
	Definir i,cantidadFacturas Como Entero;
	Definir pagado Como Logico;
	cantidadFacturas <- 0;
	Repetir
		Borrar Pantalla;
		Escribir 'Ingrese el número de factura: ';
		Leer numeroFactura;
		Escribir 'Ingrese el nombre del cliente: ';
		Leer nombreCliente;
		Escribir 'Ingrese la fecha de estancia (DD/MM/AAAA): ';
		Leer fechaEstancia;
		Escribir 'Ingrese el número de cuarto: ';
		Leer numeroCuarto;
		Escribir 'Ingrese el monto a pagar: ';
		Leer montoAPagar;
		Escribir 'Ingrese el monto pagado: ';
		Leer montoPagado;
		Si montoPagado>=montoAPagar Entonces
			pagado <- Verdadero;
		SiNo
			pagado <- Falso;
		FinSi
		Escribir 'Número de Factura: ',numeroFactura;
		Escribir 'Nombre del Cliente: ',nombreCliente;
		Escribir 'Fecha de Estancia: ',fechaEstancia;
		Escribir 'Número de Cuarto: ',numeroCuarto;
		Escribir 'Monto a Pagar: $',montoAPagar;
		Escribir 'Monto Pagado: $',montoPagado;
		Si pagado Entonces
			Escribir 'Estado: Pagado';
		SiNo
			Escribir 'Estado: Pendiente';
		FinSi
		Escribir '-----------------------------';
		cantidadFacturas <- cantidadFacturas+1;
		Escribir '¿Desea registrar otra factura? (S/N): ';
		Leer opcion;
	Hasta Que opcion=='N' O opcion=='n'
	Borrar Pantalla;
	Escribir 'Facturas Registradas:';
	Para i<-1 Hasta cantidadFacturas Hacer
		Escribir 'Número de Factura: ',numeroFactura;
		Escribir 'Nombre del Cliente: ',nombreCliente;
		Escribir 'Fecha de Estancia: ',fechaEstancia;
		Escribir 'Número de Cuarto: ',numeroCuarto;
		Escribir 'Monto a Pagar: $',montoAPagar;
		Escribir 'Monto Pagado: $',montoPagado;
		Si montoPagado>=montoAPagar Entonces
			Escribir 'Estado: Pagado';
		SiNo
			Escribir 'Estado: Pendiente';
		FinSi
		Escribir '-----------------------------';
	FinPara
FinProceso
