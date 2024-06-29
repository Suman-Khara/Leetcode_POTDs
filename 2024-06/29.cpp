// 2192. All Ancestors of a Node in a Directed Acyclic Graph
// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/
// Runtime beat: 96.60%, memory beat: 87.16%

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &graph, vector<vector<int>> &ans)
    {
        // For each neighbor 'k' of node 'j'
        for (int k : graph[j])
        {
            // If 'i' is not already an ancestor of 'k'
            if (ans[k].size() == 0 || ans[k].back() != i)
            {
                ans[k].push_back(i);   // Add 'i' as an ancestor of 'k'
                dfs(i, k, graph, ans); // Continue DFS from node 'k'
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> ans(n), graph(n);

        // Build the graph using an adjacency list
        for (vector<int> v : edges)
        {
            graph[v[0]].push_back(v[1]);
        }

        // Perform DFS for each node to find ancestors
        for (int i = 0; i < n; i++)
        {
            dfs(i, i, graph, ans);
        }

        return ans;
    }
};

void print(vector<vector<int>> &result)
{
    for (const auto &ancestors : result)
    {
        cout << "[";
        for (int i = 0; i < ancestors.size(); ++i)
        {
            cout << ancestors[i];
            if (i != ancestors.size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}

int main()
{
    // Example 1
    int n1 = 8;
    vector<vector<int>> edges1 = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};

    Solution sol1;
    vector<vector<int>> result1 = sol1.getAncestors(n1, edges1);

    print(result1);

    cout << endl;

    // Example 2
    int n2 = 5;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};

    Solution sol2;
    vector<vector<int>> result2 = sol2.getAncestors(n2, edges2);

    print(result2);

    return 0;
}
