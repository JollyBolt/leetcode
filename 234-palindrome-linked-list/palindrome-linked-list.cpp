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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head,*slow=head,*shead=new ListNode(0,head);
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
            shead=shead->next;
        }
        ListNode *curr=slow,*prev=NULL,*next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        shead->next=prev;
        ListNode* temp=head;
        slow=shead->next;
        curr=slow;
        while(temp!=slow){
            if(temp->val!=curr->val)
            return false;
            temp=temp->next;
            curr=curr->next;
        }
        return true;
        
    }
};