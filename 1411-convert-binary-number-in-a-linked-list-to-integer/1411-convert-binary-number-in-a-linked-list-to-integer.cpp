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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int len =0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        temp=head;
        int ans =0;

        while(temp!=NULL &&len>0){
            int a =(temp->val )* (pow(2,len-1));
            len--;
            ans+=a;
            temp=temp->next;
        }
        return ans;
    }
};