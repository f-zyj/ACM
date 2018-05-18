//
//  main.cpp
//  f-HDU-5935-Car
//
//  Created by ZYJ on 2017/10/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int N;
ll a[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int case_ = 1; case_ <= T; case_++)
    {
        scanf("%d", &N);
        
        a[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%lld", a + i);
        }
        
        ll ans = 1, p = a[N] - a[N - 1], q = 1;
        ll dis, tmp;
        for (int i = N - 1; i >= 1; i--)
        {
            dis = a[i] - a[i - 1];
            q *= dis;
            swap(p, q);
            
            tmp = ceil(1.0 * p / q);
            ans += tmp;
            
            p = dis;
            q = tmp;
        }
        
        printf("Case #%d: %lld\n", case_, ans);
    }
    
    return 0;
}
