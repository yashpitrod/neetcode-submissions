class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int bottom = matrix.size();
        int right = matrix[0].size();

        int top = 0;
        int left = 0;

        vector<int> ans;

        while(left < right && top < bottom){
            // left to right 
            for(int i=left; i<right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //top to bottom
            for(int i=top; i<bottom ; i++){
                ans.push_back(matrix[i][right-1]);
            }
            right--;

            //right to left
            if (top < bottom) {
                for(int i=right-1; i>=left; i--){
                    ans.push_back(matrix[bottom-1][i]);
                }
                bottom--;
            }


            if (left < right) {
                for(int i=bottom-1; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};