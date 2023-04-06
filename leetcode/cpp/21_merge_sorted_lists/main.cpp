
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if both lists are empty, we return nullptr
        if (!list1 && !list2) {
            return nullptr;
        }
        
        // create new node for head
        ListNode* head = new ListNode();        
        ListNode* current = head;

        // if list1 is smaller then list2, or list2 is empty, assign first element from list1
        if ((list1 && list2 && list1->val < list2->val) || (list1 && !list2)) {
            head->val = list1->val;
            list1 = list1->next;
        } else {
            // else, assign element from list2
            // code will execute if either list2 is smaller then list1 or list1 is null
            head->val = list2->val;
            list2 = list2->next;
        }

        // while there are elements from both lists
        while (list1 && list2) {
            ListNode* new_node = new ListNode();
            // assign smaller value to new node
            if (list1->val < list2->val) {
                new_node->val = list1->val;
                list1 = list1->next;
            } else {
                new_node->val = list2->val;
                list2 = list2->next;
            }

            // bind the node and go to next
            current->next = new_node;
            current = current->next;
        }

        // once we finish the loop, check if there is leftover in list1
        while (list1) {
            current->next = new ListNode(list1->val);
            current = current->next;
            list1 = list1->next;
        }

        // or there is leftover in list 2
        while (list2) {
            current->next = new ListNode(list2->val);
            current = current->next;
            list2 = list2->next;
        }

        // return the head of the list
        return head;
    }
};


int main() {

}