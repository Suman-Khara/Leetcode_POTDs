// Problem: 179. Largest Number
// Link: https://leetcode.com/problems/largest-number/
// Beats: 93.74% with 3 ms runtime, 47.68% with 17.28 MB memory usage

/*
Time Complexity: O(n log n)
- The time complexity is dominated by the sorting of the array of numbers. Sorting the vector of strings takes O(n log n), where n is the number of elements in the input.

Space Complexity: O(n)
- The space complexity is O(n), as we are creating a vector of strings to store the integer values in string form and then concatenate them into a final result string.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort

using namespace std;

class Solution
{
public:
    // Comparator function to arrange the numbers in the desired order
    static bool compare(string &a, string &b)
    {
        // Compare the concatenated strings in both possible orders
        return a + b > b + a;
    }

    string largestNumber(vector<int> &nums)
    {
        // Convert each integer in nums to a string and store in a vector
        vector<string> numStrings;
        for (int num : nums)
            numStrings.push_back(to_string(num));

        // Sort the string vector based on the custom comparator
        sort(numStrings.begin(), numStrings.end(), compare);

        // Edge case: if the largest number is "0", the result should be "0"
        if (numStrings[0] == "0")
            return "0";

        // Concatenate all the strings to form the largest number
        string largestNum = "";
        for (string numStr : numStrings)
            largestNum += numStr;

        return largestNum;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> nums1 = {10, 2};
    cout << "Example 1 Output: " << solution.largestNumber(nums1) << endl; // Expected output: "210"

    // Example 2
    vector<int> nums2 = {3, 30, 34, 5, 9};
    cout << "Example 2 Output: " << solution.largestNumber(nums2) << endl; // Expected output: "9534330"

    return 0;
}
