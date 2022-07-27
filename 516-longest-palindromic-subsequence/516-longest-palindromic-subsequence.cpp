class Solution {
    int lcs(string& s1, string& s2){
        int n1 = s1.length();
        int n2 = s2.length();
        //tabulation - TC=O(n*m), SC=O(n*m)
        // vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
        // for(int i = 0; i <= n1; i++) dp[i][0] = 0;
        // for(int j = 0; j <= n2; j++) dp[0][j] = 0;
        // for(int i = 1; i <= n1; i++){
        //     for(int j = 1; j <= n2; j++){
        //         if(s1[i-1] == s2[j-1])
        //             dp[i][j] = (1 + dp[i-1][j-1]);
        //         else
        //             dp[i][j] = (0 + max(dp[i-1][j], dp[i][j-1]));
        //     }
        // }
        // return dp[n1][n2];
        
        //space optimization
        //TC=O(n*m), SC=O(m)
        vector<int>prev(n2+1, 0), cur(n2+1, 0);
        for(int j = 0; j <= n2; j++) prev[j] = 0;
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(s1[i-1] == s2[j-1])
                    cur[j] = (1 + prev[j-1]);
                else
                    cur[j] = (0 + max(prev[j], cur[j-1]));
            }
            prev = cur;
        }
        return cur[n2];
    }
public:
    int longestPalindromeSubseq(string s) {
        //lps = lcs(s, reverse of s)
        string t = s;
        reverse(s.begin(), s.end());
        return lcs(s, t);
    }
};