//
//  main.cpp
//  f-CF-Codeforces Round #377 (Div. 2)-B-Cormen — The Best Friend Of a Man
//
//  Created by ZYJ on 2016/10/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 505;

int walk[MAXN];

struct value
{
    int val;
    int pos;
} val[MAXN];


int main(int argc, const char * argv[])
{
    int N, K;
    cin >> N >> K;
    
    for (int i = 0; i < N; i++)
    {
        cin >> walk[i];
    }
    
    int key = 0;
    for (int i = 1; i < N; i++)
    {
        if (walk[i - 1] + walk[i] < K)
        {
            key += K - walk[i - 1] - walk[i];
            walk[i] = K - walk[i - 1];
        }
    }
    
    cout << key << '\n';
    for (int i = 0; i < N - 1; i++)
    {
        cout << walk[i] << ' ';
    }
    cout << walk[N - 1] << '\n';
    
    return 0;
}
