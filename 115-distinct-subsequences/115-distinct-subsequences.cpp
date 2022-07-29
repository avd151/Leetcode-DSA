class Solution {
    //memoization
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j < 0)
            return 1;
        if(i < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == t[j])
            return dp[i][j] = (f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp));
        else
            return dp[i][j] = f(i-1, j, s, t, dp);
    }
public:
    int numDistinct(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        // vector<vector<int>>dp(sn, vector<int>(tn, -1));
        // return f(sn-1, tn-1, s, t, dp);
        
        vector<vector<double>>dp(sn+1, vector<double>(tn+1, 0));
        for(int i = 0; i <= sn; i++)
            dp[i][0] = 1;
        for(int j = 1; j <= tn; j++)
            dp[0][j] = 0;
        
        for(int i = 1; i <= sn; i++){
            for(int j = 1; j <= tn; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[sn][tn];
    }
};