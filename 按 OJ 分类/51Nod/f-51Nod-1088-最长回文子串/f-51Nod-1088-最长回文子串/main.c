//
//  main.c
//  f-51Nod-1088-最长回文子串
//
//  Created by ZYJ on 16/4/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include<stdio.h>
//#include<string.h>
//#define MAX(a,b) ((a>b)?(a):(b))
//int f[2005];
//char str[2005];
//
//int main()
//{
//    int i, j, k, max = 0, o, r, l;
//    scanf("%s", str);
//    l = (int)strlen(str);
//    //扩充为原来两倍长，中间补*号
//    for(i = l - 1; i >= 0; i--)
//    {
//        str[2 * i] = str[i];
//        str[2 * i - 1] = '*';
//    }
//    
//    for(o = 0, r = 0, i = 1; i <=2 * (l - 1); i++)
//    {
//        if(i > (o + r)) //i对称轴
//        {
//            j = i - 1;
//            k = i + 1;
//        }
//        else if (f[2 * o - i] >= o + r - i) //对称轴到最右位置的下标差
//        {
//            k = o + r + 1;
//            j = 2 * i - k;
//        }
//        else
//        {
//            f[i] = f[2 * o - i];
//            continue;
//        }
//        while (j >= 0 && k <= 2 * (l - 1) && str[j] == str[k])  //匹配对称
//        {
//            j--;
//            k++;
//        }
//        f[i] = --k - i; //除去轴的子串长度
//        if(k >= o + r)
//        {
//            r = k - i;  //k此子串的最靠右的位置下标
//            o = i;
//            max = MAX((r + o % 2) / 2 * 2 - (o % 2) + 1, max);
//        }
//    }
//    
//    printf("%d", max);
//    return 0;
//}

#include<stdio.h>
#include<string.h>
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
int f[2005] = {0};
char str[2005];

int main()
{
    int i, id = 0, len, maxlen = 0;
    scanf("%s", str);
    len = (int)strlen(str);
    //扩充为原来两倍长，中间补*号
    for(i = len; i >= 0; i--)
    {
        str[i + i + 2] = str[i];
        str[i + i + 1] = '*';
    }
    str[0] = '#';
    
    for(i = 2; i < len + len + 1; i++)
    {
        if (f[id] + id > i)
        {
            f[i] = MIN(f[id + id - i], f[id] + id - i);
        }
        else
        {
            f[i] = 1;
        }
        while (str[i - f[i]] == str[i + f[i]])
        {
            f[i]++;
        }
        if (id + f[id] < i + f[i])
        {
            id = i;
        }
        maxlen = MAX(maxlen, f[i]);
    }
    
    printf("%d\n", maxlen - 1);
    return 0;
}
