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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int len=0;
        ListNode* root=head;
        while(root){
            len++;
            root=root->next;
        }
        
        int cnt=0;
        if(len==1){
            return head;
        }
        ListNode * temp=head,*t=NULL,*nh=head;;
        while(head){
             cnt++;
            if(cnt==left-1)t=head;
            if(cnt==left){
                while(cnt<=right){
                    root=head->next;
                    head->next=NULL;
                    add(head);
                    head=root;
                    cnt++;
                }
                ot->next=head;
                if(left==1)return oh;
                if(t!=NULL)
                t->next=oh;
                
                return nh;
                
            }
           
            head=head->next;
        }
        return nh;
    }
};