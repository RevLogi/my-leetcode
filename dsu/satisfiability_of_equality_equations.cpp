#include <string>
#include <vector>

class Solution {
public:
    bool equationsPossible(std::vector<std::string>& equations) {
        std::vector<int> parent(26, -1);
        std::vector<int> sz(26, 1);

        for (auto& equation : equations) {
            if (equation[1] == '!') {
                continue;
            }

            int p = equation[0] - 'a';
            int q = equation[3] - 'a';

            int rootp = find(parent, p);
            int rootq = find(parent, q);

            if (rootp == rootq) continue;

            if (sz[rootp] < sz[rootq]) {
                parent[rootp] = rootq;
                sz[rootq] += sz[rootp];
            } else {
                parent[rootq] = rootp;
                sz[rootp] += sz[rootq];
            }
        }

        for (auto& equation : equations) {
            if (equation[1] == '=') {
                continue;
            }

            int p = equation[0] - 'a';
            int q = equation[3] - 'a';

            int rootp = find(parent, p);
            int rootq = find(parent, q);

            if (rootp == rootq) {
                return false;
            }
        }

        return true;
    }

    int find(std::vector<int>& parent, int x) {
        if (parent[x] == -1) {
            return x;
        }
        parent[x] = find(parent, parent[x]);
        return parent[x];
    }
};
