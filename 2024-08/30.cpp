// Problem: 2699. Modify Graph Edge Weights
// Link: https://leetcode.com/problems/modify-graph-edge-weights/
// Beats: Runtime 667 ms (Beats 38.20%), Memory 229.38 MB (Beats 90.13%)

// Time Complexity: O(n^2 * log(n)), where n is the number of nodes in the graph. The dijkstra function runs in O(n^2 * log(n)) because it uses a priority queue (min-heap) to find the shortest path.
// Space Complexity: O(n^2), for storing the graph in an adjacency matrix representation.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    // Function to run Dijkstra's algorithm and find the shortest path from start to end.
    int dijkstra(vector<vector<int>> &graph, int start, int end)
    {
        int n = graph.size();
        vector<int> distance(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distance[start] = 0;
        pq.push({distance[start], start});

        // Continue until the priority queue is empty
        while (!pq.empty())
        {
            auto [current_dist, current_node] = pq.top();
            pq.pop();

            // If the current node has already been visited with a shorter distance, skip it
            if (distance[current_node] < current_dist)
                continue;

            // Check all neighbors of the current node
            for (int neighbor = 0; neighbor < n; neighbor++)
            {
                if (graph[current_node][neighbor] != -1 && distance[neighbor] > current_dist + graph[current_node][neighbor])
                {
                    distance[neighbor] = current_dist + graph[current_node][neighbor];
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }

        return distance[end];
    }

    // Function to modify the graph edges so that the shortest path from start to end equals the target distance
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int start, int end, int target)
    {
        // Initialize the graph adjacency matrix
        vector<vector<int>> graph(n, vector<int>(n, -1));
        for (vector<int> &edge : edges)
        {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }

        // Find the current shortest distance from start to end
        int current_distance = dijkstra(graph, start, end);
        if (current_distance < target)
            return {}; // Impossible to modify edges to match the target distance

        bool found_exact_distance = false;
        if (current_distance == target)
            found_exact_distance = true;

        // Iterate over all edges to modify weights where necessary
        for (vector<int> &edge : edges)
        {
            if (edge[2] > 0)
                continue; // Skip edges with positive weights

            if (found_exact_distance)
            {
                edge[2] = 2e9; // Set a large value if target is already met
            }
            else
            {
                edge[2] = 1; // Set the weight to 1 for exploration
                graph[edge[0]][edge[1]] = edge[2];
                graph[edge[1]][edge[0]] = edge[2];
                current_distance = dijkstra(graph, start, end);

                if (current_distance <= target)
                {
                    found_exact_distance = true;
                    edge[2] += target - current_distance; // Adjust the edge weight to match the target distance
                }
            }
        }

        if (found_exact_distance)
            return edges; // Return the modified edges if the target distance is found
        return {};        // Return an empty array if it's impossible to match the target distance
    }
};

// Main function to test the solution
int main()
{
    Solution solution;

    // Example 1
    int n1 = 5;
    vector<vector<int>> edges1 = {{4, 1, -1}, {2, 0, -1}, {0, 3, -1}, {4, 3, -1}};
    int source1 = 0, destination1 = 1, target1 = 5;
    vector<vector<int>> result1 = solution.modifiedGraphEdges(n1, edges1, source1, destination1, target1);
    for (auto edge : result1)
    {
        cout << "[" << edge[0] << "," << edge[1] << "," << edge[2] << "] ";
    }
    cout << endl;

    // Example 2
    int n2 = 3;
    vector<vector<int>> edges2 = {{0, 1, -1}, {0, 2, 5}};
    int source2 = 0, destination2 = 2, target2 = 6;
    vector<vector<int>> result2 = solution.modifiedGraphEdges(n2, edges2, source2, destination2, target2);
    for (auto edge : result2)
    {
        cout << "[" << edge[0] << "," << edge[1] << "," << edge[2] << "] ";
    }
    cout << endl;

    // Example 3
    int n3 = 4;
    vector<vector<int>> edges3 = {{1, 0, 4}, {1, 2, 3}, {2, 3, 5}, {0, 3, -1}};
    int source3 = 0, destination3 = 2, target3 = 6;
    vector<vector<int>> result3 = solution.modifiedGraphEdges(n3, edges3, source3, destination3, target3);
    for (auto edge : result3)
    {
        cout << "[" << edge[0] << "," << edge[1] << "," << edge[2] << "] ";
    }
    cout << endl;

    return 0;
}
