class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> elems;
        vector<int> sol;
        for (int i = 0; i < k; i++) {
            elems.push({nums[i],i});
        }
        for (int i = k - 1; i < nums.size(); i++) {
            elems.push({nums[i],i});
            while (elems.top().second < i - k + 1) {
                elems.pop();
            }
            sol.push_back(elems.top().first);
        }
        return sol;
    }
};
