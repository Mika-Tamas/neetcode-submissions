class Solution {

    bool dfs(string& s, vector<string>& wordDict, int ind) {
        if (memo.find(ind) != memo.end()) return memo[ind];

        for (const auto& word : wordDict) {
            if (word.size() <= s.size() - ind &&
            s.substr(ind,word.size()) == word) {
                if(dfs(s,wordDict,ind+word.size())) {
                    memo[ind] = true;
                    return true;
                }
            }
        }
        memo[ind] = false;
        return false;
    }

public:

    unordered_map<int,bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.size()] = true;

        return dfs(s, wordDict, 0);
    }
};
