class Solution {
private:
    bool sol = false;
    const vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    void backtrack(vector<vector<char>>& board, string word, int x, int y,int ind) {
        if (ind == word.size()) {
            sol = true;
            return;
        }
        char original = board[y][x];
        board[y][x] = '#';
        for (auto dir : directions) {
            int dx = dir.first + x;
            int dy = dir.second + y;
            if (is_valid(board,dx,dy) && word[ind] == board[dy][dx]) {
                backtrack(board,word,dx,dy,ind+1);
            }
        }
        board[y][x] = original;
        return;

    }
    bool is_valid(vector<vector<char>>& board,int x, int y) {
        return !(y >= board.size() || y < 0 || x < 0 || x >= board[0].size());
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int y = 0; y < board.size();y++) {
            for (int x = 0; x < board[0].size();x++) {
                if (board[y][x] == word[0])
                    backtrack(board,word,x,y,1);
            }
        }
        return sol;
        
    }
};
