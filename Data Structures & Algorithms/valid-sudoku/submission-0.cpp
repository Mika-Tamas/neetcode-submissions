class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int,int>> rows(9);
        vector<unordered_map<int,int>> cols(9);
        vector<unordered_map<int,int>> squares(9);

        for (int row = 0; row < board[0].size(); row++) {
            for (int col = 0; col < board.size(); col++) {
                if (board[row][col] == '.') continue;
                int rw = rows[row][board[row][col]]++;
                int cl = cols[col][board[row][col]]++;

                int square_id = (row / 3) * 3 + (col / 3);
                int sq = squares[square_id][board[row][col]]++;
                if (rw || cl || sq) {
                    return false;
                }
            }
        }

        return true;
    }
};
