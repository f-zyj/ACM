//
//  main.cpp
//  f-51Nod-1268-和为K的组合
//
//  Created by ZYJ on 16/8/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

////  弱数据动态规划解法
//
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 25;
//const int MAXK = 10;
//
//int A[MAXN];
//int dp[MAXN][MAXK] = {0};
//
//int main(int argc, const char * argv[])
//{
//    int N, K;
//    cin >> N >> K;
//    
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d", A + i);
//    }
//    
//    for (int i = 0; i <= N; i++)
//    {
//        dp[i][0] = 1;
//    }
//    
//    for (int i = 1; i <= N; i++)
//    {
//        for (int j = 1; j <= K; j++)
//        {
//            if (j < A[i])
//            {
//                dp[i][j] = dp[i - 1][j];
//            }
//            else
//            {
//                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i]]);
//            }
//        }
//    }
//    
//    if (dp[N][K])
//    {
//        cout << "Yes\n";
//    }
//    else
//    {
//        cout << "No\n";
//    }
//    
//    return 0;
//}



////  深度优先搜索解法
//
//#include <iostream>
//#include <cstdio>
//
//const int MAXN = 22;
//
//int N, K;
//int A[MAXN];
//
//bool dfs(int rest, int dep)
//{
//    if (dep == N)
//    {
//        return false;
//    }
//    if (rest == A[dep])
//    {
//        return true;
//    }
//    if (rest > A[dep])
//    {
//        rest -= A[dep];
//        if (dfs(rest, dep + 1))
//        {
//            return true;
//        }
//        rest += A[dep];
//    }
//    return dfs(rest, dep + 1);
//}
//
//int main()
//{
//    scanf("%d %d", &N, &K);
//    for (int i = 0; i < N; i++)
//    {
//        scanf("%d", A + i);
//    }
//    
//    if (dfs(K, 0))
//    {
//        printf("Yes\n");
//    }
//    else
//    {
//        printf("No\n");
//    }
//    
//    return 0;
//}


//  强数据超大背包优化
//  个人感觉已经有些不像动态规划了~\(≧▽≦)/~
#include <iostream>
#include <map>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, k, d[25];

map<int, int> v;

void solve()
{
    int n_1 = n / 2;
    v.clear();
    for (int i = 0; i < (1 << n_1); i++)    //  1 << n_1: 每个数字都有选与不选两个状态
    {                                       //  n_1个数字则有2^n_1个状态组合，即1 << n_1
        int sw = 0;
        for (int j = 0; j < n_1; j++)
        {
            if (i & (1 << j))
            {
                sw += d[j];
            }
        }
        v[sw] = 1;
    }
    int n_2 = n - n_1;
    bool ok = 0;
    for (int i = 0; i < (1 << n_2); i++)
    {
        int sw = 0;
        for (int j = 0; j < n_2; j++)
        {
            if(i & (1 << j))
            {
                sw += d[j + n_1];
            }
        }
        if (v[k - sw] == 1)
        {
            ok = 1;
            break;
        }
    }
    if (ok)
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
}

int main()
{
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    
    solve();
    
    return 0;
}