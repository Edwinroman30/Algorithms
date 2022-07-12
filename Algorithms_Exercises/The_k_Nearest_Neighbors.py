#The k-Nearest Neighbors

import math

#data - contain list of duple.

students = [(87, "Jose"), (90, "Mario"), (78, "Pepe"), (70, "Edwin"), (75, "Julian"), (71, "Pablo")]


def Knn(k_near : int, data : list, target: str):
    more_nearest = []
    target_value = None
    target_idx = 0
    
    
    for idx,targ in enumerate(data):
        if(targ[1] == target):
            target_value = targ
            target_idx = idx
    
        
    if(target_value == None):   
        return "Error 404: target not found."
        
    for value in data:
        euclidean_distance = math.sqrt(value[0]**2 - target_value[0]**2)    
        more_nearest.append( (euclidean_distance, value[0], value[1]) )

    more_nearest.pop(target_idx)
    more_nearest = sorted(more_nearest)
    more_nearest = more_nearest[0: k_near]
    
    # Lets return the.... average
    accumulator = 0
    for grades in more_nearest:
        accumulator = accumulator + grades[1]
    
    print(more_nearest)
    return accumulator / len(more_nearest)
    

print( Knn(2, students, "Edwin") )