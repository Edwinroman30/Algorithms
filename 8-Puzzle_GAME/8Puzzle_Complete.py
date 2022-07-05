"""
# Proyecto Puzzle-8

**Integrantes del equipo:**
 
*( Roniell Pérez | 2021-0032 | 20210032@itla.edu.do)*
*( Edwin A. Roman Seberino   | 2020-10233 | 202010233@itla.edu.do)*
*( Annethy P. Javier Montero | 202010518 | 202010518@itla.edu.do)*
*( Domingo G. Alcántara Martínez | 20210255 | 20210255@itla.edu.do)*
*( Carlos Henríquez | 2020-10203 | 202010203@itla.edu.do)*
*( David Tavarez | 2019-9038 | 20199038@itla.edu.do)*

"""

"""
Código esqueleto para el proyecto Puzzle-8 del Prof. Carlos Ogando
para la asignatura Introducción a la IA en ITLA.
Python 3
"""

# Librerías
import resource #Solo funciona para Unix
import math
import time
from collections import deque 

#Variables globales
goal = (0,1,2,3,4,5,6,7,8)
start_time = maxSearchDepth = expandedNodes = 0

# Clase MyDeque para ser usada como queue o stack

class MyDeque():
    def __init__(self):
        self.deque = deque()
        self.set = set()
    
    def push(self, value) -> None:
        """Inserta un elemento en la última posición."""
        self.deque.append(value)
        self.set.add(value)
        
    def popRight(self):
        """Elimina y retorna el elemento en la última posición"""
        removedValue = self.deque.pop()
        self.set.remove(removedValue)
        return removedValue
    
    def popLeft(self):
        """Elimina y retorna el elemento en la primera posición"""
        removedValue = self.deque.popleft()
        self.set.remove(removedValue)
        return removedValue
    
    def contains(self, value) -> bool:
        """Verifica si un elemento está en el deque a traves del set""" 
        return value in self.set
    
    def isEmpty(self) -> bool:
        """Verifica si la deque está vacía"""
        return len(self.deque) == 0
    
# Clase PQueue para el Priority Queue

class MyPQueue():
    def __init__(self):
        self.pq = []
        self.set = set()
    
    def push(self, item:tuple) -> None:
        """Inserta un elemento al priority queue"""

        #Si el elemento ya está en el priority queue actualizamos su prioridad
        if self.contains(item[1]):
            self.updatePriority(item)
        #Si no, agregamos el elemento al priority queue    
        else:
            self.pq.append(item)
            self.set.add(item[1])
            
        self.orderPriorities()
    
    def pop(self):
        """Elimina el elemento con menor prioridad del priority queue"""
        removedValue = self.pq.pop(0)[1]
        self.set.remove(removedValue)
        return removedValue
    
    def isEmpty(self) -> bool:
        """Verifica si la priority queue está vacía"""
        return len(self.pq) == 0

    def contains(self, value) -> bool: 
        """Verifica si un elemento está en la priority queue"""
        return value in self.set 
    
    def updatePriority(self, item) -> None:
        """Actualiza la prioridad de un elemento"""

        #Se obtiene la posición del elemento pasado por parametro en el pq
        idx = [i[1] for i in self.pq].index(item[1])
        #Se obtiene la prioridad nueva y la actual
        newPriority, currPriority = item[0], self.pq[idx][0]
        #Si la prioridad nueva es menor que la actual se actualiza la prioridad
        if newPriority < currPriority: self.pq[idx] = item
        
    def orderPriorities(self) -> None:
        """Ordena el priority queue basandose en el valor de la prioridad"""

        self.pq.sort(key = lambda item: item[0])
    
# Clase que representa el Puzzle-n general

