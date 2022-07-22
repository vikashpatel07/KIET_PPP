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
    ListNode*oh=NULL,*ot=NULL;
    void add(ListNode* root){
        if(oh==NULL){
            oh=root;
            ot=root;
        }
        else{
            root->next=oh;
            oh=root;
        }
    }
    ListNode* reverseList(ListNode* head) {
        while(head!=NULL){
            ListNode* temp=head->next;
            head->next=NULL;
            add(head);
            head=temp;
            
        }
        return oh;
    }
};