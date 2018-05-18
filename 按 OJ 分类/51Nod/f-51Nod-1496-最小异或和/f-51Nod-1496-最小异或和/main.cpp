//
//  main.cpp
//  f-51Nod-1496-最小异或和
//
//  Created by ZYJ on 2017/7/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

ll l, r, k;

int main()
{
    cin >> l >> r >> k;
    
    if (k >= 4)
    {
        if (l + 3 < r || (l + 3 == r && !(l & 1)))
        {
            cout << 0 << endl;
            return 0;
        }
    }
    
    if (k >= 3)
    {
        int t = 0;
        while (l >> t)
        {
            t++;
        }
        ll k = 3LL << (t - 1);
        if (k <= r)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    
    if (k >= 2)
    {
        if (!(l & 1) || l + 1 < r)
        {
            cout << 1 << endl;
            return 0;
        }
        else if ((l ^ r) < l)
        {
            cout << (l ^ r) << endl;
            return 0;
        }
    }
    
    cout << l << endl;
    
    return 0;
}

