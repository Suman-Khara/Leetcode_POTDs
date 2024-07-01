#include <vector>
#include <iostream>
using namespace std;

// Leetcode Problem 1550: Three Consecutive Odds
// Link to the question: https://leetcode.com/problems/three-consecutive-odds/description/
// Runtime: 0 ms, Beats 100.00% of C++ submissions
// Memory: 10.37 MB, Beats 99.07% of C++ submissions

class Solution
{
public:
    // Function to check if there are three consecutive odd numbers in the array
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int n = arr.size(); // Get the size of the array
        for (int i = 2; i < n; i++)
        {                            // Loop through the array starting from the third element
            if (arr[i] % 2 == 0)     // Check if the current element is even
                continue;            // If even, skip to the next iteration
            if (arr[i - 1] % 2 == 0) // Check if the previous element is even
                continue;            // If even, skip to the next iteration
            if (arr[i - 2] % 2 == 0) // Check if the element before the previous one is even
                continue;            // If even, skip to the next iteration
            return true;             // If all three elements are odd, return true
        }
        return false; // If no three consecutive odd numbers are found, return false
    }
};

// Main function to test the solution
int main()
{
    Solution sol;

    // Example 1
    vector<int> arr1 = {2, 6, 4, 1};
    cout << sol.threeConsecutiveOdds(arr1) << endl; // Output: false

    // Example 2
    vector<int> arr2 = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    cout << sol.threeConsecutiveOdds(arr2) << endl; // Output: true

    return 0;
}
