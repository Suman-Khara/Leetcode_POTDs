// Problem: 1310. XOR Queries of a Subarray
// Link: https://leetcode.com/problems/xor-queries-of-a-subarray/
// Beats: Runtime 78 ms (Beats 23.40%), Memory 45.38 MB (Beats 7.64%)

// Time Complexity: O(n + q), where n is the length of the array and q is the number of queries.
// Space Complexity: O(n), for storing the prefix XOR array.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function to compute XOR for each query
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        vector<int> prefixXOR; // Store prefix XOR values
        vector<int> result;    // To store the result of each query

        prefixXOR.push_back(0); // Initialize the prefixXOR array with 0 for easier calculations

        // Build prefix XOR array
        for (int num : arr)
        {
            prefixXOR.push_back(prefixXOR.back() ^ num); // XOR the current element with the last prefix value
        }

        // Process each query
        for (vector<int> &query : queries)
        {
            // XOR from arr[left] to arr[right] is obtained by prefixXOR[right+1] ^ prefixXOR[left]
            result.push_back(prefixXOR[query[1] + 1] ^ prefixXOR[query[0]]);
        }

        return result;
    }
};

// Main function to test the solution
int main()
{
    Solution solution;

    // Example 1
    vector<int> arr1 = {1, 3, 4, 8};
    vector<vector<int>> queries1 = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    vector<int> result1 = solution.xorQueries(arr1, queries1);

    cout << "Result for Example 1: ";
    for (int res : result1)
    {
        cout << res << " ";
    }
    cout << endl;

    // Example 2
    vector<int> arr2 = {4, 8, 2, 10};
    vector<vector<int>> queries2 = {{2, 3}, {1, 3}, {0, 0}, {0, 3}};
    vector<int> result2 = solution.xorQueries(arr2, queries2);

    cout << "Result for Example 2: ";
    for (int res : result2)
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
