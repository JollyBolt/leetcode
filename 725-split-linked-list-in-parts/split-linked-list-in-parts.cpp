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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode*temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        temp=head;
        vector<ListNode*> ans;

        if(k<n){
            int x=n/k;
            int y=n%k;
            k--;
            while(k--){
                int i=0;
                ListNode* ntemp=head;
                while(i<x-1){
                    ntemp=ntemp->next;
                    i++;
                }
                if(y>0) {
                    ntemp=ntemp->next;
                    y--;
                }
                temp=ntemp->next;
                ntemp->next=NULL;
                ans.push_back(head);
                head=temp;
            }
            ans.push_back(head);
        }
        else{
            while(k--){
                if(temp){
                    ListNode* ntemp=new ListNode(temp->val,nullptr);
                    ans.push_back(ntemp);
                }
                else ans.push_back(nullptr);
                if(temp) temp=temp->next;
            }
        }

        return ans;
    }
};