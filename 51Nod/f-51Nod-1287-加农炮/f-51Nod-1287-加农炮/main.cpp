//
//  main.cpp
//  f-51Nod-1287-加农炮
//
//  Created by ZYJ on 16/9/1.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 5e4 + 10;
//
//int A[MAXN];
//
//int main(int argc, const char * argv[])
//{
//    int M, N;
//    cin >> M >> N;
//    
//    int maxPos = 0;
//    for (int i = 0; i < M; i++)
//    {
//        scanf("%d", A + i);
//        if (A[i] > A[maxPos])
//        {
//            maxPos = i;
//        }
//    }
//    
//    int B;
//    for (int i = 0; i < N; i++)
//    {
//        scanf("%d", &B);
//        if (B <= A[0] || B > A[maxPos])
//        {
//            continue;
//        }
//        for (int i = 0; i < M; i++)
//        {
//            if (A[i] >= B)
//            {
//                A[i - 1]++;
//                break;
//            }
//        }
//    }
//    
//    for (int i = 0; i < M; i++)
//    {
//        printf("%d\n", A[i]);
//    }
//    
//    return 0;
//}

#include <iostream>
#include <cstdio>

#define repe(i, a, n) for (int i = a; i <= n; i++)

using namespace std;

typedef long long LL;

const int MAXN = 5e4 + 10;
const int MAXM = 1e6 + 10;

int a[MAXN], b[MAXN], p[MAXM];

int main()
{
    int n, m, mx = 0;
    cin >> n >> m;
    
    repe(i, 1, n)
    {
        scanf("%d", a + i);
    }
    repe(i, 1, m)
    {
        scanf("%d", b + i);
        mx = max(mx, b[i]);
    }
    int s = 1;
    //  预处理不同高度炮弹的轰炸点
    repe(i, 1, mx)
    {
        while (s <= n && a[s] < i)
        {
            s++;
        }
        p[i] = s - 1;
    }
    //  逐个遍历轰炸更新状态
    repe(i, 1, m)
    {
        int v = p[b[i]];
        if (0 == v || n == v)
        {
            continue;
        }
        a[v]++;
        p[a[v]] = min(p[a[v]], v - 1);
    }
    repe(i, 1, n)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}