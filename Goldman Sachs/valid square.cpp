class Solution {
public:
    int distfind(vector<int>& p1, vector<int>& p2){
        int res=sqrt(abs((p2[0]-p1[0])*(p2[0]-p1[0])) + abs((p2[1]-p1[1])*(p2[1]-p1[1])));
        return res;
    }
    
    double slopeh(vector<int>& p1, vector<int>& p2){
     
        
        double res;
        if(p2[0]-p1[0]==0){
            res=INT_MAX;
        }else{
            res=(p2[1]-p1[1])/(p2[0]-p1[0]);
        }
        return res;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        
        unordered_map<int, int> cnt;
        
        int side2 = INT_MAX;
        
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                int x = points[i][0] - points[j][0]; 
                int y = points[i][1] - points[j][1];
            
                int var = x * x + y * y; // if we are given a valid square,
                                         // then 'var' must be equal to the side^2 or diagonal^2 of the given square
                
                side2 = min (side2, var);
                
                cnt[var]++;
            }
        }
        
        return cnt[side2] == 4 && cnt[2 * side2] == 2; // side^2 + side^2 = diagonal^2 = 2 * side^2
                                                       // our square must have 4 sides and 2 diagonals.

    }
};