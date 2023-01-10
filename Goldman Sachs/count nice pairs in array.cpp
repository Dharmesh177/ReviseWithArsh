class Solution {
public:
    #define mod 1000000007
    int countNicePairs(vector<int>& nums) {
        vector<int> revv;
        for(auto x:nums){
            int r=0,t=0;
            while(x != 0){
           r = x % 10;
           t = t * 10 + r;
           x /= 10;
          }
            revv.push_back(t);
        }
        
        for(int i=0; i<nums.size(); i++){
            nums[i]-=revv[i];
        }
        
        map<int,int> m;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i])!=m.end()){
               ans+=m[nums[i]]%mod;
                ans%=mod;
                
            }
                m[nums[i]]++;
            
        }
        return ans;
    }
};