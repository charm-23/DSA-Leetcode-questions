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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>minh; 

        for(ListNode* i: lists){
            if(i!=NULL) minh.push({i->val, i}); 
        }

        ListNode* temp= new ListNode(-1); 
        ListNode* dummy=temp; 

        while(!minh.empty()){
            pair<int, ListNode*> temp1 = minh.top(); 
            minh.pop(); 

            int val=temp1.first; 
            ListNode* node= temp1.second; 

            temp->next=node; 
            temp=temp->next; 

            if(node->next) minh.push({node->next->val, node->next}); 
        }

        return dummy->next;
    }
};