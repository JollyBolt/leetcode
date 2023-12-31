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
    ListNode* removeElements(ListNode* head, int val) {
        //Iterative
    //     ListNode *shead=new ListNode(0,head);
    //     ListNode* temp=shead;
    //     while(head)
    //     {   
    //         while(head and head->val==val) head=head->next;

    //         temp->next=head;
    //         temp=head;
    //         if(head) head=head->next; 
    //     }

    // return shead->next; 

        //Recursive
        if(!head) return NULL;
        ListNode *temp=removeElements(head->next,val);
        if(head->val==val) return temp;
        head->next=temp;
        return head;   
    }
};