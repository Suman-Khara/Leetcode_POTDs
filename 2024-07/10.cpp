// Problem: 1598. Crawler Log Folder
// Link: https://leetcode.com/problems/crawler-log-folder/description/
// Beats: Runtime 3 ms (Beats 86.11%), Memory 13.87 MB (Beats 84.88%)

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int depth = 0;
        for (string &log : logs)
        {
            if (log == "./")
            {
                continue; // Remain in the same folder
            }
            else if (log == "../")
            {
                depth = max(0, depth - 1); // Move to the parent folder
            }
            else
            {
                depth++; // Move to a child folder
            }
        }
        return depth;
    }
};

int main()
{
    Solution solution;

    vector<string> logs1 = {"d1/", "d2/", "../", "d21/", "./"};
    cout << "Minimum operations to return to main folder: " << solution.minOperations(logs1) << endl;

    vector<string> logs2 = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    cout << "Minimum operations to return to main folder: " << solution.minOperations(logs2) << endl;

    vector<string> logs3 = {"d1/", "../", "../", "../"};
    cout << "Minimum operations to return to main folder: " << solution.minOperations(logs3) << endl;

    return 0;
}
