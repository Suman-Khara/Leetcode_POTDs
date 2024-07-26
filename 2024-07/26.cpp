// Problem: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Beats: Runtime 40 ms (Beats 19.91%), Memory 22.90 MB (Beats 5.45%)

// Time Complexity: O(n^2 * log(n))
// Space Complexity: O(n^2)

#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    // Dijkstra's algorithm to find the shortest path from source to all other nodes
    int dijkstra(const vector<vector<vector<int>>> &graph, int source, int limit)
    {
        int n = graph.size();
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialize the source distance to 0
        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int v = pq.top().second;
            pq.pop();

            // If the current distance is greater than the stored distance, continue
            if (dist[v] < d)
                continue;

            // Relaxation step for the neighbors
            for (const vector<int> &neighbor : graph[v])
            {
                if (d + neighbor[1] < dist[neighbor[0]])
                {
                    dist[neighbor[0]] = d + neighbor[1];
                    pq.push({dist[neighbor[0]], neighbor[0]});
                }
            }
        }

        // Count the number of cities within the distance threshold
        int count = 0;
        for (int distance : dist)
        {
            if (distance <= limit)
            {
                count++;
            }
        }
        return count;
    }

    // Function to find the city with the smallest number of neighbors at a threshold distance
    int findTheCity(int n, vector<vector<int>> &edges, int limit)
    {
        // Build the graph
        vector<vector<vector<int>>> graph(n);
        for (const vector<int> &edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        int result = -1;
        int minNeighbors = INT_MAX;

        // Iterate through each city and find the number of reachable cities
        for (int i = 0; i < n; i++)
        {
            int reachableCities = dijkstra(graph, i, limit);
            if (reachableCities <= minNeighbors)
            {
                minNeighbors = reachableCities;
                result = i;
            }
        }

        return result;
    }
};

// Example Usage
int main()
{
    Solution solution;

    // Example 1
    int n1 = 4;
    vector<vector<int>> edges1 = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold1 = 4;
    int result1 = solution.findTheCity(n1, edges1, distanceThreshold1);
    cout << "Example 1:" << result1 << endl; // Output: 3

    // Example 2
    int n2 = 5;
    vector<vector<int>> edges2 = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    int distanceThreshold2 = 2;
    int result2 = solution.findTheCity(n2, edges2, distanceThreshold2);
    cout << "Example 2:" << result2 << endl; // Output: 0

    return 0;
}
