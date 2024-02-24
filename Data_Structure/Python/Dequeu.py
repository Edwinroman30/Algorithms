class Dequeu:
    
    def __init__(self):
        self.queue=[]
        
    # Métodos para _ingresar_ y _eliminar_ elmentos como en el concepto de cola(FIFO)
    def add_first(self, item):
        self.queue.insert(0, item) #"Agregar un elemento a la parte inicial de la estructura: "
    
    def remove_first(self):
        return None if len(self.queue) == 0 else self.queue.pop(0)     #"Remover y retornar un elemento a la parte inicial de la estructura: "
        
    # Métodos para _ingresar_ y _eliminar_ elmentos como en el concepto de pila(LIFO)
    def add_last(self, item):
        self.queue.append(item) #"Agregar un elemento a la parte final de la estructura: "
        
    def remove_last(self):
        return self.queue.pop()  #"Remover y retornar un 'elemento a la parte final de la estructura: "
      