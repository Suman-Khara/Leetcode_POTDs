// Problem: 2582. Pass the Pillow
// Link: https://leetcode.com/problems/pass-the-pillow/description/
// Beats: Runtime 2 ms (Beats 54.30%), Memory 7.03 MB (Beats 71.99%)

// Time Complexity: O(1)
// Space Complexity: O(1)

#include <iostream>

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        n--;              // Adjust n to make calculations easier
        int q = time / n; // Number of full cycles of passes
        int r = time % n; // Remainder passes within a cycle
        if (q % 2 == 0)
            return r + 1; // If even cycle, move forward
        else
            return n - r + 1; // If odd cycle, move backward
    }
};

int main()
{
    Solution solution;
    int n = 4;
    int time = 5;
    std::cout << "Person holding the pillow after " << time << " seconds: " << solution.passThePillow(n, time) << std::endl;

    n = 3;
    time = 2;
    std::cout << "Person holding the pillow after " << time << " seconds: " << solution.passThePillow(n, time) << std::endl;

    return 0;
}
