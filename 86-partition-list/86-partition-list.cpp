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
    ListNode* partition(ListNode* head, int x) {
        ListNode* nh=new ListNode(0),*sec=new ListNode(0);
        ListNode * root=head,*nhh=nh,*temp=sec;
        while(root!=NULL){
            if(root->val<x){
                sec->next=root;
                sec=sec->next;
            }
            else{
                nh->next=root;
                nh=nh->next;
            }
            root=root->next;
        }
        sec->next=nhh->next;
        // root=nhh->next;
        nh->next=NULL;
        return temp->next;
    }
};