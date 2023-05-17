# Problem

In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

# Approach
The idea here is to use stack and move first half of elements to the stack, then check if the second half sum with first is max sum.
This is done using another pointer that is increased by 2 instead of 1, that way he will get to end when current gets to half

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(n/2)

# Code
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        // create temporary pointer for current and middle
        ListNode* two_step_pointer = head;
        ListNode* current = head;
        
        // create stack of values, we will push first half of list here
        std::stack<int> sums;
        int max_sum = 0;

        // we increase two_step_pointer by 2, when he hits nullptr, we know
        // we will be at the end
        while (current) {
            // if we didnt hit middle yet, we push value and move two_step_pointer by 2
            if (two_step_pointer) {
                sums.push(current->val);
                two_step_pointer = two_step_pointer->next->next;
            } else {
                // in case we are in middle, we check if the top of stack and current is max
                if (sums.top() + current->val > max_sum) {
                    max_sum = sums.top() + current->val;
                }

                // at the end, pop the stack
                sums.pop();
            }

            // move to next node
            current = current->next;
        }
        
        // return the max value
        return max_sum;
    }
};
```