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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // if(!head or !head->next) return head;
        unordered_map<int,ListNode*> m;
        ListNode* dummy = new ListNode(0,head);
        int sum=0;
        m[0]=dummy;
        while(head){
            sum+=head->val;
            if(m.find(sum)==m.end()) {
                m[sum] = head;
            }else{
                ListNode* temp = m[sum]->next;
                int newSum = sum;
                while(temp!=head){
                    newSum+=temp->val;
                    m.erase(newSum);
                    temp=temp->next;
                }
                m[sum]->next=head->next;
            }
            head=head->next;
        }
        return dummy->next;
    }
};