#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// A utility function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic(std::string str, int size, int badchar[256]) {
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < 256; i++) {
        badchar[i] = -1;
    }

    // Fill the actual value of the last occurrence of a character
    for (i = 0; i < size; i++) {
        badchar[(int) str[i]] = i;
    }
}

/* A pattern searching function that uses the Bad Character Heuristic of the Boyer Moore Algorithm */
void search(std::string txt, std::string pat) {
    int m = pat.size();
    int n = txt.size();

    int badchar[256];

    /* Fill the bad character array by calling the preprocessing function badCharHeuristic() for given pattern */
    badCharHeuristic(pat, m, badchar);

    int s = 0;  // s is the shift of the pattern with respect to the text
    while (s <= (n - m)) {
        int j = m - 1;

        /* Keep reducing index j of the pattern while characters of the pattern and text are matching at this shift s */
        while (j >= 0 && pat[j] == txt[s + j]) {
            j--;
        }

        /* If the pattern is present at the current shift, then index j will become -1 after the above loop */
        if (j < 0) {
            std::cout << "Pattern occurs at shift = " << s << std::endl;

            /* Shift the pattern so that the next character in the text aligns with the last occurrence of it in the pattern. The condition s + m < n is necessary for the case when the pattern occurs at the end of the text */
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

        } else {
            /* Shift the pattern so that the bad character in the text aligns with the last occurrence of it in the pattern. The max function is used to make sure that we get a positive shift. We may get a negative shift if the last occurrence of the bad character in the pattern is on the right side of the current character. */
            s += max(1, j - badchar[txt[s + j]]);
        }
    }
}

int main() {
    std::string txt = "ABAAABCD";
    std::string pat = "ABC";
    search(txt, pat);
    return 0;
}
