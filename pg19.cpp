// LINKED QUEUES
#include <iostream>
using namespace std;

struct node {
    int num;
    node* next;
};

node* front = nullptr; 
node* rear = nullptr; 

void queue_create(int n) {
    for (int i = 0; i < n; i++) {
        node* newNode = new node;
        cout << "\nEnter the data into queue: ";
        cin >> newNode->num;
        newNode->next = nullptr;

        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
}

void display() {
    node* temp = front;

    if (temp == nullptr) {
        cout << "\nThe queue is empty.";
    } else {
        cout << "\nQueue elements: ";
        while (temp != nullptr) {
            cout << temp->num << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}

void del() {
    if (front == nullptr) {
        cout << "\nQueue is empty, cannot delete.";
    } else {
        node* temp = front;
        front = front->next;
        delete temp;
        cout << "Deleted from the front of the queue." << endl;
    }
}

int main() {
    int n;
    char y;

    cout << "\nEnter the number of elements in the queue: ";
    cin >> n;
    queue_create(n);
    display();

    do {
        cout << "\nDo you want to delete an element? (y/n): ";
        cin >> y;

        if (y == 'y') {
            del();
            display();
        } else if (y == 'n') {
            cout << "\nExiting." << endl;
        } else {
            cout << "Invalid input, please enter 'y' or 'n'." << endl;
        }
    } while (y == 'y');

    return 0;
}
