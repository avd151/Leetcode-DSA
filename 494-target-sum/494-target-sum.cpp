class Solution {
    //memoization - TC=O(n*target), SC=O(n + n*target)
    int countSubsetSum(vector<int>arr, int target, int idx, vector<vector<int>>& dp){
        if(idx == 0){
            if(target == 0 && (arr[idx] == 0))return 2;
            if(target == 0 || (arr[idx] == target))return 1;
            return 0;
        }
        if(dp[idx][target] != -1)
            return dp[idx][target];
        int notPick = countSubsetSum(arr, target, idx-1, dp);
        int pick = 0;
        if(arr[idx] <= target)
            pick = countSubsetSum(arr, target-arr[idx], idx-1, dp);
        return dp[idx][target] = (pick+notPick);
    }
    int partitionDifference(vector<int> arr, int target){
        int totSum = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++)
            totSum += arr[i];
        //s1 - s2 = target
        //totSum - 2*s2 = target
        //s2 = totSum-target / 2
        //ways to get s2 = ways to generate s1 and s2
        if((totSum-target < 0) || ((totSum-target)%2))
            return 0;
        int newTarget = (totSum-target)/2;
        vector<vector<int>>dp(n, vector<int>(newTarget+1, -1));
        return countSubsetSum(arr, newTarget, n-1, dp);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //same as ways to partition arr into subsets such that absoute difference is equal to target
        return partitionDifference(nums, target);
    }
};