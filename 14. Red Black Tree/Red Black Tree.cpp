#include <iostream>
#include <sstream>
#include <string>

using namespace std;

enum Color { RED, BLACK };

struct Node {
    int key;
    int value;
    Color color;
    Node *left;
    Node *right;
    Node *parent;

    Node(int k, int v, Node *nil) : key(k), value(v), color(RED), left(nil), right(nil), parent(nil) {}
};

class RedBlackTree {
private:
    Node *root;
    Node *NIL;
    int rotationCount;
    int redCount;
    int blackCount;

    void leftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;
        if (y->left != NIL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NIL) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
        rotationCount++;
    }

    void rightRotate(Node *x) {
        Node *y = x->left;
        x->left = y->right;
        if (y->right != NIL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NIL) {
            root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
        rotationCount++;
    }

    void insertFixup(Node *z) {
        while (z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node *y = z->parent->parent->right;
                if (y->color == RED) {
                    setColor(z->parent, BLACK);
                    setColor(y, BLACK);
                    setColor(z->parent->parent, RED);
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    setColor(z->parent, BLACK);
                    setColor(z->parent->parent, RED);
                    rightRotate(z->parent->parent);
                }
            } else {
                Node *y = z->parent->parent->left;
                if (y->color == RED) {
                    setColor(z->parent, BLACK);
                    setColor(y, BLACK);
                    setColor(z->parent->parent, RED);
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    setColor(z->parent, BLACK);
                    setColor(z->parent->parent, RED);
                    leftRotate(z->parent->parent);
                }
            }
        }
        if (root->color == RED) {
            setColor(root, BLACK);
        }
    }

    void deleteFixup(Node *x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node *w = x->parent->right;
                if (w->color == RED) {
                    setColor(w, BLACK);
                    setColor(x->parent, RED);
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    setColor(w, RED);
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        setColor(w->left, BLACK);
                        setColor(w, RED);
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    setColor(w, x->parent->color);
                    setColor(x->parent, BLACK);
                    setColor(w->right, BLACK);
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                Node *w = x->parent->left;
                if (w->color == RED) {
                    setColor(w, BLACK);
                    setColor(x->parent, RED);
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    setColor(w, RED);
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        setColor(w->right, BLACK);
                        setColor(w, RED);
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    setColor(w, x->parent->color);
                    setColor(x->parent, BLACK);
                    setColor(w->left, BLACK);
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        setColor(x, BLACK);
    }

    void setColor(Node *node, Color newColor) {
        if (node == NIL) return;
        if (node->color == newColor) return;
        if (node->color == RED) {
            redCount--;
        } else {
            blackCount--;
        }
        node->color = newColor;
        if (newColor == RED) {
            redCount++;
        } else {
            blackCount++;
        }
    }

    Node *searchNode(int key) {
        Node *current = root;
        while (current != NIL) {
            if (key == current->key) {
                return current;
            } else if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return NIL;
    }

    Node *minimum(Node *node) {
        while (node->left != NIL) {
            node = node->left;
        }
        return node;
    }

public:
    RedBlackTree() {
        NIL = new Node(0, 0, nullptr);
        NIL->color = BLACK;
        NIL->left = NIL->right = NIL->parent = NIL;
        root = NIL;
        rotationCount = 0;
        redCount = 0;
        blackCount = 0;
    }

    void add(int k, int v) {
        Node *existing = searchNode(k);
        if (existing != NIL) {
            cout << "KEY ALREADY EXISTS" << endl;
            return;
        }

        Node *z = new Node(k, v, NIL);
        redCount++;

        Node *y = NIL;
        Node *x = root;

        while (x != NIL) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;
        if (y == NIL) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }

        insertFixup(z);
    }

    void lookup(int k) {
        Node *node = searchNode(k);
        if (node == NIL) {
            cout << "KEY NOT FOUND" << endl;
        } else {
            cout << node->value << endl;
        }
    }

    void deleteKey(int k) {
        Node *z = searchNode(k);
        if (z == NIL) {
            cout << "KEY NOT FOUND" << endl;
            return;
        }

        Node *y = z;
        Node *x;
        Color originalColor = y->color;

        if (z->left != NIL && z->right != NIL) {
            y = minimum(z->right);
            z->key = y->key;
            z->value = y->value;
            originalColor = y->color;
        }

        if (y->left != NIL) {
            x = y->left;
        } else {
            x = y->right;
        }

        x->parent = y->parent;

        if (y->parent == NIL) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }

        if (originalColor == BLACK) {
            deleteFixup(x);
        }

        if (originalColor == RED) {
            redCount--;
        } else {
            blackCount--;
        }

        delete y;
    }

    int getRotations() { return rotationCount; }
    int getBlackCount() { return blackCount; }
    int getRedCount() { return redCount; }
};

int main() {
    RedBlackTree tree;
    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        string op;
        iss >> op;

        if (op == "ADD") {
            int k, v;
            iss >> k >> v;
            tree.add(k, v);
        } else if (op == "LOOKUP") {
            int k;
            iss >> k;
            tree.lookup(k);
        } else if (op == "DELETE") {
            int k;
            iss >> k;
            tree.deleteKey(k);
        } else if (op == "PRINT_ROTATIONS") {
            cout << tree.getRotations() << endl;
        } else if (op == "PRINT_COUNT_BLACK_KEYS") {
            cout << tree.getBlackCount() << endl;
        } else if (op == "PRINT_COUNT_RED_KEYS") {
            cout << tree.getRedCount() << endl;
        }
    }

    return 0;
}