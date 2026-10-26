class Solution {
    int n = 0;
    int m = 0;

    void dfs(vector<vector<char>>& grid,int i,int j) {
        grid[i][j] = '0';
        if (j+1 < m && grid[i][j+1] == '1') {
            dfs(grid,i,j+1);
        }
        if (j-1 >= 0 && grid[i][j-1] == '1') {
            dfs(grid,i,j-1);
        }
        if (i+1 < n && grid[i+1][j] == '1') {
            dfs(grid,i+1,j);
        }
        if (i-1 >= 0 && grid[i-1][j] == '1') {
            dfs(grid,i-1,j);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (!n) return 0;

        m = grid[0].size();
        if (!m) return 0;

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid,i,j);
                }
            }
        }

        return res;
    }
};
