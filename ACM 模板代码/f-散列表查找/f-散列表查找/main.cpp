//
//  main.cpp
//  f-散列表查找
//
//  Created by ZYJ on 16/9/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

#define HASHSIZE 12
#define NULLKEY -32768

typedef struct
{
    int *elem;  //  数据元素的基址，动态分配数组
    int count;  //  当前数据元素的个数
} HashTable;

//  初始化哈希表<(￣3￣)> 表!
int InitHashTable(HashTable *H)
{
    H->count = HASHSIZE;
    H->elem = (int *)malloc(HASHSIZE * sizeof(int));
    if (!H->elem)
    {
        return -1;  //  申请失败
    }
    for (int i = 0; i < HASHSIZE; i++)
    {
        H->elem[i] = NULLKEY;
    }
    return 0;
}

//  除留余数法生成哈希值
int Hash(int key)
{
    return key % HASHSIZE;
}

//  插入关键字到散列表
void InserHash(HashTable *H, int key)
{
    int addr;
    addr = Hash(key);
    while (H->elem[addr] != NULLKEY)    //  产生冲突
    {
        addr = (addr + 1) % HASHSIZE;   //  开放定址法线性探测
    }
    
    H->elem[addr] = key;
    return ;
}

//  散列表查找关键字
int SearchHash(HashTable H, int key, int *addr)
{
    *addr = Hash(key);
    
    while (H.elem[*addr] != key)        //  冲突则线性探测
    {
        *addr = (*addr + 1) % HASHSIZE;
        if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) //  为空或者返回原位置
        {
            return 0;                   //  不存在
        }
    }
    return 1;                           //  存在，查找成功，结果存放在addr中
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
