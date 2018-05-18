//
//  main.cpp
//  f-51Nod-1288-汽油补给
//
//  Created by ZYJ on 2017/6/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int N, T;
ll D[MAXN], P[MAXN];

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        cin >> D[i + 1] >> P[i];
        D[i + 1] += D[i];
    }
    P[N] = INF;
    
    ll cost = 0, state = 0;
    int max_len = T, pos = 0;
    for (int i = 1; i <= N; i++)
    {
        if (P[i] < P[pos] && (D[i] - D[pos]) <= max_len)
        {
            cost += ((D[i] - D[pos]) - state) * P[pos];
            pos = i;
            state = 0;
        }
        else if (P[i] >= P[pos] && (D[i] - D[pos]) <= max_len)
        {
            int tag = -1;
            double p = P[pos];
            for (int j = pos + 1; j <= N && (D[j] - D[pos]) <= max_len; j++)
            {
                if (P[j] < p)
                {
                    tag = j;
                    break;
                }
            }
            if (tag == -1 && (D[N] - D[pos]) <= max_len)
            {
                cost += ((D[N] - D[pos]) - state) * P[pos];
                pos = N;
                i = N;
                state = 0;
            }
            if (tag != -1)
            {
                cost += ((D[tag] - D[pos]) - state) * P[pos];
                pos = tag;
                i = tag;
                state = 0;
            }
            else
            {
                int tag = -1;
                double p = INF + 10;
                for (int j = pos + 1; j <= N && (D[j] - D[pos]) <= max_len; j++)
                {
                    if (P[j] < p)
                    {
                        tag = j;
                        p = P[j];
                    }
                }
                if (tag != -1)
                {
                    cost += (T - state) * P[pos];
                    state = T - (D[tag] - D[pos]);
                    pos = tag;
                    i = tag;
                }
            }
        }
    }
    
    if (pos == N)
    {
        cout << cost << '\n';
    }
    else
    {
        cout << "-1\n";
    }
    
    return 0;
}
