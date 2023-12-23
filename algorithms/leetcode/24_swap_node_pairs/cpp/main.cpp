#include <iostream>

/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You must solve the problem without modifying the values in the 
 * list's nodes (i.e., only nodes themselves may be changed.)
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Store head to current
        ListNode* current = head;
        // Store current->next to head
        if (current && current->next) {
            head = current->next;
        }

        ListNode* temp = nullptr;
        ListNode* last = nullptr;

        // Go trough each node and do the algorithm Aproach.
        // We will break from loop when current->next is null or
        // current is null because if there is odd number of 
        // nodes, we simply do not permute last node
        while (current && current->next) {
            temp = current->next->next;
            current->next->next = current;

            // In case of first node, last will be nullptr
            if (last) {
                last->next = current->next;
            }

            current->next = temp;

            last = current;

            current = current->next;
        }

        // return the head
        return head;
    }
};

int main(int, char**) {
    
}
