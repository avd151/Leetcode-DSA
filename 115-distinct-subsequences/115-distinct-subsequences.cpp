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
        vector<vector<int>>dp(sn, vector<int>(tn, -1));
        return f(sn-1, tn-1, s, t, dp);
    }
};