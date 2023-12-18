# Problem

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

# Approach
The idea is to simply go trough all of the nodes and do simple swap:
 1. Save the next node from next node
 2. Store current node in next node's next
 3. If there is last node modified, store current->next as his next
 4. Store temporary node to current's next
 >Note that we must store head->next inside head, too

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)

# Code
```
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function swapPairs(head: ListNode | null): ListNode | null {
    // Store head to current
    let current = head;

    // Store current->next to head
    if (current && current.next) {
        head = current.next;
    }

    let temp : ListNode | null = null;
    let last : ListNode | null = null;

    // Go trough each node and do the algorithm Aproach.
    // We will break from loop when current->next is null or
    // current is null because if there is odd number of 
    // nodes, we simply do not permute last node
    while (current != null && current.next != null) {
        temp = current.next.next;
        current.next.next = current;

        // In case of first node, last will be nullptr
        if (last != null) {
            last.next = current.next;
        }

        current.next = temp;
        last = current;
        current = current.next;
    }

    // return the head
    return head;
};
```