/*
Problem: Ugly Number II
Link: https://leetcode.com/problems/ugly-number-ii/

Runtime: 71 ms
Beats: 31.88%
Memory: 31.84 MB
Beats: 24.77%

Time Complexity: O(n * log(n)) - The set operations (insert and erase) are O(log n) and we perform them n times.
Space Complexity: O(n) - Space used by the set to store up to n numbers.
*/

#include <set>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        set<long long> s;  // Set to maintain unique ugly numbers in sorted order
        s.insert(1);       // The first ugly number is 1
        long long ans = 1; // Variable to store the nth ugly number

        // Generate the first n ugly numbers
        for (int i = 0; i < n; i++)
        {
            ans = *s.begin();   // Get the smallest number in the set
            s.erase(s.begin()); // Remove it from the set

            // Insert the next potential ugly numbers derived from the current smallest number
            s.insert(ans * 2);
            s.insert(ans * 3);
            s.insert(ans * 5);
        }

        return (int)ans; // Return the nth ugly number
    }
};
