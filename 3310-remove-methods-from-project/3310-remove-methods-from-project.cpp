class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>ans; 
        unordered_map<int, vector<int>>invoking; 
        unordered_map<int, vector<int>>invokedby;
        set<int>s;

        for(auto &i: invocations){
            int num1=i[0]; 
            int num2=i[1];

            invoking[num1].push_back(num2); 
            invokedby[num2].push_back(num1); 
        }

        helper(invoking, k, s);
        bool none=false; 

        for(int i:s){
            for(int ngbr: invokedby[i]){
                if(s.find(ngbr)==s.end()){
                    none=true;
                    break;
                } 
            }
        }

        if(none==true){
            for(int i=0; i<=n-1; i++) ans.push_back(i); 
        }
        else{
            for(int i=0; i<=n-1; i++){
                if(s.find(i)==s.end()) ans.push_back(i); 
            }
        }

        return ans; 
    }

    void helper(unordered_map<int, vector<int>>&invoking, int k, set<int>&s){
        if(s.count(k)) return;
        s.insert(k); 

        for(int i: invoking[k]){
            helper(invoking, i, s); 
        }
    }
};