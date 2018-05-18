//
//  main.cpp
//  f-51Nod-1065-最小正子段和
//
//  Created by ZYJ on 16/8/1.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n;
struct node
{
    long long sum;
    int pos;
} Node[50005];

bool cmp(node &a, node &b)
{
    return a.sum < b.sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
//    freopen("input.txt", "w", stdin);
    
    int i, flag;
    long long sum = 0, temp, res = 0;
    scanf("%d", &n);
    
    Node[0].pos = 0;
    Node[0].sum = 0;
    
    for (i = 1; i <= n; i++)
    {
        scanf("%lld", &temp);
        sum += temp;
        
        Node[i].pos = i;
        Node[i].sum = sum;
    }
    sort(Node, Node + n + 1, cmp);
    
    flag = 0;
    for (i = 1; i <= n; i++)
    {
        if (Node[i].pos - Node[i - 1].pos > 0 && Node[i].sum - Node[i - 1].sum > 0)
        {
            if (flag == 0)
            {
                flag = 1;
                res = Node[i].sum - Node[i-1].sum;
            }
            else
            {
                if (Node[i].sum - Node[i - 1].sum < res)
                {
                    res = Node[i].sum - Node[i - 1].sum;
                }
            }
        }
    }
    
    printf("%lld\n", res);
    
    return 0;
}