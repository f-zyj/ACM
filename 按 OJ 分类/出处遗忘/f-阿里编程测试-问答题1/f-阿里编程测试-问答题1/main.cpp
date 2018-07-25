//
//  main.cpp
//  f-阿里编程测试-问答题1
//
//  Created by ZYJ on 2018/7/25.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e7 + 7;

int a[MAXN];
int maxVal[MAXN];
int minVal[MAXN];

int main()
{
    int t, cnt = 0;;
    while (~scanf("%d", &t))
    {
        a[cnt++] = t;
        getchar();
    }
    
    int min_ = INF, max_ = -1;
    for (int i = 0; i < cnt; ++i)
    {
        min_ = min(min_, a[i]);
        max_ = max(max_, a[i]);
        maxVal[i] = -1;
        minVal[i] = INF;
    }
    
    t = (max_ - min_) / (cnt - 1);
    if ((max_ - min_) % (cnt - 1) != 0)
    {
        ++t;
    }
    for (int i = 0; i < cnt; ++i)
    {
        int id = (a[i] - min_) / t;
        minVal[id] = min(minVal[id], a[i]);
        maxVal[id] = max(maxVal[id], a[i]);
    }
    
    int ans = (max_ - min_) / (cnt - 1);
    max_ = -1;
    min_ = -1;
    for (int i = 0; i < cnt; ++i)
    {
        if (maxVal[i] == -1)
        {
            continue;
        }
        
        min_ = minVal[i];
        if (max_ != -1)
        {
            ans = max(ans, min_ - max_);
        }
        max_ = maxVal[i];
    }
    
    printf("%d\n",ans);
    
    return 0;
}
