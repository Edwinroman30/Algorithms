class Queue():
    def __init__(self) -> None:
        self._queue = []
        
    def enqueue(self, item: any):
        self._queue.append(item)
        return item
    
    def dequeue(self):
        return None if self.is_empty() else self._queue.pop(0)
    
    def is_empty(self):
        return True if len(self._queue) == 0 else False
    
    def clear(self):
        self._queue.clear()
    
    def __repr__(self) -> str:
        return str(self._queue)