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
        //iterative --> parent map + ancestors set; 
        unordered_map<TreeNode*, TreeNode*>parent;
        queue<TreeNode*>qu; 
        qu.push(root); 
        parent[root]=NULL;

        while(!qu.empty()){
            TreeNode* node= qu.front(); 
            qu.pop(); 

            if(node->left){
                parent[node->left]=node; 
                qu.push(node->left); 
            }

            if(node->right){
                parent[node->right]=node; 
                qu.push(node->right); 
            }
        }

        unordered_set<TreeNode*>ancestors; 
        while(p){
            ancestors.insert(p); 
            p=parent[p]; 
        }

        while(q){
            if(ancestors.count(q)) return q; 
            q=parent[q]; 
        }

        return NULL; 
    }
};