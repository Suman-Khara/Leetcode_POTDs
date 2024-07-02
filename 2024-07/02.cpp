#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Leetcode Problem 350: Intersection of Two Arrays II
// Link to the question: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
// Runtime: 8 ms, Beats 19.74% of C++ submissions
// Memory: 13.56 MB, Beats 34.02% of C++ submissions

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> m; // Create a hash map to count the frequency of elements in nums1
        for (int i : nums1)
            m[i]++; // Increment the count for each element in nums1

        vector<int> ans; // Initialize the result vector
        for (int i : nums2)
        {
            // If the element is in the hash map and its count is positive
            if (m.find(i) != m.end() && m[i] > 0)
            {
                ans.push_back(i); // Add the element to the result vector
                m[i]--;           // Decrement the count of the element
            }
        }
        return ans; // Return the result vector
    }
};

// Main function to test the Solution class
int main()
{
    Solution sol;

    // Example 1
    vector<int> nums1_1 = {1, 2, 2, 1};
    vector<int> nums2_1 = {2, 2};
    vector<int> result1 = sol.intersect(nums1_1, nums2_1);
    for (int num : result1)
        cout << num << " ";
    cout << endl; // Expected output: 2 2

    // Example 2
    vector<int> nums1_2 = {4, 9, 5};
    vector<int> nums2_2 = {9, 4, 9, 8, 4};
    vector<int> result2 = sol.intersect(nums1_2, nums2_2);
    for (int num : result2)
        cout << num << " ";
    cout << endl; // Expected output: 4 9 or 9 4

    return 0;
}
