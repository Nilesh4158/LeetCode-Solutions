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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast n+1 steps ahead to create a gap of n between slow and fast
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Remove the nth node from the end
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};