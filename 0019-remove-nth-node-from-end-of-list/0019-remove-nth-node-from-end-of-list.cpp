class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // STEP 1: Create the dummy node to safely handle head removal
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // STEP 2: Initialize both pointers at the dummy node
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // STEP 3: fast ko n kadam aage badhao
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // STEP 4: Move both pointers 1 step at a time until fast reaches the LAST node
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Now, 'slow' is sitting exactly BEFORE the node we want to delete
        
        // STEP 5: Re-link and delete the target node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Free up memory

        // STEP 6: Get the actual new head, delete dummy to prevent memory leaks
        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};