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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>>minh; 

        for(auto i: lists){
            ListNode* temp= i; 
            while(temp!=NULL){
                minh.push(temp->val);
                temp=temp->next; 
            } 
        }

        if(minh.empty()) return NULL; 

        ListNode* head= new ListNode(minh.top()); 
        ListNode* temp= head; 
        minh.pop(); 
        
        while(!minh.empty()){
            ListNode* temp1= new ListNode(minh.top());
            temp->next= temp1; 
            temp=temp1; 
            minh.pop();   
        }
    return head; 
    }
};