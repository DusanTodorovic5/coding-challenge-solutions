
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}
 

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