''' 
    General information about this sorting algorithm:
    # Merge Sort - Algorithm
    Merge sort is an algorithm from the sorting algorithm family, it has a time complexity of O(n log(n)) and space complexity of O(n).

    ### Resource:
    - https://www.youtube.com/playlist?list=PLprfEn_dJT0-iQbFSz324Wg3rVPWm2nj5
    - https://www.bigocheatsheet.com
    The Space complexity of the merge function is it O(s1 + s2) that in summary is equal to O(n).
    Coded on: 24 feb 2024
'''

def merge(s1: list, s2: list) -> list:
    ''' Recive two sorted list and combine them into new a one with all of the elements inside of it sorted.'''
    merged_list = list() 
    
    while  len(s1) != 0 and len(s2) != 0:
        if s1[0] <= s2[0]: # Cause all elements are sorted, we compared the 1st one of each list until we have cero element in one of them.
            merged_list.append( s1.pop(0) )
        else:
            merged_list.append( s2.pop(0) )
            
    ''' At this point we are gone have one the list with elements:
        Finally, we just gona repeat these steps above, until `s1` and `s2` 
        is empty. One possible case it that one of the list is empty before the other, the resting element are just joined to the 
        `final_sorted` list (cause they are already in sorted it wont affect).
    '''    
    if len(s1) != 0:
        merged_list.extend(s1)
    if len(s2) != 0:
        merged_list.extend(s2)
    
    return merged_list
    
# l1 = merge([1,2,4], [3,5,7]) # Doing testing with two already sorted list...

def merge_sort(unsorted_list : list) -> list:
    ''' Combined with the merge function, it composes the Famous @MergeSort algorithm. This defined function  takes care of recursively divide the list/array, and pass it to the merge function for sorting it. '''
    if len(unsorted_list) == 1: #Base case for stopping, if you give me a one_dimentional list, it considered that is already sorted list.
        return unsorted_list 
    
    middleIndex = ( len(unsorted_list) // 2 ) #middle index 
    left, right = unsorted_list[0: middleIndex], unsorted_list[middleIndex:] #Divide the list into two parts.
    
    return merge(merge_sort(left), merge_sort(right)) # Divide recursively until compare just two one_dimentional list of elements.
    # In this sample, it starts resolving from left to satisfy the left argument, then goes deeper into the right. But on every return, we get the previous passed argument sorted.

#print( merge_sort([5,4,1,3,2])  )
print( merge_sort([1,2,4,3,5,7]) )