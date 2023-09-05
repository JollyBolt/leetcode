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
        //Initial Approach
        // int c1=0,c2=0;
        // ListNode *temp=headA;
        // while(temp){
        //     c1++;
        //     temp=temp->next;
        // }
        // temp=headB;
        // while(temp){
        //     c2++;
        //     temp=temp->next;
        // }
        // if(c1>c2){
        //     int x=c1-c2;
        //     while(x--) headA=headA->next;
        // }
        // else {
        //     int x=c2-c1;
        //     while(x--) headB=headB->next;
        // }
        // while(headA){
        //     if(headA==headB)
        //     return headA;
        //     else {
        //         headA=headA->next;
        //         headB=headB->next; 
        //     }
        // }
        // return NULL;

        //Different Approach
        ListNode* a=headA,*b=headB;
        while(a!=b){
            if(!a) a=headB;
            else a=a->next;

            if(!b) b=headA;
            else b=b->next;
        }
        return a;

    }
};