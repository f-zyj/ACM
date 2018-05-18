//
//  main.cpp
//  f-51Nod-1605-棋盘问题
//
//  Created by ZYJ on 2016/9/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

//const int MAXN = 105;

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int T;
    cin >> T;
    
    int n, m;
    int sqare;
    while (T--)
    {
        cin >> n >> m;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> sqare;
                if (sqare == 1)
                {
                    res++;
                }
            }
        }
        
        if (res % 2)
        {
            cout << "yadang\n";
        }
        else
        {
            cout << "xiawa\n";
        }
    }
    
    return 0;
}
