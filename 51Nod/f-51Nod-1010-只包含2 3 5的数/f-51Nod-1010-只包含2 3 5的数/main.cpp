//
//  main.cpp
//  f-51Nod-1010-只包含2 3 5的数
//
//  Created by ZYJ on 16/7/31.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef unsigned long long ull;

const int MAXN = 1e4 + 1e3;

/*
 * Ugly Numbers
 * Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
 * 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
 */
typedef pair<ull, int> node_type;

ull result[MAXN];

void init()
{
    priority_queue<node_type, vector<node_type>, greater<node_type>> Q;
    Q.push(make_pair(1, 2));
    for (int i = 0; i < MAXN; i++)
    {
        node_type node = Q.top();
        Q.pop();
        switch (node.second)
        {
            case 2:
                Q.push(make_pair(node.first * 2, 2));
            case 3:
                Q.push(make_pair(node.first * 3, 3));
            case 5:
                Q.push(make_pair(node.first * 5, 5));
        }
        result[i] = node.first;
    }
    
    return ;
}

/*
 *  传入参数必须l <= h
 *  假设a数组已经按从小到大排序
 *  返回值l总是合理的
 */
int bs(ull a[], int l, int h, ull v)
{
    int m;
    while (l < h)
    {
        m = (l + h) >> 1;
        if (a[m] < v)
        {
            l = m + 1;
        }
        else
        {
            h = m;
        }
    }
    return l;
}

int main(int argc, const char * argv[])
{
    freopen("input.txt", "r", stdin);
//    freopen("input.txt", "w", stdin);
    
    init();
    
    int T;
    cin >> T;
    
    ull n;
    while (T--)
    {
        cin >> n;
        
        int key = bs(result, 1, MAXN - 1, n);
        
        cout << result[key] << '\n';
    }
    return 0;
}
