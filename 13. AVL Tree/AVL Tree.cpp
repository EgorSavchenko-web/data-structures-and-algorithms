#include <iostream>
#include <string>

class AVLNode {
public:
    int key, value, height;
    AVLNode *left, *right;
    AVLNode(int k, int v) : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;
    int rotations;

    int getHeight(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(AVLNode* node) {
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        updateHeight(y);
        updateHeight(x);
        
        rotations++;
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        updateHeight(x);
        updateHeight(y);
        
        rotations++;
        return y;
    }

    AVLNode* insert(AVLNode* node, int key, int value, bool& exists) {
        if (!node) {
            return new AVLNode(key, value);
        }
        
        if (key == node->key) {
            exists = true;
            return node;
        }
        
        if (key < node->key) {
            node->left = insert(node->left, key, value, exists);
        } else {
            node->right = insert(node->right, key, value, exists);
        }

        if (exists) return node;

        updateHeight(node);
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }
        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }
        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* findMin(AVLNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    AVLNode* remove(AVLNode* node, int key, bool& found) {
        if (!node) {
            found = false;
            return nullptr;
        }

        if (key < node->key) {
            node->left = remove(node->left, key, found);
        } else if (key > node->key) {
            node->right = remove(node->right, key, found);
        } else {
            found = true;
            // Node with only one child or no child
            if (!node->left) {
                AVLNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                AVLNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            AVLNode* temp = findMin(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = remove(node->right, temp->key, found);
        }

        if (!found || !node) return node;

        updateHeight(node);
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }
        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }
        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    int lookup(AVLNode* node, int key, bool& found) {
        if (!node) {
            found = false;
            return 0;
        }
        if (key == node->key) {
            found = true;
            return node->value;
        }
        return key < node->key ? 
               lookup(node->left, key, found) : 
               lookup(node->right, key, found);
    }

public:
    AVLTree() : root(nullptr), rotations(0) {}

    void add(int key, int value) {
        bool exists = false;
        root = insert(root, key, value, exists);
        if (exists) {
            std::cout << "KEY ALREADY EXISTS\n";
        }
    }

    void remove(int key) {
        bool found = false;
        root = remove(root, key, found);
        if (!found) {
            std::cout << "KEY NOT FOUND\n";
        }
    }

    void lookup(int key) {
        bool found = false;
        int value = lookup(root, key, found);
        if (found) {
            std::cout << value << "\n";
        } else {
            std::cout << "KEY NOT FOUND\n";
        }
    }

    void printRotations() {
        std::cout << rotations << "\n";
    }
};

int main() {
    int n;
    std::cin >> n;
    
    AVLTree tree;
    std::string op;
    
    for (int i = 0; i < n; i++) {
        std::cin >> op;
        if (op == "ADD") {
            int k, v;
            std::cin >> k >> v;
            tree.add(k, v);
        } else if (op == "LOOKUP") {
            int k;
            std::cin >> k;
            tree.lookup(k);
        } else if (op == "DELETE") {
            int k;
            std::cin >> k;
            tree.remove(k);
        } else if (op == "PRINT_ROTATIONS") {
            tree.printRotations();
        }
    }
    
    return 0;
}