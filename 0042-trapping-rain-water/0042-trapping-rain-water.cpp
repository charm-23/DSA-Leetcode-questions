class Solution {
public:
    int trap(vector<int>& height){
        int n=height.size(); 
        vector<int>suffix(n); 
        int leftmax=0; 
        int ans=0;

        suffix[n-1]=height[n-1];

        for(int i=height.size()-2; i>=0; i--){
            suffix[i]= max(suffix[i+1], height[i]);
        } 

        for(int i=0; i<height.size(); i++){
            leftmax= max(leftmax, height[i]);
            int rightmax= suffix[i]; 
            ans+= min(leftmax, rightmax)- height[i]; 
        }

    return ans; 
    }
};