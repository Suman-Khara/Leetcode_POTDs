// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
// Beats 77.92%

#include <iostream>
#include <vector>
#include <climits>
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
    // Function to convert linked list to vector
    void vectorify(ListNode *head, vector<int> &v)
    {
        if (head == nullptr)
            return;
        v.push_back(head->val);   // Add current node's value to vector
        vectorify(head->next, v); // Recur for the next node
    }

    // Function to find minimum and maximum distances between critical points
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> v, critical;
        vectorify(head, v); // Convert linked list to vector
        int n = v.size();
        for (int i = 1; i < n - 1; i++)
        {
            if ((v[i] > v[i - 1] && v[i] > v[i + 1]) || (v[i] < v[i - 1] && v[i] < v[i + 1]))
                critical.push_back(i); // Identify critical points
        }
        if (critical.size() < 2)
            return {-1, -1}; // If less than 2 critical points, return [-1, -1]
        else
        {
            int maxi = critical[critical.size() - 1] - critical[0]; // Maximum distance
            int mini = INT_MAX;
            for (int i = 1; i < critical.size(); i++)
                mini = min(mini, critical[i] - critical[i - 1]); // Minimum distance
            return {mini, maxi};                                 // Return min and max distances
        }
    }
};

// Main function for testing
int main()
{
    // Create the linked list [5,3,1,2,5,1,2]
    ListNode *head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);

    // Create Solution object
    Solution sol;

    // Call the function and print the result
    vector<int> result = sol.nodesBetweenCriticalPoints(head);
    cout << "Min Distance: " << result[0] << ", Max Distance: " << result[1] << endl;

    return 0;
}
