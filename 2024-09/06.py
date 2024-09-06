# Problem: 3217. Delete Nodes From Linked List Present in Array
# Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
# Beats: 56.98% (Runtime), 30.86% (Memory)
# Time Complexity: O(n), where n is the number of nodes in the linked list. We traverse the list once.
# Space Complexity: O(m), where m is the length of the nums array, due to storing elements in a set.

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Removes nodes from the linked list whose values are present in the given array 'nums'.
        
        :param nums: List of integers representing node values to be removed.
        :param head: The head of the linked list.
        :return: The head of the modified linked list.
        """
        # Convert the 'nums' list into a set for O(1) lookup time.
        to_remove = set(nums)
        
        # Create a dummy node to handle edge cases more easily (e.g., removing the first node).
        dummy = ListNode(next=head)
        
        # prev points to the last valid node; curr is the current node we are examining.
        prev, curr = dummy, head
        
        # Traverse the linked list
        while curr:
            # If the current node's value is in the 'to_remove' set, bypass the current node.
            if curr.val in to_remove:
                prev.next = curr.next  # Remove the current node by updating the previous node's next pointer.
            else:
                prev = curr  # Move prev to curr only if the current node is not removed.
            curr = curr.next  # Move to the next node in the list.
        
        # Return the new head of the list, which is dummy.next.
        return dummy.next

# Example usage:
def list_to_linkedlist(arr):
    """Helper function to convert list to linked list."""
    dummy = ListNode()
    curr = dummy
    for val in arr:
        curr.next = ListNode(val)
        curr = curr.next
    return dummy.next

def linkedlist_to_list(head):
    """Helper function to convert linked list back to list."""
    arr = []
    while head:
        arr.append(head.val)
        head = head.next
    return arr

# Test case 1
nums1 = [1, 2, 3]
head1 = list_to_linkedlist([1, 2, 3, 4, 5])
result1 = linkedlist_to_list(Solution().modifiedList(nums1, head1))
print(result1)  # Output: [4, 5]

# Test case 2
nums2 = [1]
head2 = list_to_linkedlist([1, 2, 1, 2, 1, 2])
result2 = linkedlist_to_list(Solution().modifiedList(nums2, head2))
print(result2)  # Output: [2, 2, 2]

# Test case 3
nums3 = [5]
head3 = list_to_linkedlist([1, 2, 3, 4])
result3 = linkedlist_to_list(Solution().modifiedList(nums3, head3))
print(result3)  # Output: [1, 2, 3, 4]
