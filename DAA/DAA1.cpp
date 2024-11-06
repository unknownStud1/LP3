#include <iostream>
// Non-recursive (iterative) implementation of Fibonacci numbers
int fibonacci_iterative(int n) {
if (n <= 0) return 0;
if (n == 1) return 1;
int a = 0, b = 1, c;
for (int i = 2; i <= n; ++i) {
c = a + b;
a = b;
b = c;
}
return b;
}
// Recursive implementation of Fibonacci numbers
int fibonacci_recursive(int n) {
if (n <= 0) return 0;
if (n == 1) return 1;
return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}
int main() {
int n = 10; // Example input
std::cout << "Iterative Fibonacci(" << n << ") = " << fibonacci_iterative(n) << std::endl;
std::cout << "Recursive Fibonacci(" << n << ") = " << fibonacci_recursive(n) << std::endl;
return 0;
}
/*
Output comments with time and space complexity analysis:
Iterative Fibonacci:
- Time Complexity: O(n)
The loop runs n-1 times, making the time complexity linear.
- Space Complexity: O(1)
Only a constant amount of space is used (variables a and b).
Recursive Fibonacci:
- Time Complexity: O(2^n)
Each call to fibonacci_recursive(n) results in two more calls until the base case is reached.
This exponential time complexity makes it inefficient for large n.
- Space Complexity: O(n)
The maximum depth of the recursion tree is n, leading to linear space complexity due to the call stack.
*/