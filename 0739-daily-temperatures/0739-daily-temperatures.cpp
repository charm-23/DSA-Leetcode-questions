class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size(); 
        stack<pair<int,int>>st; 
        vector<int>ans(n); 
        ans[n-1]=0; 
        st.push({n-1, temperatures[n-1]}); 

        for(int i=n-2; i>=0; i--){
            while(!st.empty() && temperatures[i]>st.top().second){
                st.pop(); 
            }
            if(st.empty()) ans[i]=0; 
            else{
                ans[i]=(st.top().first)-i; 
            }
            st.push({i, temperatures[i]}); 
        }

        return ans;     
    }
};