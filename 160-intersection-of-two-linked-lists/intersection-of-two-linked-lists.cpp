/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA, *temp2 = headB;
        int count = 0;
        while(temp1 and temp2){
            if(temp1==temp2) return temp1;
            if(!temp1->next){
                if(count<2){
                    temp1=headB;
                    count++;
                }else return NULL;
            }else temp1=temp1->next;
            if(!temp2->next){
                if(count<2){
                    temp2=headA;
                    count++;
                }else return NULL;
            }else temp2=temp2->next;
            
        }
        return NULL;
    }
};