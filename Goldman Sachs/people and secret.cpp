class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int peopleAwareOfSecret(int n, int delay, int forget) {
        ll day=2;
        vector<array<ll,3>> person = {{delay+1,forget+1,1}};
        
        while(day<=n){
            while(!person.empty() && person[0][1]==day ){
                person.erase(person.begin());
            }
            
            ll cnt=0;
            for(auto x:person){
                if(x[0]<=day){
                    cnt+=x[2];
                }
                cnt%=mod;
            }
            person.push_back({day+delay,day+forget,cnt});
            day++;
        }
        
        ll ans=0;
        for(auto x:person){
            ans+=x[2];
            ans%=mod;
        }
        return ans;
    }
};