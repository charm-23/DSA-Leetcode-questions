class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>nums1= split(version1);
        vector<int>nums2= split(version2);

        int n= max(nums1.size(), nums2.size());

        for(int i=0; i<n; i++){
            int v1;
            int v2;
            if(i<nums1.size()){
                 v1= nums1[i];
            }
            else{
                v1=0;
            }

            if(i<nums2.size()){
                v2=nums2[i];
            }
            else{
                 v2=0;
            }

            if(v1>v2) return 1;
            if(v2>v1) return -1;       
        }

    return 0;       
    }


    vector<int> split(string version){
        vector<int> res;
        int num=0; 

        for(int i=0; i<version.size(); i++){
            char ch= version[i];

            if(ch=='.'){
                res.push_back(num);
                num=0;
            }

            else{
                num= num*10+ (ch-'0');
            }
        }
    res.push_back(num);
    return res;

    }
};