//
//  main.cpp
//  f-蓝桥-ALGO-15-旅行家的预算
//
//  Created by ZYJ on 2017/6/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 100;
const int INF = 0x3f3f3f3f;

int N;
double DD1, C, DD2, PP;
double D[MAXN], P[MAXN];

int main(int argc, const char * argv[])
{
    cin >> DD1 >> C >> DD2 >> PP >> N;
    D[0] = 0;
    P[0] = PP;
    for (int i = 1; i <= N; i++)
    {
        cin >> D[i] >> P[i];
    }
    N++;
    D[N] = DD1;
    P[N] = INF;

    double cost = 0, state = 0;
    int max_len = C * DD2, pos = 0;
    for (int i = 1; i <= N; i++)
    {
        if (P[i] < P[pos] && (D[i] - D[pos]) <= max_len)
        {
            cost += ((D[i] - D[pos]) / DD2 - state) * P[pos];
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
                cost += ((D[N] - D[pos]) / DD2 - state) * P[pos];
                pos = N;
                i = N;
                state = 0;
            }
            if (tag != -1)
            {
                cost += ((D[tag] - D[pos]) / DD2 - state) * P[pos];
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
                    cost += (C - state) * P[pos];
                    state = C - (D[tag] - D[pos]) / DD2;
                    pos = tag;
                    i = tag;
                }
            }
        }
    }
    
    if (pos == N)
    {
        printf("%.2f\n", cost);
    }
    else
    {
        cout << "No Solution\n";
    }
    
    return 0;
}
