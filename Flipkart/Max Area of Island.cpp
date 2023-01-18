class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0, islandDigit = 1;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == islandDigit){
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    grid[i][j] = 0;
                    int currentArea = 0;
                    while(!todo.empty()){
                        pair<int, int> currentIndex = todo.front();
                        todo.pop();
                        currentArea++;
                        ans = max(ans, currentArea);
                        for(vector<int>& direction : directions){
                            int indexX = currentIndex.first + direction[0];
                            int indexY = currentIndex.second + direction[1];
                            if(isValidIndex(indexX, indexY, m, n) && grid[indexX][indexY] == islandDigit){
                                todo.push({indexX, indexY});
                                grid[indexX][indexY] = 0;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    bool isValidIndex(int x, int y, int m, int n){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};
