class Solution {
private:
    int lcs(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        // int ans = lcs(i-1, j, s1, s2);
        // ans = max(ans, lcs(i,j-1,s2,s2));
        // ans = max(ans, lcs(i-1,j-1, s1, s2)+(s1[i] == s2[j]));
        // return dp[i][j] = ans;
        if(s1[i] == s2[j]){
            return dp[i][j] = (1 + lcs(i-1, j-1, s1, s2, dp));
        }
        else{
            return dp[i][j] = (0 + max(lcs(i-1, j, s1, s2, dp), lcs(i, j-1, s1, s2, dp)));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return lcs(n-1, m-1, text1, text2, dp);
    }
};