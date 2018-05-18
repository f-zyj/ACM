//
//  main.cpp
//  f-HDU-3635-Dragon Balls
//
//  Created by ZYJ on 2016/11/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

const int MAXN = 1e4 + 10;

int pre[MAXN];
int sum[MAXN];
int mov[MAXN];
int total;

int find(int x)
{
    if (x != pre[x])
    {
        int temp = pre[x];
        pre[x] = find(pre[x]);
        mov[x] += mov[temp];    //  父亲移动的次数会叠加到儿子身上
    }
    return pre[x];
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    
    if (fx != fy)
    {
        pre[fx] = fy;
        sum[fy] += sum[fx];
        mov[fx]++;      //  根节点移动次数++
        sum[fx] = 0;    //  移走后剩余0
    }
}

int main()
{
    int T;
    cin >> T;
    int key = 1;
    int N, Q;
    int A, B;
    char order[2];
    
    while (T--)
    {
        printf("Case %d:\n", key++);
        
        scanf("%d%d", &N, &Q);
        for (int i = 0; i <= N; i++)
        {
            pre[i] = i;
            sum[i] = 1;
            mov[i] = 0;
        }
        
        while (Q--)
        {
            scanf("%s", order);
            if (order[0] == 'T')
            {
                scanf("%d%d", &A, &B);
                join(A, B);
            }
            else
            {
                scanf("%d", &A);
                int res = find(A);
                printf("%d %d %d\n", res, sum[res], mov[A]);
            }
        }
    }
    
    return 0;
}
