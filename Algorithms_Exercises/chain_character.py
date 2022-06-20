"""2.- Diseñe una solución que determine si una cadena de paréntesis, llaves y corchetes
es válida. Ejemplo:"""
#Entrada: (){[]()}
#Salida: Válido

#Fuente de: https://www.youtube.com/watch?v=RZatXgHAPKY
 
def cadena_validator(chain_input: str ) -> bool:
    
    parentheses_simbols = { "(" : ")",  "{" : "}",  "[" : "]"  }
    stack = []

    for chart in chain_input:
        
        if( chart in parentheses_simbols.keys() ):
            stack.append(chart)
        elif ( len(stack) == 0 or chart != parentheses_simbols.get( stack.pop() ) ) : #Este ultimo cierre, es el tuyo? si, pues ok sigue que no hay problemas.
            return False

    return len(stack) == 0 # Puede no quede alguno abierto lo que quiere decir que es valida o puede que quede alguno al que nunca encontro cerradura

print( cadena_validator("()[{}") )