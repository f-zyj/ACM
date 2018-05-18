//
//  main.cpp
//  f-51Nod-1874-字符串排序
//
//  Created by ZYJ on 2017/12/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

/*
 *  也可以用树状数组做
 *  a[0...n - 1] cnt = 0; call: MergeSort(0, n)
 */
const int MAXN = 55;
const int MAXM = 111;

int n, m, cnt;
pair<int, int> pii[MAXM];
char s[MAXM][MAXN];
char c[MAXM], t[MAXM];

void MergeSort(char *a, int l, int r)
{
    int mid, i, j, tmp;
    if (r > l + 1)
    {
        mid = (l + r) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid, r);
        tmp = l;
        for (i = l, j = mid; i < mid && j < r;)
        {
            if (a[i] > a[j])
            {
                c[tmp++] = a[j++];
                cnt += mid - i;
            }
            else
            {
                c[tmp++] = a[i++];
            }
        }
        if (j < r)
        {
            for (; j < r; ++j)
            {
                c[tmp++] = a[j];
            }
        }
        else
        {
            for (; i < mid; ++i)
            {
                c[tmp++] = a[i];
            }
        }
        for (i = l; i < r; ++i)
        {
            a[i] = c[i];
        }
    }
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    freopen("/Users/zyj/Desktop/output.txt", "w", stdout);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%s", s[i]);
        
        memcpy(t, s[i], sizeof(s[i]));
        
        cnt = 0;
        MergeSort(t, 0, n);
        pii[i].first = i;
        pii[i].second = cnt;
    }
    
    sort(pii, pii + m,
         [&](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second == b.second ? a.first < b.first : a.second < b.second; });
    
    for (int i = 0; i < m; i++)
    {
        printf("%s\n", s[pii[i].first]);
    }
    
    return 0;
}
