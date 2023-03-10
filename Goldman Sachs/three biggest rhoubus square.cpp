class Solution {
public:
int n,m;
    bool check(pair<int,int> a){
        return a.first>=0 && a.first<n && a.second>=0 && a.second<m;
    }
    vector<int> getBiggestThree(vector<vector<int>>& g) {
        set<long long> s;
         n=g.size();
        m=g[0].size();
        //single 1 size rhoumbus square
         for(int i=0; i<n; i++){
               for(int j=0; j<m; j++){
                   s.insert(g[i][j]);
               }
           }
        for(int l=1; l<=50; l++){
           for(int i=0; i<n; i++){
               for(int j=0; j<m; j++){
                   pair<int,int> a={i-l,j};
                   pair<int,int> b={i+l,j};
                   pair<int,int> c={i,j-l};
                   pair<int,int> d={i,j+l};
                   if(check(a)==false && check(b)==false && check(c)==false && check(d)==false) goto end;
                   if(check(a) && check(b) && check(c) && check(d)){
                       long long total = (long long)g[i-l][j]+g[i+l][j]+g[i][j-l]+g[i][j+l];
                        for(int k=1; k<=(l-1); k++) total+=(long long)g[i-k][j-l+k];
                        for(int k=1; k<=(l-1); k++) total+=(long long)g[i-k][j+l-k];
                        for(int k=1; k<=(l-1); k++) total+=(long long)g[i+k][j-l+k]; 
                        for(int k=1; k<=(l-1); k++) total+=(long long)g[i+k][j+l-k];
                        s.insert(total);
                   }
               }
           }
        }
        end:
        vector<int> ans;
        for(auto i:s) ans.push_back(i);
        if(ans.size()<=3){
            reverse(ans.begin(),ans.end());
            return ans;
        }
        vector<int> res;
        res.push_back(ans.back());
        ans.pop_back();
        res.push_back(ans.back());
        ans.pop_back();
        res.push_back(ans.back());
        // ans.pop_back();
        return res;
    }
};