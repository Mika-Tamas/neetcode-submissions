class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m));

        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int left = (i-1 >= 0) ? dp[i-1][j] : 0;
                int up = (j-1 >= 0) ? dp[i][j-1] : 0;
                dp[i][j] += left + up;
            }
        }

        return dp[n-1][m-1];
    }
};
