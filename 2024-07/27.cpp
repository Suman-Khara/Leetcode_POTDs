// Problem: 2976. Minimum Cost to Convert String I
// Link: https://leetcode.com/problems/minimum-cost-to-convert-string-i/
// Beats: Runtime 187 ms (Beats 48.17%), Memory 123.53 MB (Beats 21.34%)

// Time Complexity: O(26 * (E + V log V)) where E is the number of edges and V is the number of vertices in the graph
// Space Complexity: O(26 * V)

// Function to perform Dijkstra's algorithm
#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(const vector<vector<vector<int>>> &graph, int source)
{
    vector<long long> dist(graph.size(), LLONG_MAX);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        long long d = pq.top().first;
        long long v = pq.top().second;
        pq.pop();

        if (dist[v] < d)
            continue;

        for (const vector<int> &neighbor : graph[v])
        {
            if (d + neighbor[1] < dist[neighbor[0]])
            {
                dist[neighbor[0]] = d + neighbor[1];
                pq.push({dist[neighbor[0]], neighbor[0]});
            }
        }
    }

    return dist;
}

// Main solution function
long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
{
    // Build the graph
    vector<vector<vector<int>>> graph(26);
    int n = cost.size();
    for (int i = 0; i < n; ++i)
    {
        graph[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
    }

    // Compute the minimum cost for each pair of characters
    vector<vector<long long>> min_cost(26);
    for (int i = 0; i < 26; ++i)
    {
        min_cost[i] = dijkstra(graph, i);
    }

    long long ans = 0;
    for (int i = 0; i < source.size(); ++i)
    {
        if (source[i] != target[i])
        {
            long long convert = min_cost[source[i] - 'a'][target[i] - 'a'];
            if (convert == LLONG_MAX)
            {
                return -1;
            }
            ans += convert;
        }
    }

    return ans;
}

// Example usage
int main()
{
    // Example 1
    string source1 = "abcd";
    string target1 = "acbe";
    vector<char> original1 = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed1 = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost1 = {2, 5, 5, 1, 2, 20};
    long long result1 = minimumCost(source1, target1, original1, changed1, cost1);
    printf("Example 1: %lld\n", result1); // Output: 28

    // Example 2
    string source2 = "aaaa";
    string target2 = "bbbb";
    vector<char> original2 = {'a', 'c'};
    vector<char> changed2 = {'c', 'b'};
    vector<int> cost2 = {1, 2};
    long long result2 = minimumCost(source2, target2, original2, changed2, cost2);
    printf("Example 2: %lld\n", result2); // Output: 12

    // Example 3
    string source3 = "abcd";
    string target3 = "abce";
    vector<char> original3 = {'a'};
    vector<char> changed3 = {'e'};
    vector<int> cost3 = {10000};
    long long result3 = minimumCost(source3, target3, original3, changed3, cost3);
    printf("Example 3: %lld\n", result3); // Output: -1

    return 0;
}
