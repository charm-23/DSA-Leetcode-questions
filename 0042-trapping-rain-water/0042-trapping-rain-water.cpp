class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(); 
        vector<int>suffix(n); 
        suffix[n-1]=0; 

        for(int i=n-2; i>=0; i--){
            suffix[i]= max(suffix[i+1], height[i+1]); 
        }

        int water=0; 
        int leftmax=height[0]; 

        for(int i=1; i<n; i++){
            water+= max(0, min(leftmax, suffix[i])-height[i]); 
            leftmax= max(leftmax, height[i]); 
        }

        return water; 
    }
};