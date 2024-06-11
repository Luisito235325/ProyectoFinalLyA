Algoritmo ContarHabitacionesHotel

    // Definir las variables
    Definir totalHabitaciones, habitacionesLibres, habitacionesOcupadas Como Entero
    Definir estadoHabitacion Como Caracter
    Definir i Como Entero

    // Inicializar las variables
    totalHabitaciones <- 20
    habitacionesLibres <- 0
    habitacionesOcupadas <- 0

    // Recorremos cada habitación y solicitamos su estado
    Para i <- 1 Hasta totalHabitaciones Con Paso 1 Hacer
        Escribir "Ingrese el estado de la habitación ", i, " (L para libre, O para ocupada):"
        Leer estadoHabitacion
        
      
        estadoHabitacion <- Mayusculas(estadoHabitacion)
        
        // Contamos las habitaciones libres y ocupadas
        Si estadoHabitacion = "L" Entonces
            habitacionesLibres <- habitacionesLibres + 1
        Sino
            Si estadoHabitacion = "O" Entonces
                habitacionesOcupadas <- habitacionesOcupadas + 1
            FinSi
        FinSi
    Fin Para

    // Mostrar los resultados
    Escribir "Habitaciones libres: ", habitacionesLibres
    Escribir "Habitaciones ocupadas: ", habitacionesOcupadas

FinAlgoritmo
