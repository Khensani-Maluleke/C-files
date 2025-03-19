#include <iostream>
#include <list>

class Queue {
public:
    bool isEmpty();     // True if there are no items in the queue, false otherwise.
    int dequeue();      // Remove the front item from the queue and return it.
    void enqueue(int v); // Add v to the queue.

    // Constructor and Destructor
    Queue();  // Default constructor
    ~Queue(); // Destructor (no need for manual memory management here)

private:
    std::list<int> Data; // List to store queue elements
};

// Constructor: Initializes an empty queue.
Queue::Queue() {
    // Nothing extra is needed because std::list is empty by default.
}

// Destructor: No explicit memory management is needed, as std::list will handle it.
Queue::~Queue() {
    // List automatically cleans up when it goes out of scope.
}

// Check if the queue is empty
bool Queue::isEmpty() {
    return Data.empty();  // Returns true if the list is empty, false otherwise.
}

// Dequeue: Remove and return the front element of the queue.
int Queue::dequeue() {
    if (isEmpty()) {
        return -1;  // Return -1 to indicate that the queue is empty.
    }
    int front = Data.front();  // Get the front element of the list.
    Data.pop_front();          // Remove the front element from the list.
    return front;               // Return the dequeued element.
}

// Enqueue: Add an element to the back of the queue.
void Queue::enqueue(int v) {
    Data.push_back(v);  // Add the value to the end of the list.
}

int main() {
    Queue queue;

     //Test the queue operations
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Dequeue: " << queue.dequeue() << std::endl;  // Outputs: 10
    std::cout << "Dequeue: " << queue.dequeue() << std::endl;  // Outputs: 20
    std::cout << "Is empty: " << queue.isEmpty() << std::endl; // Outputs: false

    return 0;
}
