class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

     long long a=1e10,b=1e10;

     for(auto i:nums){
         if(i>b) return true;
         if(i>a) {
             if(i<b) b= (long long) i;
         } 
         if(i<a){
             a=(long long ) i;
         }
        //  a=min((long long)i,a);
     }
     return false;

//         int mini=INT_MAX;
//         int ind=-1;
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i]<mini){
//                 mini=nums[i];
//                 ind=i; 
//             }
//         }
// int ind2=-1;
// int sec=-1;
//         for(int i=ind+1; i<nums.size(); i++){
//             if(mini<nums[i]) {
//             sec=nums[i];
//             ind2=i; 
//             break;
//             }
//         }

//         if(ind2!=-1){
//         for(int i=ind2+1; i<nums.size(); i++){
//             if(sec<nums[i]) {return true;}
//         }
//         }else{
//             return false;
//         }
//         return false;
    }
};