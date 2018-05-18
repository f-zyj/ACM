//
//  main.cpp
//  f-51Nod-1191-消灭兔子
//
//  Created by ZYJ on 16/8/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 5e4 + 5;
//
//struct arrow
//{
//    int D;
//    int P;
//} Arr[MAXN];
//
//struct rabbit
//{
//    int B;
//    bool state; //  兔子状态
//} Rab[MAXN];
//
//int ans = 0;
//
//bool cmpA(arrow a, arrow b)
//{
//    return a.P < b.P;
//}
//
//bool cmpR(rabbit a, rabbit b)
//{
//    return a.B < b.B;
//}
//
////  二分查找小于等于
//int bs(int l, int r, int v)
//{
//    int m;
//    while (l < r)
//    {
//        m = (l + r + 1) >> 1;
//        if (Rab[m].B > v)
//        {
//            r = m - 1;
//        }
//        else
//        {
//            l = m;
//        }
//    }
//    if (Rab[l].B > v)
//    {
//        return -1;
//    }
//    return l;
//}
//
//int main(int argc, const char * argv[])
//{
////    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    
//    int N, M;
//    cin >> N >> M;
//    
//    for (int i = 0; i < N; i++)
//    {
//        scanf("%d", &Rab[i].B);
//        Rab[i].state = true;
//    }
//    for (int i = 0; i < M; i++)
//    {
//        scanf("%d %d", &Arr[i].D, &Arr[i].P);
//    }
//    sort(Rab, Rab + N, cmpR);
//    sort(Arr, Arr + M, cmpA);
//    
//    int tag = 0;
//    for (int i = 0; i < M; i++)
//    {
//        int pos = bs(0, N - 1, Arr[i].D);
////        cout << Arr[i].D << ' ' << pos << ' ' << Rab[pos].B << '\n';
//        while (!Rab[pos].state && pos != -1)
//        {
//            pos--;
//        }
//        if (pos != -1)
//        {
//            Rab[pos].state = false;
//            ans += Arr[i].P;
//            tag++;
//            if (tag == N)
//            {
//                break;
//            }
//        }
//    }
//    
//    if (tag < N)
//    {
//        cout << "No Solution\n";
//        return 0;
//    }
//    
//    cout << ans << '\n';
//    
//    return 0;
//}

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 5e4 + 5;

pair<int, int> p[N];    //  箭

int b[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (m < n)
    {
        printf("No Solution\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&b[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(b, b + n);
    sort(p, p + m);
    priority_queue<int> q;
    
    int i = 0, j = 0;
    long long ans = 0;
    while (j < m)
    {
        ans += p[j].second;
        q.push(p[j].second);
        if (p[j].first >= b[i] && i < n)    //  能够杀死
        {
            ++i;
            ++j;
        }
        else                                //  替换掉花费最高的箭
        {
            ans -= q.top();
            q.pop();
            ++j;
        }
    }
    if (i < n)
    {
        printf("No Solution\n");
    }
    else
    {
        printf("%lld\n",ans);
    }
    return 0;
}