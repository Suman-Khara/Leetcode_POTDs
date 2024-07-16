// Problem: 2096. Step-By-Step Directions From a Binary Tree Node to Another
// Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
// Beats: Runtime 156 ms (Beats 55.35%), Memory 119.33 MB (Beats 40.98%)

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree

#include <iostream>
#include <string>
#include <vector>

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
    // Helper function to find the path from root to a given value
    bool path(TreeNode *root, int val, string &s)
    {
        if (root == nullptr)
            return false;
        if (root->val == val)
            return true;
        s += 'L';
        if (path(root->left, val, s))
            return true;
        s.pop_back();
        s += 'R';
        if (path(root->right, val, s))
            return true;
        s.pop_back();
        return false;
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string start = "", dest = "";
        // Find paths from root to startValue and destValue
        path(root, startValue, start);
        path(root, destValue, dest);

        // Find the lowest common ancestor (LCA) by finding the longest common prefix
        int lcp;
        for (lcp = 0; start[lcp] != '\0' && dest[lcp] != '\0'; lcp++)
        {
            if (start[lcp] != dest[lcp])
                break;
        }

        // Replace remaining characters in start path with 'U' (upwards direction)
        for (int i = lcp; start[i] != '\0'; i++)
            start[i] = 'U';

        // Concatenate the modified start path and the destination path from the LCA onwards
        return start.substr(lcp) + dest.substr(lcp);
    }
};

int main()
{
    Solution solution;

    // Example 1
    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(4);

    int startValue1 = 3, destValue1 = 6;
    cout << "Output: " << solution.getDirections(root1, startValue1, destValue1) << endl; // Output: "UURL"

    // Example 2
    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);

    int startValue2 = 2, destValue2 = 1;
    cout << "Output: " << solution.getDirections(root2, startValue2, destValue2) << endl; // Output: "L"

    return 0;
}
