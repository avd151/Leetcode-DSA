class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i = 1; i < numRows; i++){
            vector<int>prev = ans.back();
            vector<int>cur;
            cur.push_back(1);
            int n = prev.size();
            for(int i = 1; i < n; i++){
                cur.push_back(prev[i]+prev[i-1]);
            }
            cur.push_back(1);
            ans.push_back(cur);
        }
        return ans;
    }
};