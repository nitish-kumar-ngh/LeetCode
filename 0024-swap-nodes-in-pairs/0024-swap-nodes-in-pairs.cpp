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
        if (!head || !head->next) return head; // Base case
        
        ListNode* temp = head->next;  // Store the second node
        head->next = swapPairs(temp->next);  // Recursively swap the remaining list
        temp->next = head;  // Swap current pair
        
        return temp;  // New head of this swapped pair
    }
};