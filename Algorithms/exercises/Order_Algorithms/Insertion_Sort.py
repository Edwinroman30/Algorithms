''' Dados los siguientes algoritmos de ordenamiento en forma de pseudocódigo, realice
el programa correspondiente de UNO de ellos.
1.- Insertion sort.
Entrada: una lista de números A.
Salida: la lista A queda ordenada. '''


# tomar la lista
# Por cada item ver si el actual es mayor que el anterior
    # Que cambien de posicion.

# Por cada item ver si el actual es menor que el siguiente.
    # Que cambien de posicion.

# SI son igual que cambien de igual forma.


def insertionsort(serie: list = []) -> list :
    inx = 0
    temp_value = 0
    counter = 1
    
    while( len(serie) == len(serie) ):
        
        # PUNTO INICIAL
        if(inx == 0): 
            
            if(serie[inx] > serie[inx + 1]):
                temp_value = serie[inx + 1]
                serie[inx + 1] = serie[inx]
                serie[inx] = temp_value
                valid_counter = valid_counter + 1
        else:                      
            next_value = inx + 1

            if(serie[inx] < serie[inx - 1]):
                temp_value = serie[inx - 1]
                serie[inx - 1] = serie[inx]
                serie[inx] = temp_value

            
            if(next_value != 9): #avoiding the outOfRange Problem.
                
                next_value = len(serie) - 1    
                
                if( serie[inx] > serie[next_value] ):
                    temp_value = serie[next_value]
                    serie[next_value] = serie[inx]
                    serie[inx] = temp_value
            
            
        #Index reset
        if( inx == len(serie)-1 ):
            inx = 0
        
        #iterating to reach the square number.    
        if( counter == len(serie)**2 ):
            break
           
        counter= counter + 1
        inx = inx + 1
        
    return serie, counter



print( insertionsort([2,4,2,234,-1,64,7565,23,-9])[0] )
print( insertionsort([2,4,2,234,-1,64,7565,23,-9])[-1] )
