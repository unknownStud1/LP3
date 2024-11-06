#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// A Huffman tree node
struct Node {
    char data;       // Character stored in the node
    int freq;        // Frequency of the character
    Node* left;      // Left child node
    Node* right;     // Right child node

    // Constructor to initialize a node
    Node(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// Comparison object to be used to order the heap based on frequency
struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);  // Min-heap based on frequency
    }
};

// Recursive function to print the Huffman codes from the root of the Huffman tree
void printCodes(Node* root, string str) {
    if (!root) return;  // If the node is null, return

    // If this is a leaf node (character node), print the character and its code
    if (root->data != '$') {
        cout << root->data << ": " << str << "\n";
    }

    // Recur for left and right subtrees
    printCodes(root->left, str + "0");  // Add "0" for left branch
    printCodes(root->right, str + "1"); // Add "1" for right branch
}

// The main function that builds a Huffman Tree and prints the Huffman codes
void HuffmanCodes(char data[], int freq[], int size) {
    Node *left, *right, *top;

    // Create a priority queue (min-heap) and insert all characters of data[] with their frequencies
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < size; ++i) {
        minHeap.push(new Node(data[i], freq[i]));  // Insert each character as a node
    }

    // Iterate while the size of the heap doesn't become 1 (until we have only one node in the heap)
    while (minHeap.size() != 1) {
        // Extract the two nodes with the minimum frequency from the heap
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        top = new Node('$', left->freq + right->freq);  // '$' represents an internal node
        top->left = left;  // Set the left child of the internal node
        top->right = right;  // Set the right child of the internal node

        // Push the internal node back into the heap
        minHeap.push(top);
    }

    // Print Huffman codes using the Huffman tree built above
    printCodes(minHeap.top(), "");  // Start from the root of the tree
}

int main() {
    // Characters and their corresponding frequencies
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    // Call the function to generate and print Huffman codes
    HuffmanCodes(arr, freq, size);

    return 0;
}