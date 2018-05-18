//
//  main.cpp
//  f-51Nod-1631-小鲨鱼在51Nod小学
//
//  Created by ZYJ on 16/8/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//
//struct task
//{
//    int y0, m0, d0;
//    int y1, m1, d1;
//    int number;
//} Task[MAXN];
//
//int res[MAXN];  //  存储任务序号 res[0] 存储任务个数
//
//template <class T>
//inline void scan_d(T &ret)
//{
//    char c;
//    ret = 0;
//    while ((c = getchar()) < '0' || c > '9');
//    while (c >= '0' && c <= '9')
//    {
//        ret = ret * 10 + (c - '0'), c = getchar();
//    }
//    return ;
//}
//
//bool cmp(task a, task b)
//{
//    return a.number < b.number;
//}
//
//int main(int argc, const char * argv[])
//{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    
//    int n;
//    scan_d(n);
//    
//    int key = 0;
//    int y0, y1, m0, m1, d0, d1;
//    int number;
//    for (int i = 0; i < n; i++)
//    {
//        scan_d(y0);
//        scan_d(m0);
//        scan_d(d0);
//        scan_d(y1);
//        scan_d(m1);
//        scan_d(d1);
//        scan_d(number);
//        if ((y0 == y1 && m0 == m1) || (y0 == y1 && m0 == m1 - 1 && d0 > d1) || (y0 == y1 - 1 && m0 == 12 && m1 == 1 && d0 > d1))
//        {
//            continue;
//        }
//        Task[key].y0 = y0;
//        Task[key].m0 = m0;
//        Task[key].d0 = d0;
//        Task[key].y1 = y1;
//        Task[key].m1 = m1;
//        Task[key].d1 = d1;
//        Task[key++].number = number;
//    }
//    sort(Task, Task + key, cmp);
//    
//    int q;
//    scan_d(q);
//    
//    int y, m, d;
//    for (int i = 0; i < q; i++)
//    {
//        res[0] = 0;
//        scan_d(y);
//        scan_d(m);
//        scan_d(d);
//        for (int i = 0; i < key; i++)
//        {
//            if (y >= Task[i].y0 && y <= Task[i].y1)
//            {
//                if ((y == Task[i].y0 && m < Task[i].m0) || (y == Task[i].y0 && m == Task[i].m0 && d < Task[i].d0) || (y == Task[i].y1 && m > Task[i].m1) || (y == Task[i].y1 && m == Task[i].m1 && d > Task[i].d1))
//                {
//                    continue;
//                }
//                res[0]++;
//                res[res[0]] = Task[i].number;
//            }
//        }
//        for (int i = 0; i < res[0]; i++)
//        {
//            printf("%d ", res[i]);
//        }
//        printf("%d\n", res[res[0]]);
//    }
//    
//    return 0;
//}

#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

typedef long long LL;

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

struct Node
{
    int id; //  任务id
    int x;  //  日期转换序号
};

Node a[MAXN];               //  指令
Node b[MAXN], c[MAXN];      //  起始和结束时间
vector<int> ans[MAXN];
set<int> now;

bool cmp(const Node &p1, const Node &p2)
{
    return p1.x < p2.x;
}

int main()
{
    int n, q;
    int year, month, day, v, m = 0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &year, &month, &day);
        v = year * 10000 + month * 100 + day;
        b[m].x = v;
        scanf("%d%d%d", &year, &month, &day);
        v = year * 10000 + month * 100 + day;
        c[m].x = v;
        scanf("%d", &v);
        b[m].id = c[m].id = v;
        if (c[m].x - b[m].x >= 100) //  够一个自然月++
        {
            m++;
        }
    }
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d", &year, &month, &day);
        v = year * 10000 + month * 100 + day;
        a[i].id = i;
        a[i].x = v;
    }
    sort(a, a + q, cmp);
    sort(b, b + m, cmp);
    sort(c, c + m, cmp);

    int p1 = 0, p2 = 0;
    b[m].x = c[m].x = INF;
    
    for (int i = 0; i < q; i++)
    {
        while (b[p1].x <= a[i].x)
        {
            now.insert(b[p1].id);
            p1++;
        }
        while (c[p2].x < a[i].x)
        {
            now.erase(c[p2].id);
            p2++;
        }
        for (auto it = now.begin(); it != now.end(); it++)  //  转存结果
        {
            ans[a[i].id].push_back(*it);
        }
    }
    
    for (int i = 0; i < q; i++)
    {
        printf("%lu", ans[i].size());
        for (int j = 0; j < ans[i].size(); j++)
        {
            printf(" %d", ans[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
