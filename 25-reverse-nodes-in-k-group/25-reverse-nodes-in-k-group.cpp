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
    int length(ListNode* root){
        int count=0;
        while(root){
            count++;
            root=root->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=length(head);
        if(len<k)return head;
        int cnt=k;
        ListNode* temp=NULL,*nh=NULL,*old=head;
        while(cnt--){
            temp=head->next;
            head->next=nh;
            nh=head;
            head=temp;
        }
        if(head)old->next=reverseKGroup(head,k);
        return nh;
    }
};