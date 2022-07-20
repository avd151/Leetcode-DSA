class Solution {
    bool subsetSumToK(int n, int k, vector<int>& arr){
        vector<bool>prev(k+1, 0), cur(k+1, 0);
        prev[0] = cur[0] = true;
        if(arr[0] < k) prev[arr[0]] = true;
        for(int ind = 1; ind < n; ind++){
            for(int targ = 1; targ <= k; targ++){
                bool notTake = prev[targ];
                bool take = false;
                if(arr[ind] <= targ){
                    take = prev[targ-arr[ind]];
                }
                cur[targ] = take | notTake;
            }
            prev = cur;
        }
        return prev[k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2) //odd sum => cannot partition
            return false;
        int target = sum/2;
        if(subsetSumToK(n, target, nums))
            return true;
        return false;
    }
};