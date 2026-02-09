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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy =new ListNode(-1,head);
        ListNode* temp= dummy; 
        ListNode*curr=head; 
        int cnt=0;
        
        while(head!=NULL){
            cnt++; 
            head=head->next;
        }

        for(int i=0; i<cnt-n ;i++){
            temp=temp->next; 
            curr=curr->next;
        }

        ListNode* nextnode= curr->next;
        temp->next= nextnode;
        
        return dummy->next;
    }
};