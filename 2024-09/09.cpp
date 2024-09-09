// Problem: 2326. Spiral Matrix IV
// Link: https://leetcode.com/problems/spiral-matrix-iv/
// Beats: 8.75% with 185 ms runtime, 17.37% with 130.65 MB memory usage

/*
Time Complexity: O(m * n)
- Each element of the matrix is visited exactly once while traversing and filling the matrix in spiral order, so the time complexity is O(m * n), where `m` is the number of rows and `n` is the number of columns.

Space Complexity: O(m * n)
- The matrix `ans` uses O(m * n) space, as we are generating a matrix of size m x n. The other variables and the linked list traversal do not require additional space proportional to the matrix size.
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        // Direction vectors for right, down, left, and up
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> matrix(m, vector<int>(n, -1)); // Initialize the matrix with -1

        ListNode *currentNode = head;
        int row = 0, col = 0, direction = 0; // Start from the top-left corner

        // Traverse the linked list and fill the matrix in spiral order
        while (currentNode != nullptr)
        {
            matrix[row][col] = currentNode->val;
            currentNode = currentNode->next;

            // Calculate the next position
            int nextRow = row + directions[direction][0];
            int nextCol = col + directions[direction][1];

            // Check if the next position is out of bounds or already filled
            if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n || matrix[nextRow][nextCol] != -1)
            {
                // Change direction (clockwise: right -> down -> left -> up)
                direction = (direction + 1) % 4;
            }

            // Move to the next position
            row += directions[direction][0];
            col += directions[direction][1];
        }

        return matrix;
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

// Helper function to print the generated matrix
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution solution;

    // Example 1
    vector<int> values1 = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};
    ListNode *head1 = createLinkedList(values1);
    int m1 = 3, n1 = 5;
    vector<vector<int>> result1 = solution.spiralMatrix(m1, n1, head1);
    cout << "Example 1 Output:" << endl;
    printMatrix(result1);

    // Example 2
    vector<int> values2 = {0, 1, 2};
    ListNode *head2 = createLinkedList(values2);
    int m2 = 1, n2 = 4;
    vector<vector<int>> result2 = solution.spiralMatrix(m2, n2, head2);
    cout << "Example 2 Output:" << endl;
    printMatrix(result2);

    return 0;
}
