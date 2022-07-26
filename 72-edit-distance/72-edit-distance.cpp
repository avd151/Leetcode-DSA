class Solution {
    //memoization - TC=O(n1*n2), SC=O(n1*n2 + min(n1, n2))
    int match(string s1, string s2, int i, int j, vector<vector<int>>& dp){
        if(s1.length() == i)
            return (s2.length()-j);
        if(s2.length() == j)
            return (s1.length()-i);
        if(dp[i][j] != -1)
            return dp[i][j];
        int res = 0;
        if(s1[i] == s2[j])
            res = match(s1, s2, i+1, j+1, dp);
        else{
            int insert = match(s1, s2, i, j+1, dp);
            int delet = match(s1, s2, i+1, j, dp);
            int replac = match(s1, s2, i+1, j+1, dp);
            res = min({insert, delet, replac})+1;
        }
        return dp[i][j] = res;
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        if(n1 == 0)return n2;
        if(n2 == 0)return n1;
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        return match(word1, word2, 0, 0, dp);
        
        //Tabulation
        // vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
        // //base case
        // for(int i = 0; i < n1)
        
    }
};