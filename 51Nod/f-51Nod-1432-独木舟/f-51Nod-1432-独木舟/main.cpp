//
//  main.cpp
//  f-51Nod-1432-独木舟
//
//  Created by ZYJ on 16/8/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

typedef long long ll;

using namespace std;

const int MAXN = 1e4 + 10;

ll M[MAXN];

int main(int argc, const char * argv[])
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", M + i);
    }
    
    sort(M, M + n);
    
    int res = 0;
    int flag = 0;
    for (int i = n - 1; i >= flag; i--)
    {
        if (M[i] + M[flag] <= m)
        {
            flag++;
        }
        res++;
    }
    
    std::cout << res << '\n';
    return 0;
}
