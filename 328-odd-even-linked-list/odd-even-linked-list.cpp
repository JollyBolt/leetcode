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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next or !head->next->next) return head;
        ListNode*temp=head,*odd=head->next,*temp2=head->next;
        while(1){
            if(temp->next and temp->next->next){
                temp->next=temp->next->next;
                temp=temp->next;
            }
            if(temp2->next and temp2->next->next){
                temp2->next=temp2->next->next;
                temp2=temp2->next;
            }
            else {
                temp2->next=NULL;
                break;
            }  
        }
        temp->next=odd;
        return head;
    }
};