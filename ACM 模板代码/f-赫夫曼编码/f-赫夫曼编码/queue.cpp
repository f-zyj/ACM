//
//  queue.cpp
//  f-赫夫曼编码
//
//  Created by ZYJ on 16/6/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include "queue.hpp"
#include <stdlib.h>

//  初始化队列
void initPQueue(pQueue **queue)
{
    (*queue) = (pQueue *)malloc(sizeof(pQueue));
    (*queue)->first = NULL;
    (*queue)->size = 0;
    return ;
}

//  将出现的字符逐个插入队列，并维护出现次数是从小到大
void addPQueue(pQueue **queue, TYPE val, unsigned int priority)
{
    if ((*queue)->size == MAX_SZ)
    {
        printf("\nQueue is full.\n");
        return ;
    }
    
    pQueueNode *aux = (pQueueNode *)malloc(sizeof(pQueueNode));
    aux->priority = priority;
    aux->val = val;
    
    if ((*queue)->size == 0 || (*queue)->first == NULL)
    {
        aux->next = NULL;
        (*queue)->first = aux;
        (*queue)->size = 1;
        return ;
    }
    else
    {
        //  小于头则插入头
        if (priority <= (*queue)->first->priority)
        {
            aux->next = (*queue)->first;
            (*queue)->first = aux;
            (*queue)->size++;
            return ;
        }
        else
        {
            pQueueNode *iterator = (*queue)->first; //  迭代器
            //  插入合适的位置，维护从小到大顺序
            while (iterator->next != NULL)
            {
                if (priority <= iterator->next->priority)
                {
                    aux->next = iterator->next;
                    iterator->next = aux;
                    (*queue)->size++;
                    return ;
                }
                iterator = iterator->next;
            }
            
            //  当大于队列内所有值，则插入队尾
            if (iterator->next == NULL)
            {
                aux->next = NULL;
                iterator->next = aux;
                (*queue)->size++;
                return ;
            }
        }
    }
}

//  从队列头逐个取出（越接近头部出现的次数越少）
TYPE getPQueue(pQueue **queue)
{
    TYPE returnValue;
    if ((*queue)->size > 0)
    {
        returnValue = (*queue)->first->val;
        (*queue)->first = (*queue)->first->next;
        (*queue)->size--;
    }
    else
    {
        printf("\nQueue is empty.\n");
    }
    return returnValue;
}