class PuzzleState(object):

    """Clase PuzzleState que genera un puzzle de n^2 posiciones.
    Las fichas del puzzle son numeros en un rango de: [1, n^2)"""

    def __init__(self, config, n, parent=None, action="Initial", cost=0):
        #Si n^2 es diferente de la longitud de la tupla de valores o es menor que 2
        #no es un puzzle valido
        if n*n != len(config) or n < 2:

            raise Exception("the length of config is not correct!")

        self.n = n

        self.cost = cost

        self.parent = parent

        self.action = action

        self.dimension = n

        self.config = config

        self.children = []
        
        #Bucle para obtener la posicion en blanco (el número 0) en el Puzzle
        for i, item in enumerate(self.config):

            if item == 0:

                self.blank_row = i // self.n

                self.blank_col = i % self.n

                break

    def display(self) -> str:
        """Retorna el puzzle representado como una matriz"""
        puzzle = ""

        for i in range(self.n):

            line = []

            offset = i * self.n

            for j in range(self.n):

                line.append(self.config[offset + j])
            
            puzzle += str(line) + "\n"

        return puzzle

    def move_left(self) -> object:
        """Mueve el espacio en blanco a la izquierda"""

        if self.blank_col == 0:

            return None

        else:

            blank_index = self.blank_row * self.n + self.blank_col

            target = blank_index - 1

            new_config = list(self.config)

            new_config[blank_index], new_config[target] = new_config[target], new_config[blank_index]

            return PuzzleState(tuple(new_config), self.n, parent=self, action="Left", cost=self.cost + 1)

    def move_right(self) -> object:
        """Mueve el espacio en blanco a la derecha"""

        if self.blank_col == self.n - 1:

            return None

        else:

            blank_index = self.blank_row * self.n + self.blank_col

            target = blank_index + 1

            new_config = list(self.config)

            new_config[blank_index], new_config[target] = new_config[target], new_config[blank_index]

            return PuzzleState(tuple(new_config), self.n, parent=self, action="Right", cost=self.cost + 1)

    def move_up(self) -> object:
        """Mueve el espacio en blanco hacia arriba"""

        if self.blank_row == 0:

            return None

        else:

            blank_index = self.blank_row * self.n + self.blank_col

            target = blank_index - self.n

            new_config = list(self.config)

            new_config[blank_index], new_config[target] = new_config[target], new_config[blank_index]

            return PuzzleState(tuple(new_config), self.n, parent=self, action="Up", cost=self.cost + 1)

    def move_down(self) -> object:
        """Mueve el espacio en blanco hacia abajo"""

        if self.blank_row == self.n - 1:

            return None

        else:

            blank_index = self.blank_row * self.n + self.blank_col

            target = blank_index + self.n

            new_config = list(self.config)

            new_config[blank_index], new_config[target] = new_config[target], new_config[blank_index]

            return PuzzleState(tuple(new_config), self.n, parent=self, action="Down", cost=self.cost + 1)

    def expand(self) -> list:

        """Expande el nodo realizando todos los movimientos posibles"""

        # Añadir nodos hijos en orden UDLR (Up-Down-Left-Right)

        if len(self.children) == 0:

            up_child = self.move_up()

            if up_child is not None:

                self.children.append(up_child)

            down_child = self.move_down()

            if down_child is not None:

                self.children.append(down_child)

            left_child = self.move_left()

            if left_child is not None:

                self.children.append(left_child)

            right_child = self.move_right()

            if right_child is not None:

                self.children.append(right_child)

        return self.children

    def __lt__(self, other):
        return self.cost < other.cost
    
    def __eq__(self, other):
        return self.config == other.config
    
    def __hash__(self):
        return hash(self.config)

#Funciones del proyecto

def writeOutput(state) -> None:

    """
    Función que escribe el archivo output.txt con la solución
    """
    global maxSearchDepth, expandedNodes
    
    #Segundos en total que tardó la busqueda en realizarse (8 decimales) 
    runningTime = round(time.time() - start_time, 8)

    #Pico de RAM consumido durante la ejecucion del programa
    maxRamUsage = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    
    #El costo  y la profundidad de busqueda es igual al costo del objeto
    costToPath = searchDepth = state.cost

    #Deque donde se guardará el camino a la solución 
    pathToGoal = deque()
    
    #Recorremos los parent para obtener el action(movimiento) de cada objeto
    while state.parent:
        pathToGoal.appendleft(state.action)
        state = state.parent

    #Creación del texto
    txt = f"Puzzle:\n{state.display()}\npath_to_goal: {list(pathToGoal)}"
    txt += f"\ncost_of_path: {costToPath}\nnodes_expanded: {expandedNodes}"
    txt += f"\nsearch_depth: {searchDepth}\nmax_search_depth: {maxSearchDepth}"
    txt += f"\nRunning_Time: {runningTime}s\nmax_ram_usage: {maxRamUsage}kb"

    #Creación del archivo output.txt 
    with open("output.txt", "w") as file:
        file.write(txt)

