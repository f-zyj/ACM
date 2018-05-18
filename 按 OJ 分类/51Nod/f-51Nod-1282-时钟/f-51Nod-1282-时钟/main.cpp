////
////  main.cpp
////  f-51Nod-1282-时钟
////
////  Created by ZYJ on 16/9/1.
////  Copyright © 2016年 ZYJ. All rights reserved.
////
//
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 5e3 + 5;
//const int INF = 0x3f3f3f3f;
//
//int N, M, P;
//
//int hands[MAXN];
//int hand[MAXN];
//
//struct clo
//{
//    int hands[MAXN];
//} Clock[MAXN];
//
//bool cmp(clo a, clo b)
//{
//    for (int i = 0; i < M; i++)
//    {
//        if (a.hands[i] != b.hands[i])
//        {
//            return a.hands[i] < b.hands[i];
//        }
//    }
//    return false;
//}
//
////  检测是否相等
//bool cmp_(clo a, clo b)
//{
//    for (int i = 0; i < M; i++)
//    {
//        if (a.hands[i] != b.hands[i])
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//void squ(int key, int *hand)
//{
//    int MIN = INF;
//    int pos = 0;
//    for (int i = 0; i < M; i++)
//    {
//        if (hand[i] < MIN)
//        {
//            MIN = hand[i];
//            pos = i;
//        }
//    }
//    for (int i = pos + 1; i < M; i++)
//    {
//        if (hand[i] == hand[pos])
//        {
//            for (int j = 1; j < M; j++)
//            {
//                if (hand[(i + j) % M] > hand[(pos + j) % M])
//                {
//                    break;
//                }
//                else if (hand[(i + j) % M] < hand[(pos + j) % M])
//                {
//                    pos = i;
//                }
//            }
//        }
//    }
//    int tag = 0;
//    for (int i = pos; i < M; i++)
//    {
//        Clock[key].hands[tag++] = hand[i];
//    }
//    for (int i = 0; i < pos; i++)
//    {
//        Clock[key].hands[tag++] = hand[i];
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    cin >> N >> M >> P;
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < M; j++)
//        {
//            scanf("%d", hands + j);
//        }
//        sort(hands, hands + M);
//        hand[0] = P - hands[M - 1] + hands[0];
//        for (int j = 1; j < M; j++)
//        {
//            hand[j] = hands[j] - hands[j - 1];
//        }
////        sort(Clock[i].hands, Clock[i].hands + M); //  WA，需要按特殊规则排
//        squ(i, hand);
//    }
//    sort(Clock, Clock + N, cmp);
//    
//    int pos = 0;
//    int ans = 0;
//    for (int i = 1; i <= N; i++)
//    {
//        if (!cmp_(Clock[pos], Clock[i]))
//        {
//            int num = i - pos;
//            ans += num * (num - 1) / 2;
//            pos = i;
//        }
//    }
//    std::cout << ans << '\n';
//    return 0;
//}


#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

const int N = 500 + 10;

int n, m, p;
int A[N][N], B[N][N];

int minID[N];

void input()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        sort(A[i], A[i] + m);
        //  求指针差
        for (int j = 0; j < m; ++j)
        {
            B[i][j] = (A[i][(j + 1) % m] - A[i][j] + p ) % p;
        }
    }
}

//  寻找起点
int getMin(int *C)
{
    int i = 0, j = 1, k = 0;
    while (i < m && j < m && k < m)
    {
        int t = C[(i + k) % m] - C[(j + k) % m];
        if (!t)
        {
            k++;
        }
        else
        {
            if (t > 0)
            {
                i += k + 1;
            }
            else
            {
                j += k + 1;
            }
            if (i == j)
            {
                j++;
            }
            k = 0;
        }
    }
    return i < j ? i : j;
}

map<int, int> S;
int SEED = 133331;

void solve()
{
    for (int i = 0; i < n; ++i)
    {
        minID[i] = getMin(B[i]);
    }
    S.clear();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int tmp = 1;
        for (int k = 0; k < m; ++k)
        {
            tmp = tmp * SEED + B[i][(minID[i] + k) % m];    //  哈希
        }
        ans += S[tmp];
        S[tmp]++;
    }
    cout << ans << endl;
    return ;
}

int main()
{
    while (~scanf("%d%d%d", &n, &m, &p))
    {
        input();
        solve();
    }
    return 0;
}