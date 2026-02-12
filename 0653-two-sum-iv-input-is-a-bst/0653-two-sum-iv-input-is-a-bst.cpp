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
class BSTiterator{
    stack<TreeNode*> st; 
    bool reverse= true;

public:
    BSTiterator(TreeNode* root, bool isReverse){
        reverse= isReverse; 
        st.push(root); 
        if(reverse==true){ //desc 
            pushAll(root->right);
        }
        else{
            pushAll(root->left); 
        }
    }

    bool hasnext(){
        return !st.empty();
    }

    int next(){
        TreeNode* ans= st.top(); 
        st.pop(); 
        if(reverse==true){
            if(ans->left){
                pushAll(ans->left); 
            }
        }
        else{
            if(ans->right){
                pushAll(ans->right); 
            }
        }
    return ans->val; 
    }

    void pushAll(TreeNode* node){
        if(reverse==true){
            while(node){
                st.push(node); 
                node=node->right; 
            }
        }
        else{
            while(node){
                st.push(node); 
                node=node->left; 
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false; 
        BSTiterator l(root, false);
        BSTiterator r(root, true);

        int i= l.next();
        int j= r.next(); 

        while(i<j){
            if(i+j==k) return true; 
            else if(i+j<k) i=l.next(); 
            else j=r.next(); 
        }
    return false; 
    }
};