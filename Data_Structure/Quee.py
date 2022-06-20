#https://stackabuse.com/stacks-and-queues-in-python/
# And a queue that only has enqueue and dequeue operations
class Queue:

    def __init__(self):
        self.queue = []
        self.value = self._stack
        
    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if len(self.queue) < 1:
            return None
        return self.queue.pop(0)

    def size(self):
        return len(self.queue) 