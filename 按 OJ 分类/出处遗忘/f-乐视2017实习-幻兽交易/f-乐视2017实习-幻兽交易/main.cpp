//
//  main.cpp
//  f-乐视2017实习-幻兽交易
//
//  Created by ZYJ on 2018/3/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int a, b;

int main(int argc, const char * argv[])
{
    while (cin >> a >> b)
    {
        int cnt = 0;
        int sta = ceil(a / 0.95);
        int end = floor(a / 0.90);
        
        while (sta % 5 != 0 && sta <= end)
        {
            sta++;
        }
        for (int i = sta; i <= end && i <= b; i += 5)
        {
            cnt++;
        }
        
        cout << cnt << endl;
    }
    
    return 0;
}
