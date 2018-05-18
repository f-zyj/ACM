//
//  main.cpp
//  f-51Nod-1675-序列变换
//
//  Created by ZYJ on 2017/3/7.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//
//int a[MAXN];
//int b[MAXN];
//
//int gcd(int a, int b)
//{
//    if (!a || !b)
//    {
//        return a > b ? a : b;
//    }
//    for (int t; t = a % b, t; a = b, b = t);
//    return b;
//}
//
//int main(int argc, const char * argv[])
//{
////        freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    int n;
//    cin >> n;
//    
//    for (int i = 1; i <= n; i++)
//    {
//        scanf("%d", a + i);
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        scanf("%d", b + i);
//    }
//    
//    int cnt = 0;
//    if (a[b[1]] == b[a[1]])
//    {
//        cnt++;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = i + 1; j <= n; j++)
//        {
//            int temp = (a[b[i]] == b[a[j]]) + (b[a[i]] == a[b[j]]);
//            if (temp && gcd(i, j) == 1)
//            {
//                cnt += temp;
//            }
//        }
//    }
//    
//    cout << cnt << endl;
//    
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

bool check[MAXN];
int prime[MAXN];
int mu[MAXN];

void Mobius()
{
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i <= MAXN; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > MAXN)
            {
                break;
            }
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

int n;
int a[MAXN];
int b[MAXN];
int vis[MAXN];

ll cal(int t)
{
    ll ret = 0;
    for (int i = t; i <= n; i += t)
    {
        vis[b[a[i]]]++;
    }
    for (int i = t; i <= n; i += t)
    {
        ret += vis[a[b[i]]];
    }
    for (int i = t; i <= n; i += t)
    {
        vis[b[a[i]]]--;
    }
    return ret;
}

int main()
{
    Mobius();
    
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a + i);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", b + i);
        }
        
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += mu[i] * cal(i);
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
