class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        unordered_map<int,int>mpp1; unordered_map<int,int>mpp2; 
        for(int i=0; i<A.size(); i++){
            mpp1[A[i]]++; mpp2[B[i]]++;
            int cnt=0; 
            for(auto k:mpp1){
                if(mpp2.find(k.first)!=mpp2.end()){
                    cnt+=min(mpp2[k.first], mpp1[k.first]); 
                }
            }
            ans.push_back(cnt);
        }
    return ans; 
    }
};