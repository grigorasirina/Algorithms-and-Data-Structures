#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // Create a 2D vector to store the maximum value that can be obtained
    // with the given weight capacity
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Build table K[][] in a bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Base Case: If no items or no capacity, the total value is 0
            if (i == 0 || w == 0)
                K[i][w] = 0;
            // If weight of the i-th item is less than or equal to 'w'
            // consider including the i-th item in the knapsack
            else if (wt[i - 1] <= w)
                // Maximize value by either including or excluding the i-th item
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                // If the i-th item's weight is more than 'w', exclude it from the knapsack
                K[i][w] = K[i - 1][w];
        }
    }

    // Return the maximum value that can be put in a knapsack of capacity W
    return K[n][W];
}

// Main function
int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> val(n), wt(n);

    // Reading values and weights of all items
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> val[i] >> wt[i];
    }

    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    // Call the knapsack function and display the result
    cout << "Maximum value in knapsack = " << knapsack(W, wt, val, n) << endl;

    return 0;
}
