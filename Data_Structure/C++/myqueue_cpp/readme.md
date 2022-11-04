## Queue Implementation

In this repository I'm trying to put hand-on practice the `Queue` data structure
using C++ and OOP. With this simple implementation I will be simulating a printer
queue that is good example of queue implementation.


### Queue Strategy

Queues are FIFO data structure that mean the first element entering is it 
the first element in out and continusly the will follow the order meaning that
the next elements will being outing the the order they enter.

When we are working with Queues strategically we need to keep a reference (property/pointer)
to first element as well to the last element (in the data structure implementation).
In the element implementation itself it always must point (maybe with a pointer) to it next
element to keep a mechanism of interchange the order when we `dequeue` an element from the 
Queue data structure.

> Dequeue mean to get the first element from the queue and also detach it from it.

> Enqueue it the process where we insert new elements into the queue.

Some developers use this naming convention to name the to principal methods or operations
of a queue and other use nomenclature as `pop` for dequeue and `push` to enqueue. But put and pop for me
sound more insightful when working with stacks data structures.