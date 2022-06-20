#5.- Diseñe una solución que a partir de una lista de palabras retorne otra lista
#conteniendo únicamente las que son palíndromos.
    #Entrada:[“agua”, “rotor”, “perla”, “reconocer”, “ojo”, “peso”]
    #Salida: [“rotor”, “reconocer”, “ojo”]

def inverts_word(words: list = []) -> list:
    
    valid_values = []
    
    for word in words:
        
        if(word == word[::-1]):
            valid_values.append(word)

    return valid_values

returned = inverts_word(["agua", "rotor", "perla", "reconocer", "ojo", "peso"])

print( returned )