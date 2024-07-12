// Problem: 1717. Maximum Score From Removing Substrings
// Link: https://leetcode.com/problems/maximum-score-from-removing-substrings/description/
// Beats: Runtime 92 ms (Beats 50.81%), Memory 25.97 MB (Beats 38.62%)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        string first, second;
        if (x > y)
        {
            first = "ab";
            second = "ba";
        }
        else
        {
            first = "ba";
            second = "ab";
        }
        int ans = 0, maxi = max(x, y), mini = min(x, y);
        string middle = "";
        for (char c : s)
        {
            if (c == first[1] && !middle.empty() && middle.back() == first[0])
            {
                middle.pop_back(); // Remove the last character if it forms the substring first
                ans += maxi;       // Add the corresponding points
            }
            else
            {
                middle.push_back(c); // Otherwise, add the character to middle
            }
        }
        string result = "";
        for (char c : middle)
        {
            if (c == second[1] && !result.empty() && result.back() == second[0])
            {
                result.pop_back(); // Remove the last character if it forms the substring second
                ans += mini;       // Add the corresponding points
            }
            else
            {
                result.push_back(c); // Otherwise, add the character to result
            }
        }
        return ans; // Return the total points gained
    }
};

int main()
{
    Solution solution;

    string s1 = "cdbcbbaaabab";
    int x1 = 4, y1 = 5;
    cout << "Output: " << solution.maximumGain(s1, x1, y1) << endl; // Expected: 19

    string s2 = "aabbaaxybbaabb";
    int x2 = 5, y2 = 4;
    cout << "Output: " << solution.maximumGain(s2, x2, y2) << endl; // Expected: 20

    return 0;
}
