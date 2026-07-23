class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        if not grid:
            return 0

        rows = len(grid)
        cols = len(grid[0])
        
        q = deque()
        INF = 2147483647

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    q.append((r,c))

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while q:
            r, c = q.popleft()

            for dr, dc in directions:
                new_r = r + dr
                new_c = c + dc
        
                if (new_r < 0 or new_r >= rows or 
                    new_c < 0 or new_c >= cols or 
                    grid[new_r][new_c] != INF):
                    continue

                grid[new_r][new_c] = grid[r][c] + 1

                q.append((new_r,new_c))
