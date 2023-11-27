#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the most efficient way to multiply given sequence of matrices
int matrixChainOrder(const vector<int> &p, int n) {
    // m[i][j] represents the minimum number of scalar multiplications needed
    // to compute the matrix A[i]A[i+1]...A[j] = A[i..j]
    // The dimensions of matrix A[i] are p[i-1] x p[i]
    vector<vector<int>> m(n, vector<int>(n));

    // Cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is chain length. 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            // Find the minimum cost for all possible splits
            for (int k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    // Return the minimum cost to multiply the chain of matrices from A[1] to A[n-1]
    return m[1][n - 1];
}

// Main function
int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    n++; // Size of p should be number of matrices + 1
    vector<int> p(n);

    cout << "Enter dimensions (p0, p1, ..., p" << n - 1 << "): ";
    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << "Minimum number of multiplications is " << matrixChainOrder(p, n) << endl;

    return 0;
}
