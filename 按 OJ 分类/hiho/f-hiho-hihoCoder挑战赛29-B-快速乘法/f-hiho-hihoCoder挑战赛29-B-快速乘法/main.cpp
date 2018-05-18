//
//  main.cpp
//  f-hiho-hihoCoder挑战赛29-B-快速乘法
//
//  Created by ZYJ on 2017/6/26.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//const int MAXN = 1e6 + 10;
//
//int n;
//char s[MAXN];
//
//int main()
//{
//    scanf("%s", s + 1);
//    n = (int)strlen(s + 1);
//    
//    //  头尾的 0 并无影响
//    int l = 1, r = n;
//    while (l <= n && s[l] == '0')
//    {
//        l++;
//    }
//    while (r && s[r] == '0')
//    {
//        r--;
//    }
//    if (!r)
//    {
//        printf("0\n");
//        return 0;
//    }
//    
//    int u = 1, d = 1;
//    for (int i = r - 1; i >= l; i--)
//    {
//        if (s[i] == '1')
//        {
//            u = min(u, d) + 1;
//        }
//        else
//        {
//            d = min(u, d) + 1;
//        }
//    }
//    
//    printf("%d\n", 2 * u - 1);
//    
//    return 0;
//}

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10;

char s[MAXN];
int sum[MAXN];
int f[MAXN];

int main()
{
    scanf("%s", s + 1);
    int len = (int)strlen(s + 1);
    reverse(s + 1, s + len + 1);    //  不倒置也行，不过要反过来搞
    
    for (int i = 1; i <= len; i++)
    {
        sum[i] = sum[i - 1] + (s[i] == '0');
    }
    
    int pos = -1;
    for (int i = 1; i <= len; i++)
    {
        if (s[i] == '0')
        {
            f[i] = f[i - 1];
        }
        else
        {
            f[i] = f[i - 1] + 1;
            if (pos)
            {
                f[i] = min(f[i], f[pos - 1] + 2 + sum[i] - sum[pos - 1]);
            }
        }
        if (pos == -1 || f[pos - 1] + 2 + sum[i + 1] - sum[pos - 1]
                          >= f[i - 1] + 2 + sum[i + 1] - sum[i - 1])
        {
            pos = i;
        }
    }
    
    printf("%d\n", f[len] * 2 - 1);
    
    return 0;
}
