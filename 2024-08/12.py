# Problem: 703. Kth Largest Element in a Stream
# Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
# Beats: 70.46% (Runtime: 77 ms), 48.47% (Memory: 20.68 MB)
# Time Complexity: O(log(k)) for each add operation due to heap operations.
# Space Complexity: O(k) for storing the k largest elements in the heap.

import heapq
from typing import List

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.smaller = []  # Min-heap for the smallest elements
        self.larger = []   # Max-heap (simulated with negative values) for the largest elements
        
        for num in nums:
            heapq.heappush(self.larger, num)
        
        while len(self.larger) > k:
            heapq.heappush(self.smaller, -heapq.heappop(self.larger))

    def add(self, val: int) -> int:
        # Add new value to the heap of largest elements
        heapq.heappush(self.larger, val)
        
        # If we have more than k elements, move the smallest of the largest elements to the smaller heap
        if len(self.larger) > self.k:
            heapq.heappush(self.smaller, -heapq.heappop(self.larger))
        
        # The root of the larger heap is the kth largest element
        return self.larger[0]

# Example usage:
# Initialize the KthLargest object with k = 3 and nums = [4, 5, 8, 2]
kthLargest = KthLargest(3, [4, 5, 8, 2])
print(kthLargest.add(3))  # Output: 4
print(kthLargest.add(5))  # Output: 5
print(kthLargest.add(10)) # Output: 5
print(kthLargest.add(9))  # Output: 8
print(kthLargest.add(4))  # Output: 8