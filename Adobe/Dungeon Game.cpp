// Dungeon Game
class Solution {
public:
//     MEMO
    int solve(int i,int j,int n,int m,vector<vector<int>>& dungeon,vector<vector<int>>& dp){
      
        if(i>=n || j>=m) return INT_MAX;
        
        if(i==n-1 && j==m-1) return dungeon[i][j]<=0 ? abs(dungeon[i][j])+1 : 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down = solve(i+1,j,n,m,dungeon,dp);
        int right = solve(i,j+1,n,m,dungeon,dp);
        
        int ans = min(down,right) - dungeon[i][j]; //neg ans rep sufficiency pos rep required energy
        return dp[i][j] = ans<=0?1:ans; //if we are suff,we at least req 1 to survive and if we are short we need the req energy i.e. ans
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,dungeon,dp);
    }
};