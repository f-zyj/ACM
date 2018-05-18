//
//  main.c
//  f-NYOJ-12-喷水装置（二）
//
//  Created by ZYJ on 16/5/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//AC
#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    int m, n;
    int w, h;
    float from[10001], to[10001];
    scanf("%d", &m);
    
    while (m--)
    {
        scanf("%d %d %d", &n, &w, &h);
        int k = 1;
        float x, r, t = h * 1.0 / 2, sq;
        for (int i = 0; i < n; i++)
        {
            scanf("%f %f", &x, &r);
            sq = sqrt(r * r - t * t);
            if (r > t)
            {
                from[k] = x - sq;
                to[k++] = x + sq;
            }
        }
        
        //排序  首要关键词  from  次要关键词  to
        for (int i = 1; i < k - 1; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                if (from[i] > from[j] || (from[i] == from[j] && to[i] < to[j]))
                {
                    float temp = from[i];
                    from[i] = from[j];
                    from[j] = temp;
                    temp = to[i];
                    to[i] = to[j];
                    to[j] = temp;
                }
            }
        }
        
        //判断区间头部是否覆盖
        if (from[1] > 0)
        {
            printf("0\n");
            continue;
        }
        
        int ans = 1;
        float flagT = to[1], flag = to[1];
        from[k] = w;
        for (int i = 2; i < k; i++)
        {
            if (from[i] <= flagT && to[i] > flagT && to[i] > flag)  //查找相对较大的区间
            {
                flag = to[i];
            }
            if (from[i + 1] > flagT)
            {
                flagT = flag;
                ans++;
            }
        }

        if (flagT < w)  //判断区间尾部是否覆盖
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
