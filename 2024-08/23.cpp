/*
Problem: 592. Fraction Addition and Subtraction
Link: https://leetcode.com/problems/fraction-addition-and-subtraction/

Runtime: 0 ms
Beats: 100.00%
Memory: 7.93 MB
Beats: 29.46%

Time Complexity: O(n) - Where n is the length of the input string. Parsing the string and performing the addition operation is linear.
Space Complexity: O(n) - For storing the parsed fractions.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <numeric> // For std::gcd

using namespace std;

class Solution
{
public:
    // Function to parse the input string into fractions
    vector<pair<long long, long long>> parse(const string &s)
    {
        vector<pair<long long, long long>> fractions;
        stringstream ss(s);
        char sign = '+';

        while (!ss.eof())
        {
            long long numerator, denominator;
            char div;

            // Handle the sign
            if (ss.peek() == '+' || ss.peek() == '-')
            {
                ss >> sign;
            }

            // Parse numerator, division symbol, and denominator
            ss >> numerator >> div >> denominator;

            // Adjust the sign of the numerator
            if (sign == '-')
            {
                numerator = -numerator;
            }

            fractions.push_back({numerator, denominator});
        }

        return fractions;
    }

    // Function to add two fractions and return the result
    pair<long long, long long> addFractions(const pair<long long, long long> &frac1, const pair<long long, long long> &frac2)
    {
        long long commonDenominator = frac1.second * frac2.second;
        long long resultNumerator = frac1.first * frac2.second + frac2.first * frac1.second;

        // Reduce the fraction by dividing by the greatest common divisor
        long long gcdValue = gcd(resultNumerator, commonDenominator);
        resultNumerator /= gcdValue;
        commonDenominator /= gcdValue;

        return {resultNumerator, commonDenominator};
    }

    // Main function to compute the result of the fraction addition and subtraction
    string fractionAddition(string s)
    {
        vector<pair<long long, long long>> fractions = parse(s);
        pair<long long, long long> result = {0, 1}; // Start with 0/1

        // Add all fractions together
        for (const auto &frac : fractions)
        {
            result = addFractions(result, frac);
        }

        // Return the result as a string in the format "numerator/denominator"
        return to_string(result.first) + '/' + to_string(result.second);
    }
};

int main()
{
    Solution solution;

    // Example 1
    string expression1 = "-1/2+1/2";
    cout << "Result for '-1/2+1/2': " << solution.fractionAddition(expression1) << endl; // Expected output: "0/1"

    // Example 2
    string expression2 = "-1/2+1/2+1/3";
    cout << "Result for '-1/2+1/2+1/3': " << solution.fractionAddition(expression2) << endl; // Expected output: "1/3"

    // Example 3
    string expression3 = "1/3-1/2";
    cout << "Result for '1/3-1/2': " << solution.fractionAddition(expression3) << endl; // Expected output: "-1/6"

    return 0;
}
