class Solution {
   private:
    int ROWS, COLS;
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i == ROWS || j == COLS || board[i][j] == 'X' || board[i][j] == '#') {
            return;
        }
        board[i][j] = '#';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }

   public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int i = 0; i < ROWS; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][COLS - 1] == 'O') {
                dfs(board, i, COLS - 1);
            }
        }
        for (int j = 0; j < COLS; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[ROWS - 1][j] == 'O') {
                dfs(board, ROWS - 1, j);
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
