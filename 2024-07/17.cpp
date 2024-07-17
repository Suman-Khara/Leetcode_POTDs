// Problem: 1110. Delete Nodes And Return Forest
// Link: https://leetcode.com/problems/delete-nodes-and-return-forest/
// Beats: Runtime 14 ms (Beats 70.59%), Memory 27.24 MB (Beats 21.35%)

// Time Complexity: O(n), where n is the number of nodes in the tree
// Space Complexity: O(n), due to the space needed for the answer vector and the unordered set

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

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
    // Helper function to delete nodes and form the forest
    TreeNode *deleteAndFormForest(TreeNode *root, unordered_set<int> &toDeleteSet, vector<TreeNode *> &forest)
    {
        if (root == nullptr)
            return nullptr;

        // Recursively delete nodes in the left and right subtree
        root->left = deleteAndFormForest(root->left, toDeleteSet, forest);
        root->right = deleteAndFormForest(root->right, toDeleteSet, forest);

        // If the current node needs to be deleted
        if (toDeleteSet.count(root->val))
        {
            // If left child exists, add it to the forest
            if (root->left != nullptr)
                forest.push_back(root->left);
            // If right child exists, add it to the forest
            if (root->right != nullptr)
                forest.push_back(root->right);
            return nullptr; // Delete the current node
        }

        return root;
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &toDelete)
    {
        vector<TreeNode *> forest;
        unordered_set<int> toDeleteSet(toDelete.begin(), toDelete.end());
        deleteAndFormForest(root, toDeleteSet, forest);

        // If the root is not deleted, add it to the forest
        if (!toDeleteSet.count(root->val))
            forest.push_back(root);

        return forest;
    }
};

int main()
{
    Solution solution;

    // Example 1
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    vector<int> toDelete1 = {3, 5};
    vector<TreeNode *> result1 = solution.delNodes(root1, toDelete1);
    for (TreeNode *node : result1)
    {
        cout << node->val << " ";
    }
    cout << endl;

    // Example 2
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->left->right->left = new TreeNode(4);

    vector<int> toDelete2 = {3};
    vector<TreeNode *> result2 = solution.delNodes(root2, toDelete2);
    for (TreeNode *node : result2)
    {
        cout << node->val << " ";
    }
    cout << endl;

    return 0;
}
