class Solution {
    //Variation of dijkstra's algorithm
    //https://www.youtube.com/watch?v=Wq1NibUMrNU&ab_channel=Pepcoding
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>> pq; //{-t,i,j} : use as min heap
        
        int n = grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        pq.push({-grid[0][0],{0,0}});
        while(!pq.empty()){
            int t = -pq.top().first ,
            x = pq.top().second.first,
            y = pq.top().second.second;
            pq.pop();
    
            if(x == n-1 && y == n-1) return t;

            if(vis[x][y]) continue;
            else vis[x][y] = true;

            for(int k = 0;k<4;k++){
                int i = x + dx[k] , j = y + dy[k];
                if(i>=0 && j>=0 && i<n && j<n && !vis[i][j]){
                    pq.push({-1*max(t,grid[i][j]) , {i,j}});
                }
            }
        }

        return -1;
    }
};