class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& comp) {
        vis[node] = true;
        comp.push_back(node);

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis, comp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            mat[u][v] = 1;
            mat[v][u] = 1;
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, adj, vis, comp);

                bool complete = true;
                int sz = comp.size();
                for (int j = 0; j < sz && complete; j++) {
                    for (int k = j + 1; k < sz; k++) {
                        if (mat[comp[j]][comp[k]] == 0) {
                            complete = false;
                            break;
                        }
                    }
                }

                if (complete)
                    ans++;
            }
        }

        return ans;
    }
};
