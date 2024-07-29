// Problem: 1395. Count Number of Teams
// Link: https://leetcode.com/problems/count-number-of-teams/
// Beats: Runtime 48 ms (Beats 48.79%), Memory 12.27 MB (Beats 30.14%)

// Time Complexity: O(n^2) - Two nested loops each iterating over n elements
// Space Complexity: O(n) - Additional space used for the four vectors to store counts

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size(), ans = 0;
        vector<int> left_smaller(n, 0), right_larger(n, 0), left_larger(n, 0), right_smaller(n, 0);

        // Loop to count left_smaller, left_larger, right_smaller, right_larger for each soldier
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j < i)
                {
                    if (rating[j] < rating[i])
                        left_smaller[i]++;
                    else
                        left_larger[i]++;
                }
                else if (j > i)
                {
                    if (rating[j] < rating[i])
                        right_smaller[i]++;
                    else
                        right_larger[i]++;
                }
            }
            // Count valid teams with soldier i as the middle soldier
            ans += left_smaller[i] * right_larger[i] + left_larger[i] * right_smaller[i];
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    vector<int> rating1 = {2, 5, 3, 4, 1};
    cout << solution.numTeams(rating1) << endl; // Output: 3

    vector<int> rating2 = {2, 1, 3};
    cout << solution.numTeams(rating2) << endl; // Output: 0

    vector<int> rating3 = {1, 2, 3, 4};
    cout << solution.numTeams(rating3) << endl; // Output: 4

    return 0;
}
