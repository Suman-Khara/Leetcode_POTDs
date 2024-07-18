// Problem: 1530. Number of Good Leaf Nodes Pairs
// Link: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
// Beats: Runtime 57 ms (Beats 33.81%), Memory 30.54 MB (Beats 99.21%)

// Time Complexity: O(n^2), where n is the number of leaf nodes
// Space Complexity: O(n), due to the space needed for the leaf paths

#include <iostream>
#include <vector>
#include <string>

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
    // Helper function to perform DFS and store the path to each leaf node
    void dfs(TreeNode *root, string &path, vector<string> &leafPaths)
    {
        if (root == nullptr)
            return;

        // Traverse left child
        path += 'L';
        dfs(root->left, path, leafPaths);
        path.pop_back();

        // Traverse right child
        path += 'R';
        dfs(root->right, path, leafPaths);
        path.pop_back();

        // If the node is a leaf, store its path
        if (root->left == nullptr && root->right == nullptr)
        {
            leafPaths.push_back(path);
        }
    }

    // Helper function to calculate the distance between two paths
    int calculateDistance(const string &path1, const string &path2)
    {
        int commonLength = 0;
        while (commonLength < path1.size() && commonLength < path2.size() && path1[commonLength] == path2[commonLength])
            commonLength++;
        return (path1.size() - commonLength) + (path2.size() - commonLength);
    }

    int countPairs(TreeNode *root, int distance)
    {
        vector<string> leafPaths;
        string path;
        dfs(root, path, leafPaths);

        int numOfLeaves = leafPaths.size();
        int goodPairsCount = 0;

        // Compare each pair of leaf nodes to count good pairs
        for (int i = 0; i < numOfLeaves; ++i)
        {
            for (int j = i + 1; j < numOfLeaves; ++j)
            {
                if (calculateDistance(leafPaths[i], leafPaths[j]) <= distance)
                {
                    ++goodPairsCount;
                }
            }
        }

        return goodPairsCount;
    }
};

int main()
{
    Solution solution;

    // Example 1
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    int distance1 = 3;
    cout << solution.countPairs(root1, distance1) << endl; // Output: 1

    // Example 2
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);
    int distance2 = 3;
    cout << solution.countPairs(root2, distance2) << endl; // Output: 2

    return 0;
}
