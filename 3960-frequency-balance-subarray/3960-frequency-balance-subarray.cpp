class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size(); 
        int ans=1; 

        for(int i=0; i<nums.size(); i++){ 
            unordered_map<int, int>freq; 
            map<int, int>cntfreq; 

            for(int j=i; j<nums.size(); j++){
                if(freq.find(nums[j])!=freq.end()){ 
                    cntfreq[freq[nums[j]]]--; 
                    if(cntfreq[freq[nums[j]]]==0) cntfreq.erase(freq[nums[j]]);
                }
                freq[nums[j]]++;
                cntfreq[freq[nums[j]]]++; 
                if(freqbalance(freq, cntfreq)) ans= max(ans, j-i+1); 
            }
        }
        return ans; 
    }

    bool freqbalance(unordered_map<int, int>&freq, map<int, int>&cntfreq){
        if(freq.size()==1) return true; 
        if(cntfreq.size()!=2) return false;
        auto it=cntfreq.begin(); 
        int minfreq= it->first; 
        it++;

        return it->first==2*minfreq; 
    }
};