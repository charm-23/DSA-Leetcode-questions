class mycomp{
    public:
    bool operator()(pair<int,string>a, pair<int,string>b){
        if(a.first==b.first){
            return a.second<b.second; //if parent<child i want to swap; 
        }
        return a.first>b.first; //in minheap if parent>child i want to swap; 
    }
}; 

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mpp; 
        vector<string>ans; 

        for(string s: words){
            mpp[s]++; 
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, mycomp>minh; 

        for(auto &i:mpp){
            int cnt=i.second; 
            string ch = i.first;

            minh.push({cnt, ch});

            if(minh.size()>k){
                minh.pop(); 
            } 
        }

        while(!minh.empty()){
            ans.push_back(minh.top().second); 
            minh.pop(); 
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};