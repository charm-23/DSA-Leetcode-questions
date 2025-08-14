class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));

        int startColor= image[sr][sc];
        if(startColor==color) return image; 

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        helper(image, sr, sc, startColor,color, dx, dy, visited); 
        return image; 
        
    }

    void helper(vector<vector<int>>& image, int i, int j, int startColor, int color,
            vector<int>& dx, vector<int>& dy, vector<vector<int>>& visited){
        visited[i][j]=1; 
        image[i][j]= color; 

        for(int k=0; k<4; k++){

            int ni= i+dx[k];
            int nj= j+dy[k];

            if(ni>=0 && ni<image.size() && nj>=0 && nj<image[0].size() && !visited[ni][nj] && image[ni][nj]==startColor){
                helper(image, ni, nj, startColor, color, dx, dy, visited);
            }
        }
    }
};