#include <iostream>
#include <vector>
#include <string>

// Function to create the longest proper prefix which is also suffix array
std::vector<int> computeLPSArray(const std::string& pattern) {
    int length = 0; // length of the previous longest prefix suffix
    int i = 1;
    std::vector<int> lps(pattern.size(), 0);

    // lps[0] is always 0
    lps[0] = 0;

    // The loop calculates lps[i] for i = 1 to M-1
    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Function to implement KMP algorithm for string matching
void KMPSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> lps = computeLPSArray(pattern);
    int i = 0; // index for text[]
    int j = 0; // index for pattern[]

    while (i < text.size()) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == pattern.size()) {
            std::cout << "Found pattern at index " << i - j << std::endl;
            j = lps[j - 1];
        } else if (i < text.size() && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    KMPSearch(text, pattern);
    return 0;
}
