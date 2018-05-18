//
//  main.cpp
//  f-51Nod-1131-覆盖数字的数量
//
//  Created by ZYJ on 2017/3/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

int T;
ll A, B, X, Y;

int main(int argc, const char * argv[])
{
    cin >> T;
    
    while (T--)
    {
        cin >> A >> B >> X >> Y;
        ll res = 0;
        
        for (int i = 1; i; i++)
        {
            if (i * A <= X)
            {
                if (i * B >= (i + 1) * A - 1)
                {
                    res += Y - X + 1;
                    break;
                }
                else if (i * B >= Y)
                {
                    res += Y - X + 1;
                    break;
                }
                else if (i * B >= X)
                {
                    res += i * B - X + 1;
                }
            }
            else if (i * B <= Y)
            {
                if (i * B >= (i + 1) * A - 1)
                {
                    res += Y - i * A + 1;
                    break;
                }
                else
                {
                    res += i * B - i * A + 1;
                }
            }
            else
            {
                if (i * A <= Y)
                {
                    res += Y - i * A + 1;
                }
                break;
            }
        }
        
        cout << res << '\n';
    }
    
    return 0;
}
