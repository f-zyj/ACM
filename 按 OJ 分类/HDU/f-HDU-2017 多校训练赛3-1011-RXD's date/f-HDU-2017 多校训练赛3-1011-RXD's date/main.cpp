//
//  main.cpp
//  f-HDU-2017 多校训练赛3-1011-RXD's date
//
//  Created by ZYJ on 2017/8/1.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int LIMIT = 35;

int t, c;

int main(int argc, const char * argv[])
{
    cin >> t;
    int cnt = 0;
    while (t--)
    {
        cin >> c;
        if (c <= LIMIT)
        {
            cnt++;
        }
    }
    
    cout << cnt << '\n';
    
    return 0;
}
