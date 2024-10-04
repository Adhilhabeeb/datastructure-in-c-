// INSERT INTO LINEAR LINKED LIST
#include<iostream>
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

// Insertion at the beginning
void ins_beg() {
    cout << "\nInsertion at the beginning";
    node *n = new node;
    cout << "\nEnter the data for the new node: ";
    cin >> n->num;
    n->next = head; 
    head = n; 
}

// Insertion at the end
void ins_end() {
    cout << "\nInsertion at the end";
    node *n = new node;
    cout << "\nEnter the data for the new node: ";
    cin >> n->num;
    n->next = NULL; 

    if (head == NULL) {
        head = n; 
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next; 
        }
        temp->next = n; 
    }
}

// Insertion at a specific position
void ins_pos() {
    cout << "\nInsertion at position";
    node *n = new node;
    cout << "\nEnter the data for the new node: ";
    cin >> n->num;

    int pos;
    cout << "\nEnter the position (1-based index): ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position.\n";
        delete n; 
        return;
    }

    if (pos == 1) {
        n->next = head;
        head = n; 
    } else {
        node *temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Position out of bounds.\n";
                delete n; 
                return;
            }
            temp = temp->next; 
        }

        n->next = temp->next; 
        temp->next = n; 
    }
}

int main() {
    int n, ch;

    cout << "Enter the number of nodes to create: ";
    cin >> n;
    create(n);
    display();

    cout << "_____ ENTER THE CHOICE FOR PERFORM _____\n";
    cout << "1) Insertion at beginning\n";
    cout << "2) Insertion at end\n";
    cout << "3) Insertion at position\n";
    cout << "4) Display\n";
    cout << "5) Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: 
                ins_beg();
                display();
                break;
            case 2: 
                ins_end();
                display();
                break;
            case 3: 
                ins_pos();
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
