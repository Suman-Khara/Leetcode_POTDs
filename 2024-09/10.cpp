// Problem: 2807. Insert Greatest Common Divisors in Linked List
// Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
// Beats: 44.84% with 42 ms runtime, 82.68% with 35.46 MB memory usage

/*
Time Complexity: O(n)
- The time complexity is O(n) because we traverse the linked list once. For each adjacent pair of nodes, we compute the GCD in constant time (since the values are small, bounded by 1000).

Space Complexity: O(1)
- The space complexity is O(1) since we do not use any extra space proportional to the input size other than a few pointers.
*/

#include <iostream>
#include <vector>
#include <algorithm> // For std::__gcd

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

class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *currentNode = head;

        // Traverse the list while there are at least two nodes remaining
        while (currentNode != nullptr && currentNode->next != nullptr)
        {
            ListNode *nextNode = currentNode->next;                // Save the next node for reference
            int gcdValue = __gcd(currentNode->val, nextNode->val); // Calculate GCD between current and next node values

            // Insert the GCD node between the current and next node
            ListNode *gcdNode = new ListNode(gcdValue, nextNode);
            currentNode->next = gcdNode;

            // Move to the next node in the list (the one after the inserted GCD node)
            currentNode = nextNode;
        }

        return head;
    }
};

// Helper function to create a linked list from a vector of integers
ListNode *createLinkedList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (int i = 1; i < values.size(); i++)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Solution solution;

    // Example 1
    vector<int> values1 = {18, 6, 10, 3};
    ListNode *head1 = createLinkedList(values1);
    ListNode *result1 = solution.insertGreatestCommonDivisors(head1);
    cout << "Example 1 Output:" << endl;
    printLinkedList(result1); // Expected output: 18 6 6 2 10 1 3

    // Example 2
    vector<int> values2 = {7};
    ListNode *head2 = createLinkedList(values2);
    ListNode *result2 = solution.insertGreatestCommonDivisors(head2);
    cout << "Example 2 Output:" << endl;
    printLinkedList(result2); // Expected output: 7

    return 0;
}