def bfs_search(initial_state: PuzzleState):

    """BFS search
    Retorna:
    *En caso de éxito: Archivo txt con los movimientos a realizar para
     obtener la solución y demás características de la búsqueda.
    *En caso de fallo: -1
    """

    #Variables globales para obtener características de la búsqueda
    global maxSearchDepth, expandedNodes
    
    #Estructuras de datos que serán utilizadas
    frontier = MyDeque()
    visited = set()
    
    frontier.push(initial_state)

    while not frontier.isEmpty():
        currState = frontier.popLeft()
        visited.add(currState)
      
        if test_goal(goal, currState):
             return writeOutput(currState)

        #Contabilizamos un nodo expandido
        expandedNodes += 1
        
        #Bucle para recorrer todos los objetos obtenidos de la expansión
        for state in currState.expand():
            
            #Se verifica si el objeto no está en el frontier ni tampoco en visited                      
            if not frontier.contains(state) and state not in visited:
                frontier.push(state)

                #Verificación para obtener la máxima profundidad de busqueda
                if state.cost > maxSearchDepth:
                   maxSearchDepth = state.cost               
    return -1

def dfs_search(initial_state: PuzzleState):

    """DFS search
    Retorna:
    *En caso de éxito: Archivo txt con los movimientos a realizar para
     obtener la solución y demás características de la búsqueda.
    *En caso de fallo: -1
    """
    
    #Variables globales para obtener características de la búsqueda
    global maxSearchDepth, expandedNodes
    
    #Estructuras de datos que serán utilizadas
    frontier = MyDeque()
    visited = set()

    frontier.push(initial_state)
    
    while not frontier.isEmpty():
        currState = frontier.popRight()
        visited.add(currState)

        if test_goal(goal, currState):
            return writeOutput(currState)
        
        #Contabilizamos un nodo expandidos
        expandedNodes += 1

        #Bucle para recorrer todos los objetos obtenidos de la expansión, empezando
        #desde la última posición para que estos se guarden en orden RLDU en el frontier
        for state in currState.expand()[::-1]:
            
            #Se verifica si el objeto no está en el frontier ni tampoco en visited
            if not frontier.contains(state) and state not in visited: 
                frontier.push(state)
                
                #Verificación para obtener la máxima profundidad de busqueda
                if state.cost > maxSearchDepth: 
                    maxSearchDepth = state.cost                  
    return -1 

def A_star_search(initial_state: PuzzleState):
    """A * search
    Retorna:
    *En caso de éxito: Archivo txt con los movimientos a realizar para
     obtener la solución y demás características de la búsqueda.
    *En caso de fallo: -1
    """
    
    #Variables globales para obtener características de la búsqueda
    global maxSearchDepth, expandedNodes
   
    #Estructuras de datos que serán utilizadas
    frontier = MyPQueue()
    visited = set()

    frontier.push((0, initial_state))
    
    while not frontier.isEmpty():
        currState = frontier.pop()
        visited.add(currState)
    
        if test_goal(goal, currState):
            #La maxima profundidad de busqueda es igual al costo del objeto
            maxSearchDepth = currState.cost

            return writeOutput(currState)

        #Cada que se expanda un objeto lo contabilizamos
        expandedNodes += 1

        #Bucle para recorrer todos los objetos obtenidos de la expansión
        for state in currState.expand():    
            if state not in visited:
                #Se calcula el costo mediante la heuristica
                cost = calculate_total_cost(state)

                frontier.push((cost, state)) 
    return -1

def calculate_total_cost(state: PuzzleState) -> int:
    """calculate the total estimated cost of a state"""
    
    #Costo del estado actual a la meta + Costo para llegar al estado actual 
    return calculate_manhattan_dist(state.config, state.n) + state.cost

def calculate_manhattan_dist(config: tuple, n: int) -> int:
    totalDist = 0
    
    for i, num in enumerate(config):
        #Posicion del numero actual en el puzzle
        currStateX = i // n 
        currStateY = i % n 
        
        #Posicion de donde debería estar el numero actual en el puzzle
        goalX = num // n 
        goalY = num % n 
        
        #Calculamos manhattan distance con su respectiva formula
        totalDist += abs(currStateX - goalX) + abs(currStateY - goalY)
    
    return totalDist

def test_goal(goal: tuple, state: PuzzleState) -> bool:
    """test the state is the goal state or not"""
    return goal == state.config
    
# Función Main que leerá las entradas y llamará el algoritmo correspondiente

def main():
    global start_time 
    
    query = input().split(" ")

    sm = query[0].lower()

    begin_state = query[1].split(",")

    begin_state = tuple(map(int, begin_state))

    size = int(math.sqrt(len(begin_state)))

    hard_state = PuzzleState(begin_state, size)
    
    start_time = time.time()
    
    if sm == "bfs":

        bfs_search(hard_state)

    elif sm == "dfs":

        dfs_search(hard_state)

    elif sm == "ast":

        A_star_search(hard_state)

    else:

        print("Introduzca comandos de argumentos válidos !")

if __name__ == '__main__':

    main()