class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s; 
        int ans=0; 
        //iterate over set not nums becuase in case of duplicates it will do the same work multiple times. 

        for(int num: nums) s.insert(num); 

        for(int num: s){ 
            if(s.find(num-1)==s.end()){
                int len=0; 
                while(s.find(num)!=s.end()){
                    len++; num++; 
                }
                ans= max(len, ans); 
            }
        }
        return ans; 
    }
};