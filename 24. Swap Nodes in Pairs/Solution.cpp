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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* newHead = head->next;
        ListNode* current = head;
        ListNode* prev = nullptr;
        
        while (current != nullptr && current->next != nullptr) {
            ListNode* nextPair = current->next->next;
            ListNode* second = current->next;
            
            // Swap the pair
            second->next = current;
            current->next = nextPair;
            
            // Link the previous node to the new head of the swapped pair
            if (prev != nullptr) {
                prev->next = second;
            }
            
            // Move pointers forward
            prev = current;
            current = nextPair;
        }
        
        return newHead;
    }
};