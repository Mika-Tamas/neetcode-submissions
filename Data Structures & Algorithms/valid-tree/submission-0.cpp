class Solution {

    bool dfs(int edge, int parent, 
    const vector<vector<int>>& adj, unordered_set<int>& visit) {
        if (visit.count(edge)) {
            return false;
        }
        visit.insert(edge);
        for (int i = 0; i < adj[edge].size(); i++) {
            if (adj[edge][i] == parent) continue;
            if (!dfs(adj[edge][i],edge,adj,visit)) return false;
        }

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);
        unordered_set<int> visit;

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if (!dfs(0,-1,adj,visit)) {
            return false;
        }

        return visit.size() == n;
    }
};
