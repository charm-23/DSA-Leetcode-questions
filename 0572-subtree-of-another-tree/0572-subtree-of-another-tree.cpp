/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true; 
        if(!root) return false; 
        if(root->val==subRoot->val){
            if(isSame(root, subRoot)) return true; 
        }
        if(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)) return true; 
    return false; 
    }

    bool isSame(TreeNode* root, TreeNode* subroot) {
        if (root == NULL && subroot == NULL)
            return true;
        if (!root && subroot || root &&!subroot)
            return false;
        if (root->val != subroot->val)
            return false;
        if (!isSame(root->left, subroot->left) || !isSame(root->right, subroot->right))
            return false;
        return true;
    }
};