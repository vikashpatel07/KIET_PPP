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
    ListNode* oh=NULL,*ot=NULL;
    void add(ListNode* head){
        if(oh==NULL){
            oh=head;
            ot=head;
        }
        else
        {
            head->next=oh;
            oh=head;
        }
            
        
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        while(head){
            temp=head->next;
            head->next=NULL;
            add(head);
            head=temp;
        }
        return oh;
    }
};