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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q; 
        unordered_map<TreeNode*, TreeNode*>parent;
        q.push(root); 
        parent[root]=NULL; 

        while(!q.empty()){
            TreeNode* curr=q.front(); 
            q.pop(); 

            if(curr->left){
                parent[curr->left]=curr; 
                q.push(curr->left); 
            }

            if(curr->right){
                parent[curr->right]=curr; 
                q.push(curr->right); 
            }
        }

        q.push(target); 

        int level=0; vector<int>ans; unordered_set<TreeNode*>s; 

        s.insert(target); 

        while(!q.empty()){
            int size= q.size(); 

            if(level==k){
                while(!q.empty()){
                    ans.push_back(q.front()->val); 
                    q.pop();
                }
                return ans;
            }

            for(int i=0; i<size; i++){
                TreeNode* ip=q.front(); 
                q.pop(); 

                if(ip->left && !s.count(ip->left)){q.push(ip->left); s.insert(ip->left);}
                if(ip->right && !s.count(ip->right)){q.push(ip->right); s.insert(ip->right);}
                if(parent[ip] && !s.count(parent[ip])){q.push(parent[ip]); s.insert(parent[ip]);}
            }

            level++; 
        }

        return ans; 

    }
};