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

// optimal TC= O(N)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(maxDepth(root)==-1) return false; 
    return true; 
    }

    int maxDepth(TreeNode* node){
        if(node==NULL) return 0; 

        if(maxDepth(node->left)==-1 || maxDepth(node->right)==-1) return -1; 
        
        int lh=1+ maxDepth(node->left); 
        int rh= 1+ maxDepth(node->right);

        if(abs(lh-rh)>1) return -1; 
        return max(lh,rh); 
    }
};