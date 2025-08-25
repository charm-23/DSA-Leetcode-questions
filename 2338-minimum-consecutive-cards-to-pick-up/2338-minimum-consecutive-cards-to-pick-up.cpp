class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_map<int, int> mpp;
        int minL = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (mpp.count(cards[i])) {
                minL = min (minL, i - mpp[cards[i]]+1);
            }
            mpp[cards[i]] = i;
        }

        return (minL == INT_MAX) ? -1 : minL;
    }
};
