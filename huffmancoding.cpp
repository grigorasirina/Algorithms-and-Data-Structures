#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

// A Tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq, Node* left = nullptr, Node* right = nullptr) 
        : ch(ch), freq(freq), left(left), right(right) {}
};

// For comparison of two heap nodes (needed in min heap)
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print the Huffman code of each character of a string
void printCodes(struct Node* root, string str) {
    if (!root)
        return;

    if (root->ch != '$') {
        cout << root->ch << ": " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Main function to build the Huffman Tree and print the codes
void HuffmanCodes(string text) {
    // Count frequency of appearance of each character
    map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a min heap & insert all characters of the input text
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (auto pair : freq) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
        // Extract the two minimum freq items from min heap
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        // Create a new internal node with these two nodes as children
        // and with frequency equal to the sum of the two nodes' frequencies.
        // Add this node to the min heap
        Node *top = new Node('$', left->freq + right->freq, left, right);
        minHeap.push(top);
    }

    // Print Huffman codes using the Huffman tree built above
    printCodes(minHeap.top(), "");
}

// Driver program to test the above functions
int main() {
    string text = "Huffman coding algorithm";
    cout << "Character With Its Huffman Code:\n";
    HuffmanCodes(text);

    return 0;
}
