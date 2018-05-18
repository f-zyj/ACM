//
//  main.cpp
//  f-51Nod-1062-序列中的最大数
//
//  Created by ZYJ on 16/8/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

typedef long long ll;

using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN];
int b[MAXN];

void init()
{
    a[0] = 0;
    a[1] = 1;
    b[0] = 0;
    b[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        int j = i / 2;
        if (i % 2)
        {
            a[i] = a[j] + a[j + 1];
//            cout << i << ' ' << a[i] << '\n';
        }
        else
        {
            a[i] = a[j];
//            cout << i << ' ' << a[i] << '\n';
        }
        if (a[i] > b[i - 1])
        {
            b[i] = a[i];
        }
        else
        {
            b[i] = b[i - 1];
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    init();
    
    int T;
    cin >> T;
    
    int n;
    while (T--)
    {
        cin >> n;
        cout << b[n] << '\n';

    }

    return 0;
}
