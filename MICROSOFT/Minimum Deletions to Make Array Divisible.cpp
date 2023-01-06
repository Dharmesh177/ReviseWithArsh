class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& divide) {
        sort(nums.begin(),nums.end());
        sort(divide.begin(),divide.end());
        
        int cntt = divide[0]; 
        for(int i=1; i<divide.size(); i++){
            cntt =__gcd(cntt, divide[i]);
        }
        
        int ans=-1,flag=0;
        for(int i=0; i<nums.size(); i++){
           if(cntt%nums[i]==0){
               flag=1;
               ans=i;
               break;
           }
        }
        
        if(flag==0){
            return -1;
        }
        
        return ans;
        
    }
};