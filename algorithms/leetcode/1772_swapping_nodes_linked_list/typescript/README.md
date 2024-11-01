# Problem

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

# Approach
Move to the first element.
Now, for second element, we dont need to know the end, as first element is k-1 elements in front of head, we move head until the pointer of first_element gets to null.

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

function swapNodes(head: ListNode | null, k: number): ListNode | null {
    if (head == null || k < 1) {
        return head;
    }

    // move to position of first node to swap
    let first_node: ListNode = head;
    for (let i = 1;i<k;i++) {
        first_node = first_node.next!;
    }

    // Move to second, we know we are there once the end_node hits null
    // as the end node is k elements in front of head
    let second_node: ListNode = head;
    let end_node: ListNode = first_node.next!;

    while (end_node != null) {
        end_node = end_node.next!;
        second_node = second_node.next!;
    }

    // swap the values and return head
    let temp_val : number = first_node.val;
    first_node.val = second_node.val;
    second_node.val = temp_val;

    return head;
};
```