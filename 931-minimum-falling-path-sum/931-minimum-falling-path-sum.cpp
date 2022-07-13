class Solution {
    int util(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j < 0 || j >=matrix[0].size())
            return 1e8;
        if(i == 0)
            return matrix[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        int up = matrix[i][j] + util(i-1, j, matrix, dp);
        int leftDiag = matrix[i][j] + util(i-1, j-1, matrix, dp);
        int rightDiag = matrix[i][j] + util(i-1, j+1, matrix, dp);
        return dp[i][j] = min({up, leftDiag, rightDiag});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = 1e8;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>>dp(rows, vector<int>(cols, -1));
        for(int j = 0; j < cols; j++){
            ans = min(ans, util(rows-1, j, matrix, dp));
        }
        return ans;
    }
};