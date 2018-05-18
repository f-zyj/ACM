//
//  main.c
//  f-51Nod-1069-Nim游戏
//
//  Created by ZYJ on 16/4/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define _MAX 1001

int main(int argc, const char * argv[])
{
    int N, stone, tag = 0;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &stone);
        tag ^= stone;
    }
    //tag为0则为后手赢，否则为先手赢
    printf("%c\n", tag == 0 ? 'B' : 'A');
    return 0;
}
