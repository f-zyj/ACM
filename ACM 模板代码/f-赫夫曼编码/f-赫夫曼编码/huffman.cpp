//
//  huffman.cpp
//  f-赫夫曼编码
//
//  Created by ZYJ on 16/6/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include "huffman.hpp"
#include "queue.hpp"
#include <string>
#include <stdlib.h>

//  创建赫夫曼树
htTree *buildTree(char *inputString)
{
    int *probability = (int *)malloc(sizeof(int) * 256);    //  存放ASCII自定义对应的字符
    //  初始化
    for (int i = 0; i < 256; i++)
    {
        probability[i] = 0;
    }
    
    //  统计待编码的字符串各个字符出现的次数
    for (int j = 0; inputString[j] != '\0'; j++)
    {
        probability[(unsigned char)inputString[j]]++;   //  此处强制转换可有可无
    }
    
    //  pQueue队列的头指针
    pQueue *huffmanQueue;
    initPQueue(&huffmanQueue);
    
    //  填充队列
    for (int k = 0; k < 256; k++)
    {
        if (probability[k] != 0)
        {
            htNode *aux = (htNode *)malloc(sizeof(htNode));
            aux->left = NULL;
            aux->right = NULL;
            aux->symbol = (char)k;
            
            addPQueue(&huffmanQueue, aux, probability[k]);
        }
    }
    
    free(probability);  //插入完毕，释放无用内存
    
    //  生成赫夫曼树
    while (huffmanQueue->size != 1)
    {
        int priority = huffmanQueue->first->priority;
        priority += huffmanQueue->first->next->priority;
        
        htNode *left = getPQueue(&huffmanQueue);
        htNode *right = getPQueue(&huffmanQueue);
        
        htNode *newNode = (htNode *)malloc(sizeof(htNode));
        newNode->left = left;
        newNode->right = right;
        
        addPQueue(&huffmanQueue, newNode, priority);
    }
    
    htTree *tree = (htTree *)malloc(sizeof(htTree));
    
    tree->root = getPQueue(&huffmanQueue);  //  赫夫曼树根结点
    
    return tree;                            //  返回赫夫曼树
}

//  生成前缀码
void traverseTree(htNode *treeNode, hlTable ** table, int k, char code[256])
{
    if (treeNode->left == NULL && treeNode->right == NULL)  //  存储前缀码
    {
        code[k] = '\0';
        hlNode *aux = (hlNode *)malloc(sizeof(hlNode));
        aux->code = (char *)malloc(sizeof(char) * (strlen(code) + 1));
        strcpy(aux->code, code);
        aux->symbol = treeNode->symbol;
        aux->next = NULL;
        
        if ((*table)->first == NULL)
        {
            (*table)->first = aux;
            (*table)->last = aux;
        }
        else
        {
            (*table)->last->next = aux;
            (*table)->last = aux;
        }
    }
    
    if (treeNode->left != NULL)     //  如果左孩子不为空，则前缀码填'0'
    {
        code[k] = '0';
        traverseTree(treeNode->left, table, k + 1, code);
    }
    
    if (treeNode->right != NULL)    //  如果右孩子不为空，则前缀码填'1'
    {
        code[k] = '1';
        traverseTree(treeNode->right, table, k + 1, code);
    }
    return ;
}

//  构建变长前缀码表
hlTable *buildTable(htTree *huffmanTree)
{
    hlTable *table = (hlTable *)malloc(sizeof(hlTable));
    table->first = NULL;
    table->last = NULL;
    
    char code[256];
    int k = 0;
    
    traverseTree(huffmanTree->root, &table, k, code);
    return table;   //  返回变长前缀码表
}

//  压缩
void encode(hlTable *table, char *stringToEncode)
{
    hlNode *traversal;
    
    printf("Encoding......\nInput string:\n%s\nEncoded string:\n", stringToEncode);
    
    for (int i = 0; stringToEncode[i] != '\0'; i++)
    {
        traversal = table->first;
        while (traversal->symbol != stringToEncode[i])
        {
            traversal = traversal->next;
        }
        printf("%s", traversal->code);
    }
    printf("\n");
    return ;
}

//  解压
void decode(htTree *tree, char *stringToDecode)
{
    htNode *traversal = tree->root;
    
    printf("\nDecoding......\nInput string:\n%s\nDecoded string:\n", stringToDecode);
    
    for (int i = 0; stringToDecode[i] != '\0'; i++)
    {
        if (traversal->left == NULL && traversal->right == NULL)
        {
            printf("%c", traversal->symbol);
            traversal = tree->root;
        }
        
        if (stringToDecode[i] == '0')       //  等于'0'向左孩子查找
        {
            traversal = traversal->left;
        }
        else /* if (stringToDecode[i] == '1')等于'1'向右孩子查找 */
        {
            traversal = traversal->right;
        }
    }
    
    if (traversal->left == NULL && traversal->right == NULL)
    {
        printf("%c", traversal->symbol);
    }
    putchar('\n');
    return ;
}