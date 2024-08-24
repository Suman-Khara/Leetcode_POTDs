/*
Problem: 564. Find the Closest Palindrome
Link: https://leetcode.com/problems/find-the-closest-palindrome/

Time Complexity:
- The `convert` function runs in O(d) time, where `d` is the number of digits in `x` (approximately O(log(x))).
- The `next` and `prev` functions each use binary search, which runs in O(log(x)) iterations. Each iteration calls `convert`, making the overall complexity O(log(x) * log(x)).
- The `nearestPalindromic` function calls `next` and `prev`, resulting in a final time complexity of O(log(x) * log(x)).

Space Complexity:
- The space complexity is primarily determined by the space needed to store the string representation of the number, which is O(d), where `d` is the number of digits in `x`.
- Additionally, the program uses constant extra space for variables, resulting in an overall space complexity of O(d).

Runtime: 9 ms
Beats: 5.63%
Memory: 11.42 MB
Beats: 5.63%
*/

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    // Converts the first half of the number into a palindrome by mirroring it
    long long convert(long long x)
    {
        string s = to_string(x);
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            s[n - i - 1] = s[i];
        }
        return stoll(s);
    }

    // Finds the next larger palindrome greater than x
    long long next(long long x)
    {
        long long left = x + 1, right = LLONG_MAX;
        long long ans = right;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long curr = convert(mid);
            if (curr > x)
            {
                ans = min(ans, curr);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }

    // Finds the next smaller palindrome less than x
    long long prev(long long x)
    {
        long long left = 0, right = x - 1;
        long long ans = left;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long curr = convert(mid);
            if (curr < x)
            {
                ans = max(ans, curr);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }

    // Main function to find the closest palindrome
    string nearestPalindromic(string n)
    {
        long long x = stoll(n); // Convert string to long long for easier manipulation
        long long a = next(x);  // Find the next larger palindrome
        long long b = prev(x);  // Find the next smaller palindrome

        // Special edge case for "1", where the closest palindrome is "0"
        if (x == 1)
            return "0";

        // Compare distances to x and return the closest palindrome
        if (abs(x - b) <= abs(a - x))
            return to_string(b);
        else
            return to_string(a);
    }
};

int main()
{
    Solution solution;

    // Example 1
    string n1 = "123";
    cout << "Closest palindrome to 123: " << solution.nearestPalindromic(n1) << endl; // Expected output: "121"

    // Example 2
    string n2 = "1";
    cout << "Closest palindrome to 1: " << solution.nearestPalindromic(n2) << endl; // Expected output: "0"

    return 0;
}
