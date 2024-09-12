// Problem: 1684. Count the Number of Consistent Strings
// Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/
// Beats: Runtime 39 ms (Beats 87.99%), Memory 33.88 MB (Beats 87.14%)

// Time Complexity: O(n * m), where n is the number of words and m is the average length of each word. For each word, we check every character against the allowed set.
// Space Complexity: O(k), where k is the size of the `allowed` string, as we store the allowed characters in an unordered set.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // Function to count how many strings are consistent with the allowed characters
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        unordered_set<char> allowed_set(allowed.begin(), allowed.end()); // Store allowed characters in a set
        int consistent_count = 0;

        // Iterate over each word
        for (string &word : words)
        {
            bool is_consistent = true; // Assume the word is consistent initially
            // Check each character in the word
            for (char &character : word)
            {
                // If a character is not in the allowed set, mark the word as inconsistent
                if (allowed_set.count(character) == 0)
                {
                    is_consistent = false;
                    break;
                }
            }
            // If the word is consistent, increment the count
            if (is_consistent)
            {
                consistent_count++;
            }
        }

        return consistent_count; // Return the total number of consistent strings
    }
};

// Main function to test the solution
int main()
{
    Solution solution;

    // Example 1
    string allowed1 = "ab";
    vector<string> words1 = {"ad", "bd", "aaab", "baa", "badab"};
    cout << "Consistent strings count (Example 1): " << solution.countConsistentStrings(allowed1, words1) << endl;

    // Example 2
    string allowed2 = "abc";
    vector<string> words2 = {"a", "b", "c", "ab", "ac", "bc", "abc"};
    cout << "Consistent strings count (Example 2): " << solution.countConsistentStrings(allowed2, words2) << endl;

    // Example 3
    string allowed3 = "cad";
    vector<string> words3 = {"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"};
    cout << "Consistent strings count (Example 3): " << solution.countConsistentStrings(allowed3, words3) << endl;

    return 0;
}
