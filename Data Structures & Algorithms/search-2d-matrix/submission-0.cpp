class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int width = matrix[0].size();
        int l = 0;
        int r = width * matrix.size() - 1;
        while (l <= r) {
            int half = l + (r - l) / 2;
            int y = half / width;
            int x = half - y * width;
            if (matrix[y][x] == target) {
                return true;
            }
            if (matrix[y][x] < target) {
                l = half + 1;
            } else {
                r = half - 1;
            }
        }
        return false;
    }
};
