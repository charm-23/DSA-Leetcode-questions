class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size(); int m=boxGrid[0].size(); 
        vector<vector<char>>ans(m, vector<char>(n)); 

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[j][n-1-i]= boxGrid[i][j]; 
            }
        }

        int rows=m; int cols=n; 
        for(int col=0; col<cols; col++){
            for(int row=rows-2; row>=0; row--){
                int r=row; 
                while(r+1<rows && ans[r][col]=='#' && ans[r+1][col]=='.'){
                    ans[r+1][col]='#'; 
                    ans[r][col]='.';
                    r++;
                }
            }
        }
    return ans; 
    }
};