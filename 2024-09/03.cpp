// Problem: 1945. Sum of Digits of String After Convert
// Link: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
// Beats 100.00% with 0 ms runtime, 77.66% with 7.94 MB memory usage

/*
Time Complexity:
1. Conversion of the string to initialSum: O(n), where n is the length of the string s.
   - Each character in the string is processed to get its corresponding numeric value.
   - The numeric value is then broken down into its digits to be added to initialSum.
2. Digit Sum Transformation: O(log(initialSum)) per transformation.
   - The sum of the digits of a number with d digits requires O(d) operations, where d = log(initialSum).
   - The maximum number of transformations is effectively bounded by 4, making the overall time complexity for this step constant, O(1).

Thus, the total time complexity is O(n) + O(1) ≈ O(n).

Space Complexity:
1. The algorithm uses a constant amount of space for variables: O(1).
2. The space required does not depend on the input size, making it O(1).
*/

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // Helper function to perform the digit sum transformation.
    int digitSum(int num, int remainingTransforms)
    {
        // Base case: If only one transform remains or the number is a single digit, return it.
        if (remainingTransforms == 1 || num < 10)
            return num;

        int sum = 0;
        // Calculate the sum of digits of the current number.
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        // Recur with the reduced sum and decreased transform count.
        return digitSum(sum, remainingTransforms - 1);
    }

    int getLucky(string s, int k)
    {
        int initialSum = 0;

        // Convert the string to its numerical representation by summing digit values.
        for (char c : s)
        {
            int value = c - 'a' + 1; // Calculate position in alphabet (a=1, b=2, ..., z=26)
            while (value > 0)
            {
                initialSum += value % 10; // Add digits of the value to initialSum
                value /= 10;
            }
        }
        // Apply the digit sum transformation k times (or until the sum is a single digit).
        return digitSum(initialSum, k);
    }
};

int main()
{
    Solution solution;

    // Test case 1
    string s1 = "iiii";
    int k1 = 1;
    cout << solution.getLucky(s1, k1) << endl; // Expected output: 36

    // Test case 2
    string s2 = "leetcode";
    int k2 = 2;
    cout << solution.getLucky(s2, k2) << endl; // Expected output: 6

    // Test case 3
    string s3 = "zbax";
    int k3 = 2;
    cout << solution.getLucky(s3, k3) << endl; // Expected output: 8

    return 0;
}
