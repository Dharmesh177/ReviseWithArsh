class Solution {
public:
    bool f(vector<int>& nums,int k, int targetsum,int currentsum,vector<bool>&visited,int index){
      if(k==0)return true;
        if(currentsum>targetsum)return false;
        if(currentsum==targetsum)return f(nums,k-1,targetsum,0,visited,0);

        for(int i=index;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                if(f(nums,k,targetsum,currentsum+nums[i],visited,i+1))return true;
                visited[i]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
         int sum=0,maxnum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxnum = max(maxnum,nums[i]);
        }
        vector<bool>visited(nums.size(),false);
        if(sum%k!=0 || maxnum >sum/k)return false;
        return f(nums,k,sum/k,0,visited,0);
    }
};