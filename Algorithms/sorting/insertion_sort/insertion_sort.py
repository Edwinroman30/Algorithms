def insertion_sort(unsorted_array : list):
    elem_space_key = 1
    elem_space_val = 0
    array_lenght = len(unsorted_array)
    
    for inx in range(1, array_lenght):
        elem_space_key = inx # Represent the key/position of last popped element.
        elem_space_val = unsorted_array[elem_space_key] # Represent the value extracted/poped from left side of the unsorted element.
        print(unsorted_array)      
       
        for y in range(elem_space_key - 1, 0, -1): # Travel the array in reverse way from the last element to the index num 0, the 1st element.
            if unsorted_array[y] > elem_space_val:
                unsorted_array[elem_space_key] = unsorted_array[y]
                elem_space_key = y
                continue
            break
        unsorted_array[elem_space_key] = elem_space_val
        
        # In case it is the first time into the loop (Index is CERO).
        if elem_space_key - 1 == 0:
            if unsorted_array[0] > elem_space_val:
                unsorted_array[elem_space_key], unsorted_array[0] = unsorted_array[0], unsorted_array[elem_space_key]
        

    return unsorted_array

print("Result", insertion_sort([50, 30, 40, 10, 20]) )
