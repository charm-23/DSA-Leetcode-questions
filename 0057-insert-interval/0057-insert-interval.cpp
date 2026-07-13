class Solution {
public:
    int bs(vector<vector<int>>& intervals, int x) {
        int low = 0, high = intervals.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (intervals[mid][0] <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>&newInterval){
        if (intervals.empty())
            return {newInterval};

        vector<vector<int>> ans;

        int prev = bs(intervals, newInterval[0]);
        int next = prev + 1;

        int start = newInterval[0];
        int end = newInterval[1];


        for (int i = 0; i < max(0, prev); i++)
            ans.push_back(intervals[i]);

       
        if (prev != -1) {
            if (intervals[prev][1] >= start) {
                start = intervals[prev][0];
                end = max(end, intervals[prev][1]);
            } else {
                ans.push_back(intervals[prev]);
            }
        }

      
        while (next < intervals.size() && intervals[next][0] <= end) {
            end = max(end, intervals[next][1]);
            next++;
        }

        ans.push_back({start, end});

        while (next < intervals.size()) {
            ans.push_back(intervals[next]);
            next++;
        }
        return ans;
    }
};