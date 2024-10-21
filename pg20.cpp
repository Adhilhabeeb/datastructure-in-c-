// DOUBLY LINKED LIST
#include <iostream>
using namespace std;

struct node {
    int num;
    node* next;
    node* prev;
};

node* head = nullptr; 

void queue_create(int n) {
    if (n <= 0) return;

    head = new node;
    cout << "\nEnter the data into queue: ";
    cin >> head->num;
    head->next = nullptr;
    head->prev = nullptr;

    node* temp = head;

    for (int i = 2; i <= n; i++) {
        node* newNode = new node;
        cout << "\nEnter the data into queue: ";
        cin >> newNode->num;
        newNode->next = nullptr;
        newNode->prev = temp;

        temp->next = newNode;
        temp = newNode;
    }
}

void display() {
    node* temp = head;

    if (temp == nullptr) {
        cout << "\nThe list is empty.";
    } else {
        while (temp != nullptr) {
            cout << temp->num << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}

void delebeg() {
    if (head == nullptr) {
        cout << "Can't delete from the beginning, the list is empty." << endl;
        return;
    }

    node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }
    
    delete temp;
    cout << "Deleted from the beginning." << endl;
}

void deleend() {
    if (head == nullptr) {
        cout << "Can't delete from the end, the list is empty." << endl;
        return;
    }

    node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr; 
    }

    delete temp;
    cout << "Deleted from the end." << endl;
}

void delepos() {
    int p;
    cout << "\nEnter the position for deletion: ";
    cin >> p;

    if (head == nullptr || p <= 0) {
        cout << "Can't delete from position " << p << "." << endl;
        return;
    }

    node* t = head;

    if (p == 1) { 
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete t;
        cout << "Deleted from position " << p << "." << endl;
        return;
    }

    for (int i = 1; t != nullptr && i < p; i++) {
        t = t->next;
    }

    if (t == nullptr) {
        cout << "Position out of range." << endl;
        return;
    }

    if (t->prev != nullptr) {
        t->prev->next = t->next;
    }
    if (t->next != nullptr) {
        t->next->prev = t->prev;
    }

    delete t;
    cout << "Deleted from position " << p << "." << endl;
}

int main() {
    int n;
    int ch;

    cout << "\nEnter the number of nodes: ";
    cin >> n;
    queue_create(n);
    cout << "\nData entered in the list: \n";
    display();

    do {
        cout << "\nEnter the choice for deletion: \n";
        cout << "1. Delete from Beginning \n";
        cout << "2. Delete from End \n";
        cout << "3. Delete from Specific Position \n";
        cout << "4. Exit \n";

        cin >> ch;

        switch (ch) {
            case 1:
                delebeg();
                display();
                break;
            case 2:
                deleend();
                display();
                break;
            case 3:
                delepos();
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (ch != 4);

    return 0;
}
