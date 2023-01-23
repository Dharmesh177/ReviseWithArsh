class Solution {
public:
    int N = 1000001;
    vector<bool>sieve = vector<bool>(N + 1,true);
    void createSieve() {
        sieve[0] = sieve[1] = false;
        for(int i = 2; i * i <= N; i++) {
            if(sieve[i] == true) {
                for(int j = i * i; j <= N; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>nums,ans(2,-1);
        if(left == right) {
            return ans;
        }
        createSieve();
        int mini = INT_MAX;
        for(int i = left; i <= right; i++) {
            if(sieve[i]) {
                nums.push_back(i);
            }
        }
        if(nums.size() <= 1) {
            return ans;
        }
        for(int i = 0; i < nums.size() - 1; i++) {
            int temp = nums[i + 1] - nums[i];
            if(temp < mini) {
                mini = temp;
                ans[0] = nums[i];
                ans[1] = nums[i + 1];
            }
        }
        return ans;    
    }
};