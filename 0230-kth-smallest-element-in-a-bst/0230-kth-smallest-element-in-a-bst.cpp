/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        queue<int>q;
        helper(root, k, q); 
        int ele=1; 
        while(!q.empty()){
            if(ele==k) return q.front(); 
            ele++; 
            q.pop();
        }
    return -1;
    }

    void helper(TreeNode* root, int k, queue<int>&q){
        if(root==NULL) return;  
        helper(root->left, k, q);
        q.push(root->val);
        helper(root->right,k, q); 
    }
};