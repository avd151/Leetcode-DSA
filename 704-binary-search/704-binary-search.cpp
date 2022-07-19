class Solution {
public:
    int search(vector<int>& nums, int target) {
        int found = -1;
        int lo = 0, hi = nums.size()-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                found = mid;
                break;
            }
            else if(nums[mid] > target){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return found;
    }
};