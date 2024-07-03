// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

// Runtime: 65 ms, Beats 77.23% of C++ submissions
// Memory: 38.70 MB, Beats 50.84% of C++ submissions

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        // If there are fewer than 5 elements, we can change all of them to the same value in at most 3 moves
        if (n < 5)
            return 0;
        // Sort the array to easily access the largest and smallest elements
        sort(nums.begin(), nums.end());
        // Return the minimum difference after removing up to 3 elements from either end
        return min({nums[n - 4] - nums[0], nums[n - 3] - nums[1], nums[n - 2] - nums[2], nums[n - 1] - nums[3]});
        // cuz if any other combination is done, the distance between the smallest and largest is going to increase which will increase the difference
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {5, 3, 2, 4};
    cout << sol.minDifference(nums1) << endl; // Output: 0

    vector<int> nums2 = {1, 5, 0, 10, 14};
    cout << sol.minDifference(nums2) << endl; // Output: 1

    vector<int> nums3 = {3, 100, 20};
    cout << sol.minDifference(nums3) << endl; // Output: 0

    return 0;
}
