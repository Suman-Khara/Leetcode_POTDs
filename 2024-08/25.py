# Problem: 145. Binary Tree Postorder Traversal
# Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
# Beats: 26.54% (Runtime: 39 ms), 64.22% (Memory: 16.44 MB)
# Time Complexity: O(n) - We visit each node exactly once.
# Space Complexity: O(n) - The recursion stack can go as deep as the height of the tree, which in the worst case is O(n).

# Definition for a binary tree node.
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        
        def traverse(node: Optional[TreeNode]):
            if not node:
                return
            if node.left:
                traverse(node.left)
            if node.right:
                traverse(node.right)
            result.append(node.val)
        
        traverse(root)
        return result

# Example usage:
solution = Solution()

# Test case 1
root1 = TreeNode(1)
root1.right = TreeNode(2)
root1.right.left = TreeNode(3)
print(solution.postorderTraversal(root1))  # Output: [3, 2, 1]

# Test case 2
root2 = None
print(solution.postorderTraversal(root2))  # Output: []

# Test case 3
root3 = TreeNode(1)
print(solution.postorderTraversal(root3))  # Output: [1]