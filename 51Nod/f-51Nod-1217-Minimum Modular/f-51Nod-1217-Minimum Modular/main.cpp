//
//  main.cpp
//  f-51Nod-1217-Minimum Modular
//
//  Created by ZYJ on 2017/4/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <map>
//#include <cmath>
//#include <cstring>
//
//using namespace std;
//
//const int MAXN = 5e3 + 10;
//const int MAXA = 1e6 + 10;
//
//int N, K, maxA = 0, maxB;   //  a 中最大元素，最多重复次数
//int A[MAXA];
//int B[MAXA];
//int dif_cnt[MAXA];
//int vis[MAXN];
//
//struct lk
//{
//    short x, y;
//    int next;
//} LK[MAXN * MAXN / 2];
//
//int key = 0;
//int dif_head[MAXA];
//
//map<int, int> m;
//
//inline void add(short x, short y, int d)
//{
//    key++;
//    LK[key].x = x;
//    LK[key].y = y;
//    LK[key].next = dif_head[d];
//    dif_head[d] = key;
//    dif_cnt[d]++;
//}
//
//int main(int argc, const char * argv[])
//{
//    cin >> N >> K;
//    
//    if (N == K)
//    {
//        cout << 1 << '\n';
//        return 0;
//    }
//    
//    maxB = K * (K + 1) / 2;
//    for (short i = 0; i < N; i++)
//    {
//        scanf("%d", A + i);
//        maxA = max(maxA, A[i]);
//        for (short j = 0; j < i; j++)
//        {
//            add(i, j, abs(A[i] - A[j]));
//        }
//    }
//    
//    maxA += 2;
//    int M = N - K;
//    int temp;
//    for (; M < maxA; M++)
//    {
//        int ct = 0;
//        for (int i = M; i < maxA; i += M)
//        {
//            ct += dif_cnt[i];
//        }
//        if (ct > maxB)
//        {
//            continue;
//        }
//        ct = 0;
//        for (int i = M; i < maxA && ct <= K; i += M)
//        {
//            for (int j = dif_head[i]; j != 0 && ct <= K; j = LK[j].next)
//            {
//                if (vis[LK[j].x] != M)
//                {
//                    temp = A[LK[j].x] % M;
//                    if (B[temp] != M)
//                    {
//                        B[temp] = M;
//                    }
//                    else
//                    {
//                        ct++;
//                    }
//                    vis[LK[j].x] = M;
//                }
//                if (vis[LK[j].y] != M)
//                {
//                    temp = A[LK[j].y] % M;
//                    if (B[temp] != M)
//                    {
//                        B[temp] = M;
//                    }
//                    else
//                    {
//                        ct++;
//                    }
//                    vis[LK[j].y] = M;
//                }
//            }
//        }
//        if (ct <= K)
//        {
//            break;
//        }
//    }
//    
//    cout << M << '\n';
//    
//    return 0;
//}

#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

inline void read(int &x)
{
    x = 0;
    char ch;
    while (ch = getchar(), ch < '!') ;
    while (x = 10 * x + ch - '0', ch = getchar(), ch > '!') ;
}

const int MAXN = 1e6 + 10;

int N, K;
int a[MAXN], b[MAXN];
int dif[MAXN];

int main()
{
    read(N);
    read(K);
    
    for (int i = 1; i <= N; ++i)
    {
        read(a[i]);
    }
    sort(a + 1, a + N + 1);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            dif[a[j] - a[i]]++;
        }
    }
    
    int M = N - K - 1;
    int cnt_max = K * (K + 1) / 2;
    int cnt, ct;
    while (M++)
    {
        cnt = ct = 0;
        for (int i = M; i < MAXN; i += M)
        {
            cnt += dif[i];
        }
        if (cnt > cnt_max)
        {
            continue;
        }
        for (int i = 1; i <= N; ++i)
        {
            if (b[a[i] % M] == M)
            {
                ++ct;
                if (ct > K)
                {
                    break;
                }
            }
            b[a[i] % M] = M;
        }
        if (ct <= K)
        {
            break;
        }
    }
    
    printf("%d\n", M);
    
    return 0;
}
