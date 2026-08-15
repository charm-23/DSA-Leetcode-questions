/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> mpp; 
        Node* newnode= new Node(node->val); 
        mpp[node]= newnode;

        //dfs
        dfs(node, mpp); 

        return newnode;
    }

    void dfs(Node* node, unordered_map<Node*, Node*>&mpp){
        for(Node* i: node->neighbors){
            if(mpp.find(i)==mpp.end()){
                Node* newnode= new Node(i->val); 
                mpp[i]=newnode; 
                (mpp[node]->neighbors).push_back(newnode); 
                dfs(i, mpp); 
            }
            else (mpp[node]->neighbors).push_back(mpp[i]); 
        }
    }
};