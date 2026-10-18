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
    int widthOfBinaryTree(TreeNode* root) {
        //use CBT indexing i-->left node= 2*i+1, right node= 2*i+2; 
        if (!root) return 0; 
        queue<pair<TreeNode*, int>>q; 
        q.push({root, 0}); 
        int maxwidth=0; 

        while(!q.empty()){
            int startindex= q.front().second; 
            int endindex= q.back().second; 
            maxwidth= max(maxwidth, endindex-startindex+1); 

            int size= q.size(); 
            for(int i=0; i<size; i++){
                TreeNode* node= q.front().first; 
                long long index= q.front().second; 

                q.pop(); 

                if(node->left) q.push({node->left, 2*index+1}); 
                if(node->right) q.push({node->right, 2*index+2}); 
            }
        }
        return maxwidth; 
    }
};