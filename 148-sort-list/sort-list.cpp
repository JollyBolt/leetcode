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
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode *newnode = sortList(head->next);
        ListNode*temp=head;
        while(temp->next and temp->val>temp->next->val){
            swap(temp->val,temp->next->val);
            temp=temp->next;
        }
        return head;
    }
};