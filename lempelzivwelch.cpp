#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// Function to perform LZW compression on a string
vector<int> LZWCompress(const string &uncompressed) {
    // Dictionary (Codebook) initialization
    int dictSize = 256;
    map<string, int> dictionary;
    for (int i = 0; i < 256; i++) {
        dictionary[string(1, i)] = i;
    }

    string w;
    vector<int> result;
    for (char c : uncompressed) {
        string wc = w + c;

        // If wc is in the dictionary, continue with the next character
        if (dictionary.count(wc)) {
            w = wc;
        } else {
            // Add wc to the dictionary and write w's dictionary code to the result
            dictionary[wc] = dictSize++;
            result.push_back(dictionary[w]);
            w = string(1, c);
        }
    }

    // Output the code for w
    if (!w.empty())
        result.push_back(dictionary[w]);

    return result;
}

// Main function
int main() {
    string uncompressed;
    cout << "Enter a string to compress: ";
    getline(cin, uncompressed);

    vector<int> compressed = LZWCompress(uncompressed);
    cout << "Compressed string: ";
    for (int code : compressed) {
        cout << code << " ";
    }
    cout << endl;

    return 0;
}
