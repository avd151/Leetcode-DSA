class Solution {
    int util(int n, int k, vector<vector<int>>& dp){
        if(n == 0)return 0;
        if(k == 0)return 1;
        if(dp[n][k] != -1)return dp[n][k];
        int inv = 0;
        for(int i = 0; i <= min(k, n-1); i++){
            inv = (inv + util(n-1, k-i, dp))%(1000000007);
        }
        return dp[n][k] = inv;
    }
public:
    int kInversePairs(int n, int k) {
        int M = 1000000007;
        // vector<vector<int>>dp(1001, vector<int>(1001, -1));
        vector<vector<int>>dp(1001, vector<int>(1001, 0));
        // return util(n, k, dp);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k && j <= (i*(i-1))/2; j++){
                if(i==1 && j == 0){
                    dp[i][j] = 1;
                    break;
                }
                else if(j == 0)
                    dp[i][j] = 1;
                else{
                    // for(int l = 0; l <= min(j, i-1); l++){
                    //     dp[i][j] = (dp[i][j] + dp[i-1][j-l])%(1000000007);
                    // }
                    int val = dp[i-1][j]+M-(((j-i)>=0? dp[i-1][j-i]: 0)%M);
                    dp[i][j] = (dp[i][j-1]%M + val%M)%M;
                 }
            }
        }
        return dp[n][k];
    }
};