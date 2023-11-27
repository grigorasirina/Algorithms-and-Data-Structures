#include <iostream>
using namespace std;

// Queue class
class Queue {
    private:
        int front;
        int rear;
        int arr[5]; // Queue with capacity of 5 elements

    public:
        Queue() {
            front = -1;
            rear = -1;
            for (int i = 0; i < 5; i++) {
                arr[i] = 0;
            }
        }

        // Function to check if queue is empty
        bool isEmpty() {
            return front == -1 && rear == -1;
        }

        // Function to check if queue is full
        bool isFull() {
            return rear == 4; // Since the size of the queue is 5
        }

        // Function to add an element to the rear of the queue
        void enqueue(int val) {
            if (isFull()) {
                cout << "Queue is full" << endl;
                return;
            } else if (isEmpty()) {
                rear = 0;
                front = 0;
            } else {
                rear++; // Increment rear
            }
            arr[rear] = val; // Add value to the queue
        }

        // Function to remove an element from the front of the queue
        int dequeue() {
            int x;
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return 0;
            } else if (front == rear) {
                x = arr[front];
                arr[front] = 0;
                rear = -1;
                front = -1;
                return x;
            } else {
                x = arr[front];
                arr[front] = 0;
                front++; // Increment front
                return x;
            }
        }

        // Function to return the element at the front of the queue
        int peek() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return 0;
            } else {
                return arr[front];
            }
        }

        // Function to display all elements in the queue
        void display() {
            cout << "All values in the Queue are " << endl;
            for (int i = 0; i < 5; i++) {
                cout << arr[i] << " ";
            }
        }
};

// Main function
int main() {
    Queue q1;
    int value, option;

    do {
        cout << "What operation do you want to perform? "
             << "Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin >> option;
        switch (option) {
            case 0:
                break;
            case 1:
                cout << "Enter an item to enqueue in the queue:" << endl;
                cin >> value;
                q1.enqueue(value);
                break;
            case 2:
                cout << "Dequeue Function Called - Dequeued Value: " << q1.dequeue() << endl;
                break;
            case 3:
                if (q1.isEmpty())
                    cout << "Queue is Empty" << endl;
                else
                    cout << "Queue is not Empty" << endl;
                break;
            case 4:
                if (q1.isFull())
                    cout << "Queue is Full" << endl;
                else
                    cout << "Queue is not Full" << endl;
                break;
            case 5:
                cout << "Peek Function Called - Value at the front of the Queue is: " << q1.peek() << endl;
                break;
            case 6:
                cout << "Display Function Called - " << endl;
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
