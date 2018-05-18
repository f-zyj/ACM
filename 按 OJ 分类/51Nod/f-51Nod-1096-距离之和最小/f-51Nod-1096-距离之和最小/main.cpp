//
//  main.cpp
//  f-51Nod-1096-距离之和最小
//
//  Created by ZYJ on 16/8/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e4 + 10;

int P[MAXN];

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    sort(P, P + N);
    
    long long sum = 0;
    int flag = N - 1;
    for (int i = 0; i < flag; i++, flag--)
    {
        sum += P[flag] - P[i];
    }
    
    std::cout << sum << '\n';
    return 0;
}
