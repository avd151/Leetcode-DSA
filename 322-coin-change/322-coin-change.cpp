class Solution {
    int f(int idx, int amt, vector<int>arr, vector<vector<int>>& dp){
        if(idx == 0){
            if(amt % arr[idx] == 0)
                return (amt/arr[idx]);
            else
                return 1e9;
        }
        if(dp[idx][amt] != -1)
            return dp[idx][amt];
        int notTake = f(idx-1, amt, arr, dp);
        int take = INT_MAX;
        if(arr[idx] <= amt)
            take = 1 + f(idx, amt-arr[idx], arr, dp);
        return dp[idx][amt] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // min coins to make the amount
        int n = coins.size();
        // vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        // int ans = f(n-1, amount, coins, dp);
        // if(ans == 1e9)
        //     return -1;
        // return ans;
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        for(int a = 1; a <= amount; a++){
            if(a % coins[0] == 0)
                dp[0][a] = a/coins[0];
            else
                dp[0][a] = 1e9;
        }
        
        for(int i = 1; i < n; i++){
            for(int amt = 0; amt <= amount; amt++){
                int notTake = dp[i-1][amt];
                int take = INT_MAX;
                if(coins[i]<= amt)
                    take = 1 + dp[i][amt-coins[i]];
                dp[i][amt] = min(take, notTake);
            }
        }
        if(dp[n-1][amount] == 1e9)
            return -1;
        return dp[n-1][amount];
    }
};