class Solution {
public:
    int n, m;
    int dp[101][101][205];

    bool solve(int i, int j, int balance, vector<vector<char>>& grid) {
        if (i >= n || j >= m)
            return false;

        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

    
        if (i == n - 1 && j == m - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool down = solve(i + 1, j, balance, grid);
        bool right = solve(i, j + 1, balance, grid);

        return dp[i][j][balance] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int len = n + m - 1;

        if (len % 2 != 0)
            return false;

        if (grid[0][0] == ')' || grid[n-1][m-1] == '(')
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, grid);
    }
};