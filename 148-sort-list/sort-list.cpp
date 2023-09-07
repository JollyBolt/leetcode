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

    ListNode* mergeSort(ListNode* head){
        if(!head or !head->next) return head;

        ListNode* fast=head,*slow=head;
        while(fast->next and fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* newNode = slow->next;
        slow->next=NULL;
        ListNode* list1=mergeSort(head);
        ListNode* list2=mergeSort(newNode);
        return mergeTwoLists(list1,list2);
    }
    ListNode* sortList(ListNode* head) {
        //Simple Recursive Approach
        /*
        if(!head or !head->next) return head;
        ListNode *newnode = sortList(head->next);
        ListNode*temp=head;
        while(temp->next and temp->val>temp->next->val){
            swap(temp->val,temp->next->val);
            temp=temp->next;
        }
        return head;
        Time Complexity: O(n^2)
        Space Complexity: O(n) for recursive stack
        */
        //Merge sort Approach
        return mergeSort(head);
    }
};