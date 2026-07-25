class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        vector<vector<long long>> best(n, vector<long long>(n, -1));
        vector<vector<long long>> cnt(n, vector<long long>(n, 0));
        best[n - 1][n - 1] = 0;
        cnt[n - 1][n - 1] = 1;
        int dx[3] = {1, 0, 1};
        int dy[3] = {0, 1, 1};
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i == n - 1 && j == n - 1) continue;
                if(board[i][j] == 'X') continue;
                long long b = -1, c =0;
                for(int k = 0; k < 3; k++){
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < n && nj < n && best[ni][nj] != -1) {
                        if (best[ni][nj] > b) {
                            b = best[ni][nj];
                            c = cnt[ni][nj];
                        } else if (best[ni][nj] == b) {
                            c = (c + cnt[ni][nj]) % MOD;
                        }
                    }
                }
                if (b == -1) continue;
                int add = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                best[i][j] = b + add;
                cnt[i][j] = c;
            }
        }

        if(best[0][0] == -1) return {0, 0};
        return {(int)(best[0][0] % MOD), (int)cnt[0][0]};
    }
};