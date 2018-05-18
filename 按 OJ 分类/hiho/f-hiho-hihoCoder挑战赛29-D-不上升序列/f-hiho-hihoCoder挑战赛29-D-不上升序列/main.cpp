//
//  main.cpp
//  f-hiho-hihoCoder挑战赛29-D-不上升序列
//
//  Created by ZYJ on 2017/6/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <cstdio>
//#include <set>
//
//using namespace std;
//
//const int MAXN = 5e5 + 10;
//
//int a[MAXN];
//multiset<int> mul;
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//    
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (mul.empty() || *mul.begin() >= a[i])
//        {
//            mul.insert(a[i]);
//        }
//        else
//        {
//            ans += a[i] - *mul.begin();
//            mul.erase(mul.begin());
//            mul.insert(a[i]);
//            mul.insert(a[i]);
//        }
//    }
//    
//    printf("%lld\n",ans);
//
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, c;
long long k;
priority_queue<int, vector<int>, greater<int> > a;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        a.push(c);
        if (a.top() < c)
        {
            k += c - a.top();
            a.pop();
            a.push(c);
        }
    }
    cout << k << '\n';
    
    return 0;
}
