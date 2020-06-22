#ifndef H_lowest_common_ancestor
#define H_lowest_common_ancestor

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class LCA {
    public:
        int n, log_v = 0;
        vector<int> depth;
        vector<T> costs;
        vector<vector<int> > to;
        vector<vector<T> > cost;
        vector<vector<int> > parent;

        LCA() {}
        LCA(int n_): n(n_) {
            while ((1 << log_v) < n) ++log_v;
            depth.assign(n, 0);
            costs.assign(n, 0);
            to = vector<vector<int> >(n);
            cost = vector<vector<T> >(n);
            parent = vector<vector<int> >(log_v, vector<int>(n, 0));
        }

        void init(int root = 0) {
            dfs(root);
            for (int i = 0; i < log_v - 1; ++i) {
                for (int j = 0; j < n; ++j) parent[i + 1][j] = parent[i][parent[i][j]];
            }
        }

        void addEdge(int u, int v, T c = 0) {
            to[u].push_back(v);
            to[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
        }

        void dfs(int v, int p = -1, int d = 0, T c = 0) {
            if (p != -1) parent[0][v] = p;
            depth[v] = d;
            costs[v] = c;
            for (int i = 0; i < to[v].size(); ++i) {
                int e = to[v][i];
                if (e == p) continue;
                dfs(e, v, d + 1, c + cost[v][i]);
            }
        }

        int query(int u, int v) {
            if (depth[u] > depth[v]) swap(u, v);
            for (int i = 0; i < log_v; ++i) {
                if ((depth[v] - depth[u]) >> i & 1) v = parent[i][v];
            }
            if (u == v) return u;
            for (int i = log_v - 1; i >= 0; --i) {
                if (parent[i][u] != parent[i][v]) {
                    u = parent[i][u];
                    v = parent[i][v];
                }
            }
            return parent[0][u];
        }

        int length(int u, int v) {
            return depth[u] + depth[v] - 2 * depth[query(u, v)];
        }

        T dist(int u, int v) {
            return costs[u] + costs[v] - 2 * costs[query(u, v)];
        }

        // is x on the path u - v
        bool isOnPath(int u, int v, int x) {
            return length(u, x) + length(v, x) == length(u, v);
        }
};

#endif