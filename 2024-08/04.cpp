// Problem: 1508. Range Sum of Sorted Subarray Sums
// Link: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
// Beats: Runtime 73 ms (Beats 85.84%), Memory 11.22 MB (Beats 84.72%)

// Time Complexity: O(n^2 log n), where n is the length of the nums array
// Space Complexity: O(n^2), for storing all possible subarray sums in the priority queue

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Push initial elements into the heap
        for (int i = 0; i < n; i++)
        {
            minHeap.push({nums[i], i});
        }

        int result = 0;
        int mod = 1e9 + 7;
        int current = 1;

        // Process the heap
        while (!minHeap.empty())
        {
            auto [sum, index] = minHeap.top();
            minHeap.pop();

            if (current >= left)
            {
                result = (result + sum) % mod;
            }

            // Push the next subarray sum into the heap if possible
            if (index < n - 1)
            {
                sum += nums[index + 1];
                minHeap.push({sum, index + 1});
            }

            if (current >= right)
            {
                break;
            }
            current++;
        }

        return result;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 2, 3, 4};
    int n1 = 4, left1 = 1, right1 = 5;
    cout << "Result: " << solution.rangeSum(nums1, n1, left1, right1) << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4};
    int n2 = 4, left2 = 3, right2 = 4;
    cout << "Result: " << solution.rangeSum(nums2, n2, left2, right2) << endl;

    // Example 3
    vector<int> nums3 = {1, 2, 3, 4};
    int n3 = 4, left3 = 1, right3 = 10;
    cout << "Result: " << solution.rangeSum(nums3, n3, left3, right3) << endl;

    return 0;
}
