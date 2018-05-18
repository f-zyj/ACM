//
//  main.cpp
//  f-51Nod-1158-全是1的最大子矩阵
//
//  Created by ZYJ on 2017/3/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 505;

int A[MAXN][MAXN];

int main(int argc, const char * argv[])
{
    int m, n;
    cin >> m >> n;
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", A[i] + j);
            A[i][j] += A[i - 1][j];
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int cnt = 0;
            for (int k = 1; k <= n; k++)
            {
                if (A[j][k] - A[i - 1][k] != j - i + 1)
                {
                    ans = max(ans, cnt * (j - i + 1));
                    cnt = 0;
                }
                else
                {
                    cnt++;
                }
            }
            ans = max(ans, cnt * (j - i + 1));
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
