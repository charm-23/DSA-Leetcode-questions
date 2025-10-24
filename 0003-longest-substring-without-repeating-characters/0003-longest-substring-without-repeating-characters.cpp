class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,0);
        int n = s.length();
        int len = 0;
        int i = 0;

        while (i < n) {
            int cnt = 0;
            int temp = i;
            vector<int> freq(256, 0); 

            while (i < n && freq[s[i]] == 0) {
                freq[s[i]] = 1;
                cnt++;
                i++;
            }

            len = max(len, cnt);
            i = temp + 1; 
        }

        return len;
    }
};
