#include <iostream>
using namespace std;

// Node structure for the Binary Search Tree
struct Node {
    int data;
    Node* left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Class for Binary Search Tree
class BinarySearchTree {
    Node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Function to insert a new node
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Function to find the smallest element in the BST
    int findSmallest() {
        Node* current = root;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current->data;
    }

    // Function to find the largest element in the BST
    int findLargest() {
        Node* current = root;
        while (current && current->right != nullptr) {
            current = current->right;
        }
        return current->data;
    }

    // Function to find a larger element than a given number
    int findLarger(int value) {
        return findLargerRec(root, value);
    }

    // Function to find a smaller element than a given number
    int findSmaller(int value) {
        return findSmallerRec(root, value);
    }

    // Function to find the average of tree
    double findAverage() {
        int sum = 0;
        int count = 0;
        findSumAndCount(root, sum, count);
        return count == 0 ? 0 : static_cast<double>(sum) / count;
    }

    // Function to find the average of all elements smaller than a given number
    double findAverageSmaller(int value) {
        int sum = 0;
        int count = 0;
        findSumAndCountSmaller(root, value, sum, count);
        return count == 0 ? 0 : static_cast<double>(sum) / count;
    }

    // Function to find the average of all elements larger than a given number
    double findAverageLarger(int value) {
        int sum = 0;
        int count = 0;
        findSumAndCountLarger(root, value, sum, count);
        return count == 0 ? 0 : static_cast<double>(sum) / count;
    }

    int findLargerRec(Node* node, int value) {
    if (node == nullptr) {
        return -1; // Return -1 if no larger element is found
    }

    if (node->data > value) {
        // Check in the left subtree if a smaller value can be found
        int left = findLargerRec(node->left, value);
        return (left > value) ? left : node->data;
    }

    // Else, go to the right subtree
    return findLargerRec(node->right, value);
    }

    int findSmallerRec(Node* node, int value) {
    if (node == nullptr) {
        return -1; // Return -1 if no smaller element is found
    }

    if (node->data < value) {
        // Check in the right subtree if a larger value can be found
        int right = findSmallerRec(node->right, value);
        return (right < value && right != -1) ? right : node->data;
    }

    // Else, go to the left subtree
    return findSmallerRec(node->left, value);
    }

    void findSumAndCount(Node* node, int& sum, int& count) {
    if (node == nullptr) {
        return;
    }

    sum += node->data; // Add node's data to sum
    count++; // Increment count

    // Recurse on both subtrees
    findSumAndCount(node->left, sum, count);
    findSumAndCount(node->right, sum, count);
    }

    void findSumAndCountSmaller(Node* node, int value, int& sum, int& count) {
    if (node == nullptr) {
        return;
    }

    if (node->data < value) {
        sum += node->data; // Add node's data to sum
        count++; // Increment count

        // Recurse on both subtrees
        findSumAndCountSmaller(node->left, value, sum, count);
        findSumAndCountSmaller(node->right, value, sum, count);
    } else {
        // Recurse on the left subtree
        findSumAndCountSmaller(node->left, value, sum, count);
    }
    }

    void findSumAndCountLarger(Node* node, int value, int& sum, int& count) {
    if (node == nullptr) {
        return;
    }

    if (node->data > value) {
        sum += node->data; // Add node's data to sum
        count++; // Increment count

        // Recurse on both subtrees
        findSumAndCountLarger(node->left, value, sum, count);
        findSumAndCountLarger(node->right, value, sum, count);
    } else {
        // Recurse on the right subtree
        findSumAndCountLarger(node->right, value, sum, count);
    }
    }




private:
    // Helper function to insert a node
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

};

// Main function to test the BST implementation
int main() {
    BinarySearchTree bst;
    // Insert elements into the BST
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(35);

    // Test the functions
    cout << "Smallest Element: " << bst.findSmallest() << endl;
    cout << "Largest Element: " << bst.findLargest() << endl;
    cout << "Larger than 15: " << bst.findLarger(15) << endl;
    cout << "Smaller than 25: " << bst.findSmaller(25) << endl;
    cout << "Average of Tree: " << bst.findAverage() << endl;
    cout << "Average smaller than 25: " << bst.findAverageSmaller(25) << endl;
    cout << "Average larger than 15: " << bst.findAverageLarger(15) << endl;

    return 0;
}
