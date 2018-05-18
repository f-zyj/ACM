//
//  main.cpp
//  f-CF-Codeforces Round #392 (Div. 2)-A-Holiday Of Equality
//
//  Created by ZYJ on 2017/1/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 101;

int A[MAXN];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    
    int mx = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", A + i);
        mx = max(mx, A[i]);
        sum += A[i];
    }
    
    printf("%d\n", mx * n - sum);
    
    return 0;
}
