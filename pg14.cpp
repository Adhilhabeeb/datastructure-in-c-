// linear queue using arrays
#include<iostream>
using namespace std;

class Queue {
    int queue[50];
    int n = 50;  // Queue size
    int fro = -1;  // Front pointer
    int rea = -1;  // Rear pointer

    public:
        void enqueue();
        void dequeue();
        void display();
};

void Queue::enqueue() {
    int num;

    // Check for queue overflow
    if(rea >= n - 1) {
        cout << "\nQueue is overflow\n";
    } else {
        if(fro == -1) // If queue is initially empty
            fro = 0;
        cout << "\nEnter the number into queue: ";
        cin >> num;
        rea++;
        queue[rea] = num;
    }
}

void Queue::dequeue() {
    // Check for queue underflow
    if(fro == -1 || fro > rea) {
        cout << "\nQueue is underflow\n";
    } else {
        cout << "\nThe deleted element is = " << queue[fro] << "\n";
        fro++;

        // Reset front and rear pointers when the queue is empty
        if(fro > rea) {
            fro = -1;
            rea = -1;
        }
    }
}

void Queue::display() {
    if(fro == -1) {
        cout << "\nQueue is empty\n";
    } else {
        cout << "\nQueue elements are: ";
        for(int i = fro; i <= rea; i++) {
            cout << queue[i] << "\t";
        }
        cout << endl;
    }
}

int main() {
    Queue obj;
    int ch;

    cout << "_____ THIS IS USING CLASS _____\n";
    cout << "1) Insertion (Enqueue)\n";
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
