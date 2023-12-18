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
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function pairSum(head: ListNode | null): number {
    let max_sum : number = 0;
    // create temporary pointer for current and middle
    let two_step_pointer : ListNode | null = head;
    let current : ListNode | null = head;

    // create stack of values, we will push first half here
    let stack : number[] = [];

    // we go trough whole list, increase two_step_pointer by 2
    // once it hits null, we know we are in the middle of the list
    while (current != null) {
        // if its not null, push the value and increase the pointer
        if (two_step_pointer != null) {
            stack.push(current.val);
            two_step_pointer = two_step_pointer.next!.next;
        } else {
            // if its null, pop the value and check if its max sum
            let first_half_number : number | undefined = stack.pop();
            
            if (first_half_number! + current.val > max_sum) {
                max_sum = first_half_number! + current.val;
            }
        }

        // increase current pointer
        current = current.next;
    }

    // return max sum
    return max_sum;
};
```