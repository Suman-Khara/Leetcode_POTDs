/*
Problem: 1140. Stone Game II
Link: https://leetcode.com/problems/stone-game-ii/

Runtime: 26 ms
Beats: 49.38%
Memory: 15.55 MB
Beats: 45.59%

Time Complexity: O(n^3) - The recursive calls involve looping over the possible moves with memoization.
Space Complexity: O(n^2) - The DP table stores intermediate results for 2 players and multiple states.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Recursive function to calculate maximum stones Alice can get
    int getMaxStones(int turn, int index, int m, vector<vector<vector<int>>> &dp, vector<int> &suffixSum)
    {
        int n = suffixSum.size() - 1;
        if (index >= n)
            return 0; // No more stones left

        // If already computed, return the stored result
        if (dp[turn][index][m] != 0)
            return dp[turn][index][m];

        int maxStones = 0;

        // Try taking all possible X piles where 1 <= X <= 2M
        for (int x = 1; x <= 2 * m && index + x <= n; x++)
        {
            int currentIdx = index + x - 1;
            int sum = suffixSum[index] - suffixSum[currentIdx + 1];
            maxStones = max(maxStones, suffixSum[index] - getMaxStones(1 - turn, currentIdx + 1, max(m, x), dp, suffixSum));
        }

        // Store and return the result
        return dp[turn][index][m] = maxStones;
    }

    // Main function to solve the problem
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n + 1, 0))); // DP table
        vector<int> suffixSum(n + 1, 0);                                                  // suffix sum array to hold cumulative sums

        // Calculate suffix sums
        for (int i = n - 1; i >= 0; i--)
        {
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }

        // Call the recursive function starting from Alice's turn, index 0, and M = 1
        return getMaxStones(0, 0, 1, dp, suffixSum);
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> piles1 = {2, 7, 9, 4, 4};
    cout << "Maximum stones Alice can get (Example 1): " << solution.stoneGameII(piles1) << endl; // Expected output: 10

    // Example 2
    vector<int> piles2 = {1, 2, 3, 4, 5, 100};
    cout << "Maximum stones Alice can get (Example 2): " << solution.stoneGameII(piles2) << endl; // Expected output: 104

    return 0;
}
