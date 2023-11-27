#include <iostream>
using namespace std;

// Node structure for a doubly linked list
struct Node {
    int data;     // Data in the node
    Node* prev;   // Pointer to the previous node
    Node* next;   // Pointer to the next node

    // Constructor to create a new node
    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

// Class for Doubly Linked List
class DoublyLinkedList {
    Node* head; // Pointer to the head of the list

public:
    DoublyLinkedList() {
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

        // Else traverse to the last node
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

        // Insert the new node at the end and set its previous pointer
        last->next = newNode;
        newNode->prev = last;
    }

    // Function to display the contents of the linked list
    void display() {
        Node* temp = head;

        // Traverse the list and print data of each node
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function
int main() {
    DoublyLinkedList list;

    // Append nodes to the list
    list.append(10);
    list.append(20);
    list.append(30);

    // Display the list
    list.display();

    return 0;
}
