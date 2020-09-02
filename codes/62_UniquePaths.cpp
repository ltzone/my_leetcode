#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> tmp(n, 0);
        vector<vector<int>> dp(m, tmp);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    int right = i > 0 ? dp[i - 1][j] : 0;
                    int down = j > 0 ? dp[i][j - 1] : 0;
                    dp[i][j] = right + down;
                }
            }
        }
        // for (int i=0;i<m;i++){
        //   for (int j=0;j<n;j++){
        //       cout << dp[i][j] << " ";
        //   }
        //     cout << endl;
        // }
        return dp[m - 1][n - 1];
    }
};