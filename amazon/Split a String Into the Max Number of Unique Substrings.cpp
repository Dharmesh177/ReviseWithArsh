//  Split a String Into the Max Number of Unique Substrings
class Solution {
public:
    int n,res=INT_MIN;
    set<string> ss;
    
    void f(int idx,string s){
        //base case 
        if(idx==n){
            int r=ss.size();
            res=max(res,r);
            return;
        }
        string temp="";
        for(int i=idx; i<n; i++){
            temp+=s[i];
            if(ss.find(temp) == ss.end()){
                ss.insert(temp);
                f(i+1,s);
                ss.erase(temp);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        n=s.length();
        res=0;
        f(0,s);
        return res;
    }
};