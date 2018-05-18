//
//  huffman.hpp
//  f-赫夫曼编码
//
//  Created by ZYJ on 16/6/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#ifndef huffman_hpp
#define huffman_hpp

#include <stdio.h>

typedef struct _htNode  //  树结点
{
    char symbol;
    struct _htNode *left, *right;
}htNode;

typedef struct _htTree  //  树
{
    htNode *root;
}htTree;

typedef struct _hlNode  //  表结点
{
    char symbol;
    char *code;
    struct _hlNode *next;
}hlNode;

typedef struct _hlTable //  表
{
    hlNode *first;
    hlNode *last;
}hlTable;

htTree *buildTree(char *inputString);               //  构建赫夫曼树
hlTable *buildTable(htTree *huffmanTree);           //  构建变长前缀码表
void encode(hlTable *table, char *stringToEncode);  //  压缩
void decode(htTree *tree, char *stringToDecode);    //  解压

#endif /* huffman_hpp */
