
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

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