//
//  main.cpp
//  f-51Nod-1718-"多项式"
//
//  Created by ZYJ on 2017/4/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int res[] = {2, 1, -1, -2, -1, 1};

int main(int argc, const char * argv[])
{
    long long n;
    
    while (cin >> n)
    {
        cout << res[n % 6] << '\n';
    }

    return 0;
}
