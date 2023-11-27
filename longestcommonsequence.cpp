#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the longest common subsequence
int lcs(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> L(m + 1, vector<int>(n + 1));

    // Building the L[m][n] in bottom up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // L[m][n] contains the length of LCS for X and Y
    return L[m][n];
}

// Main function
int main() {
    string X, Y;
    cout << "Enter first sequence: ";
    cin >> X;
    cout << "Enter second sequence: ";
    cin >> Y;

    cout << "Length of LCS: " << lcs(X, Y) << endl;

    return 0;
}
