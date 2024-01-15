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
        if(!head or !head->next) return head;
        ListNode* nHead = new ListNode(0,head);
        ListNode* temp = nHead;
        while(head and head->next){
            ListNode* next=head->next;
            head->next=next->next;
            next->next=head;
            temp->next=next;
            temp=head;
            head=head->next;
        }
        return nHead->next;
    }
};