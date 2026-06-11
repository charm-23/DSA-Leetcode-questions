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
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0; 
        int num=0; 
        int maxi= root->val; 
        solve(root, maxi, num); 
        return num;  
    }

    void solve(TreeNode* root, int maxi, int &num){
        if(root==NULL) return; 
        if(root->val >= maxi){
            num+=1; 
        }
        maxi= max(maxi, root->val); 
        solve(root->left, maxi, num); 
        solve(root->right, maxi, num); 
    }
};