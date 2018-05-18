//
//  main.c
//  f-ADV-215-Problem S4: Interesting Numbers 加强版
//
//  Created by ZYJ on 16/5/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#include <string.h>
//#define MOD 1000000007
//int ans;
//int flag[4];
//
//void dfs(int n, int init)
//{
//    if (n == 0)
//    {
//        if (flag[0] > 0 && flag[1] > 0 && flag[2] > 0 && flag[3] > 0)
//        {
//            ans++;
//            ans %= MOD;
//        }
//        return ;
//    }
//    
//    //0
//    if (init != 0 && flag[1] == 0)
//    {
//        flag[0]++;
//        dfs(n - 1, 1);
//        flag[0]--;
//    }
//    //1
//    flag[1]++;
//    dfs(n - 1, 1);
//    flag[1]--;
//    //2
//    if (flag[3] == 0)
//    {
//        flag[2]++;
//        dfs(n - 1, 1);
//        flag[2]--;
//    }
//    //3
//    flag[3]++;
//    dfs(n - 1, 1);
//    flag[3]--;
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    int n;
//    
//    while (~scanf("%d", &n))
//    {
//        ans = 0;
//        memset(flag, 0, sizeof(flag));
//        
//        dfs(n, 0);
//        printf("%d\n", ans);
//    }
//    
//    return 0;
//}



