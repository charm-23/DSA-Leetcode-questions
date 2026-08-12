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
    void reorderList(ListNode* head) {
        ListNode* slow=head; 
        ListNode* fast=head; 

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next; 
            fast=fast->next->next; 
        }

        ListNode* curr= slow->next; 
        slow->next=NULL; 
        ListNode* dummy=NULL; 

        while(curr){
            ListNode* temp= curr->next;
            curr->next=dummy; 
            dummy=curr; 
            curr=temp; 
        }

        ListNode* start1=head; 
        ListNode* start2 = dummy;

        while(start1 !=NULL && start2!=NULL){
            ListNode* next1= start1->next; 
            ListNode* next2= start2->next;

            start1->next=start2;
            start2->next=next1;

            start1=next1;
            start2=next2;
        }
    }
};