class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size(), inf = 1e9, m;
        if(n<d)
            return -1;
        
        vector<int> dp(n+1, 1e9);
        dp[n] = 0;
        for(int i=1; i<=d; ++i){
            for(int j=0; j<=n-i; ++j){
                m = 0, dp[j] = inf;
                for(int k=j; k<=n-i; ++k){
                    m = max(m, jobDifficulty[k]);
                    dp[j] = min(dp[j], m+dp[k+1]);
                }
            }
        }
        return dp[0];
    }
};