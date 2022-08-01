class Solution {
    //memoization - TC=O(n*m), SC=O(n*m + n+m))
    int f(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        //0,0 to m-1,n-1 => down and right
        //m-1,n-1 to 0,0 => up and left
        int up = f(i-1, j, dp);
        int left = f(i, j-1, dp);
        return dp[i][j] = (up+left);
    }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // return f(m-1, n-1, dp);
        
        //tabulation TC=O(n*m), SC=O(n*m))
        vector<vector<int>>dp(m, vector<int>(n, 0));
        // for(int i = 0; i <= m; i++)
        //     dp[i][0] = 0;
        // for(int j = 0; j <= n; j++)
        //     dp[0][j] = 0;
        // // dp[1][1] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int up = 0, left = 0;
                if(i==0 && j== 0)
                    dp[i][j] = 1;
                else{
                    if(i >= 1)
                        up += dp[i-1][j];
                    if(j >= 1)
                        left += dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};