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
        // return if list is empty or k is less than 1
        if (k < 1 || head == nullptr) {
            return head;
        }

        // find the end node marker, we will do it by moving
        // node to the k-th place, after which we will increase another node
        ListNode* end_node = head;
        
        for (int i = 1;i<k;i++) {
            end_node = end_node->next;
        }

        // we store the end_node marker to first swap node
        // move end_node marker to one place after and start
        // moving the second node until we get to null on end_node marker
        ListNode* first_swap = end_node;
        end_node = end_node->next;
        ListNode* second_swap = head;

        while (end_node) {
            second_swap = second_swap->next;
            end_node = end_node->next;
        }

        // swap the values of the nodes and return head
        std::swap(first_swap->val, second_swap->val);

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

    sol.swapNodes(head, 2);
    return 0;
}
