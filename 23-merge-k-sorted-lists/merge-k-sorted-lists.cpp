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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> minh;
        int n=lists.size();
        for(int i=0;i<n;i++){
            ListNode *temp = lists[i];
            while(temp){
                minh.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode *head = new ListNode();
        ListNode *temp=head;
        while(!minh.empty()){
            int x=minh.top();
            ListNode *dummy = new ListNode(x);
            temp->next=dummy;
            temp=temp->next;
            minh.pop();
        }
        return head->next;
    }
};