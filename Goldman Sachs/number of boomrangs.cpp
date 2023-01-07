class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        // int i=0,j=1;
        int n=cards.size();
        // vector<int> v;
        // v.push_back(cards[0]);
        // int ans=INT_MAX,flag=0;
        // while(j<n){
        //     if(find(v.begin(),v.end(),cards[j])!=v.end()){
        //         ans=min(ans,j-i+1);
        //         v.push_back(cards[j]);
        //         i=j;
        //         flag=1;
        //     }else{
        //         v.push_back(cards[j]);
        //     }
        //     j++;
        // }
        // if(flag==0) return -1;
        // return ans;
        
        int ans= INT_MAX;
        unordered_map<int,int> mp;
        for (int i=0; i<cards.size(); i++){
            if (mp.find(cards[i]) != mp.end()){
                ans= min(ans,i-mp[cards[i]]+1);
            }
            mp[cards[i]]= i;
        }
        if (ans==INT_MAX)return -1;
        return ans;
        
        
    }
};