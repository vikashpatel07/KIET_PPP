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
    ListNode* m(ListNode* root){
        ListNode *dummy=new ListNode(0);
        dummy->next=root;
        ListNode *slow=dummy,* fast=dummy;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *rev(ListNode* root){
        ListNode* dummy=NULL,*temp;
        while(root){
            temp=root->next;
            root->next=dummy;
            dummy=root;
            root=temp;
        }
        return dummy;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid=m(head);
        ListNode * re=rev(mid->next);
        while(re){
            if(re->val!=head->val)return false;
            re=re->next;
            head=head->next;
        }
        return true;
    }
};