class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh_count = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
                if (grid[r][c] == 1) {
                    fresh_count++;
                }
            }
        }

        if (fresh_count == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            int level_size = q.size();
            bool rotted_this_minute = false;

            for (int i = 0; i < level_size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (auto& dr : dirs) {
                    int new_r = r + dr.first;
                    int new_c = c + dr.second;

                    if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols &&
                        grid[new_r][new_c] == 1) {
                        grid[new_r][new_c] = 2;
                        q.push({new_r, new_c});
                        fresh_count--;
                        rotted_this_minute = true;
                    }
                }
            }
            if (rotted_this_minute) {
                minutes++;
            }
        }
        if (fresh_count == 0) {
            return minutes;
        } else {
            return -1;
        }
    }
};
