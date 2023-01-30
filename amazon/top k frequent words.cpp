class Solution {
public:
    bool static comapre(pair<int,string> p1,pair<int,string> p2){
        if(p1.first==p2.first)return p1.second<p2.second;
        return p1.first>p2.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
       unordered_map<string,int> map;
       for(auto word:words)map[word]++;

       vector<pair<int,string>> v;
       for(auto word:map)v.push_back({word.second,word.first});
       sort(v.begin(),v.end(),comapre);

       vector<string> ans;
       for(int i=0;i<k;i++){
           ans.push_back(v[i].second);
       }       
    return ans;
    }
};