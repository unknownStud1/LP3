#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve the 0-1 Knapsack problem
pair<int, vector<int>> knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = values.size();
    
    // Create a DP table with (n+1) rows and (capacity+1) columns
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Building the DP table
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            // Check if the current item can be included in the knapsack
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Retrieving the selected items
    vector<int> selected_items;
    int total_value = dp[n][capacity];
    int w = capacity;
    for (int i = n; i > 0 && total_value > 0; --i) {
        // If the current item was included in the optimal solution
        if (dp[i][w] != dp[i - 1][w]) {
            selected_items.push_back(i - 1);  // Store the index of the item
            total_value -= values[i - 1];     // Reduce the total value
            w -= weights[i - 1];              // Reduce the weight capacity
        }
    }

    // Reverse the order of the selected items (to display them in increasing order of their index)
    reverse(selected_items.begin(), selected_items.end());
    
    return make_pair(dp[n][capacity], selected_items);
}

int main() {
    // Example weights and values for the knapsack problem
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int capacity = 50;

    // Call the knapsack function to get the result
    pair<int, vector<int>> result = knapsack(weights, values, capacity);

    // Output the maximum value and the selected items
    cout << "Maximum value: " << result.first << endl;  // Output: Maximum value: 220
    cout << "Selected items: ";
    for (int item : result.second) {
        cout << item << " ";  // Output: Selected items: 1 2
    }
    cout << endl;

    return 0;
}