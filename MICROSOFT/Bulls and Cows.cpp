class Solution {
public:
    string getHint(string s, string g) {
        map<int,int> m;
        for(int i=0; i<s.length(); i++){
            m[s[i]]++;
        }
        int bull=0,cow=0;
        for(int i=0; i<g.length(); i++){
           if((m.find(g[i]) == m.end())) continue;
            if(m[g[i]]==0) continue;
            m[g[i]]--;
            cow++;
        }
        
        for(int i=0; i<s.length(); i++){
           if(s[i]==g[i]){
               bull++;
           }
        }
        string ans="";
        ans+=to_string(bull);
        ans+="A";
        ans+=to_string(cow-bull);
        ans+="B";
        return ans;
        
        
    }
};