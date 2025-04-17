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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* groupStart = curr;
            ListNode* groupEnd = curr;
            int count = 1;
            
            // Check if there are at least k nodes remaining
            while (groupEnd->next != nullptr && count < k) {
                groupEnd = groupEnd->next;
                count++;
            }
            
            if (count < k) {
                break; // Not enough nodes to form a complete group
            }
            
            ListNode* nextGroup = groupEnd->next;
            groupEnd->next = nullptr; // Temporarily break the list to reverse the group
            
            // Reverse the current group
            ListNode* reversedGroup = reverseList(groupStart);
            
            // Link the reversed group back to the list
            prev->next = reversedGroup;
            groupStart->next = nextGroup;
            
            // Move pointers forward
            prev = groupStart;
            curr = nextGroup;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
};