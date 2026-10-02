class Solution {
public:
    void generate(vector<int>&nums, int index, int end, vector<vector<int>>&sums, int count, int sum){
        if(index==end){
            sums[count].push_back({sum}); 
            return; 
        }
        generate(nums, index+1, end,sums, count, sum); 
        generate(nums, index+1, end, sums, count+1, sum+nums[index]); 
    }

    int minimumDifference(vector<int>& nums) {
        int n= nums.size(); 
       //s1-s2= D ; s1+s2=S; s1-(S-s1)=D --> abs(2s1-S)= D (min) s1=S/2; (closest to)

       //meet in the middle--> leftsum+ rightsum= S/2; 
       vector<vector<int>>left((n/2)+1); // 0 1 2 
       vector<vector<int>>right((n/2)+1); 

       int sum=accumulate(nums.begin(), nums.end(), 0); 

       //step1--> generate subsets; 
       generate(nums, 0, n/2, left, 0, 0); 
       generate(nums, n/2, n, right, 0, 0); 

       int ans=INT_MAX; 

       for(int k=0; k<=n/2; k++){
        vector<int> leftcount=left[k]; 
        vector<int> rightcount=right[n/2-k];

        sort(rightcount.begin(), rightcount.end()); 

        for(int leftsum: leftcount){
            int rightsum= sum/2 - leftsum; 

            auto it= lower_bound(rightcount.begin(), rightcount.end(), rightsum); 

            if(it!=rightcount.end()){
                ans=min(ans, abs(2*(leftsum+ *it)-sum)); 
            }

            if(it!=rightcount.begin()){
                it--; 
                ans=min(ans, abs(2*(leftsum+ *it)-sum)); 
            }
        }

       }

       return ans; 
    }
};