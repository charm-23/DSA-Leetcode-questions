class Solution {
public:
    bool search(vector<int>& nums, int target) {
        set<int> st;
        for (int i = 0; i<nums.size(); i++) st.insert(nums[i]);
        return st.find(target) != st.end();
    }
};