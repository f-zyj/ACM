//
//  main.cpp
//  f-51Nod-1093-骆驼和香蕉
//
//  Created by ZYJ on 16/8/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    double N, K;
    
    while (cin >> N >> K)
    {
        double ans = 0;
        double flag = 1;
        int tag = 0;
        while (N - K / flag >= 0)
        {
            N -= K / flag;
            flag += 2;
            tag++;
        }
        ans += tag * K;
        if (N > 0)
        {
            ans += N * flag;
        }
        int res = ans == (int)ans ? (int)ans : (int)(ans + 1);
        cout << res << '\n';
    }
    
    return 0;
}
