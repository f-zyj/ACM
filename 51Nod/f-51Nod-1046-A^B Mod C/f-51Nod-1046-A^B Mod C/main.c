//
//  main.c
//  f-51Nod-1046-A^B Mod C
//
//  Created by ZYJ on 16/4/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

/*
                如来在此 谁敢造次
 
                    _ooOoo_
                   o8888888o
                   88" . "88
                   (| -_- |)
                   O\  =  /O
                ____/`---'\____
              .'  \\|     |//  `.
             /  \\|||  :  |||//  \           
            /  _||||| -:- |||||-  \
            |   | \\\  -  /// |   |
            | \_|  ''\---/''  |   |
            \  .-\__  `-`  ___/-. /
          ___`. .'  /--.--\  `. .'__
       ."" '<  `.___\_<|>_/___.'  >' "".
      | | :  `- \`.;`\ _ /`;.`/ - ` : | |
      \  \ `-.   \_ __\ /__ _/   .-` /  /
 ======`-.____`-.___\_____/___.-`____.-'======
                    `=---='
 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */


#include <stdio.h>

long PowerMod(long long A, long long B, long long C)
{
    long ans = 1;
    A %= C;
    while (B > 0)
    {
        if (B % 2 == 1)
        {
            ans = (ans * A) % C;
        }
        B /= 2;
        A = (A * A) % C;
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);
    
    printf("%ld\n", PowerMod(A, B, C));
    return 0;
}
