//
//  main.cpp
//  f-51Nod-1316-回文矩阵
//
//  Created by ZYJ on 16/9/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>

#define PINF 0x3f3f3f3f
#define NINF -PINF
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define FOR(i, f, e) for (int i = f; i < e; i++)

using namespace std;

typedef long long ll;

const int MAXN = 9;

int matrix[MAXN][MAXN];
int tmp[MAXN][MAXN];

void next(int &x)
{
    if (x == 0)
    {
        x = PINF;
    }
    else
    {
        int t1 = x & -x;
        int t2 = x + t1;
        x = t2 | ((x ^ t2) / t1 >> 2);
    }
    return ;
}

int main()
{
    int N, M = 0, Row, Colum, ans = PINF;
    char c[MAXN];
    scanf("%d%d%d", &Row, &Colum, &N);
    
    //  将矩阵存储到int型数组中
    FOR(i, 0, N)
    {
        scanf("%s", c);
        if (!M)
        {
            M = (int)strlen(c);
        }
        FOR(j, 0, M)
        {
            matrix[i][j] = (c[j] == '1');
        }
    }
    
    //  初始状态11111111(Row=8)
    int chooseRow = ~(-1 << Row);
    do
    {
        //  初始状态11111111(Colum=8)
        int chooseColum = ~(-1 << Colum);
        do
        {
            memcpy(tmp, matrix, sizeof(matrix));
            int res = 0;
            int getRow[MAXN], getColum[MAXN], posRow = 0, posColum = 0;
            FOR(i, 0, N)
            {
                if (chooseRow & 1 << i)
                {
                    getRow[posRow++] = i;       //  选取的行
                }
            }
            FOR(i, 0, M)
            {
                if (chooseColum & 1 << i)
                {
                    getColum[posColum++] = i;   //  选取的列
                }
            }
            //  固定行查找列(结束后保证行是回文的)
            FOR(i, 0, Row)
            {
                FOR(j, 0, M / 2)
                {
                    int instead = M - 1 - j;
                    //  第j列和第instead列都被选取
                    if ((chooseColum & 1 << j) && (chooseColum & 1 << instead))
                    {
                        int sum = tmp[getRow[i]][j] + tmp[getRow[i]][instead] + tmp[N - 1 - getRow[i]][j] + tmp[N - 1 - getRow[i]][instead];
                        //  四个交叉或对称点的情况，如果小于等于2说明有sum个可以改成0，否则说明有4-sum个可以改成1
                        if (sum <= 2)
                        {
                            res += sum;
                            tmp[getRow[i]][j] = tmp[getRow[i]][instead] = tmp[N - 1 - getRow[i]][j] = tmp[N - 1 - getRow[i]][instead] = 0;
                        }
                        else
                        {
                            res += 4 - sum;
                            tmp[getRow[i]][j] = tmp[getRow[i]][instead] = tmp[N - 1 - getRow[i]][j] = tmp[N - 1 - getRow[i]][instead] = 1;
                        }
                    }
                    //  第j列被选取
                    else if (chooseColum & 1 << j)
                    {
                        int sum = tmp[getRow[i]][j] + tmp[getRow[i]][instead] + tmp[N - 1 - getRow[i]][j];
                        //  三个交叉或对称点的情况，如果小于等于1说明有sum个可以改成0，否则说明有3-sum个可以改成1
                        if (sum <= 1)
                        {
                            res += sum;
                            tmp[getRow[i]][j] = tmp[getRow[i]][instead] = tmp[N - 1 - getRow[i]][j] = 0;
                        }
                        else
                        {
                            res += 3 - sum;
                            tmp[getRow[i]][j] = tmp[getRow[i]][instead] = tmp[N - 1 - getRow[i]][j] = 1;
                        }
                    }
                    //  第instead列被选取
                    else if (chooseColum & 1 << instead)
                    {
                        int sum = tmp[getRow[i]][j] + tmp[getRow[i]][instead] + tmp[N - 1 - getRow[i]][instead];
                        //  三个交叉点或对称的情况，如果小于等于1说明有sum个可以改成0，否则说明有3-sum个可以改成1
                        if (sum <= 1)
                        {
                            res += sum;
                            tmp[getRow[i]][j] = tmp[getRow[i]][instead] = tmp[N - 1 - getRow[i]][instead] = 0;
                        }
                        else
                        {
                            res += 3 - sum;
                            tmp[getRow[i]][j] = tmp[getRow[i]][instead] = tmp[N - 1 - getRow[i]][instead] = 1;
                        }
                    }
                    //  都没有被选取
                    else
                    {
                        int sum = tmp[getRow[i]][j] + tmp[getRow[i]][instead];
                        //  两个对称点的情况，如果等于1说明有1个可以被改成0
                        if (sum == 1)
                        {
                            res++;
                            tmp[getRow[i]][j] = tmp[getRow[i]][instead] = 0;
                        }
                    }
                }
            }
            //  固定列查找行(结束后保证列是回文的)
            FOR(i, 0, Colum)
            {
                FOR(j, 0, N / 2)
                {
                    if (tmp[j][getColum[i]] != tmp[N - 1 - j][getColum[i]])
                    {
                        tmp[j][getColum[i]] = tmp[N - 1 - j][getColum[i]] = 0;
                        res++;
                    }
                }
            }
            if (res < ans)
            {
                ans = res;
            }
            next(chooseColum);  //  下一个状态
        } while (chooseColum < 1 << M);
        next(chooseRow);        //  下一个状态
    } while (chooseRow < 1 << N);
    
    printf("%d", ans);
    
    return 0;
}