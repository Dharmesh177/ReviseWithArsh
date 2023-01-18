class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        
        
        for(auto x: queries){
            int i = x[1];
            int k= x[0];
            priority_queue<pair<string,int>> pq;
            for(int j=0; j<nums.size(); j++){
                int s=nums[j].length()-x[1];
                string ss = nums[j].substr(s,x[1]);
                if(pq.size() < x[0])
                   pq.push({ss,j});
                //by doing this step minimum element will always on top of priority queue
                else{
                    if(pq.top().first > ss){
                    pq.pop();
                    pq.push({ss,j});
                }
                }
            }
            int index = pq.top().second;
            res.push_back(index);
        }
        return res;
    }
};

//The function takes two parameters, a vector of strings 'nums' and a vector of queries. Each query is represented by a vector of two integers, where the first integer is the number of smallest trimmed numbers we need to select and the second integer is the trimming length.
//For each query, we create a priority queue to store the trimmed numbers in ascending order of their value.
//We iterate through the input vector of strings and for each string, we calculate the start index of the trimming and the trimmed number.
//If the size of the priority queue is less than the number of smallest trimmed numbers we need to select, we push the current trimmed number to the priority queue.
//Otherwise, we compare the current trimmed number with the top element of the priority queue. If it is smaller, we pop the top element and push the current trimmed number to the priority queue.
//After processing all the strings for a query, we get the index of the top element in the priority queue, which is the index of the smallest trimmed number and store it in the result vector.
//Finally, we return the result vector containing the indices of the smallest trimmed numbers for all queries. The time complexity of this solution is O(nmlog(k)), where n is the number of strings, m is the number of queries and k is the number of smallest trimmed numbers we need to select for each query.
