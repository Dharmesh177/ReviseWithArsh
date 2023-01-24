class Solution {
public:
	double new21Game(int N, int K, int W) {
		vector<double> dp(N+1);
		double sum=0;
		dp[0]=1;
		for(int i=1;i<=N;i++)
		{
			if(i-1<K)
			{
				sum+=dp[i-1];
			}

			if(i-W-1>=0)
			{
				sum-=dp[i-W-1];
			}
			dp[i]=(double)sum*((double)1.0/W);
		}
		double ans=0;
		for(int i=0;i<=N;i++)
		{
			if(i>=K)
			{
				ans+=dp[i];
			}
		}

		return ans;
	}
};