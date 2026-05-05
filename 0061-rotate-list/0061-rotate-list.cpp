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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0 || head->next==NULL){
            return head;
        }

        int len=1;
        ListNode* last= head; 
        while(last->next!=NULL){
            last=last->next; 
            len++; 
        }

        k=k%len; //normalise k
        if(k==0) return head; 
        int rem= len-k; 
        ListNode* first=head;
        ListNode* newtail= NULL; 

        for(int i=0; i<rem; i++){
            newtail=first;
            first= first->next;
        }
        newtail->next= NULL;
        last->next= head; 

    return first; 
    }
};