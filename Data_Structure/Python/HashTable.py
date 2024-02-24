from typing import Any

class HashTablev1:
    ''' Basic hash table implementation, without collision handling '''
    ''' SOURCES: https://www.youtube.com/playlist?list=PLeo1K3hjS3uu_n_a__MI_KktGTLYopZ12 '''
        
    def __init__(self, size):
        self.size = size
        self.table = [None for x in range(size)]

    def hash(self, key:str):
        ''' The importan hash function should calculate and return the index on where the value is or should be store.'''
        asciiValue = 0
        for x in key:
            asciiValue += ord(x)
        
        return asciiValue % self.size
    
    def set(self, key:str, value:any):
        hash_index = self.hash(key)
        self.table[ hash_index ] = value        
            
    def get(self, key):
        return self.table[self.hash(key)]
    
    def __setitem__(self, __key: str, __value: Any) -> None:
        hash_index = self.hash(__key)
        self.table[ hash_index ] = __value  
    
    def __getitem__(self, __key:str):
        return self.table[ self.hash(__key) ]

class HashTable:
    ''' It's a HashTable data structure with collision handling using a linked-list or list for storing values pairs even 
    when their are repeated.'''
    
    def __init__(self, fixed_size: int):
        self.size = fixed_size
        self.table = [ [] for x in range(fixed_size) ]
    
    def __hash__(self, key:str):
        ''' The importan hash function should calculate and return the index on where the value is or should be store.'''
        asciiValue = 0
        for x in key:
            asciiValue += ord(x)
        
        return asciiValue % self.size
    
    def __setitem__(self, __key: str, __value: Any):
        # Now this implementation of the set function compared with the previous on the HashTableV1, not 
        # just store the value, it store the key and the value.
        key_exist = False
        hash_index = self.__hash__(__key)
        
        if len(self.table[hash_index]) >= 1:
            
            for idx, val in enumerate(self.table[hash_index]):
                if val[0] == __key:
                    self.table[ hash_index ][idx] = (__key, val)
                    key_exist = True
                    break
        
        if not key_exist:
            self.table[hash_index].append( (__key, __value) )
            
    def __getitem__(self, __key:str):
        hash_index = self.__hash__(__key)
        found_value = None
        
        for idx, val in enumerate(self.table[hash_index]):
            if val[0] == __key:
                found_value = val[1]
                break
        return found_value
    
    def __delitem__(self, __name: str) -> None:
        hash_index = self.__hash__(__name)
        
        for idx, val in enumerate(self.table[hash_index]):
            if val[0] == __name:
                del self.table[hash_index][idx]
                break

class HashtableLinearProbing:
    
    def __init__(self, size):
        self.size = size
        self.keys = [None] * size
        self.values = [None] * size

    def hash_function(self, key):
        return hash(key) % self.size

    def put(self, key, value):
        index = self.hash_function(key)

        while self.keys[index] is not None:
            if self.keys[index] == key:
                # Key already exists, update the value
                self.values[index] = value
                return
            # Linear probing to find the next available slot
            index = (index + 1) % self.size

        # Found an empty slot, insert the key and value
        self.keys[index] = key
        self.values[index] = value

    def get(self, key):
        index = self.hash_function(key)

        while self.keys[index] is not None:
            if self.keys[index] == key:
                # Key found, return the corresponding value
                return self.values[index]
            # Linear probing to search for the key
            index = (index + 1) % self.size

        # Key not found
        raise KeyError(key)


#table = HashTable(3)

# Collision issues between UNPHU and ITLA value.
''' table["UNPHU"] = 80
table["ITLA"]= 4.0

table["uasd"] = 90

print(table.table)
print("For ITLA:", table["ITLA"])
print("For UNPHU {} and UASD {}".format(table["UNPHU"], table["uasd"]))

del table["uasd"]

print(table.table) '''

# Create a hashtable with size 10
htable = HashtableLinearProbing(10)

# Insert key-value pairs
htable.put('apple', 10)
htable.put('banana', 20)
htable.put('orange', 30)

# Retrieve values
print(htable.get('apple'))   # Output: 10
print(htable.get('banana'))  # Output: 20
print(htable.get('orange'))  # Output: 30
