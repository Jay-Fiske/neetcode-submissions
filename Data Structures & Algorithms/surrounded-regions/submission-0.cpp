class Solution {
   private:
    int ROWS, COLS;
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited0, int i, int j) {
        if (i < 0 || j < 0 || i == ROWS || j == COLS || board[i][j] == 'X' || visited0[i][j] == 1) {
            return;
        }
        visited0[i][j] = 1;
        dfs(board, visited0, i - 1, j);
        dfs(board, visited0, i + 1, j);
        dfs(board, visited0, i, j - 1);
        dfs(board, visited0, i, j + 1);
    }

   public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();
        vector<vector<int>> visited0(ROWS, vector<int>(COLS, 0));

        for (int i = 0; i < ROWS; i++) {
            if (board[i][0] == 'O' && visited0[i][0] == 0) {
                dfs(board, visited0, i, 0);
            }
            if (board[i][COLS - 1] == 'O' && visited0[i][COLS - 1] == 0) {
                dfs(board, visited0, i, COLS - 1);
            }
        }
        for (int j = 0; j < COLS; j++) {
            if (board[0][j] == 'O' && visited0[0][j] == 0) 
                dfs(board, visited0, 0, j);
            if (board[ROWS - 1][j] == 'O' && visited0[ROWS - 1][j] == 0) {
                dfs(board, visited0, ROWS - 1, j);
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'O' && visited0[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
