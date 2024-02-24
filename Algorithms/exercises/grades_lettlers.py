#4.- Diseñe una solución que a partir de una lista de calificaciones retorne una lista
#con su valor equivalente en letras

#Entrada: [92, 68, 77, 75, 82]
#Salida: [A, D, C, C, B]


def grades_equivalent( collection: list = [] ) -> list:
    output = []
    
    for grades in collection:
        if(grades < 70):
            output.append("D")
        elif(grades < 80):
            output.append("C")
        elif( grades < 90 ):
            output.append("B")
        elif( grades <= 100 ):
            output.append("A") 
    #end for
    
    return output
    
print( grades_equivalent([92, 68, 77, 75, 82]) )