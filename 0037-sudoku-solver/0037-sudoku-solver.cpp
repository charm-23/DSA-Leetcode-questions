
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {

            if (board[i][col] == c) return false;

            if (board[row][i] == c) return false;

            if (board[3 * (row / 3) + i / 3]
                    [3 * (col / 3) + i % 3] == c)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {

                    for (char dig = '1'; dig <= '9'; dig++) {

                        if (isValid(board, row, col, dig)) {

                            board[row][col] = dig;

                            if (solve(board)) return true;

                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
};
