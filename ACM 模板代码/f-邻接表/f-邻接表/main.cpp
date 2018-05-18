//
//  main.cpp
//  f-邻接表
//
//  Created by ZYJ on 16/6/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

//  边点结构
typedef struct Edge
{
    int tag;
    int weigh;
    struct Edge *next;
}Edge;

//  表结构
typedef struct Table
{
    int data;
    Edge *first;
}Table, *Tables;

int main(int argc, const char * argv[])
{
    int N, M;
    while (cin >> N >> M)   //  N结点数、M路径数
    {
        Tables table = (Tables)malloc(sizeof(Table) * N);
        int data, start, end, weigh;
        
        //  初始化结点
        for (int i = 0; i < N; i++)
        {
            cin >> data;
            table[i].data = data;
            table[i].first = NULL;
        }
        
        //  添加路径
        for (int i = 0; i < M; i++)
        {
            cin >> start >> end >> weigh;
            Edge *NN = (Edge *)malloc(sizeof(Edge));
            if (NULL == table[start].first)
            {
                table[start].first = NN;
                NN->tag = end;
                NN->weigh = weigh;
                NN->next = NULL;
            }
            else
            {
                NN = table[start].first;
                while (NULL != NN->next)
                {
                    NN = NN->next;
                }
                Edge *MM = (Edge *)malloc(sizeof(Edge));
                MM->tag = end;
                MM->weigh = weigh;
                MM->next = NULL;
                NN->next = MM;
            }
        }
        
        //  打印邻接表
        for (int i = 0; i < N; i++)
        {
            cout << i << ":" << table[i].data << "   ";         //  结点下标:结点权值
            if (table[i].first == NULL)
            {
                cout << "OVER" << endl;
                continue;
            }
            Edge *NN = (Edge *)malloc(sizeof(Edge));
            NN = table[i].first;
            cout << NN->tag << ":" << NN->weigh << "   ";       //  路径终点:路径权值
            while (NN->next != NULL)
            {
                NN = NN->next;
                cout << NN->tag << ":" << NN->weigh << "   ";   //  路径终点:路径权值
            }
            cout << "OVER" << endl;
        }
    }

    return 0;
}
