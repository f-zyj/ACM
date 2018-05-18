//
//  main.cpp
//  f-51Nod-1424-零树
//
//  Created by ZYJ on 2017/6/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n;
int val[MAXN];
ll add[MAXN];
ll sub[MAXN];
vector<int> vi[MAXN];

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0; //EOF
    }
    while (c != '-' && (c < '0' || c > '9'))
    {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

void dfs(int root, int pre)
{
    for (int i = 0; i < vi[root].size(); i++)
    {
        int tmp = vi[root][i];
        if (tmp != pre)
        {
            dfs(tmp, root);
            add[root] = max(add[root], add[tmp]);
            sub[root] = max(sub[root], sub[tmp]);
        }
    }
    
    val[root] += add[root] - sub[root];
    val[root] < 0 ? add[root] -= val[root] : sub[root] += val[root];
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    scan_d(n);
    
    int a, b;
    for (int i = 1; i < n; i++)
    {
        scan_d(a), scan_d(b);
        vi[a].push_back(b);
        vi[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        scan_d(val[i]);
    }
    
    dfs(1, 0);
    
    cout << add[1] + sub[1] << '\n';
    
    return 0;
}
