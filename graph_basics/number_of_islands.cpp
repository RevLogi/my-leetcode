#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        int res = 0;
        int row_num = grid.size();
        int col_num = grid[0].size();
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j, row_num, col_num);
                }
            }
        }
        return res;
    }

    void dfs(std::vector<std::vector<char>> &grid, int row, int col, int maxr, int maxc) {
        if (row < 0 || col < 0 || row >= maxr || col >= maxc || grid[row][col] == '0') return;

        grid[row][col] = '0';
        dfs(grid, row + 1, col, maxr, maxc);
        dfs(grid, row - 1, col, maxr, maxc);
        dfs(grid, row, col + 1, maxr, maxc);
        dfs(grid, row, col - 1, maxr, maxc);
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                           {'1', '1', '0', '1', '0'},
                                           {'1', '1', '0', '0', '0'},
                                           {'0', '0', '0', '0', '0'}};
    solution.numIslands(grid);
    return 0;
}
