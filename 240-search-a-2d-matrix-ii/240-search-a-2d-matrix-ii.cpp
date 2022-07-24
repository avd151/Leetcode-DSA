class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        //merge rows in sorted order or cols in sorted order
        
        //O(n*m)
        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < cols; j++){
        //         if(matrix[i][j] == target)
        //             return true;
        //         else if(matrix[i][j] > target){
        //             j
        //         }
        //     }
        // }
        
        //O(nlogm)
        // for(int i = 0; i < rows; i++){
        //     int lo = 0;
        //     int hi = cols-1;
        //     while(lo <= hi){
        //         int mid = lo + (hi-lo)/2;
        //         if(matrix[i][mid] == target)
        //             return true;
        //         else if(matrix[i][mid] > target)
        //             hi = mid-1;
        //         else
        //             lo = mid+1;
        //     }
        // }
        int i = 0, j = cols-1; //stand at top rightmost element
        while(i < rows && j >= 0){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else 
                i++;
        }
        
        return false;
    }
};