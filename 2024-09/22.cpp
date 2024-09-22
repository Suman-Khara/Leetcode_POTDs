// Problem: 440. K-th Smallest in Lexicographical Order
// Link: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
// Beats: 53.78% with 2 ms runtime, 54.58% with 7.44 MB memory usage

/*
Time Complexity: O(log(n)^2)
- The time complexity is dominated by the counting of steps. For each level of the tree, we are performing logarithmic operations based on the number of digits, leading to a complexity of O(log(n)^2).

Space Complexity: O(1)
- The space complexity is O(1) since we only use a constant amount of extra space for variables and computations.
*/

#include <iostream>
#include <algorithm> // for min

using namespace std;

class Solution
{
public:
    // Main function to find the k-th lexicographically smallest number in the range [1, n]
    int findKthNumber(int n, int k)
    {
        int current = 1; // Start with the smallest number in lexicographical order
        k--;             // We decrement k because we count '1' as the first number, and we already start from it

        // Loop until we have found the k-th number
        while (k > 0)
        {
            int steps = countSteps(n, current, current + 1); // Count the steps between 'current' and 'current + 1'
            if (steps <= k)
            {
                // If steps between current and next prefix are fewer or equal to k, move to the next prefix
                current++;
                k -= steps; // Subtract the steps taken
            }
            else
            {
                // If steps are greater than k, move deeper in the current prefix tree
                current *= 10; // Go to the next level of the tree (move deeper in the lexicographical order)
                k--;           // Decrease k since we've moved one step in the tree
            }
        }

        return current; // Return the k-th number
    }

private:
    // Helper function to count the number of steps between prefix1 and prefix2 in the range [1, n]
    int countSteps(int n, long prefix1, long prefix2)
    {
        int steps = 0;
        // Count how many numbers exist between prefix1 and prefix2
        while (prefix1 <= n)
        {
            steps += min((long)(n + 1), prefix2) - prefix1;
            prefix1 *= 10; // Move deeper in the tree for prefix1
            prefix2 *= 10; // Move deeper in the tree for prefix2
        }
        return steps; // Return the total number of steps
    }
};

int main()
{
    Solution solution;

    // Example 1
    int n1 = 13, k1 = 2;
    cout << "Example 1 Output: " << solution.findKthNumber(n1, k1) << endl; // Expected output: 10

    // Example 2
    int n2 = 1, k2 = 1;
    cout << "Example 2 Output: " << solution.findKthNumber(n2, k2) << endl; // Expected output: 1

    return 0;
}
