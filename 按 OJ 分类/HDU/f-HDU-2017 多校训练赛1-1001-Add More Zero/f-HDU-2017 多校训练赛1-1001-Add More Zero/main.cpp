//
//  main.cpp
//  f-HDU-2017 多校训练赛1-1001-Add More Zero
//
//  Created by ZYJ on 2017/7/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int m;

int main(int argc, const char * argv[])
{
    int cs = 1;
    while (cin >> m)
    {
        cout << "Case #" << cs++ << ": " << (int)(m * log10(2)) << '\n';
    }
    
    return 0;
}
