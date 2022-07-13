class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        // for(int i = 0; i < n; i++){
        //     int temp = 1;
        //     for(int j = i; j < n; j++){
        //         temp = temp*nums[j];
        //         ans = max(ans, temp);
        //     }
        // }
        int l = 0, r = 0;
        for(int i = 0; i < n; i++){
            l = (l ? l : 1)*nums[i];
            r = (r? r: 1)*nums[n-1-i];
            ans = max(ans, max(l,r));
        }
        return ans;
    }
};