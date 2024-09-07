// Problem: 1367. Linked List in Binary Tree
// Link: https://leetcode.com/problems/linked-list-in-binary-tree/
// Beats 41.65% with 27 ms runtime, 74.94% with 30.77 MB memory usage

/*
Time Complexity:
1. The recursive depth-first search (dfs) function checks for each match between the linked list and a path in the binary tree.
2. The `dfs` runs for every node in the tree (T nodes), and for each node, it traverses a possible matching path of the linked list (L nodes).
3. Therefore, the time complexity is O(T * L), where T is the number of nodes in the tree and L is the length of the linked list.

Space Complexity:
1. The space complexity is dominated by the recursion stack. In the worst case, the depth of recursion is O(T) for the tree traversal and O(L) for the linked list matching.
2. Hence, the overall space complexity is O(T + L).
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    // Helper function to check if the linked list can be found starting from the current tree node
    bool dfs(ListNode *head, TreeNode *root)
    {
        if (head == nullptr)
            return true; // If we have successfully matched all nodes in the list
        if (root == nullptr || head->val != root->val)
            return false; // Mismatch found

        // Recursively check if the list matches down the left or right subtree
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }

    // Main function to check if the linked list is a subpath of the binary tree
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (root == nullptr)
            return false; // Tree is empty

        // Check if the path starts at the current node, or explore the left and right subtrees
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

// Main function to demonstrate functionality (example usage)
int main()
{
    // Creating a linked list: 4 -> 2 -> 8
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(8);

    // Creating a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(8);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);

    Solution solution;
    bool result = solution.isSubPath(head, root);
    cout << (result ? "True" : "False") << endl; // Expected output: True

    return 0;
}
