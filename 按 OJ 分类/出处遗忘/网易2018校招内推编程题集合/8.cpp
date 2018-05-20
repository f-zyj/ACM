#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXK = 1e5 + 5;
const int MAXN = 15;

int n, k;
int dp[MAXK][MAXN]; //  dp[i][j] 前 j 个数以 i 结尾的个数

int main()
{
    cin >> n >> k;
    
    int sum;
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        //  前 i - 1 个数的序列个数
        for (int j = 1; j <= k; j++)
        {
            sum += dp[j][i - 1];
            sum %= MOD;
        }
        
        int sum2;
        for (int j = 1; j <= k; j++)
        {
            sum2 = 0;
            //  前 i - 1 个数以 j 的倍数结尾的序列个数
            for (int z = j + j; z <= k; z += j)
            {
                sum2 += dp[z][i - 1];
                sum2 %= MOD;
            }
            dp[j][i] = (sum - sum2 + MOD) % MOD;
        }
    }
    
    int ans = 0;
    for (int j = 1; j <= k; j++)
    {
        ans += dp[j][n];
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}
