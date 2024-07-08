// Problem: 1823. Find the Winner of the Circular Game
// Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Beats: Runtime 18 ms (Beats 34.34%), Memory 25.64 MB (Beats 20.59%)

// Time Complexity: O(n * k)
// Space Complexity: O(n)

#include <iostream>
#include <queue>

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        std::queue<int> q;
        for (int i = 1; i <= n; ++i)
        {
            q.push(i); // Initialize the queue with friends numbered from 1 to n
        }
        while (q.size() > 1)
        {
            for (int i = 1; i < k; ++i)
            {
                int alive = q.front();
                q.pop();
                q.push(alive); // Move the first k-1 friends to the back of the queue
            }
            q.pop(); // Remove the k-th friend from the queue (they lose the game)
        }
        return q.front(); // The last remaining friend is the winner
    }
};

int main()
{
    Solution solution;
    int n = 5;
    int k = 2;
    std::cout << "The winner is: " << solution.findTheWinner(n, k) << std::endl;

    n = 6;
    k = 5;
    std::cout << "The winner is: " << solution.findTheWinner(n, k) << std::endl;

    return 0;
}
