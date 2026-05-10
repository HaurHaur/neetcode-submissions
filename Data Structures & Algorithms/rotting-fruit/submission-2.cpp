class Solution {
public:
    void bfs(vector<vector<int>>& grid, int xx, int yy, vector<vector<int>> &min_path, vector<vector<int>> &visited){
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        q.push({xx - 1, yy, 1});
        q.push({xx + 1, yy, 1});
        q.push({xx, yy - 1, 1});
        q.push({xx, yy + 1, 1});
        while(!q.empty()){
            vector<int> info = q.front();
            q.pop();
            int x = info[0];
            int y = info[1];
            if(x >= m || x < 0 || y >= n || y < 0){
                continue;
            }
            cout << "index = " << xx << ", " << yy << " visited x = " << x << " y = " << y << " add by " << info[2] <<endl;
            if(grid[x][y] == 1 && !visited[info[0]][info[1]]){
                visited[x][y] = 1;
                min_path[x][y] = min(min_path[x][y], info[2]);
                q.push({x - 1, y, info[2] + 1});
                q.push({x + 1, y, info[2] + 1});
                q.push({x, y - 1, info[2] + 1});
                q.push({x, y + 1, info[2] + 1});
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> min_path(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 2){
                    continue;
                }
                vector<vector<int>> visited(m, vector<int>(n, 0));
                bfs(grid, i, j, min_path, visited);
            }

        }

        int result = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    result = max(result, min_path[i][j]);
                }
            }

        }
        return result == INT_MAX ? -1 : result;
    }
};
