//
//  main.cpp
//  f-CF-Educational Codeforces Round 44 (Rated for Div. 2)-E-Pencils and Boxes
//
//  Created by ZYJ on 2018/5/22.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

//  WA
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//const int MAXN = 5e5 + 10;
//
//int n, k, d;
//int a[MAXN];
//
//int main()
//{
//    cin >> n >> k >> d;
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> a[i];
//    }
//    sort(a, a + n);
//
//    int m = n / k, pos = 0;
//
//    while (m && pos < n)
//    {
//        m--;
//        int mx = a[pos] + d;
//        while (pos < n && (n - pos > m * k) && a[pos] <= mx)
//        {
//            pos++;
//        }
//    }
//
//    if (m == 0 && pos == n)
//    {
//        printf("YES\n");
//    }
//    else
//    {
//        printf("NO\n");
//    }
//
//    return 0;
//}

//  AC1
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 5e5 + 10;

int n, k, d;
int a[MAXN], pos[MAXN];
int ans[MAXN], dif[MAXN];

int main()
{
    scanf("%d%d%d", &n, &k, &d);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    sort(a, a + n);

    int ptr = 0;
    for (int i = 0; i < n; i++)
    {
        while (ptr < n && a[ptr] - a[i] <= d)
        {
            ptr++;
        }
        pos[i] = ptr;   //  i ~ ptr - 1 差值小于等于 d 且 ptr 最大
    }

    ans[0] = 1;         //  i 作为下一个分组的起点的情况数
    dif[1] = -1;        //  控制下一个起点的范围，如果当前 i 为起点，那么 i + k 可以为下一个起点，
                        //  换言之，对于 i 为起点的情况，他的终点必须在 i + k - 1 ~ pos[i] - 1 这个范围
                        //  所以 i + k ~ pos[i] 可以作为下一个起点，而 pos[i] + 1 则不能作为下一个起点
                        //  因为 ans[i] = ans[i - 1] + dif[i]，所以只需要设置
                        //  dif[i + k]++ 与 dif[pos[i] + 1]-- 即可
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            ans[i] = ans[i - 1] + dif[i];
        }

        if (ans[i] == 0)
        {
            continue;
        }
        if (pos[i] - i < k)
        {
            continue;
        }

        dif[i + k]++;
        dif[pos[i] + 1]--;
    }

    ans[n] = ans[n - 1] + dif[n];

    puts(ans[n] ? "YES" : "NO");

    return 0;
}

