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
    int maxPathSum(TreeNode* root) {
        int maxsum= INT_MIN; 
        solve(root, maxsum); 
        return maxsum; 
    }

    int solve(TreeNode* root, int &maxsum){
        if(root==NULL) return 0; 
        int leftsum= solve(root->left,maxsum); 
        int rightsum= solve(root->right,maxsum);

        int sum= max(rightsum+ root->val, max(leftsum+ root->val ,max(root->val, leftsum + root->val + rightsum)));

        maxsum= max(maxsum,sum);
        return max(root->val,max(rightsum+ root->val, leftsum+ root->val)); 
    }
};