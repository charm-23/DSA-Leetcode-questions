class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp; 
        for(int i: nums2){
            mpp[i]++;
        }

        for(int i:nums1){
            if(mpp.find(i)!=mpp.end()) return i; 
        }
    return -1; 
    }
};