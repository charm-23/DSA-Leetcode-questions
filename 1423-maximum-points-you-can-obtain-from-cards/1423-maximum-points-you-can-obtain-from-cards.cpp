class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int n=cardPoints.size(); 
       int l=0; int r=n-1; 
       int finalans=0; int ans=0;

       while(l<k){
        ans+= cardPoints[l]; 
        l++;
       }

       finalans= max(ans,finalans); 
       l--; 
       while(l>=0){
        ans-=cardPoints[l]; 
        l--; 
        ans+=cardPoints[r]; 
        r--; 
        finalans= max(ans,finalans); 
       }

       return finalans; 
    }
};