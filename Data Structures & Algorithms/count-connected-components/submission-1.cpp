class Solution {
    unordered_set<int> seen;
    void dfs(vector<vector<int>>& edges,
    vector<vector<int>>& adj,
    int node) {
        for (auto neighbor : adj[node]) {
            if (seen.count(neighbor)) continue;
            seen.insert(neighbor);
            dfs(edges,adj,neighbor);
            
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int node = 0; node < n; node++) {
            if (seen.count(node)) continue;
            dfs(edges, adj, node);
            res++;
        }

        return res;
    }
};
