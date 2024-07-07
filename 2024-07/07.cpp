// Problem: 1518. Water Bottles
// Link: https://leetcode.com/problems/water-bottles/description/
// Beats: Runtime 2 ms (Beats 53.84%), Memory 7.17 MB (Beats 30.43%)

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>

class Solution
{
public:
    int numWaterBottles(int full, int exchange)
    {
        int ans = 0, empty = 0;
        while (full > 0)
        {
            ans += full;             // Drink all full bottles
            empty += full;           // Add these bottles to empty ones
            full = empty / exchange; // Get new full bottles from empty ones
            empty %= exchange;       // Remaining empty bottles after exchange
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    int numBottles = 9;
    int numExchange = 3;
    std::cout << "Maximum number of water bottles you can drink: " << solution.numWaterBottles(numBottles, numExchange) << std::endl;

    numBottles = 15;
    numExchange = 4;
    std::cout << "Maximum number of water bottles you can drink: " << solution.numWaterBottles(numBottles, numExchange) << std::endl;

    return 0;
}
