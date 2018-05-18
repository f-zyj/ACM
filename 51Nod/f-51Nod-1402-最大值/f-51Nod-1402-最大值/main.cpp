//
//  main.cpp
//  f-51Nod-1402-最大值
//
//  Created by ZYJ on 16/8/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXM = 55;

int X[MAXM];
int T[MAXM];

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int P;
    cin >> P;
    
    int N, M;
    int x, t;
    while (P--)
    {
        cin >> N >> M;
        int key = 0;
        for (int i = 0; i < M; i++)
        {
            cin >> x >> t;
            if (t < x - 1)  //  会卡住数据上限的转存
            {
                X[key] = x;
                T[key++] = t;
            }
        }
        //  如理特殊卡点 ex: (3)*(0) (3)无法取3
        for (int i = 0; i < key; i++)
        {
            if (T[i] > T[i - 1] + X[i] - X[i - 1] && i != 0)
            {
                T[i] = T[i - 1] + X[i] - X[i - 1];
            }
            if (T[i] > T[i + 1] + X[i + 1] - X[i] && i != key - 1)
            {
                T[i] = T[i + 1] + X[ i + 1] - X[i];
                if (i >= 2)
                {
                    i -= 2;
                }
            }
        }
        
        if (!key)
        {
            cout << N - 1 << '\n';
            continue;
        }
        int ans = T[0] > (X[0] + T[0] - 1) / 2 ? T[0] : (X[0] + T[0] - 1) / 2;
        for (int i = 1; i < key - 1; i++)
        {
            if ((T[i] + T[i + 1] + X[i + 1] - X[i]) / 2 > ans)
            {
                ans = (T[i] + T[i + 1] + X[i + 1] - X[i]) / 2;
            }
        }
        ans = T[key - 1] + N - X[key - 1] > ans ? T[key - 1] + N - X[key - 1] : ans;
        cout << ans << '\n';
    }
    
    return 0;
}
