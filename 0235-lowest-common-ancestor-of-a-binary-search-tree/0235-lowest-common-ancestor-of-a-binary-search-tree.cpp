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
            if(a== root->val || b== root->val){
                return root; 
            }
            else if(a< root->val && root->val< b) return root; 

            else if(a< root->val && b <root->val){
                root= root->left; 
            }
            else{ 
                root= root->right; 
            }
        }
    return NULL; 
    }
};