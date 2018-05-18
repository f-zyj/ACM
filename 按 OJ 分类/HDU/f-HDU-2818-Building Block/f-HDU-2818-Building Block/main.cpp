//
//  main.cpp
//  f-HDU-2818-Building Block
//
//  Created by ZYJ on 2016/11/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

const int MAXN = 3e4 + 10;

int total;
int pre[MAXN];
int sum[MAXN];
int low[MAXN];  //  存储结果

int find(int x)
{
    if (x != pre[x])
    {
        int temp = find(pre[x]);    //  必须先find
        low[x] += low[pre[x]];
        pre[x] = temp;
    }
    return pre[x];
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    
    if (fx != fy)
    {
        low[fx] = sum[fy];
        pre[fx] = fy;
        sum[fy] += sum[fx];
    }
}

int main()
{
    int P;
    int A, B;
    char order[2];
        
    scanf("%d", &P);
    for (int i = 0; i <= MAXN; i++)
    {
        pre[i] = i;
        sum[i] = 1;
        low[i] = 0;
    }
    
    while (P--)
    {
        scanf("%s", order);
        if (order[0] == 'M')
        {
            scanf("%d%d", &A, &B);
            join(A, B);
        }
        else
        {
            scanf("%d", &A);
            find(A);    //  这一句看似没用，但是必不可少
            printf("%d\n", low[A]);
        }
    }

    return 0;
}
