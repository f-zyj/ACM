//
//  main.cpp
//  f-HDU-2017 多校训练赛1-1002-Balala Power!
//
//  Created by ZYJ on 2017/7/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//  CE
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cstring>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXK = 26;
//const int MAXS = 1e5 + 10;
//const int MOD = 1e9 + 7;
//
//int n, cnt;
//int vis[MAXK];
//string s;
//
//struct xxx
//{
//    int pos;
//    int len;
//    int num[MAXS];
//} Num[MAXK];
//
//bool cmp(const xxx &a, const xxx &b)
//{
//    if (a.len != b.len)
//    {
//        return a.len > b.len;
//    }
//    for (int i = a.len; i > 0; i--)
//    {
//        if (a.num[i] != b.num[i])
//        {
//            return a.num[i] > b.num[i];
//        }
//    }
//    
//    return a.num[0] > b.num[0];
//}
//
//int main(int argc, const char * argv[])
//{
//    int ce = 1;
//
//    while (cin >> n)
//    {
//        cnt = 25;
//        memset(vis, 0, sizeof(vis));
//        memset(Num, 0, sizeof(Num));
//        for (int i = 0; i < MAXK; i++)
//        {
//            Num[i].pos = i;
//        }
//        
//        for (int i = 0; i < n; i++)
//        {
//            cin >> s;
//            if (s.length() > 1)
//            {
//                vis[s[0] - 'a'] = 1;
//            }
//            
//            for (int j = 0, k = (int)s.length(); j < s.length(); j++, k--)
//            {
//                int t = s[j] - 'a';
//                Num[t].num[k]++;
//                int x = k;
//                while (Num[t].num[x] == MAXK)
//                {
//                    Num[t].num[x++] = 0;
//                    Num[t].num[x]++;
//                }
//                Num[t].len = max(Num[t].len, x);
//            }
//        }
//        
//        sort(Num, Num + MAXK, cmp);
//        
//        if (vis[Num[MAXK - 1].pos])
//        {
//            int i = MAXK - 1;
//            for (; i >= 0; i--)
//            {
//                if (vis[i] == 0)
//                {
//                    break;
//                }
//            }
//            xxx a = Num[i];
//            for (; i < MAXK - 1; i++)
//            {
//                Num[i] = Num[i + 1];
//            }
//            Num[MAXK - 1] = a;
//        }
//        
//        long long res = 0;
//        for (int i = 0; i < n; i++)
//        {
//            long long tmp = 0;
//            for (int j = Num[i].len; j > 0; j--)
//            {
//                tmp *= MAXK;
//                tmp += (long long)Num[i].num[j] * cnt;
//                tmp %= MOD;
//            }
//            cnt--;
//            res += tmp;
//            res %= MOD;
//        }
//        
//        cout << "Case #" << ce++ << ": " << res << '\n';
//    }
//    
//    return 0;
//}

//  AC
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int MAXK = 26;
const int MOD = 1e9 + 7;

struct node
{
    int pos;
    char num[MAXN];
} Num[MAXK + 1];

int vis[MAXK];

bool cmp(node &A, node &B)
{
    for (int i = MAXN - 1; i > 0; i--)
    {
        if (A.num[i] != B.num[i])
        {
            return A.num[i] < B.num[i];
        }
    }
    return A.num[0] < B.num[0];
}

int n;
char str[MAXN];

int main()
{
    int ce = 1;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < MAXK; i++)
        {
            vis[i] = 0;
            Num[i].pos = i;
            for (int j = 0; j < MAXN; j++)
            {
                Num[i].num[j] = 0;
            }
        }
        
        int x, y;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str);
            
            int len = (int)strlen(str);
            
            if (len > 1)    //  前置标记
            {
                vis[str[0] - 'a'] = 1;
            }
            
            for (int j = 0 ; j < len; j++)
            {
                x = str[j] - 'a';
                y = len - j - 1;
                Num[x].num[y]++;
                
                while (Num[x].num[y] == MAXK)
                {
                    Num[x].num[y++] = 0;
                    Num[x].num[y]++;
                }
            }
        }
        
        sort(Num, Num + MAXK, cmp);
        
        int op = -1;
        ll ans = 0, tmp, mul;
        for (int i = 0; i < MAXK; i++)
        {
            if (vis[Num[i].pos] == 0)
            {
                op = i;
                break;
            }
        }
        
        for (int i = 0; i < MAXK; i++)
        {
            tmp = 0;
            mul = 0;
            
            if (i == op)
            {
                mul = 0;
            }
            else if (i < op)
            {
                mul = i + 1;
            }
            else
            {
                mul = i;
            }
            
            for (int j = MAXN - 1; j >= 0; j--)
            {
                
                tmp = (tmp * MAXK) % MOD;
                tmp = (tmp + (ll)Num[i].num[j] * mul) % MOD;
            }
            ans = (ans + tmp) % MOD;
        }
        
        printf("Case #%d: %lld\n", ce++, ans);
    }
    
    return 0;
}

