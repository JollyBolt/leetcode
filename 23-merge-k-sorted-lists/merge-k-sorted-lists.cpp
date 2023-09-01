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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head,*temp;
        head = new ListNode();
        temp=head;
        while(list1 and list2)
        {
            if(list1->val<list2->val)
            {
                temp->next=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;           
        }
        if(list1)
        {
            temp->next=list1;
        }
        if(list2)
        {
            temp->next=list2;
        }
        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Using Heap
        // priority_queue<int,vector<int>,greater<int>> minh;
        // int n=lists.size();
        // for(int i=0;i<n;i++){
        //     ListNode *temp = lists[i];
        //     while(temp){
        //         minh.push(temp->val);
        //         temp=temp->next;
        //     }
        // }
        // ListNode *head = new ListNode();
        // ListNode *temp=head;
        // while(!minh.empty()){
        //     int x=minh.top();
        //     ListNode *dummy = new ListNode(x);
        //     temp->next=dummy;
        //     temp=temp->next;
        //     minh.pop();
        // }
        // return head->next;

        //Using Merge
        int n=lists.size();
        if(n==0) return NULL;
        cout<<n;
        while(lists.size()>1){
            n=lists.size();
            vector<ListNode*> v;    
            for(int i=0;i<n;i+=2){
                ListNode *one = lists[i],*two=(i>=n-1)?NULL:lists[i+1];
                v.push_back(mergeTwoLists(one,two));
            }
            lists=v;
            cout<<lists.size();
        }
        return lists[0];
        
    }
};