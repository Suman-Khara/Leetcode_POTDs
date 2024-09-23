// Problem: 2707. Extra Characters in a String
// Link: https://leetcode.com/problems/extra-characters-in-a-string/
// Beats: 40.37% with 157 ms runtime, 52.70% with 86.83 MB memory usage

/*
Time Complexity: O(n * m), where n is the length of the string s, and m is the average length of words in the dictionary. For each position in the string, we check all possible substrings and whether they are present in the dictionary.

Space Complexity: O(n), where n is the length of the string s. We use a DP array of size n+1 to store intermediate results.

Explanation:
- We use dynamic programming to find the minimum number of extra characters in string s.
- We initialize a dp array of size n+1, where dp[i] represents the minimum extra characters if we start considering the string from index i onwards.
- For each position in the string, we try to match all possible substrings with words in the dictionary and update dp accordingly.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        unordered_set<string> dict(dictionary.begin(), dictionary.end()); // Convert dictionary into a set for O(1) lookup
        int n = s.size();
        vector<int> dp(n + 1, 0); // DP array, dp[i] will store the minimum number of extra characters from index i to end

        // Process the string from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = dp[i + 1] + 1; // Initialize with assuming current character is extra
            for (int j = i; j < n; j++)
            {
                string curr = s.substr(i, j - i + 1); // Extract substring from i to j
                if (dict.count(curr))                 // Check if substring is in the dictionary
                    dp[i] = min(dp[i], dp[j + 1]);    // Update dp[i] with the minimum
            }
        }
        return dp[0]; // Return the result stored at dp[0] which is the final answer
    }
};

int main()
{
    Solution solution;

    // Example 1
    string s1 = "leetscode";
    vector<string> dictionary1 = {"leet", "code", "leetcode"};
    cout << "Example 1 Output: " << solution.minExtraChar(s1, dictionary1) << endl;
    // Expected Output: 1

    // Example 2
    string s2 = "sayhelloworld";
    vector<string> dictionary2 = {"hello", "world"};
    cout << "Example 2 Output: " << solution.minExtraChar(s2, dictionary2) << endl;
    // Expected Output: 3

    return 0;
}
