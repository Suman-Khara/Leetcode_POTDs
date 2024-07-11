// Problem: 1190. Reverse Substrings Between Each Pair of Parentheses
// Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
// Beats: Runtime 3 ms (Beats 49.64%), Memory 7.68 MB (Beats 60.32%)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<int> st;
        string ans = "";
        for (int i = 0; s[i] != '\0'; ++i)
        {
            if (s[i] == '(')
            {
                st.push(ans.size()); // Push the current length of ans to mark the start of a substring
            }
            else if (s[i] == ')')
            {
                int start = st.top(); // Get the start index of the substring to reverse
                st.pop();
                reverse(ans.begin() + start, ans.end()); // Reverse the substring
            }
            else
            {
                ans += s[i]; // Append the current character to ans
            }
        }
        return ans; // Return the final result without any parentheses
    }
};

int main()
{
    Solution solution;

    string s1 = "(abcd)";
    cout << "Output: " << solution.reverseParentheses(s1) << endl; // Expected: "dcba"

    string s2 = "(u(love)i)";
    cout << "Output: " << solution.reverseParentheses(s2) << endl; // Expected: "iloveu"

    string s3 = "(ed(et(oc))el)";
    cout << "Output: " << solution.reverseParentheses(s3) << endl; // Expected: "leetcode"

    return 0;
}
