class Solution {
public:
    // int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // priority_queue<int> q;
        // vector<pair<int,int>> v;
        // for(int i=0; i<profits.size(); i++){
        //     v.push_back({profits[i],capital[i]});
        
        // }
        // sort(v.begin(),v.end());
        
        // int ans = 0, i=0;
        // while(i<v.size() and k){
        //     if(w>=v[i].second) q.push(v[i++].first);
        //     else{
		// 		// This condition will check if we had enough capital to choose any project or not. If not, we directly return the current capital.
        //         if(q.empty()) return w;
                
        //         w += q.top();
        //         q.pop();
        //         k--;
        //     }
        // }
		// // Here, we check if we could still choose some projects
        // while(k-- and !q.empty()){
        //     w += q.top();
        //     q.pop();
        // }

        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n=profits.size();
    vector<pair<int,int>> projects(n);
    for(int i=0;i<n;i++) projects[i]={profits[i],capital[i]}; 
    int i=0;
    
    sort(projects.begin(),projects.end(),
    [&](pair<int,int> a,pair<int,int> b){ return a.second<b.second;});

    priority_queue<int> maxProfit;
    while(k--){
        while(i<n && w>=projects[i].second) maxProfit.push(projects[i++].first);
        
        if(!maxProfit.empty()) w+=maxProfit.top(),maxProfit.pop();
    }
    return w;
}
    
};