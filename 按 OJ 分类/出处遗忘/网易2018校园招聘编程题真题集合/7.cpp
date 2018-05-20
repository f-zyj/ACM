#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2222;
const int INF = 0x3f3f3f3f;

int n;
int val[MAXN];
int dif[MAXN];
int dp[MAXN][MAXN];

int main()
{
    scanf("%d%d", &n, val);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", val + i);
        dif[i] = abs(val[i] - val[i - 1]);
    }
    
    int res = INF;
    for (int i = 2; i < n; i++)
    {
        //      dp[i][0] = dp[i - 1][0] + dif[i];
        dp[i][i - 1] = dp[i - 1][i - 2] + dif[i - 1];
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            dp[i][j] = dp[i - 1][j] + dif[i];
            dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + abs(val[i] - val[j]));
        }
    }
    
    int ans = INF;
    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans << '\n';
    
    return 0;
}
