# Problem: 590. N-ary Tree Postorder Traversal
# Link: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
# Beats: 32.58% (Runtime), 43.75% (Memory)
# Time Complexity: O(n) where n is the number of nodes in the tree.
# Space Complexity: O(h) where h is the height of the tree (for the recursion stack).

from typing import List

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        result = []

        def traverse(node: 'Node'):
            if not node:
                return
            if node.children: #this statement was not necessary in LeetCode but in VS Code it gives TypeError : None type is not iterable
                for child in node.children:
                    traverse(child)
            result.append(node.val)

        traverse(root)
        return result

# Example usage:
solution = Solution()

# Test case 1
root1 = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
print(solution.postorder(root1))  # Output: [5, 6, 3, 2, 4, 1]

# Test case 2
root2 = Node(1, [
    Node(2),
    Node(3, [Node(6), Node(7, [Node(11, [Node(14)])])]),
    Node(4, [Node(8, [Node(12)])]),
    Node(5, [Node(9, [Node(13)]), Node(10)])
])
print(solution.postorder(root2))  # Output: [2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1]