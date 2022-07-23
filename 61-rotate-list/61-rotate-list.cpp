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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=length(head);
        if(!head || !head->next || k==0)return head;
        k=k%len;
        if(k==0)return head;
        int diff=len-k-1;
        ListNode* temp=head;
        while(diff--){
            temp=temp->next;
        }
        ListNode* nh=temp->next;
        temp->next=NULL;
        ListNode* last=nh;
        while(1){
            if(last->next==NULL)break;
            last=last->next;
        }
         last->next=head;
        return nh;
    }
};