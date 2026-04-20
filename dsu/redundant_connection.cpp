#include <vector>

class Solution {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges) {
        std::vector<int> parent(edges.size(), -1);
        std::vector<int> sz(edges.size(), 1);

        for (auto &edge : edges) {
            int p = edge[0] - 1;
            int q = edge[1] - 1;

            int rootp = find(parent, p);
            int rootq = find(parent, q);

            if (rootp == rootq) {
                return edge;
            }
            if (sz[rootp] < sz[rootq]) {
                parent[rootp] = rootq;
                sz[rootq] += sz[rootp];
            } else {
                parent[rootq] = rootp;
                sz[rootp] += sz[rootq];
            }
        }

        return {};
    }

    int find(std::vector<int> &parent, int x) {
        if (parent[x] == -1) {
            return x;
        }

        parent[x] = find(parent, parent[x]);
        return parent[x];
    }
};
