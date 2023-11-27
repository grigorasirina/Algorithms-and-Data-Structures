#include <iostream>
using namespace std;

// Stack class
class Stack {
    private:
        int top;
        int arr[5]; // Stack with capacity of 5 elements

    public:
        Stack() {
            top = -1; // Initialize top to -1 indicating an empty stack
            for (int i = 0; i < 5; i++) {
                arr[i] = 0; // Initialize stack elements to 0
            }
        }

        // Function to check if stack is empty
        bool isEmpty() {
            return top == -1;
        }

        // Function to check if stack is full
        bool isFull() {
            return top == 4; // Since the size of the stack is 5
        }

        // Function to add an element to the stack
        void push(int val) {
            if (isFull()) {
                cout << "Stack overflow" << endl;
            } else {
                top++; // Increment top
                arr[top] = val; // Add value to the stack
            }
        }

        // Function to remove the top element from the stack
        int pop() {
            if (isEmpty()) {
                cout << "Stack underflow" << endl;
                return 0;
            } else {
                int popValue = arr[top];
                arr[top] = 0; // Reset the value at top
                top--; // Decrement top
                return popValue;
            }
        }

        // Function to return the top element of the stack without removing it
        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return 0;
            } else {
                return arr[top];
            }
        }

        // Function to display all elements in the stack
        void display() {
            cout << "All values in the Stack are " << endl;
            for (int i = 4; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
};

// Main function
int main() {
    Stack s1;
    int option, value;

    do {
        cout << "What operation do you want to perform? "
             << "Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
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
                cout << "Enter an item to push in the stack:" << endl;
                cin >> value;
                s1.push(value);
                break;
            case 2:
                cout << "Pop Function Called - Popped Value: " << s1.pop() << endl;
                break;
            case 3:
                if (s1.isEmpty())
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is not Empty" << endl;
                break;
            case 4:
                if (s1.isFull())
                    cout << "Stack is Full" << endl;
                else
                    cout << "Stack is not Full" << endl;
                break;
            case 5:
                cout << "Peek Function Called - Value at the Top of the Stack is: " << s1.peek() << endl;
                break;
            case 6:
                cout << "Display Function Called - " << endl;
                s1.display();
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
