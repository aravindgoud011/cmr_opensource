#include <iostream>
using namespace std;

// Define the structure for a node in the binary search tree
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Class for the binary search tree
class BST {
private:
    TreeNode* root;

    // Helper function for inserting a new node
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Helper function for searching a value
    bool search(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (node->value == value) {
            return true;
        } else if (value < node->value) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    // Helper function for in-order traversal
    void inOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }

public:
    BST() : root(nullptr) {}

    // Public function to insert a new value
    void insert(int value) {
        root = insert(root, value);
    }

    // Public function to search for a value
    bool search(int value) {
        return search(root, value);
    }

    // Public function for in-order traversal
    void inOrder() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal: ";
    tree.inOrder();

    cout << "Search 30: " << (tree.search(30) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (tree.search(25) ? "Found" : "Not Found") << endl;

    return 0;
}
