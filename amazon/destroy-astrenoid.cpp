class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ass) {
        long long int e= mass;
          sort(ass.begin(), ass.end());

        for(int i = 0; i < ass.size(); ++i)
        {
           if(e < ass[i]) return false;
           
           
            else e += ass[i];   
        }

        return true;
    }
};