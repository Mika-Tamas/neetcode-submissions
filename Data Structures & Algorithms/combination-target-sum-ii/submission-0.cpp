class Solution {
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, int target, 
    vector<int>& cur, int sum, int i) {
        if (sum == target) {
            res.push_back(cur); return;
        }
        if (sum > target || i == candidates.size()) return;

        cur.push_back(candidates[i]);
        backtrack(candidates,target,cur,sum+candidates[i],i+1);
        cur.pop_back();

        while (i+1 < candidates.size() && 
        candidates[i+1] == candidates[i]) {
            i++;
        }
        backtrack(candidates,target,cur,sum,i+1);

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        backtrack(candidates,target,cur,0,0);
        return res;
    }
};
