#1.- Diseñe una solución que convierte cualquier número romano a decimal. Ejemplo:
#Entrada: XXXIV
#Salida: 34

dict_roman = {
    
    "I" : 1,
    "V" : 5,
    "X" : 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000
}


def roman_converter( r_number : str ) -> int:
    
    r_number = r_number.upper() # Convert To UPPER
    roman_value = 0
    counter = 0
    
    for num in r_number:
                
        # JUST FOR previos_roman
        last_position = counter - 1
        last_position = 0 if (last_position < 0) else last_position
        
        previous_roman = dict_roman[ r_number[ last_position ] ]
        current_roman = dict_roman[ r_number[counter] ]
        
        if( previous_roman < current_roman  ):
            
            roman_value += current_roman - previous_roman
            roman_value -= previous_roman
            
        else:    
            roman_value += dict_roman[num]
        
        counter += 1
    
    return roman_value


print( roman_converter("CDXCI") )


# SOLUTION OF CARLOS ORGANDO

# Diseñe una solución que convierte cualquier número romano a decimal.

roman_to_int = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000
}

def roman_to_dec(roman: str) -> int:
  answer = 0
  for i in range(len(roman) - 1):
    curr = roman_to_int[roman[i]]
    next = roman_to_int[roman[i + 1]]
    if next > curr: answer -= curr
    else: answer += curr
  return answer + roman_to_int[roman[-1]]

print(roman_to_dec("CDXCI"))


#STACK and QUeeQ
#https://stackabuse.com/stacks-and-queues-in-python/