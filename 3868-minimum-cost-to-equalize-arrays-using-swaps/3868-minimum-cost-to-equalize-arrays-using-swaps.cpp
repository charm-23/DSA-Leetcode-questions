class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mpp1; 
        unordered_map<int, int>mpp2; 

        for(int i:nums1){
            mpp1[i]++; 
        }

        for(int i:nums2){
            mpp2[i]++; 
        }

        int swaps=0; 
        for(auto &i:mpp1){
            int num=i.first; 
            int cnt1=i.second; 
            int cnt2=mpp2[num]; 

            int total= cnt1+cnt2; 
            if(total%2!=0) return -1; 

            if(mpp1[num]!=total/2){
                int diff=abs(mpp1[num]-mpp2[num]); 
                swaps+=diff/2; 
            }
        }

        for(auto &i:mpp2){
            int num=i.first; 
            int cnt1=i.second; 

            if(mpp1.find(num)==mpp1.end()){
                if(cnt1%2!=0) return -1; 
                swaps+=cnt1/2; 
            }
        }

        return swaps/2; 
    }
};