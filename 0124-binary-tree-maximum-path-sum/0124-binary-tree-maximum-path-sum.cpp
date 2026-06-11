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
        int leftsum= max(0,solve(root->left,maxsum)); 
        int rightsum= max(0,solve(root->right,maxsum));

        int sum=leftsum + root->val + rightsum;

        maxsum= max(maxsum,sum);
        return root->val+ max(rightsum, leftsum); 
    }
};