/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
// Fast and slow pointer approach;
// fast moves two steps and slow move one single step;
// logic (if fast = 10 then slow = 5) i.e middle;
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head; 
        ListNode* fast = head;
        while(fast!= nullptr && fast->next!= nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};