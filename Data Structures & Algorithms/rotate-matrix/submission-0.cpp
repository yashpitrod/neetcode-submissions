class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();

        for(int row=0 ; row<n ; row++){
            for(int col=row; col<n ; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        for(int row=0 ; row<n; row++){
            for(int col=0; col<n/2; col++){
                swap(matrix[row][col], matrix[row][n - col - 1]);
            }
        }
    }
};
