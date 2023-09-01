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
        if(!head or !head->next) return head;
        ListNode *shead=new ListNode(0,head);
        ListNode* temp=shead;
        while(head)
        {
            // if(!head->next){
            //     temp->next=head;
            //     break;
            // }
            int x=head->val;
            if(!head->next or head->next->val!=x)
            {
                temp->next=head;
                temp=head;
                head=head->next;
            }
            else {
                while(head and head->val==x){
                    head=head->next;
                }
                temp->next=head;
            }
        }
    return shead->next;    
    }
};