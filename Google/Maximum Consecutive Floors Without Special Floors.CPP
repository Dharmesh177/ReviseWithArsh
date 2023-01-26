// Maximum Consecutive Floors Without Special Floors

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        
        // int count=0;
        // int maxans=0;
        // for(int i=bottom; i<=top; i++){
        //     if((find(special.begin(),special.end(),i) != special.end())){
        //         maxans=max(maxans,count);
        //         count=0;
        //         continue;
        //     }
        //     count++;
        // }
        // maxans=max(maxans,count);
        // return maxans;
       int ans = max((special[0]-bottom), (top-special[special.size()-1]));  // Maximum of non special floors before 1st special floor and last special floor

        int count  = 0;
        
        for(int i=0;i<special.size()-1;i++)                                 //  Counting the number of floors between two consecutive special floors
        {
            count = special[i+1]-special[i]-1;
            ans=max(count,ans);
        }
        
        return ans;
    }
};