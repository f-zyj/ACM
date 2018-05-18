//
//  main.cpp
//  f-51Nod-TalkingData数据科学精英夏令营挑战赛-C-好数
//
//  Created by ZYJ on 2017/6/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll n;

int main(int argc, const char * argv[])
{
    while (cin >> n)
    {
        cout << n - (int)sqrt(n) << '\n';
    }
    
    return 0;
}

