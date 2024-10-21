// BINARY TREE
#include <iostream>
#include <cstdlib>

using namespace std;

class BST {
private:
    struct Node {
        int info;
        Node *left;
        Node *right;
        
        Node(int value) : info(value), left(nullptr), right(nullptr) {}
    };

    Node *root;

    void insert(Node *&current, int key) {
        if (current == nullptr) {
            current = new Node(key);
        } else if (key < current->info) {
            insert(current->left, key);
        } else {
            insert(current->right, key);
        }
    }

    void deleteNode(Node *&current) {
        if (current->left == nullptr && current->right == nullptr) {
            delete current;
            current = nullptr;
        } else if (current->left == nullptr) {
            Node *temp = current;
            current = current->right;
            delete temp;
        } else if (current->right == nullptr) {
            Node *temp = current;
            current = current->left;
            delete temp;
        } else {
            Node *temp = findMin(current->right);
            current->info = temp->info;
            del(temp->info);
        }
    }

    Node* findMin(Node *current) {
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    void find(int key, Node **parent, Node **current) {
        while (*current && (*current)->info != key) {
            *parent = *current;
            if (key < (*current)->info) {
                *current = (*current)->left;
            } else {
                *current = (*current)->right;
            }
        }
    }

    void inorder(Node *current) {
        if (current) {
            inorder(current->left);
            cout << current->info << " ";
            inorder(current->right);
        }
    }

    void preorder(Node *current) {
        if (current) {
            cout << current->info << " ";
            preorder(current->left);
            preorder(current->right);
        }
    }

    void postorder(Node *current) {
        if (current) {
            postorder(current->left);
            postorder(current->right);
            cout << current->info << " ";
        }
    }

    void display(Node *current, int level) {
        if (current != nullptr) {
            display(current->right, level + 1);
            for (int i = 0; i < level; i++) {
                cout << "   ";
            }
            cout << current->info << endl;
            display(current->left, level + 1);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        insert(root, key);
    }

    void del(int key) {
        Node *parent = nullptr;
        Node **current = &root;
        find(key, &parent, current);
        
        if (*current) {
            deleteNode(*current);
        } else {
            cout << "Element not found!" << endl;
        }
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void preorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    void display() {
        cout << "Display Tree:" << endl;
        display(root, 0);
    }
};

int main() {
    int choice, num;
    BST bst;

    while (true) {
        cout << "--------------------" << endl;
        cout << "Operations on BST" << endl;
        cout << "--------------------" << endl;
        cout << "1. Insert Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "4. Preorder Traversal" << endl;
        cout << "5. Postorder Traversal" << endl;
        cout << "6. Display" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> num;
                bst.insert(num);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> num;
                bst.del(num);
                break;
            case 3:
                bst.inorder();
                break;
            case 4:
                bst.preorder();
                break;
            case 5:
                bst.postorder();
                break;
            case 6:
                bst.display();
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
