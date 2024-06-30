#include <bits/stdc++.h>
using namespace std;

// Leetcode Problem 2285: Maximum Total Importance of Roads
// Link to the question: https://leetcode.com/problems/maximum-total-importance-of-roads/description/
// Runtime: 292 ms, Beats 63.01% of C++ submissions
// Memory: 132.68 MB, Beats 60.47% of C++ submissions

class Solution
{
public:
    // Function to calculate the maximum total importance of roads
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> v(n, 0); // Initialize a vector to store the degree of each node

        // Count the number of roads connected to each node
        for (vector<int> e : roads)
        {
            v[e[0]]++; // Increment the degree of the first node in the edge
            v[e[1]]++; // Increment the degree of the second node in the edge
        }

        sort(v.begin(), v.end()); // Sort the degrees in non-decreasing order

        long long ans = 0; // Initialize the variable to store the result

        // Calculate the maximum total importance by multiplying the degree by the importance values
        for (int i = 0; i < n; i++)
            ans += (long long)(i + 1) * v[i]; // Importance values range from 1 to n

        return ans; // Return the computed maximum total importance
    }
};

// Function to print the result
void print(long long result)
{
    cout << result << endl;
}

int main()
{
    // Create an instance of the Solution class
    Solution sol;

    // Example 1
    int n1 = 5;
    vector<vector<int>> roads1 = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    // Calculate the maximum total importance for Example 1
    cout << sol.maximumImportance(n1, roads1) << endl;
    // Expected Output: 43

    // Example 2
    int n2 = 5;
    vector<vector<int>> roads2 = {{0, 3}, {2, 4}, {1, 3}};
    // Calculate the maximum total importance for Example 2
    cout << sol.maximumImportance(n2, roads2) << endl;
    // Expected Output: 13

    return 0;
}
