/*
Intuition :
Whenever we get a set bit we consider it to be 0 and then find the ans for the rest number of
bits where we did not find consecutive ones.
for eg. -> 10110
           ^
           |
    leftmost set bit
    
we consider it to be 0 -> resulting in (00110) and find the ans for number of bit = 4 -> f(4) = 8

-> 10110
     ^
     |
next leftmost set bit

we consider it to be 0 resulting in (10010) and find the ans for number of bit = 2 -> f(2) = 3

-> 10110
      ^
      |
next leftmost set bit

we consider it to be 0 resulting in (10100) and find the ans for number of bit = 1 -> f(2) = 2

now we have encountered  consecutive ones which means if we explore further we would be including 
consecutive ones in our solution so we simply break out

for eg. 101101
           ^
           |
after this set bit we would not reach the next set bit as getting ahead of this set bit 
would mean that we are considering consecutive set bits in our answer

*/

class Solution {
public:
    int findIntegers(int n) {
        //10^9 representation would at max require 31 binary digits
        vector<int> f(31);
        f[0] = 1;
        f[1] = 2;
        
        for(int i=2; i<31; i++) {
            f[i] = f[i-1] + f[i-2];
        }
        
        //general solution for all numbers
        //actually if our binary representation does not contain 31 bits then the n & (1 << k)
        //operation would not hold true and prebit will be set to 0 and k-- will be done until
        //k reaches a value which yeilds a set bit
        
        int ans = 0, k = 30, prebit = 0;
        
        while(k >= 0) {
            //considering bit from the left if it is 1
            if(n & (1 << k)) {
                ans += f[k];
                //if we get 2 consecutive set bits
                if(prebit == 1) 
                    return ans;
                //as bit found here is 1 so update prebit as 1
                prebit = 1;
            }
            else {
                prebit = 0;
            }
            --k;
        }
        return ans+1;
    }
};

// class Solution {
// public:
//     string binary(int n)
//     {
//         string s = "";
//         while(n>0)
//         {
//             int a = n%2;
//             s+=to_string(a);
//             n/=2;
//         }
//         reverse(s.begin(),s.end());
//         return s;
//     }
//     int dp[32][2][2];
//     int rec(string &num,int n,bool tight,bool one)
//     {
//         if(n==0)
//         {
//             return 1;
//         }
//         if(dp[n][tight][one]!=-1)
//         {
//             return dp[n][tight][one];
//         }
//         int ans=0;
//         int ub = (tight)?num[num.size()-n]-'0':1;
//         for(int dig=0;dig<=ub;dig++)
//         {
//             if(one and dig==1)
//             {
//                 continue;
//             }
//             else if(one and dig==0)
//             {
//                 ans+=rec(num,n-1,tight&(dig==ub),0);
//             }else if(!one and dig==1)
//             {
//                ans+=rec(num,n-1,tight&(dig==ub),1);
//             }else
//             {
//                 ans+=rec(num,n-1,tight&(dig==ub),0);
//             }
//         }
//         return dp[n][tight][one]=ans;
//     }
//     int findIntegers(int n) {
//         string num = binary(n);
//         memset(dp,-1,sizeof(dp));
//         return rec(num,num.size(),1,0);
//     }
// };