#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int   key;
    Node *next;
};
Node *newNode(int k) {
    Node *temp = new Node();
    temp->key  = k;
    temp->next = NULL;
    return temp;
}

// A utility function to create an empty queue
Queue *createQueue() {
    Queue *q = new Queue();
    q->front = q->rear = NULL;
    return q;
}

// The function to add a key k to q
void enQueue(Queue *q, int k) {
    // Create a new LL node
    Node *temp = newNode(k);

    // If queue is empty, then
    // new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at
    // the end of queue and change rear
    q->rear->next = temp;
    q->rear       = temp;
}

// Function to remove
// a key from given queue q
Node *deQueue(Queue *q) {
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return NULL;

    // Store previous front and
    // move front one node ahead
    Node *temp = q->front;
    delete (temp);

    q->front = q->front->next;

    // If front becomes NULL, then
    // change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}

// Driver code
int main() {
    Queue *q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    Node *n = deQueue(q);
    if (n != NULL)
        cout << "Dequeued item is " << n->key;
    return 0;
}

// This code is contributed by rathbhupendra
