/*
Problem: 1514. Path with Maximum Probability
Link: https://leetcode.com/problems/path-with-maximum-probability/

Time Complexity:
- The algorithm primarily relies on Dijkstra's algorithm using a priority queue.
- Building the graph takes O(E) time, where E is the number of edges.
- The main loop processes each edge in the worst case, taking O(E log V) time, where V is the number of vertices.
- Overall time complexity: O(E log V).

Space Complexity:
- The space complexity is O(V + E) for storing the graph and the probability array.

Runtime: 115 ms
Beats: 92.90%
Memory: 70.08 MB
Beats: 65.46%
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution
{
public:
    // Dijkstra's algorithm to find the maximum probability path
    double dijkstra(vector<vector<pair<int, double>>> &graph, int start, int end)
    {
        int numNodes = graph.size();
        vector<double> maxProb(numNodes, 0.0); // Probability array to store the max probability to each node
        maxProb[start] = 1.0;                  // Start node has a probability of 1.0

        // Max-heap to store (probability, node) pairs for processing the most probable path first
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        while (!pq.empty())
        {
            auto [probability, node] = pq.top();
            pq.pop();

            if (probability < maxProb[node])
                continue; // Skip if we have already found a better path

            for (auto &[neighbor, succProb] : graph[node])
            {
                double newProb = probability * succProb; // Calculate the new probability
                if (newProb > maxProb[neighbor])
                { // If the new probability is better, update it
                    maxProb[neighbor] = newProb;
                    pq.push({newProb, neighbor}); // Push the neighbor with the updated probability
                }
            }
        }
        return maxProb[end]; // Return the max probability to reach the end node
    }

    // Main function to create the graph and invoke Dijkstra's algorithm
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> graph(n); // Adjacency list representation of the graph

        // Build the graph from the edges and success probabilities
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        return dijkstra(graph, start, end); // Run Dijkstra's algorithm to find the max probability path
    }
};

int main()
{
    Solution solution;

    // Example 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb1 = {0.5, 0.5, 0.2};
    int start1 = 0;
    int end1 = 2;
    cout << "Max probability from 0 to 2: " << solution.maxProbability(n1, edges1, succProb1, start1, end1) << endl; // Expected output: 0.25000

    // Example 2
    int n2 = 3;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb2 = {0.5, 0.5, 0.3};
    int start2 = 0;
    int end2 = 2;
    cout << "Max probability from 0 to 2: " << solution.maxProbability(n2, edges2, succProb2, start2, end2) << endl; // Expected output: 0.30000

    // Example 3
    int n3 = 3;
    vector<vector<int>> edges3 = {{0, 1}};
    vector<double> succProb3 = {0.5};
    int start3 = 0;
    int end3 = 2;
    cout << "Max probability from 0 to 2: " << solution.maxProbability(n3, edges3, succProb3, start3, end3) << endl; // Expected output: 0.00000

    return 0;
}