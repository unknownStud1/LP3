#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure to represent an item
struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;  // Sorting in descending order of value-to-weight ratio
}

// Function to get the maximum value in the knapsack
double fractionalKnapsack(vector<Item> items, int capacity) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0; // Total value in knapsack
    for (Item item : items) {
        if (capacity >= item.weight) {
            // If item can be added completely
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            // If item can be added partially
            totalValue += item.value * ((double)capacity / item.weight);
            break; // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };
    int capacity = 50;

    double maxValue = fractionalKnapsack(items, capacity);
    cout << "Maximum value in the knapsack: " << maxValue << endl; // Output: 240.0

    return 0;
}