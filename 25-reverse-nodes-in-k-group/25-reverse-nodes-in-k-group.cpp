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
        while(root!=NULL){
            count++;
            root=root->next;
        }
        return count;
    }
    ListNode* oh=NULL,*ot=NULL,*th=NULL,*tt=NULL;
    void add(ListNode* root){
        if(th==NULL){
            th=root;
            tt=root;
        }
        else{
            root->next=th;
            th=root;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=length(head);
        while(len>0){
            if(len-k>=0){
                int cnt=k;
                while(cnt--){
                    ListNode* temp=head->next;
                    head->next=NULL;
                    add(head);
                    head=temp;
                }
                len-=k;
                if(oh==NULL){
                    oh=th;
                    ot=tt;
                    
            
            }
                else{
                    ot->next=th;
                    ot=tt;
                    
                }
                th=NULL,tt=NULL;
        }
        else{
            ot->next=head;
            break;
        }
        }
            return oh;
    }
};