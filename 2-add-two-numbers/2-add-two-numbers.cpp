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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(1);
        ListNode *res=dummy;
        int carry=0;
        while(l1 || l2 || carry){
            int data=0;
            if(l1){
                data+=l1->val;
                l1=l1->next;
            }
            if(l2){
                data+=l2->val;
                l2=l2->next;
            }
            data+=carry;
            carry=data/10;
            res->next=new ListNode(data%10);
            res=res->next;
        }
        return dummy->next;
    }
};