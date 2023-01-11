class Solution {
public:
    string fractionToDecimal(long long n, long long d) {
        if(n==0) return "0";
        string ans="";
        if (n < 0 ^ d < 0) ans += '-';
        n=abs(n);
        d=abs(d);
        ans+=to_string(n/d);

        if(n%d==0) return ans;

        ans+=".";

        map<int,int> m;
        long long r=n%d;
        while(r){
         if(m.count(r)>0){
             ans.insert(m[r],1,'(');
             ans+=")";
             break;
         }

         m[r]=ans.size();  //why we used mapp?
         r*=10;
         ans+=to_string(r/d);
         r%=d;
        }
        return ans;
    }
};