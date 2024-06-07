Proceso Facturacion_Apartamentos
	// Definir variables principales
	Definir numeroFactura,nombreCliente,fechaEstancia,numeroCuarto,montoAPagar,montoPagado,opcion Como Caracter;
	Definir i,cantidadFacturas Como Entero;
	Definir pagado Como Logico;
	cantidadFacturas <- 0;
	// Proceso de registro de facturas
	Escribir 'RegistrarFactura';
	Escribir 'ActualizarEstadoPago';
	Escribir 'MostrarFactura';
	cantidadFacturas <- cantidadFacturas+1;
	Escribir '¿Desea registrar otra factura? (S/N): ';
	Leer opcion;
	// Mostrar todas las facturas registradas
	Escribir 'MostrarFacturasRegistradas';
	Escribir 'RegistrarFactura';
	// Leer datos de la factura: número de factura, nombre del cliente, fecha de estancia, número de cuarto, monto a pagar, monto pagado
	Escribir 'ActualizarEstadoPago'; // Actualizar el estado de pago basado en el monto pagado y el monto a pagar
	Escribir 'MostrarFactura';
	// Mostrar detalles de la factura registrada
	Escribir 'MostrarFacturasRegistradas';
	// Mostrar todas las facturas registradas
	// Mostrar detalles de cada factura
FinProceso
