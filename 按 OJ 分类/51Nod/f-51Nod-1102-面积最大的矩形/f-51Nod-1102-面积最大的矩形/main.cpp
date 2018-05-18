//
//  main.cpp
//  f-51Nod-1102-面积最大的矩形
//
//  Created by ZYJ on 16/8/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stack>

typedef long long ll;

using namespace std;

const int MAXN = 5e4 + 10;

struct a
{
    ll value;
    int left;
    int right;
} A[MAXN];

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    //  单调递减栈
    stack<a> AA;
    int key = 0;
    a num;
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &num.value);
        num.left = num.right = i;
        if (AA.empty())
        {
            AA.push(num);
        }
        else
        {
            a pop = {0, 0, 0};
            while (!AA.empty() && AA.top().value > num.value)
            {
                AA.top().right = i - 1;
                A[key++] = pop = AA.top();
                AA.pop();
            }
            if (pop.value)
            {
                num.left = !AA.empty() && AA.top().value == num.value ? AA.top().left : pop.left;
            }
            else
            {
                num.left = !AA.empty() && AA.top().value == num.value ? AA.top().left : i;
            }
            AA.push(num);
        }
    }
    //  全部出栈
    while (!AA.empty())
    {
        AA.top().right = N;
        A[key++] = AA.top();
        AA.pop();
    }
    
    ll ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max((A[i].right - A[i].left + 1) * A[i].value, ans);
    }
    
    cout << ans << '\n';
    return 0;
}
