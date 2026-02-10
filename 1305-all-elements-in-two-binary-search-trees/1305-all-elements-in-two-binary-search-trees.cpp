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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans; 
        stack<TreeNode*> st1; 
        stack<TreeNode*> st2; 
        
        while(root1){
            st1.push(root1);
            root1= root1->left;
        }

        while(root2){
            st2.push(root2);
            root2= root2->left;
        }

        while(!st1.empty() && !st2.empty()){
            if(st1.top()->val <=st2.top()->val){
                ans.push_back(st1.top()->val); 
                TreeNode* temp= st1.top()->right; 
                st1.pop(); 
                while(temp){
                    st1.push(temp);
                    temp= temp->left;  
                }
            }
            else{
                ans.push_back(st2.top()->val); 
                TreeNode* temp= st2.top()->right; 
                st2.pop(); 
                while(temp){
                    st2.push(temp);
                    temp= temp->left;  
                }

            }
        }

        while(!st1.empty()){
            TreeNode* node= st1.top(); 
            st1.pop();
            ans.push_back(node->val); 

            node= node->right; 
            while(node){
                st1.push(node); 
                node= node->left; 
            }
        }


        while(!st2.empty()){
            TreeNode* node= st2.top(); 
            st2.pop();
            ans.push_back(node->val); 

            node= node->right; 
            while(node){
                st2.push(node); 
                node= node->left; 
            }
        }

       
    return ans; 
    }
};