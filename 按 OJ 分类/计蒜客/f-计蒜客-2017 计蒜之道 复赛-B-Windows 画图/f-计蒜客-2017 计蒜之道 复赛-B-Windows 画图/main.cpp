//
//  main.cpp
//  f-计蒜客-2017 计蒜之道 复赛-B-Windows 画图
//
//  Created by ZYJ on 2017/6/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXM = 255;

int n, m, q;
int map[MAXM][MAXM];

struct node
{
    int x, y;
} A, B;

int main(int argc, const char * argv[])
{
    cin >> n >> m;
    
    for (int cnt = 1; cnt <= n; cnt++)
    {
        scanf("%d%d%d%d", &A.x, &A.y, &B.x, &B.y);
        if (A.x > B.x)
        {
            swap(A, B);
        }
        int tempX = B.x - A.x;
        int tempY = B.y - A.y;
        for (int i = A.x; i <= B.x; i++)
        {
            double y = A.y + (double)(i - A.x) * tempY / tempX;
            int y_ = (int)y;
            if (y == y_)
            {
                map[i][y_] = cnt;
            }
        }
    }
    
    cin >> q;
    while (q--)
    {
        scanf("%d%d", &A.x, &A.y);
        cout << map[A.x][A.y] << '\n';
    }
    
    return 0;
}
