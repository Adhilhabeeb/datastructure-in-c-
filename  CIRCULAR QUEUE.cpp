// CIRCULAR QUEUE
#include<iostream>
using namespace std;

class Queue {
    int que[4];
    int n = 4;  // Queue size
    int front = -1;  // Front pointer
    int rear = -1;  // Rear pointer

public:
    void enqueue();
    void dequeue();
    void display();
};

void Queue::enqueue() {
    if ((rear + 1) % n == front) {
        cout << "\nThe Queue is overflow\n";
        return;  // Early return if queue is full
    }
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;  // Initialize both front and rear to 0
    } else {
        rear = (rear + 1) % n;  // Update rear in a circular manner
    }

    cout << "\nEnter the element to enqueue: ";
    int val;
    cin >> val;
    que[rear] = val;
}

void Queue::dequeue() {
    if (front == -1) {
        cout << "\nThe queue is underflow\n";
        return;  // Early return if queue is empty
    }
    
    int deletedValue = que[front];  // Store the value to display
    if (front == rear) {  // If the queue becomes empty
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % n;  // Update front in a circular manner
    }
    cout << "\nThe value " << deletedValue << " is deleted\n";  // Print deleted value
}

void Queue::display() {
    if (front == -1) {
        cout << "\nQueue is empty\n";
        return;
    }
    
    cout << "\nQueue elements are: ";
    
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            cout << que[i] << " ";
        }
    } else {
        for (int i = front; i < n; i++) {
            cout << que[i] << " ";
        }
        for (int i = 0; i <= rear; i++) {
            cout << que[i] << " ";
        }
    }

    cout << endl;
}

int main() {
    Queue obj;
    int ch;

    cout << "_____ THIS IS CIRCULAR QUEUE CLASS _____\n";
    cout << "\n1) Insertion (Enqueue)\n";
    cout << "2) Deletion (Dequeue)\n";
    cout << "3) Display Queue\n";
    cout << "4) Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: 
                obj.enqueue();
                break;
            case 2: 
                obj.dequeue();
                break;
            case 3: 
                obj.display();
                break;
            case 4: 
                cout << "\nExit\n";
                break;
            default:
                cout << "\nEnter a valid choice\n";
        }
    } while (ch != 4);

    return 0;
}
