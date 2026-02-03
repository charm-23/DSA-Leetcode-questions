class Solution {
public: 
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right; 
        else if(root->right==NULL) return root->left; 
        else{
            TreeNode* rightchild= root->right; 
            TreeNode* leftchild= root->left; 
            TreeNode* dummy= root->left; 
            TreeNode* temp= root->right; 
            while(leftchild->right!=NULL){
                leftchild= leftchild->right; 
            }
            leftchild->right= temp; 
            return dummy; 
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL; 
        if(root->val== key){
            return helper(root); 
        }

        TreeNode* curr= root; 
        while(curr!=NULL){
            if(key<curr->val){
                if(curr->left && curr->left->val==key){
                    curr->left=  helper(curr->left); 
                }
                else{
                    curr=curr->left; 
                } 

            }
            else if(key>curr->val){
                if(curr->right && curr->right->val==key){
                    curr->right=  helper(curr->right); 
                }
                else{
                    curr=curr->right; 
                }

            }
        }
    return root; 
    }
};