class Node {
    public:
        unordered_map<char,Node*> subtree;
        string word;
};

class Solution {
    set<string> res;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    void trie_add(Node* root, string& word) {
        Node* node = root;
        for (char c : word) {
            if (node->subtree.find(c) == node->subtree.end()) {
                node->subtree[c] = new Node();
            }
            node = node->subtree[c];
        }
        node->word = word;
    }

    bool is_valid(vector<vector<char>>& board, int y, int x) {
        return (y >= 0 && x >= 0 && y < board.size() && x < board[0].size());
    }

    void backtrack(vector<vector<char>>& board, Node* root, int y, int x, int ind) {
        if (root->word != "" && root->word.size() == ind) {
            res.insert(root->word);
        }
        for (auto dir : directions) {
            int dx = dir.first + x;
            int dy = dir.second + y;
            if (is_valid(board,dy,dx) && root->subtree.find(board[dy][dx]) != root->subtree.end()) {
                char original = board[y][x];
                board[y][x] = '#';
                backtrack(board,root->subtree[board[dy][dx]],dy,dx,ind+1);
                board[y][x] = original;
            }
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for (string word : words) {
            trie_add(root, word);
        }
        for (int y = 0; y < board.size();y++) {
            for (int x = 0; x < board[0].size();x++) {
                if (root->subtree.find(board[y][x]) != root->subtree.end()) {
                    backtrack(board,root->subtree[board[y][x]],y,x,1);
                }
            }
        }
        vector<string> sol(res.begin(),res.end());
        return sol;
    }
};
