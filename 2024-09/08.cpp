// Problem: 725. Split Linked List in Parts
// Link: https://leetcode.com/problems/split-linked-list-in-parts/
// Beats: 73.95% with 4 ms runtime, 93.69% with 13.62 MB memory usage

/*
Time Complexity: O(N + k)
1. First, we traverse the entire list to calculate its length (O(N)).
2. Then, we traverse the list again and split it into parts based on the calculated lengths (O(N)).
3. The final loop runs for k iterations to handle each split, leading to a total time complexity of O(N + k).

Space Complexity: O(k)
1. We use a vector of size k to store the resulting parts, which leads to a space complexity of O(k).
*/

#include <iostream>
#include <vector>
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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        // Step 1: Calculate the total length of the linked list
        int totalLength = 0;
        ListNode *currentNode = head;
        while (currentNode != nullptr)
        {
            totalLength++;
            currentNode = currentNode->next;
        }

        // Step 2: Calculate the size of each part and the remainder
        int partSize = totalLength / k;  // Minimum size of each part
        int remainder = totalLength % k; // Extra nodes to distribute

        vector<ListNode *> result; // Store the resulting parts

        // Step 3: Split the linked list into k parts
        for (int i = 0; i < k; i++)
        {
            // Determine the size of the current part
            int currentPartSize = partSize + (remainder > 0 ? 1 : 0);
            if (remainder > 0)
                remainder--;

            // Add the current head to the result
            result.push_back(head);

            // Move the head pointer to the end of the current part
            ListNode *prev = nullptr;
            for (int j = 0; j < currentPartSize; j++)
            {
                prev = head;
                head = head->next;
            }

            // Disconnect the current part from the rest of the list
            if (prev != nullptr)
            {
                prev->next = nullptr;
            }
        }

        return result;
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
    vector<int> values1 = {1, 2, 3};
    ListNode *head1 = createLinkedList(values1);
    int k1 = 5;
    vector<ListNode *> result1 = solution.splitListToParts(head1, k1);
    cout << "Example 1 Output: " << endl;
    for (auto part : result1)
    {
        printLinkedList(part);
    }

    // Example 2
    vector<int> values2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode *head2 = createLinkedList(values2);
    int k2 = 3;
    vector<ListNode *> result2 = solution.splitListToParts(head2, k2);
    cout << "Example 2 Output: " << endl;
    for (auto part : result2)
    {
        printLinkedList(part);
    }

    return 0;
}
