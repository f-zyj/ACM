//
//  main.cpp
//  f-51Nod-1215-数组的宽度
//
//  Created by ZYJ on 2017/4/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 5e4 + 10;

struct num
{
    long long value;
    int maxLeft, maxRight;
    int minLeft, minRight;
    
    num() : maxLeft(1), maxRight(1), minLeft(1), minRight(1) {}
} A[MAXN];

int N;
int value, key;
long long res = 0;
stack<pair<int, int> > S;

void stackClear()
{
    while (!S.empty())
    {
        S.pop();
    }
}

void getMax()
{
    stackClear();
    
    S.push(make_pair(A[0].value, 0));
    for (int i = 1; i < N; i++)
    {
        while (!S.empty() && S.top().first <= A[i].value)
        {
            value = S.top().first;
            key = S.top().second;
            S.pop();
            
            A[i].maxLeft += A[key].maxLeft;
            if (!S.empty())
            {
                A[S.top().second].maxRight += A[key].maxRight;
            }
        }
        S.push(make_pair(A[i].value, i));
    }
    while (!S.empty())
    {
        key = S.top().second;
        S.pop();
        if (!S.empty())
        {
            A[S.top().second].maxRight += A[key].maxRight;
        }
    }
}

void getMin()
{
    stackClear();
    
    S.push(make_pair(A[0].value, 0));
    for (int i = 1; i < N; i++)
    {
        while (!S.empty() && S.top().first >= A[i].value)
        {
            value = S.top().first;
            key = S.top().second;
            S.pop();
            
            A[i].minLeft += A[key].minLeft;
            if (!S.empty())
            {
                A[S.top().second].minRight += A[key].minRight;
            }
        }
        S.push(make_pair(A[i].value, i));
    }
    while (!S.empty())
    {
        key = S.top().second;
        S.pop();
        if (!S.empty())
        {
            A[S.top().second].minRight += A[key].minRight;
        }
    }
}

void solve()
{
    for (int i = 0; i < N; i++)
    {
        res += A[i].value * A[i].maxRight * A[i].maxLeft;
        res -= A[i].value * A[i].minRight * A[i].minLeft;
    }
}

int main(int argc, const char * argv[])
{
    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i].value);
    }
    
    getMax();
    getMin();
    
    solve();
    
    cout << res << '\n';
    
    return 0;
}
