#include <iostream>
#include <string>
using namespace std;

// Function to perform Run-Length Encoding on a string
string runLengthEncode(string str) {
    string encoded = "";
    int n = str.length();

    // Iterate through the characters in the string
    for (int i = 0; i < n; i++) {
        // Count occurrences of the current character
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // Append the current character and its count to the result
        encoded += str[i];
        encoded += to_string(count);
    }

    return encoded;
}

// Main function
int main() {
    string str;
    cout << "Enter a string to encode: ";
    cin >> str;

    string encodedString = runLengthEncode(str);
    cout << "Encoded string: " << encodedString << endl;

    return 0;
}
