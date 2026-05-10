class Solution {
public:
    bool bs_2d(vector<vector<int>> &matrix, int target, int start, int end){
        int m = matrix.size();
        int n = matrix[0].size();
        if(start > end)
            return false;
        
        int mid = (start + end) / 2;
        if(matrix[mid / n][mid % n] == target)
            return true;
        else
            return matrix[mid / n][mid % n] > target ? 
                bs_2d(matrix, target, start, mid-1) : bs_2d(matrix, target, mid+1, end);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return bs_2d(matrix, target, 0, m * n - 1);
    }
};
