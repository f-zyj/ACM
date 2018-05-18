//
//  queue.hpp
//  f-赫夫曼编码
//
//  Created by ZYJ on 16/6/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
#include "huffman.hpp"

#define TYPE    htNode *
#define MAX_SZ  256

typedef struct _pQueueNode  //  队列结点
{
    TYPE val;
    unsigned int priority;
    struct _pQueueNode *next;
}pQueueNode;

typedef struct _pQueue      //  队列
{
    unsigned int size;
    pQueueNode *first;
}pQueue;

void initPQueue(pQueue **queue);                                    //  初始化队列
void addPQueue(pQueue **queue, TYPE val, unsigned int priority);    //  插入队列头结点
TYPE getPQueue(pQueue **queue);                                     //  获取队列头结点

#endif /* queue_hpp */
