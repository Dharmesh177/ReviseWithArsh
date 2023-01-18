class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total=0;
        long long negative_cnt=0;
        long long minabsval=INT_MAX;
        bool zero = false;
        
        for(auto x : matrix){
            for(auto i : x){
                if(i==0) {zero = true;}
             if(i<0) {
                negative_cnt++;
            }
            total += abs(i);

            if(abs(i)<minabsval) {
                minabsval = abs(i);
            }
        }
        }
        
        if(zero || negative_cnt%2==0){
            return total;
        }
        return total-2*minabsval;
    }
};