#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int countNodesWithBothChildren(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int count = 0;
    if (node->left != nullptr && node->right != nullptr) {
        count = 1;
    }

    count += countNodesWithBothChildren(node->left) + countNodesWithBothChildren(node->right);

    return count;
}

void printBinaryTree(Node* node, int level = 0) {
    if (node == nullptr) {
        return;
    }

    printBinaryTree(node->right, level + 1);

    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
    cout << node->data << endl;

    printBinaryTree(node->left, level + 1);
}

int main() {
    // Створення бінарного дерева
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->left->left = new Node(5);
    root->left->left->left->right = new Node(6);
    root->left->left->right = new Node(9);


    // Виведення бінарного дерева
    cout << "Binary Tree:" << endl;
    printBinaryTree(root);
    cout << endl;

    // Визначення кількості вузлів з обома дочірніми елементами
    int count = countNodesWithBothChildren(root);

    cout << "Count of node with both children: " << count << endl;

    return 0;
}
