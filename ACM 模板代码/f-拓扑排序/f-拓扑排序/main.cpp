//
//  main.cpp
//  f-拓扑排序
//
//  Created by ZYJ on 16/7/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  拓扑排序
 *  INIT:edge[][]置为图的邻接矩阵;count[0...i...n-1]:顶点i的入度。
 */
const int V = 10010;
int edge[V][V];
int count[V];

void TopoOrder(int n)
{
    int i, top = -1;
    for (i = 0; i < n; ++i)
    {
        if (count[i] == 0)
        {   //  下标模拟堆栈
            count[i] = top;
            top = i;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (top == -1)
        {
            printf("存在回路\n");
            return ;
        }
        else
        {
            int j = top;
            top = count[top];
            printf("%d", j);
            for (int k = 0; k < n; k++)
            {
                if (edge[j][k] && (--count[k]) == 0)
                {
                    count[k] = top;
                    top = k;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
