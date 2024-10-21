// BINARY TREE TRAVERSAL
#include <iostream>
using namespace std;

struct node {
    int d;
    node *l, *r;

    node(int value) {
        d = value;
        l = r = nullptr;
    }
};

node *r = NULL;

void create() {
    int v, c = 0;
    while (c < 6) {
        if (r == NULL) {
            cout << "Enter value of root node: ";
            cin >> v;
            r = new node(v);
        } else {
            node *p = r;
            cout << "Enter value of node: ";
            cin >> v;

            while (true) {
                if (v < p->d) {
                    if (p->l == NULL) {
                        p->l = new node(v);
                        break;
                    } else {
                        p = p->l;
                    }
                } else {
                    if (p->r == NULL) {
                        p->r = new node(v);
                        break;
                    } else {
                        p = p->r;
                    }
                }
            }
        }
        c++;
    }
}

void inorder(node *current) {
    if (current) {
        inorder(current->l);
        cout << current->d << " ";
        inorder(current->r);
    }
}

void preorder(node *current) {
    if (current) {
        cout << current->d << " ";
        preorder(current->l);
        preorder(current->r);
    }
}

void postorder(node *current) {
    if (current) {
        postorder(current->l);
        postorder(current->r);
        cout << current->d << " ";
    }
}

int main() {
    create();

    cout << "Inorder Traversal: ";
    inorder(r);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(r);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(r);
    cout << endl;

    return 0;
}
