class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        //TC=O(log(r*c)), SC=O(1)
        int l = 0, r = row*col - 1, mid = 0;
        while(l <= r){
            mid = l + (r-l)/2;
            if(matrix[mid/col][mid%col] == target)
                return true;
            else if(matrix[mid/col][mid%col] < target)
                l = mid+1;
            else 
                r = mid-1;
        }
        return false;
        // int row = 0, col = cols-1;
        // while(row < rows && col >= 0){
        //     int curr = matrix[row][col];
        //     if(curr == target)
        //         return true;
        //     else if(curr > target)
        //         col--;
        //     else
        //         row++;
        // }
        // return false;
    }
};