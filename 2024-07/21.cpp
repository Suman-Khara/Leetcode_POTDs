// Problem: 2392. Build a Matrix With Conditions
// Link: https://leetcode.com/problems/build-a-matrix-with-conditions/
// Beats: Runtime 106 ms (Beats 48.73%), Memory 65.90 MB (Beats 30.14%)

// Time Complexity: O(k^2), due to the topological sort and matrix filling
// Space Complexity: O(k^2), for storing the matrix and graph

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

class Solution
{
public:
    vector<int> toposort(int k, unordered_map<int, vector<int>> &graph)
    {
        vector<int> indegree(k + 1, 0), ans;
        // Calculate indegree for all nodes
        for (auto &[i, v] : graph)
        {
            for (int j : v)
            {
                indegree[j]++;
            }
        }
        queue<int> q;
        // Initialize queue with nodes having zero indegree
        for (int i = 1; i <= k; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // Perform topological sort
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            if (graph.find(curr) != graph.end())
            {
                for (int i : graph[curr])
                {
                    indegree[i]--;
                    if (indegree[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }
        return ans;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &row_conditions, vector<vector<int>> &col_conditions)
    {
        unordered_map<int, vector<int>> row_graph, col_graph;
        // Construct graphs for row and column conditions
        for (vector<int> v : row_conditions)
        {
            row_graph[v[0]].push_back(v[1]);
        }
        for (vector<int> v : col_conditions)
        {
            col_graph[v[0]].push_back(v[1]);
        }
        // Perform topological sort on both graphs
        vector<int> row = toposort(k, row_graph);
        vector<int> col = toposort(k, col_graph);
        if (row.size() < k || col.size() < k)
        {
            return {};
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        unordered_map<int, pair<int, int>> index;
        // Map values to their positions in the resulting matrix
        for (int i = 0; i < k; i++)
        {
            index[row[i]].first = i;
            index[col[i]].second = i;
        }
        // Fill the matrix with values based on the indices
        for (auto &[val, ind] : index)
        {
            ans[ind.first][ind.second] = val;
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Example 1
    int k1 = 3;
    vector<vector<int>> rowConditions1 = {{1, 2}, {3, 2}};
    vector<vector<int>> colConditions1 = {{2, 1}, {3, 2}};
    vector<vector<int>> result1 = solution.buildMatrix(k1, rowConditions1, colConditions1);
    for (const auto &row : result1)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Example 2
    int k2 = 3;
    vector<vector<int>> rowConditions2 = {{1, 2}, {2, 3}, {3, 1}, {2, 3}};
    vector<vector<int>> colConditions2 = {{2, 1}};
    vector<vector<int>> result2 = solution.buildMatrix(k2, rowConditions2, colConditions2);
    if (result2.empty())
    {
        cout << "[]\n";
    }
    else
    {
        for (const auto &row : result2)
        {
            for (int num : row)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
