
#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* left;
    Node* right;
    int height;
    Node(int _value) : value(_value), left(nullptr), right(nullptr), height(1) {}
};
struct AVLTree {
    Node* head = nullptr;
    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }
    int balanceFactor(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }
    void updateHeight(Node* node) {
        if (node != nullptr) {
            updateHeight(node->left);
            updateHeight(node->right);
            node->height = 1 + max(height(node->left), height(node->right));
            if (node->left == nullptr && node->right == nullptr) {
                node->height = 1;
            }
            
        }
    }
    Node* rotateRight(Node* root) {
        Node* newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        if (root == head) {
            head = newRoot;
        }
        return newRoot;
    }
    Node* rotateLeft(Node* root) {
        Node* newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        if (root == head) {
            head = newRoot;
        }
        return newRoot;
    }
    void insert(int _value, Node* &current) {
        if (head == nullptr) {
            head = new Node(_value);
            updateHeight(head);
            return;
        }
        if (_value > current->value) {
            if (current->right == nullptr) {
                current->right = new Node(_value);
                updateHeight(head);
                return;
            }
            insert(_value, current->right);
        }
        else if (_value < current->value) {
            if (current->left == nullptr) {
                current->left = new Node(_value);
                updateHeight(head);
                return;
            }
            insert(_value, current->left);
        }
        

        int balance = balanceFactor(current);

        if (balance >= 2 && _value < current->left->value) {
            current = rotateRight(current);
            updateHeight(head);
            return;
        }
        if (balance <= -2 && _value > current->right->value) {
            current = rotateLeft(current);
            updateHeight(head);
            return;
        }

        if (balance >= 2 && _value > current->left->value) {
            current->left = rotateLeft(current->left);
            current = rotateRight(current);
            updateHeight(head);
            return;
        }

        if (balance <= -2 && _value < current->right->value) {
            current->right = rotateRight(current->right);
            current = rotateLeft(current);
            updateHeight(head);
            return;
        }
    }
    void print(Node* node) {
        if (node == NULL) { return; }
        cout << node->value << endl;
        print(node->left);
        print(node->right);
    }
    Node* minValue(Node* current) {
        Node* prev;
        while (current->left != nullptr) {
            prev = current;
            current = current->left;
            prev->left = nullptr;
        }
        return current;
    }
    //void deleteNode(int _value) {
    //    Node* current = head;
    //    Node* prev = nullptr;
    //    while (current->value != _value) {
    //        prev = current;
    //        if (_value > current->value) {
    //            current = current->right;
    //        }
    //        else {
    //            current = current->left;
    //        }
    //    }
    //    if (current->left == nullptr && current->right == nullptr) {
    //        if (current == head) {
    //            head = nullptr;
    //            return;
    //        }
    //        if (prev->left == current) {
    //            prev->left = nullptr;
    //        }
    //        else if (prev->right == current) {
    //            prev->right = nullptr;
    //        }
    //    }
    //    else if (current->left != nullptr && current->right == nullptr) {
    //        if (current == head) {
    //            head = head->left;
    //            return;
    //        }
    //        if (prev->left == current) {
    //            prev->left = current->left;
    //        }
    //        else if (prev->right == current) {
    //            prev->right = current->left;
    //        }
    //    }
    //    else if (current->right != nullptr && current->left == nullptr) {
    //        if (current == head) {
    //            head = head->right;
    //            return;
    //        }
    //        if (prev->left == current) {
    //            prev->left = current->right;
    //        }
    //        else if (prev->right == current) {
    //            prev->right = current->right;
    //        }
    //    }
    //    else {
    //        if (current == head) {
    //            Node* temp = head;
    //            head = head->right;
    //            head->left = temp->left;
    //            return;
    //        }
    //        if (prev->left == current) {
    //            prev->left = minValue(current->left);
    //            prev->left->right = current->right;
    //            //prev->left->left = current->left;
    //        }
    //        else if (prev->right == current) {
    //            prev->right = minValue(current->left);
    //            prev->right->right = current->right;
    //            //prev->right->left = current->left;

    //        }
    //    }
    //    updateHeight(head);
    //    int balance = balanceFactor(prev);

    //    if (balance >= 2 && _value < prev->left->value) {
    //        prev = rotateRight(prev);
    //        updateHeight(head);
    //        return;
    //    }
    //    if (balance <= -2 && _value > prev->right->value) {
    //        prev = rotateLeft(prev);
    //        updateHeight(head);
    //        return;
    //    }

    //    if (balance >= 2 && _value > prev->left->value) {
    //        prev->left = rotateLeft(prev->left);
    //        prev = rotateRight(prev);
    //        updateHeight(head);
    //        return;
    //    }

    //    if (balance <= -2 && _value < prev->right->value) {
    //        prev->right = rotateRight(prev->right);
    //        prev = rotateLeft(prev);
    //        updateHeight(head);
    //        return;
    //    }

    //}
};
int main()
{
    AVLTree tree;
    tree.insert(4, tree.head);
    tree.insert(5, tree.head);
    tree.insert(7, tree.head);
    tree.insert(2, tree.head);
    tree.insert(1, tree.head);
    tree.insert(3, tree.head);
    tree.insert(6, tree.head);
}

