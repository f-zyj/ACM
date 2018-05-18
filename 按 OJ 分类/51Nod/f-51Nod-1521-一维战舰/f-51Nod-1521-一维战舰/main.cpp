//
//  main.cpp
//  f-51Nod-1521-一维战舰
//
//  Created by ZYJ on 2016/10/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstring>
//#include <cstdio>
//#include <set>
//
//#define mem(a, b) memset(a, b, sizeof(a))
//
//using namespace std;
//
//const int MAXN = 2e5 + 10;
//
//set<int> s;
//set<int>::iterator it;
//set<int>::iterator it_;
//
//int vis[MAXN];
//
//int main(int argc, const char * argv[])
//{
//    int n, k, a;
//    cin >> n >> k >> a;
//    
//    int m;
//    cin >> m;
//    
//    int maxNum = (n + 1) / (a + 1); //  初始化最多可以放maxNum艘
//    s.insert(0);        //  下界
//    s.insert(n + 1);    //  上界
//    mem(vis, 0);
//    
//    int point;
//    for (int i = 0; i < m; i++)
//    {
//        scanf("%d", &point);
//        if (vis[point])
//        {
//            continue;
//        }
//        vis[point] = 1;
//        s.insert(point);
//        it = s.lower_bound(point);
//        it--;
//        it_ = s.upper_bound(point);
//        maxNum -= ((*it_) - (*it)) / (a + 1) - ((*it_) - point) / (a + 1) - (point - (*it)) / (a + 1);
//        if (maxNum < k)
//        {
//            printf("%d\n", i + 1);
//            return 0;
//        }
//    }
//    
//    printf("-1\n");
//    return 0;
//}

#include <stdio.h>

const int MAXN = 2e5 + 10;

int place[MAXN];

int main()
{
    int n, k, a;
    scanf("%d%d%d", &n, &k, &a);
    
    int m;
    scanf("%d", &m);
    
    int flag = -1;
    int left, right;
    int maxNum = (n + 1) / (a + 1);
    
    int x;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        place[x] = 1;
        for (left = x - 1; left >= 1 && place[left] == 0; left--) ;
        for (right = x + 1; right <= n && place[right] == 0; right++) ;
        maxNum -= (right - left) / (a + 1) - (right - x) / (a + 1) - (x - left) / (a + 1);

        if (maxNum < k && flag == -1)
        {
            flag = i + 1;
            break;
        }
    }
    
    printf("%d\n", flag);
    return 0;
}
