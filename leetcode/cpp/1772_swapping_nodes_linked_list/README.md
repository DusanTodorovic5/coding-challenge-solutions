# Problem

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

# Approach
The idea is to go trough linked list and count the elements.
The complexity can be a bit lower, currently its O(2n), it can be O(n) but then space complexity would be O(n),too. Idea behind second solution is to use stack.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)

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
    ListNode* swapNodes(ListNode* head, int k) {
        // return if K is not in bounds or list is empty
        if (k < 1 || head == nullptr) {
            return head;
        }

        // we will count the index
        int index = 1;
        ListNode* first_swap = NULL;
        
        for (ListNode* current = head;current;current = current->next) {
            if (k == index++) {
                first_swap = current;
            }
        }

        // now we find element on position n-k and swap them
        int n = index;
        index = 1;
        for (ListNode* current = head;current;current = current->next) {
            if (n - k == index++) {
                std::swap(first_swap->val, current->val);
                break;
            }
        }

        return head;
    }
};
```