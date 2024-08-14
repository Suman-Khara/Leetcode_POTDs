// Problem: 719. Find K-th Smallest Pair Distance
// Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
// Beats: Runtime 21 ms (Beats 25.45%), Memory 12.95 MB (Beats 25.87%)

// Time Complexity: O(n log n + n log(max_distance)), where n is the size of the nums array
// Space Complexity: O(1), as no additional space proportional to input size is used

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        // Sort the array to allow binary search on the difference
        sort(nums.begin(), nums.end());
        int low_diff = 0, high_diff = nums.back() - nums[0], n = nums.size();

        // Perform binary search on the difference
        while (low_diff <= high_diff)
        {
            int mid_diff = (low_diff + high_diff) / 2;
            int count = 0;

            // Count the number of pairs with a difference less than or equal to mid_diff
            for (int i = 0; i < n; i++)
            {
                int mini = nums[i] - mid_diff;
                int min_index = lower_bound(nums.begin(), nums.end(), mini) - nums.begin();
                count += i - min_index;
            }

            // Adjust the binary search range based on the count
            if (count < k)
                low_diff = mid_diff + 1;
            else
                high_diff = mid_diff - 1;
        }

        return low_diff;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 3, 1};
    int k1 = 1;
    cout << "Result: " << solution.smallestDistancePair(nums1, k1) << endl;

    // Example 2
    vector<int> nums2 = {1, 1, 1};
    int k2 = 2;
    cout << "Result: " << solution.smallestDistancePair(nums2, k2) << endl;

    // Example 3
    vector<int> nums3 = {1, 6, 1};
    int k3 = 3;
    cout << "Result: " << solution.smallestDistancePair(nums3, k3) << endl;

    return 0;
}
