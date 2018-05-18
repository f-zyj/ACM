//
//  main.cpp
//  f-赫夫曼编码
//
//  Created by ZYJ on 16/6/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include "huffman.hpp"

int main(int argc, const char * argv[])
{
    //  源码
//    char S[] = "I love Golden Dream!";
//    char S[] = "I love FishC.com!";
    char S[] = "三無科技esc炮灰";
    //  压缩码
//    char s[] = "01101101001111111001011100111111110000001010010110010011101101000100110101";
//    char s[] = "100011001110010000101011010010100000101011111011111101100101101110";
    char s[] = "10010010010111111010011011100010111100001001100110111101101010111110110000111110000011";
    
    //  构建赫夫曼树
    htTree *codeTree = buildTree(S);
    //  构建变长前缀码表
    hlTable *codeTable = buildTable(codeTree);
    //  压缩
    encode(codeTable, S);
    //  解压
    decode(codeTree, s);
    
    return 0;
}
