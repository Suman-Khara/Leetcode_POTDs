// Problem: 1105. Filling Bookcase Shelves
// Link: https://leetcode.com/problems/filling-bookcase-shelves/
// Beats: Runtime 3ms (87.31%), Memory 10.96MB (63.73%)
// Time Complexity: O(n^2), Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX); // dp[i] will be the min height for first i books
        dp[0] = 0;                      // No books means no height

        // Iterate over each book
        for (int i = 1; i <= n; i++)
        {
            int currentWidth = 0, currentHeight = 0;

            // Consider placing books j to i on the same shelf
            for (int j = i - 1; j >= 0; j--)
            {
                currentWidth += books[j][0];

                // If the current shelf exceeds the shelf width, break
                if (currentWidth > shelfWidth)
                    break;

                // Update the height of the current shelf
                currentHeight = max(currentHeight, books[j][1]);

                // Update the dp value for placing the first i books
                dp[i] = min(dp[i], dp[j] + currentHeight);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> books1 = {{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
    int shelfWidth1 = 4;
    cout << "Minimum height for books1: " << solution.minHeightShelves(books1, shelfWidth1) << endl; // Output: 6

    vector<vector<int>> books2 = {{1, 3}, {2, 4}, {3, 2}};
    int shelfWidth2 = 6;
    cout << "Minimum height for books2: " << solution.minHeightShelves(books2, shelfWidth2) << endl; // Output: 4

    return 0;
}
