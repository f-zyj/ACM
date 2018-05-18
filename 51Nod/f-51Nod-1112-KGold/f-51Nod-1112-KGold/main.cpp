//
//  main.cpp
//  f-51Nod-1112-KGold
//
//  Created by ZYJ on 16/8/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 1e4;
//const int MAXM = MAXN + 10;
//
//struct man
//{
//    int M;
//    int S;
//} People[MAXM];
//
//class surpass
//{
//public:
//    int A;
//    int B;
//    double time;
//    surpass(int a, int b, double c) : A(a), B(b), time(c) {}
//};
//
//struct ans
//{
//    int A;
//    int B;
//} Ans[MAXN];
//
//bool operator < (const surpass a, const surpass b)
//{
//    if (a.time == b.time)
//    {
//        if (a.A == b.A)
//        {
//            return a.B < b.B;
//        }
//        return a.A < b.A;
//    }
//    return a.time < b.time;
//}
//
//priority_queue<surpass> q;
//
//int main(int argc, const char * argv[])
//{
//    int N;
//    cin >> N;
//    
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d %d", &People[i].M, &People[i].S);
//        for (int j = 1; j <= i; j++)
//        {
//            if (People[i].S < People[j].S && People[i].M > People[j].M)
//            {
//                double time = (People[i].M - People[j].M) * 1.0 / (People[j].S - People[i].S);
//                q.push(surpass(j, i, time));
//            }
//            else if (People[i].S > People[j].S && People[i].M < People[j].M)
//            {
//                double time = (People[j].M - People[i].M) * 1.0 / (People[i].S - People[j].S);
//                q.push(surpass(i, j, time));
//            }
//            if (q.size() > MAXN)
//            {
//                q.pop();
//            }
//        }
//    }
//    
//    int key = 0;
//    while (!q.empty())
//    {
//        Ans[key].A = q.top().A;
//        Ans[key++].B = q.top().B;
//        q.pop();
//    }
//    
//    for (int i = key - 1; i >= 0; i--)
//    {
//        cout << Ans[i].A << ' ' << Ans[i].B << '\n';
//    }
//    
//    if (key == 0)
//    {
//        cout << "No Solution\n";
//    }
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define FOR(i, f, e) for (int i = (f); i < (e); i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAXN = 1e4;
const int MAXM = MAXN + 5;

//  判断直线相交
pair<double, double> intersection(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
    ll a0 = y1 - y2, b0 = x2 - x1, c0 = x1 * y2 - x2 * y1;
    ll a1 = y3 - y4, b1 = x4 - x3, c1 = x3 * y4 - x4 * y3;
    ll div = a0 * b1 - a1 * b0;
    //    if (div == 0)   //  不会相交
    //    {
    //        return make_pair(-1, -1);
    //    }
    double x = (b0 * c1 - b1 * c0) / (double)div;
    double y = (a1 * c0 - a0 * c1) / (double)div;
    return make_pair(x, y);
}

int n;

struct node
{
    int M, S, t;
    int id;         //  按照M排序后序列号
    int ordinal;    //  原始序列号
    
    inline bool operator < (const node &nd)
    {
        return t < nd.t;
    }
} input[MAXM];

struct RESULT
{
    int beyond, win;
    double time;
} ans[MAXM * 2];

bool cmp_1(const node &nd1, const node &nd2)
{
    return nd1.M < nd2.M;
}

bool cmp_2(const RESULT &p1, const RESULT &p2)
{
    if (p1.time == p2.time)
    {
        if (p1.win == p2.win)
        {
            return p1.beyond < p2.beyond;
        }
        return p1.win < p2.win;
    }
    return p1.time < p2.time;
}

int g_times(int time)
{
    FOR(i, 0, n)
    {
        input[i].t = input[i].M + input[i].S * time;
    }
    sort(input, input + n);
    int res = 0;
    FOR(i, 0, n)
    {
        if (input[i].id < i)
        {
            res += i - input[i].id;
        }
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    FOR(i, 0, n)
    {
        scanf("%d%d", &input[i].M, &input[i].S);
        input[i].ordinal = i;
    }
    sort(input, input + n, cmp_1);  //  根据现有资产排序
    FOR(i, 0, n)
    {
        input[i].id = i;
    }
    int l = 0, r = MAXM * 10, time = MAXM * 10; //  初始化一个比较大的r
    //  二分查找 查找出前MAXN次所需要的时间
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        int tmp = g_times(mid);
        time = mid;
        if (tmp == MAXN)
        {
            break;
        }
        else if (tmp < MAXN)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    
    int pos = 0;
    FOR(i, 0, n)    //  现在的排序状态是按照time时间的状态从小到大排
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (input[j].M > input[i].M)
            {
                pair<double, double> tmp = intersection(input[j].M, 0, input[j].t, time, input[i].M, 0, input[i].t, time);
                ans[pos].beyond = input[j].ordinal;
                ans[pos].win = input[i].ordinal;
                ans[pos++].time = tmp.second;
            }
        }
    }
    sort(ans, ans + pos, cmp_2);
    if (!pos)
    {
        printf("No Solution\n");
    }
    else
    {
        int maxnum = min(pos, MAXN);
        FOR(i, 0, maxnum)
        {
            printf("%d %d\n", ans[i].win + 1, ans[i].beyond + 1);
        }
    }
    
    return 0;
}