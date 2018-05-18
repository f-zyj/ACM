//
//  main.cpp
//  ICPC Asia Regional Qingdao Online-1010-Brute Force Sorting
//
//  Created by ZYJ on 2017/9/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <set>

#define PB push_back

using namespace std;

const int MAXN = 1e6 + 7;

int n, now, pre;
int A[MAXN];
int pe[MAXN];
int nt[MAXN];
int bz[MAXN];
set<int> si;
vector<int> vi;

int main(void)
{
    int T;
    cin >> T;
    
    while (T--)
    {
        memset(bz, 0, sizeof(bz));
        
        scanf("%d", &n);
        
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", A + i);
            bz[i] = 0;
            pe[i] = i - 1;
            nt[i] = i + 1;
            si.insert(i);
        }
        nt[0] = 1, pe[n + 1] = n, pe[1] = 0, nt[n] = n + 1;
        A[0] = 0, A[n + 1] = MAXN;
        
        while (si.size())
        {
            vi.clear();
            for (auto &x : si)
            {
                int ntx = nt[x], pex = pe[x];
                if (A[pex] > A[x])
                {
                    vi.PB(pex);
                    vi.PB(x);
                }
                if (A[x] > A[ntx])
                {
                    vi.PB(x);
                    vi.PB(ntx);
                }
            }
            
            si.clear();
            for (auto &x : vi)
            {
                if (!bz[x])
                {
                    int ntx = nt[x], pex = pe[x];
                    nt[pex] = ntx, pe[ntx] = pex;
                    si.insert(pex);
                    bz[x] = 1;
                }
            }
        }
        
        int cnt = 0;
        for (int i = nt[0]; i != n + 1; i = nt[i])
        {
            cnt++;
        }
        printf("%d\n", cnt);
        
        for (int i = nt[0]; i != n + 1; i = nt[i])
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    
    return 0;
}
