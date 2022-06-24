from queue import Queue

graphs_nodes = {
    "A" : ["B", "D"],
    "B" : ["A","C"],
    "C": ["B"],
    "D": ["A","E","F"],
    "E": ["D","F","G"],
    "F": ["D", "E", "H"],
    "H": ["F", "G"],
    "G": ["E", "H"]
}


node_parents = {}
visited = {}
deep_level = {}

queue = Queue()

for node in graphs_nodes.keys():
    node_parents[node] = None
    visited[node] = False
    deep_level[node] = -1 

bfs_algorithm_output = []

#Let select "A" as our Node Root:
selected_root = "A"

node_parents[selected_root] = None
visited[selected_root] = True
deep_level[selected_root] = 0 # The Deep level from the parent node

queue.put(selected_root)

while ( not queue.empty() ):
    
    node = queue.get()
    bfs_algorithm_output.append(node)
    
    for child in graphs_nodes[node]:
        
        if not visited[child]:
            visited[child] = True
            deep_level[child] = deep_level[node] + 1
            node_parents[child] = node
            
            queue.put(child)

#-----------------------------------------------------------
#Looking for the Breadth root of G

target = "H"
searchInOrder = []

while target is not None:
    searchInOrder.append(target);
    target = node_parents[target]
    
searchInOrder = searchInOrder[::-1]
print(searchInOrder)

#Reference
#https://www.youtube.com/watch?v=PQhMkmhYZjQ