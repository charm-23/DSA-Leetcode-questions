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
    int averageOfSubtree(TreeNode* root) {
        int ans=0; 
        dfs(root, ans); 
        return ans; 
    }

    pair<int, int> dfs(TreeNode* root, int &ans){
        if(root==NULL) return {0, 0}; 

        pair<int, int> lefttree= dfs(root->left, ans); 

        pair<int, int>righttree= dfs(root->right, ans); 

        int sum= lefttree.first + righttree.first + root->val; 
        int count= 1+ lefttree.second + righttree.second;

        if(root->val== sum/count) ans++; 

        return {sum, count}; 
    }


};