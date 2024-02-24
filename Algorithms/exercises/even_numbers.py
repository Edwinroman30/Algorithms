#3.- Diseñe una solución que a partir de una lista de números retorne la cantidad de
#números primos que contiene la misma.
# Entrada: [2, 8, 10, 15, 13, 29, 50, 149]
# Salida: 4


def even_count(list_numbers: list = [] ) -> int:
    counter = 0
        
    for num in list_numbers:
        
        if(num % 2 == 0):
            counter = counter + 1
    
    return counter

print( even_count( [2, 8, 10, 15, 13, 29, 50, 149] ) )