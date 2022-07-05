from collections import deque 

# Clase MyQueue para ser usada como queue y stack

class MyQueue():
    def __init__(self):
        self.queue = deque()
        self.set = set()
    
    def push(self, value) -> None:
        """Inserta un elemento en la última posición."""
        self.queue.append(value)
        self.set.add(value)
        
    def popRight(self):
        """Elimina y retorna el elemento en la última posición"""
        removedValue = self.queue.pop()
        self.set.remove(removedValue)
        return removedValue
    
    def popLeft(self):
        """Elimina y retorna el elemento en la primera posición"""
        removedValue = self.queue.popleft()
        self.set.remove(removedValue)
        return removedValue
    
    def contains(self, value) -> bool:
        """Verifica si un elemento está en el queue""" 
        return value in self.set
    
    def isEmpty(self) -> bool:
        """Verifica si la queue está vacía"""
        return self.queue == 0