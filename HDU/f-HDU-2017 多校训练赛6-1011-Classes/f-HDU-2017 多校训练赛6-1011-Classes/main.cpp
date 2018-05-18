//
//  main.cpp
//  f-HDU-2017 多校训练赛6-1011-Classes
//
//  Created by ZYJ on 2017/8/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int N;
int A, B, C, AB, BC, AC, ABC;
int A_, B_, C_, AB_, BC_, AC_, ABC_;

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N;
     
        int ans = 0;
        while (N--)
        {
            cin >> A >> B >> C >> AB >> BC >> AC >> ABC;
            A_ = A - AB - AC + ABC;
            B_ = B - AB - BC + ABC;
            C_ = C - AC - BC + ABC;
            AB_ = AB - ABC;
            BC_ = BC - ABC;
            AC_ = AC - ABC;
            ABC_ = ABC;
            if (A_ >= 0 && B_ >= 0 && C_ >= 0 && AB_ >= 0 && BC_ >= 0 && AC_ >= 0 && ABC_ >= 0)
            {
                ans = max(ans, A_ + B_ + C_ + AB_ + BC_ + AC_ + ABC_);
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
