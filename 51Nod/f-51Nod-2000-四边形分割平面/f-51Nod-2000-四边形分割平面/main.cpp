//
//  main.cpp
//  f-51Nod-2000-四边形分割平面
//
//  Created by ZYJ on 2017/12/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

long long n;

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> n;
        n--;
        cout << 4 * n * n + 4 * n + 2 << '\n';
    }
    
    return 0;
}
