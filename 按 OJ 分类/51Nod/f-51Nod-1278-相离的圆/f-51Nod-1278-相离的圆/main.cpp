//
//  main.cpp
//  f-51Nod-1278-相离的圆
//
//  Created by ZYJ on 16/8/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5e4 + 10;

struct line
{
    int left;
    int right;
} Line[MAXN];

bool cmp(line a, line b)
{
    return a.left < b.left;
}


//  查找大于v的第一个数的下标
int bs(line a[], int l, int h, int v)
{
    int m;
    while (l < h)
    {
        m = (l + h) >> 1;
        if (a[m].left <= v)
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
    int N;
    cin >> N;
    
    int P, R;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &P, &R);
        Line[i].left = P - R;
        Line[i].right = P + R;
    }
    sort(Line, Line + N, cmp);
    
    int res = 0;
    int tag;
    for (int i = 0; i < N - 1; i++)
    {
        tag = bs(Line, i, N, Line[i].right);
        res += N - tag;
    }
    
    cout << res << '\n';
    return 0;
}
