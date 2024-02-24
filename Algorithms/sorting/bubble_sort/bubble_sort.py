S = [50, 30, 40, 10, 20]

def bubble_sort(values_set : list):
    length = len(values_set)
    
    for elem in range(length):  # Iterar sobre la cantidad de elementos para asegurar que todos los elementos sean comparados.
        for inx_val in range(length - 1):
            if values_set[inx_val] > values_set[inx_val + 1]:
                values_set[inx_val], values_set[inx_val + 1] = values_set[inx_val + 1], values_set[inx_val] # values_set interchanging

    print(values_set)
