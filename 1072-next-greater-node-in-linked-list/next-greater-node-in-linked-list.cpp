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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> s1,s2;
        while(head){
            s1.push(head->val);
            head=head->next;
        }
        int n=s1.size();
        vector<int> ans(n,0);
        n--;
        while(!s1.empty()){
            int x=s1.top();
            s1.pop();
            while(!s2.empty() and s2.top()<=x) s2.pop();
            if(!s2.empty()) ans[n]=s2.top();
            n--;
            s2.push(x); 
        }
        return ans;
    }
};