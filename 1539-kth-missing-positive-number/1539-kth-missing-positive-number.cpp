class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int j=0; int num=1; 
       while(j<arr.size() && k>0){
        if(num==arr[j]){
            j++;
        }
        else{
            k--;
            if(k==0) return num;
        }
        num++; 
       }

       while(k>0){
        k--;
        if(k==0) return num;
        num++; 
       }
       
    return -1;
    }
};