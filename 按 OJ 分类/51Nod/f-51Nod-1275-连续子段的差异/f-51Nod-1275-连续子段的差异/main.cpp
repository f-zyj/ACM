//
//  main.cpp
//  f-51Nod-1275-连续子段的差异
//
//  Created by ZYJ on 2017/4/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXN = 50005;

int N, K;
int A[MAXN];
ll ans = 0;
deque<int> dqMin, dqMax;

void solve()
{
    for (int i = 0, j = 0; i < N; i++)
    {
        while (j < N)
        {
            //  维护单调递增双向队列
            while (!dqMin.empty() && A[dqMin.back()] >= A[j])
            {
                dqMin.pop_back();
            }
            dqMin.push_back(j);
            
            //  维护单调递减双向队列
            while (!dqMax.empty() && A[dqMax.back()] <= A[j])
            {
                dqMax.pop_back();
            }
            dqMax.push_back(j);
            
            //  dqMax 单调递减，dqMin 单调递增，所以只需要拿头比即可
            if (A[dqMax.front()] - A[dqMin.front()] <= K)
            {
                j++;
            }
            else
            {
                break;
            }
        }
        
        ans += (j - i);
        if (dqMin.front() == i)
        {
            dqMin.pop_front();
        }
        if (dqMax.front() == i)
        {
            dqMax.pop_front();
        }
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", A + i);
    }
    
    solve();
    
    printf("%lld", ans);

    return 0;
}
