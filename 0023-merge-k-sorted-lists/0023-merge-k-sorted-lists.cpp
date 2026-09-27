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
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val; 
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode* , vector<ListNode*>, cmp> minh; 

        for(ListNode* i :lists){
            if(i!=NULL) minh.push(i); 
        }

        ListNode* dummy= new ListNode(-1); 
        ListNode* temp=dummy; 

        while(!minh.empty()){
            ListNode* temp1= minh.top(); 
            minh.pop(); 

            temp->next= temp1; 
            temp=temp->next; 

            if(temp1->next!=NULL) minh.push(temp1->next); 
        }

        return dummy->next; 
    }
};