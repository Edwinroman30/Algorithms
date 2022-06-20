# A simple class stack that only allows pop and push operations
class Stack:
    """
    Definition:
    es una lista ordenada o estructura de datos que permite almacenar y recuperar datos, siendo el modo de acceso a sus elementos de tipo LIFO (del inglés Last In, First Out, «último en entrar, primero en salir»). Esta estructura se aplica en multitud de supuestos en el área de la informática debido a su simplicidad y capacidad de dar respuesta a numerosos procesos.
    
    Wikipedia: https://es.wikipedia.org/wiki/Pila_(inform%C3%A1tica)
    """
    
    def __init__(self) -> None:
        self._stack = []
        self.value = self._stack
        
    def size(self) -> int:
        return len( self._stack )
    
    def pop(self):
        if len(self._stack) < 1:
            return None
        return self._stack.pop()

    def push(self, item):
        self._stack.append(item)

    def peek(self):
        if(self._stack):
            return self._stack[-1]
        else:
            return None
            