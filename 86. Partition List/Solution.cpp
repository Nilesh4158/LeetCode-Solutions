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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_head = new ListNode(0); // Dummy node for less than x
        ListNode* less_tail = less_head;
        ListNode* greater_head = new ListNode(0); // Dummy node for greater or equal to x
        ListNode* greater_tail = greater_head;
        
        ListNode* current = head;
        
        while (current != nullptr) {
            if (current->val < x) {
                less_tail->next = current;
                less_tail = less_tail->next;
            } else {
                greater_tail->next = current;
                greater_tail = greater_tail->next;
            }
            current = current->next;
        }
        
        // Combine the two lists
        less_tail->next = greater_head->next;
        greater_tail->next = nullptr; // Important to avoid cycles
        
        ListNode* result = less_head->next;
        
        // Clean up dummy nodes
        delete less_head;
        delete greater_head;
        
        return result;
    }
};