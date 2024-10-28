// DELETE FROM LINEAR LINKED LIST
#include <iostream>
using namespace std;

struct node {
    node *next;
    int num;
};

node *head = NULL; 

void create(int n) {
    if (n <= 0) return;

    head = new node; 
    cout << "\nEnter the data for node 1: ";
    cin >> head->num;
    head->next = NULL;

    node *temp = head; 

    for (int i = 1; i < n; i++) {
        node *fnode = new node; 
        cout << "\nEnter the data for node " << (i + 1) << ": ";
        cin >> fnode->num;
        fnode->next = NULL;
        temp->next = fnode; 
        temp = fnode; 
    }
}

// Function to display the linked list
void display() {
    if (head == NULL) {
        cout << "The list is empty.\n";
        return;
    }
    
    node *temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->num << " ";
        temp = temp->next;
    }
    cout << endl;
}



// Deletion from the beginning
void del_beg() {
    if (head == NULL) {
        cout << "The list is empty. No node to delete.\n";
        return;
    }

    node *temp = head;
    head = head->next; 
    delete temp; 
    cout << "Node deleted from the beginning.\n";
}

// Deletion from the end
void del_end() {
    if (head == NULL) {
        cout << "The list is empty. No node to delete.\n";
        return;
    }

    if (head->next == NULL) { 
        delete head;
        head = NULL; 
        cout << "Node deleted from the end.\n";
        return;
    }

    node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next; 
    }

    delete temp->next; 
    temp->next = NULL; 
    cout << "Node deleted from the end.\n";
}

// Deletion from a specific position
void del_pos() {
    if (head == NULL) {
        cout << "The list is empty. No node to delete.\n";
        return;
    }

    int pos;
    cout << "\nEnter the position (1-based index) of the node to delete: ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1) {
        del_beg(); 
        return;
    }

    node *temp = head;
    node *prev = NULL;
    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            cout << "Position out of bounds.\n";
            return;
        }
        prev = temp; 
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of bounds.\n";
        return;
    }

    prev->next = temp->next; 
    delete temp; 
    cout << "Node deleted from position " << pos << ".\n";
}

int main() {
    int n, ch;

    cout << "Enter the number of nodes to create: ";
    cin >> n;
    create(n);
    display();

    cout << "_____ ENTER THE CHOICE FOR PERFORM _____\n";
    cout << "1) Deletion at beginning\n";
    cout << "2) Deletion at end\n";
    cout << "3) Deletion at position\n";
    cout << "4) Display\n";
    cout << "5) Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
           case 1: 
                del_beg();
                display();
                break;
            case 2: 
                del_end();
                display();
                break;
            case 3: 
                del_pos();
                display();
                break;
            case 4: 
                display();
                break;
            case 5:
                cout << "\nExiting...\n";
                break;
            default:
                cout << "\nEnter a valid choice\n";
        }
    } while (ch != 5);

    return 0;
}
