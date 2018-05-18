//
//  main.cpp
//  f-51Nod-1350-斐波那契表示
//
//  Created by ZYJ on 16/9/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 90;
//
//long long Fib[MAXN] = {1, 1};
//long long A[MAXN] = {0, 1, 1};
//
//void init()
//{
//    for (int i = 2; i < MAXN; i++)
//    {
//        Fib[i] = Fib[i - 1] + Fib[i - 2];
//    }
//    for (int i = 3; i < MAXN; i++)
//    {
//        A[i] = A[i - 1] + A[i - 2] + Fib[i - 3];
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    init();
//    
//    int T;
//    cin >> T;
//    
//    long long n;
//    while (T--)
//    {
//        long long ans = 0;
//        scanf("%lld", &n);
//        for (int i = 1; i < MAXN; i++)
//        {
//            if (Fib[i] + Fib[i - 1] - 1 <= n)
//            {
//                ans += A[i];
//            }
//            else
//            {
//                long long sur = n - Fib[i] + 1;
//                while (sur)
//                {
//                    for (i--; i >= 1; i--)
//                    {
//                        if (Fib[i - 1] <= sur)
//                        {
//                            sur -= Fib[i - 1];
//                            ans += A[i] + sur;
//                            break;
//                        }
//                    }
//                }
//                break;
//            }
//        }
//        printf("%lld\n", ans);
//    }
//    
//    return 0;
//}

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 90;

ll f[MAXN], g[MAXN];

ll F(ll n)
{
    int x;
    x = (int)(lower_bound(f, f + MAXN, n) - f);
    if (f[x] == n)
    {
        return g[x];
    }
    x--;
    return g[x] + F(n - f[x]) + n - f[x];
}

int main()
{
    ll n;
    int i, T;
    f[0] = f[1] = 1;
    g[0] = g[1] = 1;
    for (i = 2; i < MAXN; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        g[i] = g[i - 1] + g[i - 2] + f[i - 2] - 1;
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &n);
        printf("%lld\n", F(n));
    }
    return 0;
}