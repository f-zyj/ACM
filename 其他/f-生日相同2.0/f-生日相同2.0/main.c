//
//  main.c
//  f-生日相同2.0
//
//  Created by ZYJ on 16/4/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define _MAX 181

int n;
char name[_MAX][21];
int len[_MAX];
int month[_MAX];
int day[_MAX];

//交换
void swap(int i, int j)
{
    int k, length;
    len[i] ^= len[j];
    len[j] ^= len[i];
    len[i] ^= len[j];
    month[i] ^= month[j];
    month[j] ^= month[i];
    month[i] ^= month[j];
    day[i] ^= day[j];
    day[j] ^= day[i];
    day[i] ^= day[j];
    length = len[i] > len[j] ? len[i] : len[j];
    for (k = 0; k < length; k++)
    {
        name[i][k] ^= name[j][k];
        name[j][k] ^= name[i][k];
        name[i][k] ^= name[j][k];
    }
    return ;
}

//判断字典顺序
int dic(int i, int j)
{
    int k;
    for (k = 0; k < len[i]; k++)
    {
        if (name[i][k] > name[j][k])
        {
            return 1;
        }
        else if (name[i][k] < name[j][k])
        {
            return 0;
        }
    }
    return 0;
}

//排序
void sequence()
{
    int i = 0, j = 0;
    for (; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (month[i] > month[j])
            {
                swap(i, j);
            }
            else if (month[i] == month[j])
            {
                if (day[i] > day[j])
                {
                    swap(i, j);
                }
                else if (day[i] == day[j])
                {
                    if (len[i] > len[j])
                    {
                        swap(i, j);
                    }
                    else if (len[i] == len[j])
                    {
                        if (dic(i, j))
                        {
                            swap(i, j);
                        }
                    }
                }
            }
        }
    }
    return ;
}

//输出
void print()
{
    int i, j, count, key = 0;
    for (i = 0; i < n;)
    {
        count = 0;
        for (j = i + 1; j < n; j++)
        {
            if (month[i] == month[j] && day[i] == day[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count)
        {
            key++;
            printf("%d %d ", month[i], day[i]);
            for (; i < j - 1; i++)
            {
                printf("%s ", name[i]);
            }
            printf("%s\n", name[i++]);
        }
        if (!key)
        {
            printf("None\n");
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int i = 0;
    scanf("%d", &n);
    for (; i < n; i++)
    {
        scanf("%s %d %d", name[i], &month[i], &day[i]);
        len[i] = (int)strlen(name[i]);
    }
    sequence();
    
    print();
    return 0;
}
