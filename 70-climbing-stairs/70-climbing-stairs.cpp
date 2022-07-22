class Solution {
private:
    int help(int n, vector<int>& dp){
        if(n <= 2)
            return n;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = help(n-1, dp) + help(n-2, dp);
    }
public:
    int climbStairs(int n) {
        // vector<int>dp(n+1, -1);
        // return help(n, dp);
        if(n <= 2)
            return n;
        vector<int>dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};