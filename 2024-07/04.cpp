// 2181. Merge Nodes in Between Zeros
// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/
// Runtime: 417 ms
// Beats: 78.54%
// Memory: 256.61 MB
// Beats: 76.60%

#include <iostream>

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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *acc = head, *curr = head->next;
        int sum = 0;
        while (curr != nullptr)
        {
            if (curr->val > 0)
            {
                // Accumulate values between zeros
                sum += curr->val;
                acc->next = curr->next;
            }
            else
            {
                // On encountering zero, set accumulated sum and reset sum
                acc->val = sum;
                sum = 0;
                if (curr->next == nullptr)
                {
                    // If it's the last zero, set acc->next to null to exclude it
                    acc->next = nullptr;
                }
                else
                {
                    acc = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Example 1: [0,3,1,0,4,5,2,0]
    ListNode *head1 = new ListNode(0);
    head1->next = new ListNode(3, new ListNode(1, new ListNode(0, new ListNode(4, new ListNode(5, new ListNode(2, new ListNode(0)))))));

    Solution sol;
    ListNode *result1 = sol.mergeNodes(head1);
    printList(result1); // Output: 4 11

    // Example 2: [0,1,0,3,0,2,2,0]
    ListNode *head2 = new ListNode(0);
    head2->next = new ListNode(1, new ListNode(0, new ListNode(3, new ListNode(0, new ListNode(2, new ListNode(2, new ListNode(0)))))));

    ListNode *result2 = sol.mergeNodes(head2);
    printList(result2); // Output: 1 3 4

    return 0;
}
