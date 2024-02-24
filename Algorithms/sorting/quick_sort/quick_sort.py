
def swap(list_elems: str, currentIdx: int, targetIdx):
    length = len(list_elems)
    if (0 > currentIdx or length < currentIdx) or (0 > targetIdx or length < targetIdx): # Valido que las posiciones a cambiar esten en el rango validao del iterable busqueda.
        raise Exception("Incorrecto, ha especificado valores que estan fuera de rango...")
    
    list_elems[currentIdx], list_elems[targetIdx] = list_elems[targetIdx], list_elems[currentIdx] # Efectuación del deslizamiento o cambios.
    

def partition_func(sub_set: list, start:int, end:int):
    ''' Should return the last position taken by the Pivot, when all was travel '''
    pivot_value = sub_set[end]
    pivot_idx = start #@
    i = start
    
    for x in range(start, end):
              
        # If the pivot is highter move it to the left
        if pivot_value > sub_set[i]:# if the current index is lower thant pivot
            swap(sub_set, pivot_idx, i)
            pivot_idx += 1
            
        i += 1 #increse the travelsal index.
    
    if pivot_value == sub_set[i]: # Cuando el indice de exploracion coincida con el valor del pivot, puede realizar el cambio que posiciona al pivot en el centro, luego de haber evaluado todo los elementos anteriores del pivot.
        swap(sub_set, pivot_idx, i)
    
    return pivot_idx

import random
def partition_func_with_random(sub_set: list, start:int, end:int):
    ''' Should return the last position taken by the Pivot, when all was travel.'''
    random_index = random.randint(start, end)
    
    #sub_set[random_index], sub_set[end] = sub_set[end], sub_set[random_index], 
    swap(sub_set, end, random_index) #Cambiamos el valor final por un numero random dentro del rango(start, end). Con esto logramos un reajuste.
    
    pivot_value = sub_set[end] #Normalmente se utiliza el último, pero con esta implementación de Random Pivot, las cosas cambiaran.
    
    pivot_idx = start #@
    i = start
    
    for x in range(start, end):
              
        # If the pivot is highter move it to the left
        if pivot_value > sub_set[i]:# if the current index is lower thant pivot
            swap(sub_set, pivot_idx, i)
            pivot_idx += 1
            
        i += 1 #increse the travelsal index.
    
    if pivot_value == sub_set[i]: # Cuando el indice de exploracion coincida con el valor del pivot, puede realizar el cambio que posiciona al pivot en el centro, luego de haber evaluado todo los elementos anteriores del pivot.
        swap(sub_set, pivot_idx, i) # Aún así, el condicional anterior puede ser omitido.
    
    return pivot_idx

def quick_sort(sub_set: list, start:int, end:int):
    
    if len(sub_set) == 1: # Caso cuando llega a un extremo, osea unico elemento por lo cual esta ordenado.
        return
    
    if start < end:
        pivot = partition_func(sub_set, start, end)
        quick_sort(sub_set, start, pivot -1)
        quick_sort(sub_set, pivot+1, end)

par = [10,12,20,25,13,22,15]

partition_func(par,0, len(par) - 1)
print(par)