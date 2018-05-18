//
//  main.cpp
//  f-51Nod-1163-最高的奖励
//
//  Created by ZYJ on 16/8/8.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <cstdio>
//
//typedef long long ll;
//
//using namespace std;
//
//const int MAXN = 5e4 + 10;
//
//struct task
//{
//    int times;
//    int cost;
//} t[MAXN];
//
//bool cmp(const task a,const task b)
//{
//    return a.times < b.times;
//}
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d%d", &t[i].times, &t[i].cost);
//    }
//    sort(t, t + n, cmp);
//    //  优先队列维护
//    priority_queue<int, vector<int>, greater<int> > pq;
//    long long  ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int k = t[i].cost;
//        if (t[i].times > pq.size())     //  pq.size这里理解代表时间点
//        {
//            ans += k;
//            pq.push(k);
//        }
//        else                            //  时间点有冲突，把cost最小删除
//        {
//            ans += k;
//            pq.push(k);
//            int minn = pq.top();
//            ans -= minn;
//            pq.pop();                   //  删除
//        }
//    }
//    printf("%lld\n", ans);
//    
//    return 0;
//}


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 5e4 + 5;

struct task
{
    int times;
    int cost;
} Task[MAXN];

//  使用并查集
int F[MAXN];    //  F[i] = j:最晚结束时间i可以在j时间完成

bool cmp(const task a, const task b)
{
    return a.cost > b.cost;
}

int find(int x)
{
    if (x <= 0)
    {
        return -1;
    }
    if (F[x] == x)
    {
        return F[x] = x - 1;
    }
    else
    {
        return F[x] = find(F[x]);   //  路径压缩
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &Task[i].times, &Task[i].cost);
        F[i] = i;
    }
    sort(Task, Task + n, cmp);
    
    long long  ans = 0;
    for (int i = 0; i < n; i++)
    {
        int k = Task[i].times;
        if (find(k) >= 0)
        {
            ans += Task[i].cost;
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}