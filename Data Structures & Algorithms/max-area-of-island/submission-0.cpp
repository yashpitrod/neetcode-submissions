class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 0;
        }
        
        grid[r][c] = 0;
        
        return 1 + dfs(grid, r - 1, c) 
                 + dfs(grid, r + 1, c) 
                 + dfs(grid, r, c - 1) 
                 + dfs(grid, r, c + 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int max_area = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    int current_island_area = dfs(grid, r, c);
                    max_area = max(max_area, current_island_area);
                }
            }
        }
        
        return max_area;
    }
};