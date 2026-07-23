class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // 1. C++ mein vector object hota hai pointer nahi, toh .empty() check karte hain
        if (grid.empty()) {
            return;
        }

        // Variable ka type (int) batana zaroori hai
        int rows = grid.size();
        int cols = grid[0].size();

        // C++ mein BFS ke liye directly 'queue' use karte hain, jo pairs store karega
        queue<pair<int, int>> q;
        int INF = 2147483647; // int lagana zaroori tha

        // C++ mein array/pairs banane ke liye {} (curly braces) use hote hain
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 1: Saare Khazanon ko line mein lagao
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j}); // Pair ko push karne ke liye {}
                }
            }
        }

        // Step 2: Line process karo (The remaining code)
        while (!q.empty()) {
            // C++ mein line ke aage wale ko dekhne ke liye .front(), aur nikalne ke liye .pop() hota hai
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Chaaron padosiyon ke paas jao
            for (auto dir : directions) {
                int new_r = r + dir.first;
                int new_c = c + dir.second;

                // Agar boundaries ke bahar hai, ya paani (-1) hai, ya pehle se visited hai toh ignore
                if (new_r < 0 || new_r >= rows || new_c < 0 || new_c >= cols || grid[new_r][new_c] != INF) {
                    continue;
                }

                // Naya distance set karo
                grid[new_r][new_c] = grid[r][c] + 1;
                
                // Naye cell ko line mein khada kar do
                q.push({new_r, new_c});
            }
        }
    }
};