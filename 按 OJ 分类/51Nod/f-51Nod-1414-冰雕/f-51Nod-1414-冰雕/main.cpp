//
//  main.cpp
//  f-51Nod-1414-冰雕
//
//  Created by ZYJ on 16/8/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 2e4 + 10;
//
//int T[MAXN];
//
//int main(int argc, const char * argv[])
//{
//    int n;
//    
//    while (cin >> n)
//    {
//        int sum = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            scanf("%d", T + i);
//            sum += T[i];
//        }
//        int ans = sum;
//        for (int i = 3; i <= n / 2; i++)
//        {
//            if (n % i)
//            {
//                continue;
//            }
//            int key = n / i;
//            for (int j = 1; j <= key; j++)
//            {
//                sum = 0;
//                for (int k = j; k <= n; k += key)
//                {
//                    sum += T[k];
//                }
//                if (sum > ans)
//                {
//                    ans = sum;
//                }
//            }
//        }
//        cout << ans << '\n';
//    }
//    
//    return 0;
//}

#include <stdio.h>

#define MAXN 20000
#define INF 0x3f3f3f3f
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int n;
int a[MAXN * 2];

int calc(int cnt, int step)
{
    int ans = -INF;
    int tmp;
    for (int i = 0; i < step; ++i)
    {
        tmp = 0;
        for (int j = 0; j < n; j += step)
        {
            tmp += a[i + j];
        }
        ans = MAX(ans, tmp);
    }
    return ans;
}

int main()
{
    int i, x, y;
    int ans = -INF;
    int tmp;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
        a[i + n] = a[i];
    }
    for (x = 1; x * x <= n; ++x)
    {
        if (n % x)  //  不能x等分或者n/x等分
        {
            continue;
        }
        y = n / x;
        if (x >= 3) //  x等分
        {
            tmp = calc(x, y);
            ans = MAX(ans, tmp);
        }
        if (y >= 3) //  y等分
        {
            tmp = calc(y, x);
            ans = MAX(ans, tmp);
        }
    }
    
    printf( "%d\n", ans );
    
    return 0;
}