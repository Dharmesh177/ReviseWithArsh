class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
//         int s,e;
//           int c=0;
//         for(int i=0; i<nums.size()-1; i++){
//             if(nums[i]>nums[i+1]){
//                 s=i;
//                  c=1;
//                 break;
//             }
//         }
//        if(c==0){
//            return 0; 
//         }
//          for(int i=nums.size()-1; i>0; i--){
//             if(nums[i]<nums[i-1]){
//                 e=i;
               
//                 break;
//             }
//         }
        
//         int m=nums[s],n=nums[e];
//         for(int i=s; i<e; i++){
//             m=min(m,nums[i]);
//             n=max(n,nums[i]);
//         }
//         for(int i=0; i<s; i++){
//             if(nums[i]>m) s=i;
//         }
        
//          for(int i=e+1; i<nums.size(); i++){
//             if(nums[i]<n) e=i;
//         }
//         return e-s+1;
         vector<int> temp;
        temp = nums;
        sort(temp.begin(),temp.end());
        int n = nums.size();
        int i=0,j=n-1;
        
           for(;i<n;i++)
        {
            if(nums[i]!=temp[i])
                break;
        }
        
         for(;j>=0;j--)
        {
            if(nums[j]!=temp[j])
                break;
        }
        int c=0;
        
         for(int k=i;k<=j;k++)
            c++;
        return c;
    }
};
