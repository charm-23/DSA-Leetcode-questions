class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m= mat.size(); 
        int n= mat[0].size();
        int count=0; 

        for(int i=0; i<m; i++){ 
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    bool flag= true; 
                    int row=i; int col=j;
                    for(int k=0; k<m; k++){
                        if(k!=i && mat[k][col]==1) flag=false; 
                    } 
                    for(int k=0 ; k<n; k++){
                        if(k!=j && mat[row][k]==1) flag= false; 
                    }
                if(flag==true) count++; 
                }
            }
        }
        return count;    
    }
};