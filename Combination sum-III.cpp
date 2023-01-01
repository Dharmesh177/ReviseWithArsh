class Solution {
public:
    void helper(int s,int k,int n,vector<vector<int>> &ans,vector<int> &temp){
        if(k<0 || n<0){
            return;
        }
        if(k==0 && n==0){
            ans.push_back(temp);
            return;
        }
        for(int i=s; i<=9; i++){
            temp.push_back(i);
            helper(i+1,k-1,n-i,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>temp;
        helper(1,k,n,ans,temp);
        return ans;
    }
};