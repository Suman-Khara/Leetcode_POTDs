// Problem: 2028. Find Missing Observations
// Link: https://leetcode.com/problems/find-missing-observations/
// Beats 50.00% with 100 ms runtime, 69.12% with 116.40 MB memory usage

/*
Time Complexity:
1. Finding the total sum requires iterating over the `rolls` array: O(m), where m is the length of `rolls`.
2. The loop that distributes the missing values runs for n iterations.
3. Hence, the overall time complexity is O(m + n).

Space Complexity:
1. The primary space used is for storing the result array `ans`, which requires O(n) space.
2. The input array `rolls` does not require additional space since it's read-only.
3. Thus, the overall space complexity is O(n).
*/

#include <iostream>
#include <vector>
#include <numeric>   // for accumulate
#include <algorithm> // for min

using namespace std;

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        // Calculate the sum of all n + m rolls
        int totalSum = mean * (n + rolls.size());

        // Find the sum of the rolls that are known
        int currentSum = accumulate(rolls.begin(), rolls.end(), 0);

        // The sum we need to get from the missing rolls
        int missingSum = totalSum - currentSum;

        // Check if the missingSum is achievable within the constraints
        if (missingSum < n || missingSum > 6 * n)
            return {}; // Impossible case, return an empty vector

        vector<int> missingRolls(n);

        // Distribute the missing sum into the n missing rolls
        for (int i = 0; i < n; i++)
        {
            // Ensure each missing roll is between 1 and 6
            int value = min(6, missingSum - (n - i - 1));
            missingRolls[i] = value;
            missingSum -= value; // Update the remaining sum
        }

        return missingRolls;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> rolls1 = {3, 2, 4, 3};
    int mean1 = 4, n1 = 2;
    vector<int> result1 = solution.missingRolls(rolls1, mean1, n1);
    for (int r : result1)
        cout << r << " "; // Expected output: [6, 6]
    cout << endl;

    // Test case 2
    vector<int> rolls2 = {1, 5, 6};
    int mean2 = 3, n2 = 4;
    vector<int> result2 = solution.missingRolls(rolls2, mean2, n2);
    for (int r : result2)
        cout << r << " "; // Expected output: [2, 3, 2, 2]
    cout << endl;

    // Test case 3
    vector<int> rolls3 = {1, 2, 3, 4};
    int mean3 = 6, n3 = 4;
    vector<int> result3 = solution.missingRolls(rolls3, mean3, n3);
    for (int r : result3)
        cout << r << " "; // Expected output: [] (empty array)
    cout << endl;

    return 0;
}
