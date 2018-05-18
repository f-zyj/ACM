//
//  main.cpp
//  f-NYOJ-201-作业题
//
//  Created by ZYJ on 16/7/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node
{
public:
    int x, y;
} Node;

Node a[1001];

bool cmp(Node a, Node b)
{
    return a.x < b.x;
}

int main(int argc, const char * argv[])
{
    int T;
    int N;
    while (cin >> T)
    {
        while (T--)
        {
            int sum[1001];
            int res_1, res_2;
            cin >> N;
            for (int i = 0; i < N; i++)
            {
                cin >> a[i].x >> a[i].y;
                sum[i] = 1;
            }
            sort(a, a + N, cmp);
            for (int i = N - 1; i >= 0; i--)    //  单调递增
            {
                for (int j = i + 1; j < N; j++)
                {
                    if (a[i].y < a[j].y && sum[i] <= sum[j])
                    {
                        sum[i] = sum[j] + 1;
                    }
                }
            }
            res_1 = sum[0];
            for (int i = 0; i < N; i++)
            {
                if (res_1 < sum[i])
                {
                    res_1 = sum[i];
                }
            }
            for (int i = 0; i < N; i++)
            {
                sum[i] = 1;
            }
            for (int i = N - 1; i >= 0; i--)    //  单调递减
            {
                for (int j = i + 1; j < N; j++)
                {
                    if (a[i].y > a[j].y && sum[i] <= sum[j])
                    {
                        sum[i] = sum[j] + 1;
                    }
                }
            }
            res_2 = sum[0];
            for (int i = 0; i < N; i++)
            {
                if (res_2 < sum[i])
                {
                    res_2 = sum[i];
                }
            }
            int ans = res_1 > res_2 ? res_1 : res_2;
            cout << ans << endl;
        }
    }
    return 0;
}
