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
    ListNode* deleteDuplicates(ListNode* head) {
        //Iterative Way
        // ListNode* temp=head;
        // if(head==NULL)
        // return head;
        // while(temp->next)
        // {
        //     if(temp->val==temp->next->val)
        //     temp->next=temp->next->next;
        //     else temp=temp->next;
        // }

        // Recursive way
        if(!head or !head->next) return head;
        ListNode *nhead = deleteDuplicates(head->next);
        if(head->val==nhead->val) return nhead;
        else head->next = nhead;
        
    return head;    
    }
};