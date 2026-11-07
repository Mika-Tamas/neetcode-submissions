class Solution {
    int dfs(string& s, int ind, vector<int>& dp) {

        if (dp[ind] != -1) return dp[ind];
        if (s[ind] == '0') return 0;

        int res = dfs(s, ind+1,dp);
        if (ind + 1 < s.size() && (s[ind] == '1' || s[ind] == '2' && s[ind+1] < '7')) {
            res += dfs(s, ind+2,dp);
        }

        dp[ind] = res;
        return res;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        dp[s.size()] = 1;
        return dfs(s,0,dp);
    }
};
