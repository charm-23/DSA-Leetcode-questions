/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a= min(p->val, q->val); 
        int b= max(p->val, q->val); 

        while(root){
            if(b<root->val) root=root->left;
            else if(a>root->val) root= root->right; 
            else return root; 
        }
    return NULL; 
    }
};