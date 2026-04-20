#include <vector>
#include <string>

class Solution {
public:
    std::vector<bool> used;
    std::vector<bool> diag1;
    std::vector<bool> diag2;
    std::vector<std::string> board;
    std::vector<std::vector<std::string>> res;

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        used.assign(n, false);
        board.assign(n, std::string(n, '.'));
        backtrack(n, 0);
        return res;
    }

    void backtrack(int n, int row) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i] || diag1[row - i + n] || diag2[row + i]) {
                continue;
            }

            used[i] = diag1[row - i + n] = diag2[row + i] = true;
            board[row][i] = 'Q';
            backtrack(n, row + 1);
            used[i] = diag1[row - i + n] = diag2[row + i] = false;
        }
    }
};
