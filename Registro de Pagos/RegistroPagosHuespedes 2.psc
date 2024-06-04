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
				// Ingresar los datos del cliente, apartamento y el total pagado
			2:
				// Mostrar los datos ingresados por el huesped
			3:
				// Opcion a seleccionar para salir de programa y validar si alguna de las opciones ingresadas es correcta o no
		FinSegun
	Hasta Que opcion=3
FinAlgoritmo
