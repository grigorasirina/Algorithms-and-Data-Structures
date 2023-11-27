#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;   // Data in the node
    Node* next; // Pointer to the next node

    // Constructor to create a new node
    // next is by default initialized as nullptr
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Class for Singly Linked List
class LinkedList {
    Node* head; // Pointer to the head of the list

public:
    LinkedList() {
        head = nullptr; // Initially, the list is empty
    }

    // Function to insert a new node at the end of the list
    void append(int data) {
        Node* newNode = new Node(data);

        // If the list is empty, then make the new node as head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Else traverse till the last node
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

        // Insert the new_node at the last node
        last->next = newNode;
    }

    // Function to display the contents of the linked list
    void display() {
        Node* temp = head;

        // Traverse the list and print data of each node
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function
int main() {
    LinkedList list;

    // Append nodes to the list
    list.append(10);
    list.append(20);
    list.append(30);

    // Display the list
    cout << "Linked List: ";
    list.display();

    return 0;
}
