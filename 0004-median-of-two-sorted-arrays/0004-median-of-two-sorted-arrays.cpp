class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(); int m=nums2.size(); 
        int i=0; int j=0; 

        if(n==0 && m==0) return NULL; 

        vector<int>merged; 

        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i]);
                i++; 
            }
            else if(nums1[i]==nums2[j]){
                merged.push_back(nums1[i]); 
                merged.push_back(nums2[j]); 
                i++; j++; 
            }
            else{
                merged.push_back(nums2[j]); 
                j++; 
            }
        }

        while(i<n){
            merged.push_back(nums1[i]);
                i++;
        }

        while(j<m){
            merged.push_back(nums2[j]); 
                j++; 
        }

    int low=0; int high=n+m-1; 
    int mid=low+ (high-low)/2; 

    if((n+m)%2==0){
        return (double)(merged[mid]+ merged[mid+1])/2; 
    }

    return (double)(merged[mid]); 
    }
};