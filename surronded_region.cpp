class Solution {
public:
    void bfs(vector<vector<char>>& board, int sr, int sc) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        q.push({sr, sc});
        board[sr][sc] = '#';

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    board[nx][ny] == 'O') {
                    board[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }
    }
//approch: convert all the border connected zeros to # and then connect all #=0,0=X
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // First and last column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                bfs(board, i, 0);

            if (board[i][m - 1] == 'O')
                bfs(board, i, m - 1);
        }

        // First and last row
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                bfs(board, 0, j);

            if (board[n - 1][j] == 'O')
                bfs(board, n - 1, j);
        }

        // Convert surrounded O -> X
        // Convert safe # -> O
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};