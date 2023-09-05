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
        // if(!head or !head->next) return true;
        ListNode* fast=head,*slow=head;
        while(fast and fast->next and fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode *curr=slow->next,*prev=NULL,*next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        slow->next=prev;
        ListNode* temp=head;
        curr=slow->next;
        while(curr){
            if(temp->val!=curr->val)
            return false;
            temp=temp->next;
            curr=curr->next;
        }
        return true;
        
    }
};