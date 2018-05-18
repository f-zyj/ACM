//
//  main.c
//  f-BSG白山极客挑战赛-B-AVL树的种类
//
//  Created by ZYJ on 16/5/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int n;
    int nodeNum[] = {1, 3, 7, 15, 31, 63, 127, 255, 512, 1023};
    
    while (~scanf("%d", &n))
    {
        int tire;
        for (int i = 0; i < 11; i++)
        {
            if (n > nodeNum[i])
            {
                tire = i;
                break;
            }
        }
        int thisTire = nodeNum[tire - 1] + 1;
        int nextTire = nodeNum[tire] + 1;
        
    }
    printf("Hello, World!\n");
    return 0;
}
