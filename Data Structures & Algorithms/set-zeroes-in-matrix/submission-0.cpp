class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> zero_rows(n);
        vector<bool> zero_cols(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    zero_rows[i] = true;
                    zero_cols[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (zero_rows[i] || zero_cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
