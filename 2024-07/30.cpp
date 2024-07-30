// Problem: 1653. Minimum Deletions to Make String Balanced
// Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Beats: Runtime 105ms (38.76%), Memory 24.51MB (54.55%)
// Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        stack<char> charStack; // Stack to track characters
        int deletionCount = 0; // Count of deletions needed

        // Iterate over each character in the string
        for (char ch : s)
        {
            // If the stack is empty, push the current character
            if (charStack.empty())
            {
                charStack.push(ch);
            }
            // If top of stack is 'b' and current character is 'a', we need a deletion
            else if (charStack.top() == 'b' && ch == 'a')
            {
                charStack.pop();
                deletionCount++;
            }
            // Otherwise, push the current character onto the stack
            else
            {
                charStack.push(ch);
            }
        }

        return deletionCount;
    }
};

int main()
{
    Solution solution;

    string s1 = "aababbab";
    cout << "Minimum deletions for \"" << s1 << "\": " << solution.minimumDeletions(s1) << endl; // Output: 2

    string s2 = "bbaaaaabb";
    cout << "Minimum deletions for \"" << s2 << "\": " << solution.minimumDeletions(s2) << endl; // Output: 2

    return 0;
}
