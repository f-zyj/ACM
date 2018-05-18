//
//  main.c
//  f-树的遍历
//
//  Created by ZYJ on 16/4/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//  SqStack *S = (SqStack*)malloc(sizeof(SqStack));

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char TElemType;
#define MAX_TREE_SIZE 100

typedef struct BiTNode  //结点结构
{
    TElemType data; //结点数据
    struct BiTNode *lchild, *rchild;    //左右孩子指针
} BiTNode, *BiTree;

//建树并前序遍历
void BinaryTreeFromOrderings(char *mid, char *last, int len)
{
    //长度为0则返回空
    if (len == 0)
    {
        return ;
    }
    BiTree node = (BiTree)malloc(sizeof(BiTNode));  //分配结点空间
    node->data = last[len - 1];
    //mid中寻找根结点
    int rootIndex = 0;
    for (; rootIndex < len; rootIndex++)
    {
        if (mid[rootIndex] == last[len - 1])
        {
            break;
        }
    }
    //前序遍历，则在建一个节点打印一次
    printf("%c", node->data);
    //Left
    BinaryTreeFromOrderings(mid, last, rootIndex);
    //Right
    BinaryTreeFromOrderings(mid + rootIndex + 1, last + rootIndex, len - (rootIndex + 1));  //后段为右子树
    return ;
}

int main(int argc, const char * argv[])
{
    char mid[100], last[100], len;
    scanf("%s %s", mid, last);
    len = (int)strlen(mid);
    
    BinaryTreeFromOrderings(mid, last, len);
    
    printf("\n");
    return 0;
}

//C++
//#include <iostream>
//#include <fstream>
//#include <string>
//
//struct TreeNode
//{
//   struct TreeNode* left;
//   struct TreeNode* right;
//   char  elem;
//};
//
//void BinaryTreeFromOrderings(char* inorder, char* preorder, int length)
//{
//    if(length == 0)
//    {
//       //cout<<"invalid length";
//       return;
//    }
//    TreeNode* node = new TreeNode;//Noice that [new] should be written out.
//    node->elem = *preorder;
//    int rootIndex = 0;
//    for(;rootIndex < length; rootIndex++)
//    {
//        if(inorder[rootIndex] == *preorder)
//           break;
//    }
//    //Left
//    BinaryTreeFromOrderings(inorder, preorder +1, rootIndex);
//    //Right
//    BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1));
//    cout<<node->elem<<endl;
//    return;
//}
//
//int main(int argc, char* argv[])
//{
//    printf("Hello World!\n");
//    char* pr="GDAFEMHZ";
//    char* in="ADEFGHMZ";
//     
//    BinaryTreeFromOrderings(in, pr, 8);
//  
//    printf("\n");
//    return 0;
//}