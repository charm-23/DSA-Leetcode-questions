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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL; 
        TreeNode*curr =root; 

        if(root->val==key){
            return helper(root); 
        }

        while(curr){
            if(key<curr->val){
                if(curr->left && curr->left->val==key){
                    curr->left= helper(curr->left); 
                    break; 
                }
                else curr=curr->left; 
            }

            else if(key>curr->val){
               if(curr->right && curr->right->val==key){
                curr->right= helper(curr->right); 
                break; 
               }
               else curr=curr->right; 
            }
        }  

        return root; 
    }

    TreeNode* helper(TreeNode* node){
        if(!node->left && !node->right) return NULL; 
        if(node->left==NULL) return node->right; 
        if(node->right==NULL) return node->left; 

        TreeNode* leftchild= node->left; 
        TreeNode* rightchild= node->right; 
        TreeNode* rightleftmostchild= node->right;

        while(rightleftmostchild->left!=NULL){
            rightleftmostchild= rightleftmostchild->left; 
        }

        rightleftmostchild->left= leftchild;

        return rightchild; 
    }
};