// Problem: 386. Lexicographical Numbers
// Link: https://leetcode.com/problems/lexicographical-numbers/
// Beats: 80.49% with 5 ms runtime, 48.33% with 14.10 MB memory usage

/*
Time Complexity: O(n)
- We generate each number from 1 to n in lexicographical order recursively, where each number is visited once, giving O(n) time complexity.

Space Complexity: O(1) (extra space)
- We use O(1) extra space apart from the output vector, as we don't utilize any extra data structures that scale with n.

Explanation:
- The recursive function generates numbers by starting from 1 and exploring deeper into each number's children in the lexicographical tree.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Helper function to perform a depth-first search to generate lexicographically sorted numbers
    void generateNumbers(int n, int current, vector<int> &result)
    {
        if (n < current)
            return;                                  // If the current number exceeds n, stop recursion
        result.push_back(current);                   // Add the current number to the result
        generateNumbers(n, current * 10, result);    // Explore numbers in the next level (current * 10)
        if (current % 10 < 9)                        // Ensure we only increment numbers that don't end in 9
            generateNumbers(n, current + 1, result); // Explore numbers by incrementing the last digit
    }

    vector<int> lexicalOrder(int n)
    {
        vector<int> result;
        generateNumbers(n, 1, result); // Start generating numbers from 1
        return result;
    }
};

int main()
{
    Solution solution;

    // Example 1
    int n1 = 13;
    vector<int> result1 = solution.lexicalOrder(n1);
    cout << "Example 1 Output: ";
    for (int num : result1)
    {
        cout << num << " "; // Expected output: [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]
    }
    cout << endl;

    // Example 2
    int n2 = 2;
    vector<int> result2 = solution.lexicalOrder(n2);
    cout << "Example 2 Output: ";
    for (int num : result2)
    {
        cout << num << " "; // Expected output: [1, 2]
    }
    cout << endl;

    return 0;
}
