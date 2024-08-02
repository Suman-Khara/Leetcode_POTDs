// Problem: 2134. Minimum Swaps to Group All 1's Together II
// Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
// Beats: Runtime 73 ms (Beats 35.76%), Memory 83.15 MB (Beats 47.74%)

// Time Complexity: O(n), where n is the length of the nums array
// Space Complexity: O(1), as we use a constant amount of extra space

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        int totalOnes = count(nums.begin(), nums.end(), 1);

        // If no ones or all ones, no swaps needed
        if (totalOnes == 0 || totalOnes == n)
            return 0;

        // Calculate initial zero count in the first window of size totalOnes
        int zeroCount = 0;
        for (int i = 0; i < totalOnes; ++i)
        {
            if (nums[i] == 0)
                ++zeroCount;
        }

        int minSwaps = zeroCount;

        // Sliding window over circular array
        for (int i = 1; i < n; ++i)
        {
            if (nums[(i + totalOnes - 1) % n] == 0)
                ++zeroCount;
            if (nums[i - 1] == 0)
                --zeroCount;
            minSwaps = min(minSwaps, zeroCount);
        }

        return minSwaps;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> nums1 = {0, 1, 0, 1, 1, 0, 0};
    cout << "Minimum swaps needed: " << solution.minSwaps(nums1) << endl;

    // Example 2
    vector<int> nums2 = {0, 1, 1, 1, 0, 0, 1, 1, 0};
    cout << "Minimum swaps needed: " << solution.minSwaps(nums2) << endl;

    // Example 3
    vector<int> nums3 = {1, 1, 0, 0, 1};
    cout << "Minimum swaps needed: " << solution.minSwaps(nums3) << endl;

    return 0;
}
