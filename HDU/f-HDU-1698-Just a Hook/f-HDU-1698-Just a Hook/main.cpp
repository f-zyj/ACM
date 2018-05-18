//
//  main.cpp
//  f-HDU-1698-Just a Hook
//
//  Created by ZYJ on 2017/1/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 1e5;

struct node
{
    int left;
    int right;
    int data;
    int sum;
};

node hook[4 * MAXN];

void build(int root, int left, int right)
{
    hook[root].left = left;
    hook[root].right = right;
    
    if (left == right)
    {
        hook[root].data = 1;
        hook[root].sum = 1;
    }
    else
    {
        int mid = (left + right) >> 1;
        build(root * 2, left, mid);
        build(root * 2 + 1, mid + 1, right);
        hook[root].data = 0;
        hook[root].sum = (hook[root * 2].sum + hook[root * 2 + 1].sum);
    }
}

void updata(int root, int left, int right, int data)
{
    if (hook[root].left == left && hook[root].right == right)
    {
        if (hook[root].data != data)
        {
            hook[root].data = data;
            hook[root].sum = (right - left + 1) * data;
        }
    }
    else
    {
        if (hook[root].data > 0)
        {
            hook[root * 2].data = hook[root].data;      //  更新延时标记
            hook[root * 2].sum = (hook[root * 2].right - hook[root * 2].left + 1)
                                * hook[root * 2].data;
            hook[root * 2 + 1].data = hook[root].data;  //  更新延时标记
            hook[root * 2 + 1].sum = (hook[root * 2 + 1].right - hook[root * 2 + 1].left + 1)
                                * hook[root * 2 + 1].data;
        }
        hook[root].data = 0;    //  延时标记重置为0
        
        int mid = (hook[root].left + hook[root].right) >> 1;
        if (right <= mid)
        {
            updata(root * 2, left, right, data);
        }
        else if (left > mid)
        {
            updata(root * 2 + 1, left, right, data);
        }
        else
        {
            updata(root * 2, left, mid, data);
            updata(root * 2 + 1, mid + 1, right, data);
        }
        
        hook[root].sum = hook[root * 2].sum + hook[root * 2 + 1].sum;
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    
    int N, Q;
    int X, Y, Z;
    
    for (int i = 1; i <= T; i++)
    {
        scanf("%d", &N);
        build(1, 1, N);
        
        scanf("%d", &Q);
        while (Q--)
        {
            scanf("%d%d%d", &X, &Y, &Z);
            updata(1, X, Y, Z);
        }
        
        printf("Case %d: The total value of the hook is %d.\n", i, hook[1].sum);
    }
    
    return 0;
}
