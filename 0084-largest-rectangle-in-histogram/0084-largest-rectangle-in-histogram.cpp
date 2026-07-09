class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>st; //pse
        int ans=0; 

        for(int i=0; i<heights.size(); i++){
            if(st.empty()){
                st.push({i, heights[i]}); 
            }
            else{
                while(!st.empty() && heights[i]<st.top().second){
                    int nse=i; int ele=st.top().second; 
                    st.pop(); 
                    int pse;
                    if (st.empty()){
                        pse=-1;
                    }
                    else pse= st.top().first; 
                    int area= ele*(nse-pse-1); 
                    ans= max(area,ans); 
                }
                st.push({i, heights[i]});
            }
        }

        while(!st.empty()){
            int nse= heights.size(); int ele= st.top().second; 
            st.pop(); int pse; 
            if (st.empty()){
                 pse=-1;
            }
            else pse= st.top().first; 
            int area= ele*(nse-pse-1); 
            ans= max(area,ans); 
        }

    return ans; 
    }
};