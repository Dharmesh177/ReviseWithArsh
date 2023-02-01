class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int res=0;
        for(int i=1; i<grid.size()-1; i++){
            for(int j=1; j<grid[0].size()-1; j++){
             int   ans = grid[i][j] + grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1] +
                      grid[i+1][j-1] + grid[i+1][j]+ grid[i+1][j+1];
                res=max(ans,res);
            }
        }
        return res;
    }
};