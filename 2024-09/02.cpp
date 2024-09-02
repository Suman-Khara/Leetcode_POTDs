/*
Problem: 1894. Find the Student that Will Replace the Chalk
Link: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

Time Complexity:
- The time complexity is O(n) where n is the number of students. This is because we iterate through the `chalk` array twice: once to calculate the total sum and once to find the student who needs to replace the chalk.

Space Complexity:
- The space complexity is O(1) as we are using a constant amount of extra space.

Runtime: 84 ms
Beats: 90.07%
Memory: 77.04 MB
Beats: 18.08%
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        // Calculate the total amount of chalk used in one full round
        long long total_chalk = accumulate(chalk.begin(), chalk.end(), 0LL);

        // Reduce k by the total chalk used in full rounds
        k %= total_chalk;

        // Iterate through the students and find who will replace the chalk
        for (int i = 0; i < chalk.size(); i++)
        {
            // If current student can't use their chalk, they will replace it
            if (chalk[i] > k)
                return i;
            // Otherwise, decrease k by the amount of chalk this student used
            k -= chalk[i];
        }

        // This point should never be reached because the loop guarantees a return
        return -1;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> chalk1 = {5, 1, 5};
    int k1 = 22;
    cout << "Student to replace chalk in example 1: " << solution.chalkReplacer(chalk1, k1) << endl; // Expected output: 0

    // Example 2
    vector<int> chalk2 = {3, 4, 1, 2};
    int k2 = 25;
    cout << "Student to replace chalk in example 2: " << solution.chalkReplacer(chalk2, k2) << endl; // Expected output: 1

    return 0;
}
