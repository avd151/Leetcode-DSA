class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //using map
        unordered_map<int,int>freq;
        for(auto it: nums){
            freq[it]++;
            if(freq[it] >= 2)
                return true;
        }
        return false;
    }
};