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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size(); 
        unordered_map<int, int>mpp; 

        for(int i=0; i<n; i++){
            mpp[inorder[i]]=i; 
        }
    
        TreeNode* root= helper(preorder, inorder, 0, n-1, 0, n-1, mpp); 

        return root; 
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend, unordered_map<int, int>&mpp){
        if(prestart>preend || instart>inend) return NULL; 

        TreeNode* node= new TreeNode(preorder[prestart]); 

        int inmap= mpp[node->val]; 
        int numsleft= inmap-instart;

        node->left= helper(preorder, inorder, prestart+1, prestart+numsleft, instart, inmap-1, mpp); 
        node->right= helper(preorder, inorder, prestart+numsleft+1, preend, inmap+1, inend, mpp); 

        return node; 
    }
};