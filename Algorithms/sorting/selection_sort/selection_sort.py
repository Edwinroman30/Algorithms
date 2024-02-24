elements = [50, 30, 40, 10, 20]

def selection_sort(elements: list):
    for idx  in range(len(elements)):
        pivot_inx = idx
        
        for y in range(pivot_inx + 1, len(elements)):
            if elements[pivot_inx] > elements[y]:
                elements[pivot_inx], elements[y] = elements[y], elements[pivot_inx]
                
    print(elements)
    
selection_sort(elements)