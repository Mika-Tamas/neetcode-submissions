class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> output(temperatures.size(),0);
        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!st.empty() && st.top().first < t) {
                auto pr = st.top();
                st.pop();
                output[pr.second] = i - pr.second;
            }
            st.push({t,i});
        }
        return output;
    }
};
