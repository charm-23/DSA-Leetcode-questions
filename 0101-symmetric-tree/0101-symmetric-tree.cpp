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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true; 
        TreeNode* t1= root->left; 
        TreeNode* t2= root->right; 

        return check(t1, t2);
    }

    bool check (TreeNode* t1, TreeNode* t2){
        if(t1==NULL && t2==NULL) return true; 
        if(t1==NULL) return false; 
        if(t2==NULL) return false; 
        if(t1->val != t2->val) return false; 

        if(!check(t1->left, t2->right)) return false; 
        if(!check(t1->right, t2->left)) return false; 

        return true; 
    }
};