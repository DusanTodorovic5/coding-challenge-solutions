/*
 * You are given the head of a linked list, and an integer k.
 * Return the head of the linked list after swapping the values of the kth node from the 
 * beginning and the kth node from the end (the list is 1-indexed).
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
        // if (k == 1) {
        //     first_swap = head;
        // }

        // std::swap(first_swap->next, second_swap->next);
        // std::swap(first_swap->next->next, second_swap->next->next);

        return head;
    }
};

int main(int, char**) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;

    sol.swapNodes(head, 1);
    return 0;
}
