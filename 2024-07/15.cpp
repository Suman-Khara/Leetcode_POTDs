// Problem: 2196. Create Binary Tree From Descriptions
// Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/description/
// Beats: Runtime 779 ms (Beats 30.79%), Memory 329.05 MB (Beats 7.86%)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Helper function to recursively construct the tree
    TreeNode *construct(int val, unordered_map<int, pair<int, int>> &graph)
    {
        TreeNode *left = nullptr, *right = nullptr;
        if (graph[val].first)
        {
            left = construct(graph[val].first, graph);
        }
        if (graph[val].second)
        {
            right = construct(graph[val].second, graph);
        }
        return new TreeNode(val, left, right);
    }

    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_set<int> children;
        unordered_map<int, pair<int, int>> graph;

        // Build the graph and record all child nodes
        for (vector<int> v : descriptions)
        {
            children.insert(v[1]);
            if (v[2] == 1)
            {
                graph[v[0]].first = v[1];
            }
            else
            {
                graph[v[0]].second = v[1];
            }
        }

        int root = 0;
        // Find the root (node that is not a child of any other node)
        for (auto &[x, p] : graph)
        {
            if (!children.contains(x))
            {
                root = x;
                break;
            }
        }

        // Construct and return the tree starting from the root
        return construct(root, graph);
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> descriptions1 = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    TreeNode *result1 = solution.createBinaryTree(descriptions1);
    // Output should represent the tree: [50,20,80,15,17,19]
    // Further implementation required to print or verify the tree structure

    vector<vector<int>> descriptions2 = {{1, 2, 1}, {2, 3, 0}, {3, 4, 1}};
    TreeNode *result2 = solution.createBinaryTree(descriptions2);
    // Output should represent the tree: [1,2,null,null,3,4]

    return 0;
}
