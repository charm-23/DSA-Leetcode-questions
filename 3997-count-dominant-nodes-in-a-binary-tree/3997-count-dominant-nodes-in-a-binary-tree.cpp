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
    int countDominantNodes(TreeNode* root) {
        int dominant=0; 
        helper(root, dominant); 
        return dominant; 
    }

    int helper(TreeNode* root, int &dominant){
        if(root==NULL) return 0; 

        int left= helper(root->left, dominant); 
        int right= helper(root->right, dominant); 

        if(root->val>=left && root->val>=right){
            dominant++; 
            return root->val; 
        }

        return left>right? left: right; 
    }
};