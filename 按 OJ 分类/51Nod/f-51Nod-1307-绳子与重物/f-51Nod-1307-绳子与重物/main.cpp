//
//  main.cpp
//  f-51Nod-1307-绳子与重物
//
//  Created by ZYJ on 16/9/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 5e4 + 10;

struct line
{
    int C;
    int W;
    int last;
} Line[MAXN];

int power[MAXN];

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    int ans = -1;
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &Line[i].C, &Line[i].W, &Line[i].last);
        power[i] = Line[i].C;
        int key = i;
        while (key != -1)
        {
            power[key] -= Line[i].W;
            if (ans == -1 && power[key] < 0)
            {
                ans = i;
            }
            key = Line[key].last;
        }
    }
   
    if (ans == -1)
    {
        cout << N << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
    
    return 0;
}
